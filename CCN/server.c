#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include "common.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0,reg_no=3;
    struct sockaddr_in serv_addr; 

    char sendBuff[1025],reg_users[10][20];
    time_t ticks; 


    strcpy(reg_users[0],"William");
    strcpy(reg_users[1],"John");
    strcpy(reg_users[2],"Emily");


    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    //Initializing the Socket
    if(listenfd<0){
        error("Error creating socket\n");
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 

    //Binding the socket to the address
    if(bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0){
      
      error("Error binding to socket\n");
    } 

    listen(listenfd, 5); 


    while(1){
        //Initializing one socket for each client
        int clientSockFd[MAX_PLAYERS];
        struct sockaddr_in clientAddress;
        socklen_t clientLen = sizeof(clientAddress);
        int pid,flag=0;
        char uname[20];

        printf("\nWelcome to the Wisconsin's Casino gaming company..!!!\n\n");
        printf("\nLet's start the BLack-Jack game\n");
        printf("Do you want to register users?\n1.Yes\n2.No\n");

        scanf("%d",&flag);

        if(flag==1)
        while(flag==1)
        {
            printf("\nEnter your username:  ");
            scanf("%s",uname);
            strcpy(reg_users[reg_no],uname);
            reg_no++;

            printf("\nThe user %s has been added to Wiscon's Casino..!\n",uname);

            printf("\nDo you want to add more users?\n1.YES\n2.NO\n");
            scanf("%d",&flag);

            if(flag==2)
                break;
        }
        
        printf("\nThe Dealer Mr.Robin is waiting to begin a new game.....\n\n");

        clientSockFd[0] = accept(listenfd, (struct sockaddr*)&clientAddress, &clientLen);
        if(clientSockFd[0]<0)
        {
            error("Error accepting first client");
        } 
        else
        {
            printf("First player is connected on socket %d\n",clientSockFd[0]);
            int number_of_clients = 1;
            while(number_of_clients<MAX_PLAYERS)
            {
                printf("Waiting for next player to connect \n \n");
                if((clientSockFd[number_of_clients]=accept(listenfd,(struct sockaddr*)&clientAddress,&clientLen))<0)
                {
                    error("Error accepting next client\n");
                }
                else
                {
                    printf("Next player connected on socket %d \n",clientSockFd[number_of_clients]);
                }

                number_of_clients++;
            }

            printf("\nNOW THE REAL GAME BEGINS.....!! \n");
            //At this stage all the players in the game are connected

            //At this stage -- Create a new process
            switch(pid=fork())
            {
                case -1: error("A new process cannot be created");
                case 0:
                {
                    //New process created:
                    char arguments[MAX_PLAYERS+2+reg_no][300];
                    char *args[MAX_PLAYERS+2+reg_no];
                    strcpy(arguments[0],"./dealer");
                    args[0] = arguments[0];
                    int i,j;
                    for(i=0;i<number_of_clients;i++)
                    {
                        sprintf(arguments[i+1],"%d",clientSockFd[i]);
                        args[i+1] = arguments[i+1];
                    }
                    
                    for(i=number_of_clients+1;i<=MAX_PLAYERS+1;i++)
                    {
                        args[i] = 0;
                    }

                    for(j=0;j<reg_no;j++)
                    {
                        sprintf(arguments[i+1+j],"%s",reg_users[j]);
                        args[i+1+j] = arguments[i+1+j];
                    }
                    
                    printf("%d",i+j+1);
                    execv("./dealer",args);
                    //printf("Check\n");
                    error("exec didn't succeed");


                }
                //Default : Parent process
                default:{
                    break;
                }

            }



        }

        close(clientSockFd[0]);
        close(clientSockFd[1]);
        close(clientSockFd[2]);

    //break;
    sleep(100);

    }  

}
