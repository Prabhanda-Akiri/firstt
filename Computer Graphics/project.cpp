#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>

GLfloat x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
GLint le1[1000],le2[1000],re1[1000],re2[1000];

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
                if(le2[i]<2 && re2[i]<2){
                if(x<le1[i])
                {
                    le1[i]=x;
                    le2[i]++;
                    if(le2[i]==2){
                        le2[i]=1000;
                        re2[i]=0;}
                }
                if(x>re1[i])
                {
                    re1[i]=x;
                    re2[i]++;
                    if(re2[i]==2){
                        le2[i]=1000;
                        re2[i]=0;}
                }}
                else
                {
                    if(x<le2[i])
                    {
                    le2[i]=x;
                    }
                    if(x>re2[i])
                    {
                    re2[i]=x;
                    }

                }
                x+=mx;
            }
}
void drawpixel(int x,int y,float a,float b,float c)
{
            glColor3f(a,b,c);
            glBegin(GL_POINTS);
            glVertex2i(x,y);
            glEnd();
}
void scanfill_poly(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float x5,float y5,float a,float b,float c)
{
            int i,y;
            for(i=0;i<1000;i++)
            {
                        le1[i]=1000;
                        re1[i]=0;
                        le2[i]=0;
                        re2[i]=0;
            }
            edgedetect(x1,y1,x2,y2);
            edgedetect(x2,y2,x3,y3);
            edgedetect(x3,y3,x4,y4);
            edgedetect(x4,y4,x5,y5);
            edgedetect(x5,y5,x1,y1);

            for(y=0;y<1000;y++)
            {
                if(le1[y]<=re1[y])
                    for(i=le1[y]+1;i<re1[y];i++)
                        drawpixel(i,y,a,b,c);
                if(le2[y]>2 && re2[y]>2)
                    for(i=le2[y]+1;i<re2[y];i++)
                        drawpixel(i,y,a,b,c);
            }
}
void display()
{
            glColor3f(0.3,0.5,0.5);
            glClear(GL_COLOR_BUFFER_BIT);
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
            /*x1=200,y1=200,x2=100,y2=300,x3=200,y3=400,x4=300,y4=300;
            glColor3f(0.139,0.69,0.19);
            glBegin(GL_LINE_LOOP);
            glVertex2f(x1,y1);
             glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glVertex2f(x4,y4);
            glVertex2f(x5,y5);
            glEnd();*/
   glFlush();
}
void myinit()
{
            glClearColor(0.3,0.5,0.5,1.0);
            glColor3f(0.3,0.5,0.5);
            glPointSize(1.0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(0.0,999.0,0.0,999.0);
}
int main(int argc,char **argv)
{           glutInit(&argc,argv);
            glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
            glutInitWindowSize(900,600);
            glutInitWindowPosition(0,0);
            glutCreateWindow("scanfill");
            glutDisplayFunc(display);
            myinit();
            glutMainLoop();
            return 0;
   }
