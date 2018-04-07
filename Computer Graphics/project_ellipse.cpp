#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>

GLfloat x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
GLfloat xb1=600,yb1=10,xb2=680,yb2=10,xb3=700,yb3=60,xb4=580,yb4=60,xb5=580,yb5=60;
GLfloat xf1=640,yf1=90,xf2=700,yf2=130,xf3=640,yf3=170,xf4=xf3,yf4=yf3,xf5=xf3,yf5=yf3;
GLfloat xp1=636,yp1=60,xp2=640,yp2=60,xp3=640,yp3=180,xp4=636,yp4=180,xp5=xp4,yp5=yp4;

GLint le[1000][20],re[1000][20];
GLint ct[1000],cur_l[1000],cur_r[1000];

GLfloat Xsize_s=0,Xsize_e=999;

void drawpixel(int x,int y,float a,float b,float c)
{
            glColor3f(a,b,c);
            glBegin(GL_POINTS);
            glVertex2i(x,y);
            glEnd();
}

void store_vertex(int x,int y)
{
            if(cur_l[y]<2 && cur_r[y]<2)
                {
                if(x<le[y][ct[y]])
                {
                    le[y][ct[y]]=x;
                    cur_l[y]++;
                }
                if(x>re[y][ct[y]])
                {
                    re[y][ct[y]]=x;
                    cur_r[y]++;
                }
                }
                else
                {
                    ct[y]++;
                    cur_l[y]=0;
                    cur_r[y]=0;
                if(x<le[y][ct[y]])
                {
                    le[y][ct[y]]=x;
                    cur_l[y]++;
                }
                if(x>re[y][ct[y]])
                {
                    re[y][ct[y]]=x;
                    cur_r[y]++;
                }

                }
}

void edgedetect(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2)
{
            float mx,x,temp;
            int i;
            if((y2-y1)<0)
            {
              temp=x1;
              x1=x2;
              x2=temp;

              temp=y1;
              y1=y2;
              y2=temp;
            }

            if((y2-y1)!=0)
                mx=(x2-x1)/(y2-y1);
            else
                mx=x2-x1;

            x=x1;

            for(i=y1;i<y2;i++)
            {
                store_vertex(x,i);
                x+=mx;
            }
}

void detect_ellipse_up(double a,double b,float l,float st_x,float st_y,double a1,double b1,float l1,float st_x1,float st_y1,float u,float v,float w)
{
    int i,y,j;
    for(i=0;i<1000;i++)
    {
       ct[i]=0;
       cur_l[i]=0;
       cur_r[i]=0;
       for(j=0;j<20;j++)
       {
          le[i][j]=1000;
          re[i][j]=0;
       }
    }

    int sa=a*a;
    int sb=b*b;
    int ex=0;
    int ey=b;

    double d1=sb-(sa*b) + (0.5*sa) ;

    store_vertex(ex+st_x,ey+st_y);

    while((sa*(ey-0.5)>sb*(ex+1)) && ex<l1)
    {
        if(d1<0)
            d1+=sb*3+sb*2*ex;
        else
        {
            d1+=sb*3+sb*2*ex+2*sa-2*sa*ey;
            ey--;
        }
        ex++;
        store_vertex(-(ex)+st_x,ey+st_y);
         store_vertex(ex+st_x,ey+st_y);
    }

    int le_y=ey+st_y,  le_x=ex+st_x,  le_x_l=-(ex)+st_x;
    a=a1;
    b=b1;
    sa=a*a;
    sb=b*b;
    ex=0;
    ey=b;
    int flag=0;
    d1=sb-(sa*b) + (0.5*sa) ;
    for(y=ey+st_y1;y<le_y;y++)
    {
        store_vertex(le_x_l,y);
        store_vertex(le_x,y);
    }
    store_vertex(ex+st_x1,ey+st_y1);

    while((sa*(ey-0.5)>sb*(ex+1)) && ex<l)
    {
        flag=0;

        if(d1<0)
            d1+=sb*3+sb*2*ex;
        else
        {
            d1+=sb*3+sb*2*ex+2*sa-2*sa*ey;
            ey--;
            flag=1;
        }
        ex++;

        if(ex!=l && flag==1){
        store_vertex(le_x_l,ey+st_y1);
        store_vertex(-(ex)+st_x1,ey+st_y1);
        store_vertex(ex+st_x1,ey+st_y1);
        store_vertex(le_x,ey+st_y1);}
    }

    for(y=0;y<1000;y++)
    {
       for(i=0;i<ct[y]+1;i++)
       {
          //printf("plotting point ellipse");
          if(le[y][i]<re[y][i])
          {
             for(j=le[y][i]+1;j<re[y][i];j++)
                drawpixel(j,y,u,v,w);
          }
       }
     }

}

void scanfill_poly(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float x5,float y5,float a,float b,float c)
{
            int i,y,j;
            for(i=0;i<1000;i++)
            {
                        ct[i]=0;
                        cur_l[i]=0;
                        cur_r[i]=0;
                        for(j=0;j<20;j++)
                        {
                            le[i][j]=1000;
                            re[i][j]=0;
                        }
            }

            edgedetect(x1,y1,x2,y2);
            edgedetect(x2,y2,x3,y3);
            edgedetect(x3,y3,x4,y4);
            edgedetect(x4,y4,x5,y5);
            edgedetect(x5,y5,x1,y1);

            for(y=0;y<1000;y++)
            {
                for(i=0;i<ct[i]+1;i++)
                {
                    if(le[y][i]<re[y][i])
                    {
                        for(j=le[y][i]+1;j<re[y][i];j++)
                        drawpixel(j,y,a,b,c);
                    }
                }
            }
}

void display()
{
            glColor3f(0.3,0.5,0.5);
            glClear(GL_COLOR_BUFFER_BIT);

            detect_ellipse_up(800,200,400,600,120,450,200,400,600,0,0.1,0.3,0.3);
            //for the land mass
            x1=0,y1=0,x2=300,y2=0,x3=200,y3=300,x4=0,y4=300,x5=0,y5=300;
            scanfill_poly(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,0.5,0.1,0);

            //for the tree bark
            x1=90,y1=300,x2=110,y2=300,x3=110,y3=370,x4=90,y4=370,x5=90,y5=370;
            scanfill_poly(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,0.3,0.1,0);
            // first triangle in tree from bottom
            x1=50,y1=370,x2=150,y2=370,x3=100,y3=440,x4=100,y4=440,x5=100,y5=440;
            scanfill_poly(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,0.1,0.8,0.0);
            // second triangle in tree from bottom
            x1=60,y1=420,x2=140,y2=420,x3=100,y3=490,x4=100,y4=490,x5=100,y5=490;
            scanfill_poly(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,0.1,0.8,0.0);
            // third triangle in tree from bottom
            x1=70,y1=470,x2=130,y2=470,x3=100,y3=520,x4=100,y4=520,x5=100,y5=520;
            scanfill_poly(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,0.1,0.8,0.0);

            // water level
            x1=300,y1=0,x2=1000,y2=0,x3=1000,y3=9,x4=297,y4=9,x5=297,y5=9;
            scanfill_poly(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,0.0,0.0,0.8);

            //boat base
            scanfill_poly(xb1,yb1,xb2,yb2,xb3,yb3,xb4,yb4,xb5,yb5,0.3,0.1,0);

            //boat flag
            scanfill_poly(xf1,yf1,xf2,yf2,xf3,yf3,xf4,yf4,xf5,yf5,0.8,0.0,0);

            //boat pole
            scanfill_poly(xp1,yp1,xp2,yp2,xp3,yp3,xp4,yp4,xp5,yp5,0,0.0,0);


   glFlush();
   glutPostRedisplay();
   glutSwapBuffers();
}

void translate_boat(float tx)
{
    if(xb4+tx>280 && xb3+tx<1000){
    xb1=xb1+tx;
    xb2=xb2+tx;
    xb3=xb3+tx;
    xb4=xb4+tx;
    xb5=xb5+tx;

    xf1=xf1+tx;
    xf2=xf2+tx;
    xf3=xf3+tx;
    xf4=xf4+tx;
    xf5=xf5+tx;

    xp1=xp1+tx;
    xp2=xp2+tx;
    xp3=xp3+tx;
    xp4=xp4+tx;
    xp5=xp5+tx;
    }
}

void specialkey(int key,int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        translate_boat(-5);
        /*translate_x(xb2,-5,2);
        translate_x(xb3,-5,3);
        translate_x(xb4,-5,4);
        translate_x(xb5,-5,5);*/
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:
        translate_boat(5);
        /*translate_x(xb2,5,2);
        translate_x(xb3,5,3);
        translate_x(xb4,5,4);
        translate_x(xb5,5,5);*/
        glutPostRedisplay();
        break;
    }

}

void myinit()
{
            glClearColor(0.3,0.5,0.5,1.0);
            glColor3f(0.3,0.5,0.5);
            glPointSize(1.0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(Xsize_s,Xsize_e,0.0,999.0);
}
int main(int argc,char **argv)
{           glutInit(&argc,argv);
            glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
            glutInitWindowSize(900,600);
            glutInitWindowPosition(0,0);
            glutCreateWindow("scanfill");
            glutDisplayFunc(display);
            myinit();
            glutSpecialFunc(specialkey);
            glutMainLoop();
            return 0;
}
