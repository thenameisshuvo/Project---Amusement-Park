#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
#include<stdio.h>
#define PI 3.1416
static GLfloat spin = 0.0;
static float tx	=  0.0,bx=0.0,by=0.0,isbaby=0,dolnay=0,countdolna=0,glUp=1;
static float step=0,stepx=0,stepy=0;
static float angle=0,cloudleftx=0,cloudmiddlex=0,cloudrightx=0,cloudrightupx=0;
static float ty	=  5.0;
static float shipx=0;
void baby();
void circle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;
    glBegin(GL_POLYGON);
    for(i = 0; i < 100; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }
    glEnd();
}
void halfcircle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;
    glBegin(GL_POLYGON);
    for(i = 0; i < 51; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }
    glEnd();
}
void sky()
{
    glPushMatrix();
    glColor3f(0.1,0.6,0.9);
    glTranslatef(0,10,0),
    glBegin(GL_QUADS);
    glVertex3f(-150.0,0.0,0.0);
    glVertex3f(150.0,0.0,0.0);
    glVertex3f(150.0,-8,0.0);
    glVertex3f(-150.0,-8,0.0);
    glEnd();
    glPopMatrix();
}
void sun()
{
    glPushMatrix();
    glTranslated(-4,8,0);
    glScaled(0.3,0.3,0);
    glColor3f(1,1,0);
    circle(4,4);
    glPopMatrix();
}
void hillSide()
{
    glPushMatrix();
    glScaled(1,0.6,0);

    glPushMatrix(); //Hill-1
    glTranslatef(-9.5,5.0,1);
    glColor3f(0,0.6,0);
    halfcircle(12,5);
    glPopMatrix();

    glPushMatrix();//Hill-2
    glTranslatef(8.5,5.0,1);
    glColor3f(0,0.5,0.1);
    halfcircle(15,7);
    glPopMatrix();

    glPushMatrix();//Hill-3
    glTranslatef(-4.5,5.0,1);
    glColor3f(0,0.9,0.2);
    halfcircle(6,3);
    glPopMatrix();

    glPopMatrix();
}
void hillTree()
{
    glPushMatrix();//Full tree
    glTranslatef(-15,6,0);
    glScaled(0.5,0.2,0);

    glPushMatrix();//Tree Root
    glTranslatef(-1,-12,1);
    glColor3f(0.55,0.27,0.0745);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(1.0,10.0);
    glVertex2d(1.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Tree Leaf-1
    glTranslated(-0.5,0,0);
    glScaled(0.4,1,1);
    glPushMatrix();
    glColor3f(0.0,0.39,0);
    glTranslatef(0,4,0);
    circle(7,6);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-2
    glTranslated(-5.5,1.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-3
    glTranslated(-5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-4
    glTranslated(5.5,-0.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-5
    glTranslated(5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-6
    glTranslated(0.0,6.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-7
    glTranslated(-5.5,-3.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-8
    glTranslated(5.5,-3.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}
void hillTree2()
{
    glPushMatrix();//Full tree
    glTranslatef(-10,6,0);
    glScaled(0.5,0.2,0);

    glPushMatrix();//Tree Root
    glTranslatef(-1,-12,1);
    glColor3f(0.55,0.27,0.0745);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(1.0,10.0);
    glVertex2d(1.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Tree Leaf-1
    glTranslated(-0.5,0,0);
    glScaled(0.4,1,1);
    glPushMatrix();
    glColor3f(0.0,0.39,0);
    glTranslatef(0,4,0);
    circle(7,6);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-2
    glTranslated(-5.5,1.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-3
    glTranslated(-5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-4
    glTranslated(5.5,-0.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-5
    glTranslated(5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-6
    glTranslated(0.0,6.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-7
    glTranslated(-5.5,-3.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-8
    glTranslated(5.5,-3.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}
void hillTree3()
{
    glPushMatrix();//Full tree
    glTranslatef(7,6,0);
    glScaled(0.5,0.2,0);

    glPushMatrix();//Tree Root
    glTranslatef(-1,-12,1);
    glColor3f(0.55,0.27,0.0745);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(1.0,10.0);
    glVertex2d(1.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Tree Leaf-1
    glTranslated(-0.5,0,0);
    glScaled(0.4,1,1);
    glPushMatrix();
    glColor3f(0.0,0.39,0);
    glTranslatef(0,4,0);
    circle(7,6);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-2
    glTranslated(-5.5,1.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-3
    glTranslated(-5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-4
    glTranslated(5.5,-0.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-5
    glTranslated(5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-6
    glTranslated(0.0,6.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-7
    glTranslated(-5.5,-3.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-8
    glTranslated(5.5,-3.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}
void hillTree4()
{
    glPushMatrix();//Full tree
    glTranslatef(13,6,0);
    glScaled(0.5,0.2,0);

    glPushMatrix();//Tree Root
    glTranslatef(-1,-12,1);
    glColor3f(0.55,0.27,0.0745);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(1.0,10.0);
    glVertex2d(1.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Tree Leaf-1
    glTranslated(-0.5,0,0);
    glScaled(0.4,1,1);
    glPushMatrix();
    glColor3f(0.0,0.39,0);
    glTranslatef(0,4,0);
    circle(7,6);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-2
    glTranslated(-5.5,1.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-3
    glTranslated(-5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-4
    glTranslated(5.5,-0.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-5
    glTranslated(5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-6
    glTranslated(0.0,6.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,2);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-7
    glTranslated(-5.5,-3.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();//Tree Leaf-8
    glTranslated(5.5,-3.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}
void field()
{
    glPushMatrix();
    glColor3f(0.2,0.7,0.1);
    glBegin(GL_QUADS);
    glVertex2d(-150.0,0.0);
    glVertex2d(150.0,0.0);
    glVertex2d(150.0,-50);
    glVertex2d(-150.0,-50);
    glEnd();
    glPopMatrix();
}
void river()
{
    glPushMatrix();
    glTranslatef(0,20,0);

    glPushMatrix();//River Border-1
    glBegin(GL_QUADS);
    glColor3f(0.55,0.27,0.0745);
    glVertex2d(-150.0,-16.4);
    glVertex2d(150.0,-16.4);
    glVertex2d(150.0,-16.5);
    glVertex2d(-150.0,-16.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();//River Border-2
    glBegin(GL_QUADS);
    glColor3f(0.55,0.27,0.0745);
    glVertex2d(-150.0,-20);
    glVertex2d(150.0,-20);
    glVertex2d(150.0,-20.1);
    glVertex2d(-150.0,-20.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();//River
    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.565f, 1.0f);
    glVertex2d(150.0,-16.5);
    glVertex2d(-150.0,-16.5);
    glVertex2d(-150.0,-20);
    glVertex2d(150.0,-20);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
void ship()
{
    if(isbaby==8)
    {

        shipx=shipx-0.03;
        if(shipx<-25)
            shipx=20;

    }
    glPushMatrix();
    glTranslated(0+shipx,0.8,0);
    glScaled(0.6,0.2,0);

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0); //ship body
    glVertex2d(0.0,0.0);
    glVertex2d(-3.0,7.0);
    glVertex2d(10.0,7.0);
    glVertex2d(8.0,0.0);

    glColor3f(0.0,1.0,0.0); //green box
    glVertex2d(2.0,7.0);
    glVertex2d(2.0,9.0);
    glVertex2d(8.0,9.0);
    glVertex2d(8.0,7.0);

    glColor3f(1.0,1.0,0.0); //yellow box
    glVertex2d(3.0,9.0);
    glVertex2d(3.0,11.0);
    glVertex2d(7.0,11.0);
    glVertex2d(7.0,9.0);

    glColor3f(1.0,0.0,0.0); //red stand
    glVertex2d(4.0,9.0);
    glVertex2d(4.0,15.0);
    glVertex2d(6.0,15.0);
    glVertex2d(6.0,9.0);

    glEnd();
    glPopMatrix();
}
void cloudRightUp()//Cloud Off
{
    glPushMatrix();
    glTranslated(14,16.5,1);
    glScaled(0.5,0.2,0);
    glColor3f(1.0f,1.0f,1.0f);

    glPushMatrix();//1
    glTranslated(0,-38,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();//2
    glTranslated(1,-35,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();//3
    glTranslated(3,-35,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();//4
    glTranslated(4.5,-37.5,1);
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();//5
    glTranslated(2.5,-38.5,1),
    circle(1.5,2.5);
    glPopMatrix();
    glPopMatrix();

}
void cloudLeft()//Cloud Slow
{
    cloudleftx=cloudleftx-0.01;
    if(cloudleftx<-4)
    {
        cloudleftx=40;
    }
    glPushMatrix();
    glTranslated(-20+cloudleftx,8.5,1);
    glScaled(0.5,0.2,1);
    glColor3f(1.0f,1.0f,1.0f);

    glPushMatrix();//1
    glTranslated(0,0,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();//2
    glTranslated(1.5,1,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();//3
    glTranslated(4,1.5,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();//4
    glTranslated(4.5,-0.7,1),
    circle(2.5,2.0);
    glPopMatrix();

    glPushMatrix();//5
    glTranslated(2.0,-1.0,1),
    circle(1.5,2.5);
    glPopMatrix();
    glPopMatrix();
}
void cloudRight()//Cloud Average
{

    cloudrightx-=0.02;
    if(cloudrightx<-35)
    {
        cloudrightx=20;
    }
    glPushMatrix();
    glTranslated(12+cloudrightx,16,1);
    glScaled(0.5,0.2,1);
    glColor3f(1.0f,1.0f,1.0f);

    glPushMatrix();//1
    glTranslated(0,-38,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();//2
    glTranslated(1,-35,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();//3
    glTranslated(3,-35,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();//4
    glTranslated(4.5,-37.5,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();//5
    glTranslated(2.5,-38.5,1),
    circle(1.5,2.5);
    glPopMatrix();
    glPopMatrix();
}
void cloudMiddle()//Cloud Fast
{
    cloudmiddlex=cloudmiddlex-0.03;
    if(cloudmiddlex<-20)
    {
        cloudmiddlex=30;
    }
    glPushMatrix();
    glTranslated(-3.5+cloudmiddlex,16,1);
    glScaled(0.5,0.2,1);
    glColor3f(1.0f,1.0f,1.0f);

    glPushMatrix();//1
    glTranslated(0,-38,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();//2
    glTranslated(1,-35,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();//3
    glTranslated(3,-35,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();//4
    glTranslated(4.5,-37.5,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();//5
    glTranslated(2.5,-38.5,1),
    circle(1.5,2.5);
    glPopMatrix();
    glPopMatrix();
}
void baby()
{
    glPushMatrix();
    if(isbaby==0)
    {
        glTranslated(0+bx,0+by,0);
        glScalef(0.05,0.07,0);
    }
    else if(isbaby==5)
    {
        glTranslated(-0.5,2,0);
        glScaled(0.07,0.2,0);
    }
    else if(isbaby==6)
    {
        glTranslated(0+bx,0+by,0);
        glScalef(0.04,0.06,0);
    }

    else if(isbaby==8)
    {
        glTranslated(0+shipx,3,0);
        glTranslated(0,0,0);
        glScalef(0.04,0.04,0);
    }
    glPushMatrix();   //Dress top
    glColor3f(1,0,1);
    glBegin(GL_POLYGON);
    glVertex2d(-6,-6);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-6,-11);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(6,-11);
    glVertex2d(9,-13);
    glVertex2d(11,-9);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPopMatrix();

    glPushMatrix();//left hand
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-13,-20);
    glVertex2d(-16,-18);
    glEnd();
    glPopMatrix();

    glPushMatrix();//left hand Palm
    glTranslated(-15,-20,0);
    glColor3f(0.87,0.72,0.53);
    circle(3,2.5);
    glPopMatrix();

    glPushMatrix();//right hand
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(11,-9);
    glVertex2d(9,-13);
    glVertex2d(13,-20);
    glVertex2d(16,-18);
    glEnd();
    glPopMatrix();

    glPushMatrix();//right hand palm
    glTranslated(15,-20,0);
    glColor3f(0.87,0.72,0.53);
    circle(3,2.5);
    glPopMatrix();

    glPushMatrix();//Dress skirt
    glColor3f(1,1,0);
    glBegin(GL_QUADS);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(13,-32);
    glVertex2d(-13,-32);
    glEnd();
    glPopMatrix();

    glPushMatrix();//left leg
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(-6,-32);
    glVertex2d(-2,-32);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();//right leg
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(6,-32);
    glVertex2d(2,-32);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();//right shoe
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(10,-42);
    glVertex2d(2,-42);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();//left shoe
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(-10,-42);
    glVertex2d(-2,-42);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //hair
    glColor3f(0,0,0);
    circle(13,10);
    glPopMatrix();

    glPushMatrix();//head, neck,eye, lips
    glColor3f(0.87,0.72,0.53);
    circle(7,6); //head
    glBegin(GL_QUADS);//neck
    glVertex2d(-6,-6);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();

    glPushMatrix();//right eye
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2d(4,3);
    glVertex2d(1,3);
    glEnd();

    glBegin(GL_LINES);//lips
    glVertex2d(2,-3);
    glVertex2d(-2,-3);
    glEnd();
    glPopMatrix();

    glPushMatrix();//left eye
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2d(-4,3);
    glVertex2d(-1,3);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}
void babySwing()
{
    glPushMatrix();
    if(isbaby==1)
    {
        if(dolnay==0)
        {
            glTranslated(-14,1,0);
            glScaled(0.05,0.05,0);
        }
        else if(dolnay>=1 )
        {
            glTranslated(-14,-0.4+dolnay,0);
            glScaled(0.04,0.04,0);
            dolnay=-0.1;
        }
        else if(dolnay<=-1 )
        {
            glTranslated(-14,2.4+dolnay,0);
            glScaled(0.06,0.06,0);
            dolnay=0.1;
        }
        else if(dolnay>0.1 && dolnay <1)
        {
            glTranslated(0,-0.29+dolnay,0);
            glTranslated(-14,1,0);
            glScaled(0.05,0.05,0);
            countdolna++;
        }
        else if(dolnay<-0.1 && dolnay >-1)
        {
            glTranslated(-14,1.35+dolnay,0);
            glScaled(0.05,0.05,0);
        }

        glPushMatrix();   //Dress Tops
        glRotated(-20,0,1,0);
        glColor3f(1,0,1);
        glBegin(GL_POLYGON);
        glVertex2d(-6,-6);
        glVertex2d(-11,-9);
        glVertex2d(-9,-13);
        glVertex2d(-6,-11);
        glVertex2d(-6,-22);
        glVertex2d(6,-22);
        glVertex2d(6,-11);
        glVertex2d(9,-13);
        glVertex2d(11,-9);
        glVertex2d(6,-6);
        glVertex2d(4,-10);
        glVertex2d(-4,-10);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left hand
        glRotated(-20,0,1,0);
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(-11,-9);
        glVertex2d(-9,-13);
        glVertex2d(-13,-20);
        glVertex2d(-16,-18);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left hand Palm
        glRotated(-20,0,1,0);
        glTranslated(-15,-20,0);
        glColor3f(0.87,0.72,0.53);
        circle(3,2.5);
        glPopMatrix();

        glPushMatrix();//right hand
        glRotated(-20,0,1,0);
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(11,-9);
        glVertex2d(9,-13);
        glVertex2d(13,-20);
        glVertex2d(16,-18);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right hand palm
        glRotated(-20,0,1,0);
        glTranslated(15,-20,0);
        glColor3f(0.87,0.72,0.53);
        circle(3,2.5);
        glPopMatrix();

        glPushMatrix(); //Dress skirt
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
        glVertex2d(-6,-22);
        glVertex2d(6,-22);
        glVertex2d(-1,-28);
        glVertex2d(-16,-28);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left leg
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(-13,-28);
        glVertex2d(-8,-28);
        glVertex2d(-11,-32);
        glVertex2d(-17,-32);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right leg
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(-2,-28);
        glVertex2d(-7,-28);
        glVertex2d(-10,-32);
        glVertex2d(-5,-32);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right shoe
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex2d(-5,-32);
        glVertex2d(-10,-32);
        glVertex2d(-13,-35);
        glVertex2d(-6,-35);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left shoe
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex2d(-17,-32);
        glVertex2d(-11,-32);
        glVertex2d(-12,-35);
        glVertex2d(-20,-35);
        glEnd();
        glPopMatrix();

        glPushMatrix();//hair
        glRotated(-20,0,1,0);
        glColor3f(0,0,0);
        circle(13,10);
        glPopMatrix();

        glPushMatrix();//head, neck,eye, lips
        glRotated(-20,0,1,0);
        glColor3f(0.87,0.72,0.53);
        circle(7,6);//head
        glBegin(GL_QUADS);//neck
        glVertex2d(-6,-6);
        glVertex2d(6,-6);
        glVertex2d(4,-10);
        glVertex2d(-4,-10);
        glEnd();

        glPushMatrix();//right eye
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex2d(4,3);
        glVertex2d(1,3);
        glEnd();

        glBegin(GL_LINES);//lips
        glVertex2d(2,-3);
        glVertex2d(-2,-3);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left eye
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex2d(-4,3);
        glVertex2d(-1,3);
        glEnd();
        glPopMatrix();
        glPopMatrix();
    }
    glPopMatrix();
}
void swing()
{
    glPushMatrix();
    glTranslated(-18,-1.5,0);
    glScaled(0.7,0.4,0);
    glColor3f(0.54,0,0);

    glPushMatrix(); //Swing left bar
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(0.4,10.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //Swing right bar
    glTranslated(10,0,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(0.4,10.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //Swing up bar
    glTranslated(0,9,1);
    glRotatef(-90,0,0,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.4);
    glVertex2d(0.4,10.4);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //Swing left line
    glTranslated(2.9,3,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,dolnay);
    glVertex2d(0.0,6.0);
    glVertex2d(0.1,6.0);
    glVertex2d(0.1,dolnay);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //Swing right side
    glTranslated(7.7,3,1);
    glBegin(GL_QUADS);
    glVertex2d(0,dolnay);
    glVertex2d(0,6.0);
    glVertex2d(0.1,6.0);
    glVertex2d(0.1,dolnay);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //Swing sitting table
    glTranslated(1.8,3,1);
    glBegin(GL_QUADS);
    glVertex2d(1.0,dolnay+1);
    glVertex2d(6.0,dolnay+1);
    glVertex2d(7.0,dolnay);
    glVertex2d(0.0,dolnay);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    babySwing();
}
void wheerligig()
{
    glPushMatrix();

    glPushMatrix();  //stand
    glTranslated(13,-5,1);
    glScaled(0.4,0.25,0);
    glColor3f(0.545,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,-10);
    glVertex2d(1,-10);
    glVertex2d(1,30);
    glVertex2d(0,30);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(13.25,2.5,1);
    glScaled(0.35,0.2,0);
    glRotated(angle,0,0,1);
    glPushMatrix();
    glTranslatef(10,13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);//2 box upper small line
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();

    glPushMatrix();
    glBegin(GL_QUADS);//2 box
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glVertex2d(1.5,-2.5);
    glVertex2d(1.5,-7.5);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);//2 box middle line
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,-13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);//3 box upper small line
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();

    glPushMatrix();
    glBegin(GL_QUADS);//2 box
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);//3 box middle line
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,-13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);//4 box upper small line
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    if(isbaby==5)
    {
        baby();
    }
    glPushMatrix();
    glBegin(GL_QUADS);//4 box
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);//4 box middle line
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);//1 box upper small line
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();

    glPushMatrix();
    glBegin(GL_QUADS);// 1 box
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);//1 box middle line
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();//4 cross lines
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(10,13);
    glVertex2d(0,0);
    glVertex2d(10,-13);
    glVertex2d(0,0);
    glVertex2d(-10,-13);
    glVertex2d(0,0);
    glVertex2d(-10,13);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Middle Circle
    glTranslated(0,0,0);
    glColor3f(0.545,0,0);
    circle(2,2);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}
void bench()
{
    glPushMatrix();
    glTranslated(-8,-3,1);
    glColor3f(0.54,0,0);
    glScaled(0.8,0.6,1);

    glPushMatrix(); //Bench
    glTranslated(1.8,3,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(1.0,1.0);
    glVertex2d(6.0,1.0);
    glVertex2d(7.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Line Under Bench
    glRotatef(-90,0,0,1);
    glTranslated(-2.8,1.8,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,7.0);
    glVertex2d(0.1,7.0);
    glVertex2d(0.1,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Bench Left bar
    glTranslated(3,1.7,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,1.0);
    glVertex2d(0.4,1.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Bench Right bar
    glTranslated(7,1.7,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,1.0);
    glVertex2d(0.4,1.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    if(isbaby==3)
    {
        glTranslated(-4,0.5,0);
        glScaled(0.05,0.06,0);
        glPushMatrix();//Dress top
        glColor3f(1,0,1);
        glBegin(GL_POLYGON);
        glVertex2d(-6,-6);
        glVertex2d(-11,-9);
        glVertex2d(-9,-13);
        glVertex2d(-6,-11);
        glVertex2d(-6,-22);
        glVertex2d(6,-22);
        glVertex2d(6,-11);
        glVertex2d(9,-13);
        glVertex2d(11,-9);
        glVertex2d(6,-6);
        glVertex2d(4,-10);
        glVertex2d(-4,-10);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left hand
        glColor3f(0.87,0.72,0.53);
        glRotated(-15,0,1,0);
        glBegin(GL_QUADS);
        glVertex2d(-11,-9);
        glVertex2d(-9,-13);
        glVertex2d(-13,-20);
        glVertex2d(-16,-18);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left hand palm
        glTranslated(-15,-18.5,0);
        glColor3f(0.87,0.72,0.53);
        circle(3.3,2.7);
        glPopMatrix();

        glPushMatrix();//right hand
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(11,-9);
        glVertex2d(9,-13);
        glVertex2d(13,-20);
        glVertex2d(16,-18);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right hand palm
        glTranslated(15,-20,0);
        glColor3f(0.87,0.72,0.53);
        circle(3,2.5);
        glPopMatrix();

        glPushMatrix();//Dress skirt
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
        glVertex2d(-6,-22);
        glVertex2d(6,-22);
        glVertex2d(4,-32);
        glVertex2d(-16,-30);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left leg
        glTranslated(-6,1.5,0);
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(-6,-32);
        glVertex2d(-2,-32);
        glVertex2d(-2,-38);
        glVertex2d(-6,-38);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right leg
        glTranslated(-5,0.8,0);
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(6,-32);
        glVertex2d(2,-32);
        glVertex2d(2,-38);
        glVertex2d(6,-38);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right shoe
        glTranslated(-5,0.8,0);
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex2d(6,-42);
        glVertex2d(-2,-42);
        glVertex2d(2,-38);
        glVertex2d(6,-38);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left shoe
        glTranslated(-6,1.5,0);
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex2d(-10,-42);
        glVertex2d(-2,-42);
        glVertex2d(-2,-38);
        glVertex2d(-6,-38);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //hair
        glColor3f(0,0,0);
        circle(13,10);
        glPopMatrix();

        glPushMatrix();//head, neck,eye, lips
        glColor3f(0.87,0.72,0.53);
        circle(7,6); //head
        glBegin(GL_QUADS);//neck
        glVertex2d(-6,-6);
        glVertex2d(6,-6);
        glVertex2d(4,-10);
        glVertex2d(-4,-10);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right eye
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex2d(4,3);
        glVertex2d(1,3);
        glEnd();

        glBegin(GL_LINES);//lips
        glVertex2d(2,-3);
        glVertex2d(-2,-3);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left eye
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex2d(-4,3);
        glVertex2d(-1,3);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();
}
void babySlide()
{
    glPushMatrix();
    if(isbaby==7 && step==4)
    {
        glTranslatef(3.5+stepx,-1.7+stepy,0);
        glScaled(0.04,0.06,0);

        glPushMatrix();//Dress top
        glRotated(-20,0,1,0);
        glColor3f(1,0,1);
        glBegin(GL_POLYGON);
        glVertex2d(-6,-6);
        glVertex2d(-11,-9);
        glVertex2d(-9,-13);
        glVertex2d(-6,-11);
        glVertex2d(-6,-22);
        glVertex2d(6,-22);
        glVertex2d(6,-11);
        glVertex2d(9,-13);
        glVertex2d(11,-9);
        glVertex2d(6,-6);
        glVertex2d(4,-10);
        glVertex2d(-4,-10);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left hand
        glRotated(-20,0,1,0);
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(-11,-9);
        glVertex2d(-9,-13);
        glVertex2d(-13,-20);
        glVertex2d(-16,-18);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left hand palm
        glRotated(-20,0,1,0);
        glTranslated(-15,-20,0);
        glColor3f(0.87,0.72,0.53);
        circle(3,2.5);
        glPopMatrix();


        glPushMatrix();//right hand
        glRotated(-20,0,1,0);
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(11,-9);
        glVertex2d(9,-13);
        glVertex2d(13,-20);
        glVertex2d(16,-18);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right hand palm
        glRotated(-20,0,1,0);
        glTranslated(15,-20,0);
        glColor3f(0.87,0.72,0.53);
        circle(3,2.5);
        glPopMatrix();

        glPushMatrix();//Dress skirt
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
        glVertex2d(-6,-22);
        glVertex2d(6,-22);
        glVertex2d(17,-28);
        glVertex2d(-2,-28);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left leg
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(5,-28);
        glVertex2d(0,-28);
        glVertex2d(3,-32);
        glVertex2d(8,-32);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right leg
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(14,-28);
        glVertex2d(9,-28);
        glVertex2d(12,-32);
        glVertex2d(17,-32);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right shoe
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex2d(17,-32);
        glVertex2d(12,-32);
        glVertex2d(15,-35);
        glVertex2d(21,-35);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left shoe
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex2d(8,-32);
        glVertex2d(3,-32);
        glVertex2d(5,-35);
        glVertex2d(12,-35);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //hair
        glRotated(-20,0,1,0);
        glColor3f(0,0,0);
        circle(13,10);
        glPopMatrix();

        glPushMatrix();//head, neck,eye, lips
        glRotated(-20,0,1,0);
        glColor3f(0.87,0.72,0.53);
        circle(7,6);//head
        glBegin(GL_QUADS);//neck
        glVertex2d(-6,-6);
        glVertex2d(6,-6);
        glVertex2d(4,-10);
        glVertex2d(-4,-10);
        glEnd();

        glPushMatrix();//right eye
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex2d(4,3);
        glVertex2d(1,3);
        glEnd();

        glBegin(GL_LINES); //lips
        glVertex2d(2,-3);
        glVertex2d(-2,-3);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left eye
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex2d(-4,3);
        glVertex2d(-1,3);
        glEnd();
        glPopMatrix();
        glPopMatrix();
    }
    glPopMatrix();
}
void slide()
{
    glPushMatrix();
    glTranslatef(2,-3,0);

    glPushMatrix();//Small ladder-1
    glTranslatef(-3,-3,0);
    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(3,0);
    glVertex2d(2.8,-0.1);
    glVertex2d(-0.1,-0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Small ladder-2
    glTranslatef(-2,-2,0);
    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(3,0);
    glVertex2d(2.8,-0.1);
    glVertex2d(-0.1,-0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Small ladder-3
    glTranslatef(-1,-1,0);
    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(3,0);
    glVertex2d(2.8,-0.1);
    glVertex2d(-0.1,-0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Small ladder left bar
    glColor3f(0.54,0.396,0.031);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(0.3,0);
    glVertex2d(-3.7,-4);
    glVertex2d(-4,-4);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Small ladder Right bar
    glColor3f(0.54,0.396,0.031);
    glBegin(GL_QUADS);
    glVertex2d(3,0);
    glVertex2d(2.7,0);
    glVertex2d(-1.3,-4);
    glVertex2d(-1,-4);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Slipper Tool
    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(3,0);
    glVertex2d(6,-5);
    glVertex2d(3,-5);
    glEnd();
    glPopMatrix();

    glPopMatrix();
    babySlide();
}
void glidder()
{
    glPushMatrix();
    glTranslated(-18.5,-6,0);
    glColor3f(0.54,0,0);
    glScalef(0.8,0.5,0);
    if(glUp==0)
    {
        glPushMatrix();//glider lower bar
        glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(13,3.0);
        glVertex2f(13,3.3);
        glVertex2f(0,0.3);
        glEnd();
        glPopMatrix();

        glPushMatrix();//glider lower left box
        glBegin(GL_QUADS);
        glVertex2d(3.0,0.9);
        glVertex2d(3.0,1.5);
        glVertex2d(3.3,1.5);
        glVertex2d(3.3,0.9);
        glEnd();
        glPopMatrix();

        glPushMatrix();//glider lower right box
        glBegin(GL_QUADS);
        glVertex2d(10.0,2.4);
        glVertex2d(10.0,3.0);
        glVertex2d(9.7,3.0);
        glVertex2d(9.7,2.4);
        glEnd();
        glPopMatrix();

        glPushMatrix();  //glider down bar
        glTranslated(6.2,1.0,1);
        glBegin(GL_QUADS);
        glVertex2d(0.0,0.5);
        glVertex2d(0.0,-2.0);
        glVertex2d(0.5,-2.0);
        glVertex2d(0.5,0.6);
        glEnd();
        glPopMatrix();
    }

    else if(glUp==1)
    {
        glPushMatrix();//glider upper bar
        glBegin(GL_QUADS);
        glVertex2f(0,3.0);
        glVertex2f(0,3.3);
        glVertex2f(13,0.3);
        glVertex2f(13,0);
        glEnd();
        glPopMatrix();

        glPushMatrix();//glider upper left box
        glBegin(GL_QUADS);
        glVertex2d(3.0,2.4);
        glVertex2d(3.0,3.0);
        glVertex2d(3.3,3.0);
        glVertex2d(3.3,2.4);
        glEnd();
        glPopMatrix();

        glPushMatrix();//glider upper right box
        glBegin(GL_QUADS);
        glVertex2d(10.0,0.9);
        glVertex2d(10.0,1.5);
        glVertex2d(9.7,1.5);
        glVertex2d(9.7,0.9);
        glEnd();
        glPopMatrix();

        glPushMatrix();  //glider down bar
        glTranslated(6.2,1.0,1);
        glBegin(GL_QUADS);
        glVertex2d(0.0,0.6);
        glVertex2d(0.0,-2.0);
        glVertex2d(0.5,-2.0);
        glVertex2d(0.5,0.5);
        glEnd();
        glPopMatrix();

    }
    glPopMatrix();

    glPushMatrix();
    if(isbaby==2)
    {
        if(glUp==0)
        {
            glRotatef(20,1,1,1);
            glTranslated(-17.8,-0.6,0);
        }
        else if(glUp==1)
        {
            glRotatef(-20,1,1,1);
            glTranslated(-15.8,-6.6,0);

        }

        glScaled(0.05,0.05,0);
        glPushMatrix();//Dress top
        glColor3f(1,0,1);
        glBegin(GL_POLYGON);
        glVertex2d(-6,-6);
        glVertex2d(-11,-9);
        glVertex2d(-9,-13);
        glVertex2d(-6,-11);
        glVertex2d(-6,-22);
        glVertex2d(6,-22);
        glVertex2d(6,-11);
        glVertex2d(9,-13);
        glVertex2d(11,-9);
        glVertex2d(6,-6);
        glVertex2d(4,-10);
        glVertex2d(-4,-10);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left hand
        glColor3f(0.87,0.72,0.53);
        glRotated(-15,0,1,0);
        glBegin(GL_QUADS);
        glVertex2d(-11,-9);
        glVertex2d(-9,-13);
        glVertex2d(-18,-11);
        glVertex2d(-16,-7);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left hand palm
        glTranslated(-18.5,-9,0);
        glColor3f(0.87,0.72,0.53);
        circle(3.3,2.7);
        glPopMatrix();

        glPushMatrix();//right hand
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(11,-9);
        glVertex2d(9,-13);
        glVertex2d(13,-20);
        glVertex2d(16,-18);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right hand palm
        glTranslated(15,-20,0);
        glColor3f(0.87,0.72,0.53);
        circle(3,2.5);
        glPopMatrix();

        glPushMatrix();//Dress skirt
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
        glVertex2d(-6,-22);
        glVertex2d(6,-22);
        glVertex2d(4,-32);
        glVertex2d(-16,-30);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left leg
        glTranslated(-6,1.5,0);
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(-6,-32);
        glVertex2d(-2,-32);
        glVertex2d(-2,-38);
        glVertex2d(-6,-38);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right leg
        glTranslated(-5,0.8,0);
        glColor3f(0.87,0.72,0.53);
        glBegin(GL_QUADS);
        glVertex2d(6,-32);
        glVertex2d(2,-32);
        glVertex2d(2,-38);
        glVertex2d(6,-38);
        glEnd();
        glPopMatrix();

        glPushMatrix();//right shoe
        glTranslated(-5,0.8,0);
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex2d(6,-42);
        glVertex2d(-2,-42);
        glVertex2d(2,-38);
        glVertex2d(6,-38);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left shoe
        glTranslated(-6,1.5,0);
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex2d(-10,-42);
        glVertex2d(-2,-42);
        glVertex2d(-2,-38);
        glVertex2d(-6,-38);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //hair
        glColor3f(0,0,0);
        circle(13,10);
        glPopMatrix();

        glPushMatrix();//head, neck,eye, lips
        glColor3f(0.87,0.72,0.53);
        circle(7,6);//head
        glBegin(GL_QUADS);//neck
        glVertex2d(-6,-6);
        glVertex2d(6,-6);
        glVertex2d(4,-10);
        glVertex2d(-4,-10);
        glEnd();

        glPushMatrix();//right eye
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex2d(4,3);
        glVertex2d(1,3);
        glEnd();

        glBegin(GL_LINES);//lips
        glVertex2d(2,-3);
        glVertex2d(-2,-3);
        glEnd();
        glPopMatrix();

        glPushMatrix();//left eye
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex2d(-4,3);
        glVertex2d(-1,3);
        glEnd();
        glPopMatrix();
        glPopMatrix();
    }
    glPopMatrix();
    glPushMatrix();
    if(glUp==0)
    {
        glRotatef(20,1,1,1);
        glTranslated(-10.6,-1.2,0);
    }
    else if(glUp==1)
    {
        glRotatef(-20,1,1,1);
        glTranslated(-8.5,-6.2,0);
    }
    glScalef(0.05,0.05,0);
    glPushMatrix();   //Dress top
    glColor3f(1,0.27,0);
    glBegin(GL_POLYGON);
    glVertex2d(-6,-6);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-6,-11);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(6,-11);
    glVertex2d(9,-13);
    glVertex2d(11,-9);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //left hand
    glColor3f(1,0.94,0.83);
    glBegin(GL_QUADS);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-13,-20);
    glVertex2d(-16,-18);
    glEnd();
    glPopMatrix();

    glPushMatrix();//left hand palm
    glTranslated(-15,-20,0);
    glColor3f(1,0.94,0.83);
    circle(3,2.5);
    glPopMatrix();

    glPushMatrix();//right hand
    glColor3f(1,0.94,0.83);
    glBegin(GL_QUADS);
    glVertex2d(11,-9);
    glVertex2d(9,-13);
    glVertex2d(13,-20);
    glVertex2d(16,-18);
    glEnd();
    glPopMatrix();

    glPushMatrix();//right hand palm
    glTranslated(15,-20,0);
    glColor3f(1,0.94,0.83);
    circle(3,2.5);
    glPopMatrix();

    glPushMatrix();//Dress skirt
    glColor3f(0.6,0.196,0.8);
    glBegin(GL_QUADS);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(4,-32);
    glVertex2d(-16,-30);
    glEnd();
    glPopMatrix();

    glPushMatrix();//left leg
    glTranslated(-6,1.5,0);
    glColor3f(1,0.94,0.83);
    glBegin(GL_QUADS);
    glVertex2d(-6,-32);
    glVertex2d(-2,-32);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();//right leg
    glTranslated(-5,0.8,0);
    glColor3f(1,0.94,0.83);
    glBegin(GL_QUADS);
    glVertex2d(6,-32);
    glVertex2d(2,-32);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();//right shoe
    glTranslated(-5,0.8,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(6,-42);
    glVertex2d(-2,-42);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();//left shoe
    glTranslated(-6,1.5,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(-10,-42);
    glVertex2d(-2,-42);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //hair
    glColor3f(0,0,0);
    circle(13,10);
    glPopMatrix();

    glPushMatrix();//head, neck,eye, lips
    glColor3f(1,0.94,0.83);
    circle(7,6);//head
    glBegin(GL_QUADS);//neck
    glVertex2d(-6,-6);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();

    glPushMatrix();//right eye
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2d(4,3);
    glVertex2d(1,3);
    glEnd();

    glBegin(GL_LINES);//lips
    glVertex2d(2,-3);
    glVertex2d(-2,-3);
    glEnd();
    glPopMatrix();

    glPushMatrix();//left eye
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2d(-4,3);
    glVertex2d(-1,3);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    sun();
    hillSide();
    hillTree();
    hillTree2();
    hillTree3();
    hillTree4();
    field();
    river();
    cloudLeft();
    cloudRightUp();
    cloudRight();
    cloudMiddle();
    glidder();
    if(isbaby!=8)
    {
        ship();
        wheerligig();
        swing();
    }
    bench();
    if(isbaby==0||isbaby==6||isbaby==8)
    {
        baby();
    }
    slide();
    if(isbaby==8)
    {
        ship();
        wheerligig();
        swing();

    }
    glutPostRedisplay();
    glFlush();
}
void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(-20.0, 20.0, -10.0, 10.0, -15.0, 15.0);
}

void spe_key(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        bx=bx-0.5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:
        bx=bx+0.5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:
        by=by-0.5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_UP:
        by=by+0.5;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}
void windMove()
{
    if(angle<-326.5)
    {
        isbaby=0;
        angle=0;
        bx=7;
        by=0;
        glutIdleFunc(NULL);
    }
    else
    {
        angle=angle-0.3;
    }
    glutPostRedisplay();

}
void dolnaMove()
{
    if(dolnay>=0.1)
    {
        dolnay+=0.002;
    }
    else if(dolnay<=-0.1)
    {
        dolnay-=0.002;
    }
    glutPostRedisplay();
}
void slideMove()
{
    stepx+=0.007;
    stepy-=0.01;
    glutPostRedisplay();
    if(stepy<-4.5)
    {
        isbaby=0;
        step=0;
        stepx=0;
        stepy=0;
        bx=-1;
        by=-4;
        glutIdleFunc(NULL);
        glutPostRedisplay();
    }
}
void normal_key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'f': //Swing right position
        dolnay=-1;
        glutPostRedisplay();
        break;

    case 'u'://Swing get up
        isbaby=1;
        dolnay=0.1;
        glutIdleFunc(dolnaMove);
        glutPostRedisplay();
        break;
    case 'd'://Swing get down
        isbaby=0;
        bx=-15;
        by=-0.5;
        glutIdleFunc(NULL);
        glutPostRedisplay();
        break;

    case 'g'://Glider get up
        isbaby=2;
        glutPostRedisplay();
        break;

    case 'j'://Glider get down
        isbaby=0;
        bx=-17;
        by=-6;
        glUp=1;
        glutPostRedisplay();
        break;

    case 'h'://Glider Higher portion
        glUp=1;
        glutPostRedisplay();
        break;

    case 'l'://Glider Lower portion
        glUp=0;
        glutPostRedisplay();
        break;

    case 'r'://Bench Sit
        isbaby=3;
        glutPostRedisplay();
        break;

    case 's'://Bench Stand up
        isbaby=0;
        bx=-4;
        by=-1;
        glutPostRedisplay();
        break;

    case 'w'://Whirligig get up
        isbaby=5;
        glutIdleFunc(windMove);
        break;

    case 'o'://Slide step
        isbaby=6;
        step++;
        if(step==1)
        {
            bx=0.5;
            by=-3.5;
        }
        else if(step==2)
        {
            bx=1.5;
            by=-2.5;
        }
        else if(step==3)
        {
            bx=2.5;
            by=-1.5;
        }

        else if(step==4)
        {
            isbaby=7;
            glutIdleFunc(slideMove);
        }
        glutPostRedisplay();
        break;

    case 'b'://get up to boat
        isbaby=8;
        glutPostRedisplay();
        break;

    case 'c'://get down to boat
        if(shipx<5 && shipx>-5)
        {
            isbaby=0;
            bx=0;
            by=0;
        }
    default:
        break;
    }
}
int main()
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1600, 1000);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("My CG Project");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(normal_key);
    glutMainLoop();
    return 0;
}


// Tanvir Rahman Shuvo