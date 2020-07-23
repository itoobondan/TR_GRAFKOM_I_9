#include <windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>

#define RATIO 1.200 //mendefinisikan rasio dengan perbandingan 1:1.200
#define WW 100 //lebar viewport = 100
#define WH (WW/RATIO) // tinggi viewport
#define HALFX ((int)(WW/2)) //koordinat X min atau max
#define HALFY ((int)(WH/2)) //koordinat Y min atau max
#define deltat .001 //menambahkan nilai t
void init(void);
void display(void);
void mouse(int button, int state, int x, int y);
GLuint texture[35];
@@ -67,8 +73,8 @@ void display(void) //
    //Bagian tanah
    glBegin(GL_QUADS);
       glColor3f(37/255.0f,134/255.0f,22/255.0f);
        glVertex3f(-45.0,-20.0,35.0);
        glVertex3f(40.0,-20.0,35.0);
        glVertex3f(-45.0,-20.0,55.0);
        glVertex3f(40.0,-20.0,55.0);
        glVertex3f(40.0,-20.0,-45.0);
        glVertex3f(-45.0,-20.0,-45.0);
    glEnd();
@@ -730,39 +736,39 @@ glBegin(GL_TRIANGLES);
    }

    //jendela depan bagian paling bawah
    for(float b=10.0;b<=15;b+=5.0)
    for(float b=10.0;b<=15;b+=4.0)
    {
        for(float a=-20.0;a<=1.0;a+=6.0)
        for(float a=-20.0;a<=6.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(-10.0+a,-3.0-b,14.1);
                glVertex3f(-10.0+a,-1.0-b,14.1);
                glVertex3f(-12.0+a,-1.0-b,14.1);
                glVertex3f(-12.0+a,-3.0-b,14.1);
                glVertex3f(-16.0+a,-4.0-b,14.1);
                glVertex3f(-16.0+a,-2.0-b,14.1);
                glVertex3f(-18.0+a,-2.0-b,14.1);
                glVertex3f(-18.0+a,-4.0-b,14.1);
            glEnd();
        }
    }

    //jendela depan bagian paling bawah
    for(float b=10.0;b<=15;b+=5.0)
    for(float b=10.0;b<=15;b+=4.0)
    {
        for(float a=-20.0;a<=1.0;a+=6.0)
        for(float a=-20.0;a<=6.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(27.0+a,-3.0-b,14.1);
                glVertex3f(27.0+a,-1.0-b,14.1);
                glVertex3f(29.0+a,-1.0-b,14.1);
                glVertex3f(29.0+a,-3.0-b,14.1);
                glVertex3f(27.0+a,-4.0-b,14.1);
                glVertex3f(27.0+a,-2.0-b,14.1);
                glVertex3f(29.0+a,-2.0-b,14.1);
                glVertex3f(29.0+a,-4.0-b,14.1);
            glEnd();
        }
    }

    //jendela depan kedua dari bawah
    for(float b=10.0;b<=15;b+=10.0)
    {
        for(float a=-20.0;a<=-5.0;a+=6.0)
        for(float a=-20.0;a<=3.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
@@ -777,37 +783,37 @@ glBegin(GL_TRIANGLES);
    //jendela depan kedua dari bawah
    for(float b=10.0;b<=15;b+=10.0)
    {
        for(float a=-20.0;a<=-5.0;a+=6.0)
        for(float a=-20.0;a<=3.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(-4.0+a,3.0-b,14.1);
                glVertex3f(-4.0+a,1.0-b,14.1);
                glVertex3f(-6.0+a,1.0-b,14.1);
                glVertex3f(-6.0+a,3.0-b,14.1);
                glVertex3f(-13.0+a,3.0-b,14.1);
                glVertex3f(-13.0+a,1.0-b,14.1);
                glVertex3f(-15.0+a,1.0-b,14.1);
                glVertex3f(-15.0+a,3.0-b,14.1);
            glEnd();
        }
    }

    //jendela depan ketiga dari bawah
    for(float b=10.0;b<=15;b+=10.0)
    {
        for(float a=-20.0;a<=-10.0;a+=6.0)
        for(float a=-20.0;a<=-3.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(0.0+a,8.0-b,14.1);
                glVertex3f(0.0+a,6.0-b,14.1);
                glVertex3f(2.0+a,6.0-b,14.1);
                glVertex3f(2.0+a,8.0-b,14.1);
                glVertex3f(-9.0+a,8.0-b,14.1);
                glVertex3f(-9.0+a,6.0-b,14.1);
                glVertex3f(-7.0+a,6.0-b,14.1);
                glVertex3f(-7.0+a,8.0-b,14.1);
            glEnd();
        }
    }

    //jendela depan ketiga dari bawah
    for(float b=10.0;b<=15;b+=10.0)
    {
        for(float a=-20.0;a<=-10.0;a+=6.0)
        for(float a=-20.0;a<=-3.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
@@ -822,7 +828,7 @@ glBegin(GL_TRIANGLES);
    //jendela depan ketiga dari bawah
    for(float b=10.0;b<=15;b+=10.0)
    {
        for(float a=-20.0;a<=-10.0;a+=6.0)
        for(float a=-20.0;a<=-12.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
@@ -837,7 +843,7 @@ glBegin(GL_TRIANGLES);
    //jendela depan ketiga dari bawah
    for(float b=10.0;b<=15;b+=10.0)
    {
        for(float a=-20.0;a<=-10.0;a+=6.0)
        for(float a=-20.0;a<=-12.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
@@ -849,11 +855,11 @@ glBegin(GL_TRIANGLES);
        }
    }


    //jendela BRLAKANG
/*    for(float b=-10.0;b<=-6;b+=4.0)
//////////////////////////////////////////////////////////////////
    //jendela BRLAKANG paling bawah
    for(float b=-10.0;b<=-6;b+=4.0)
    {
        for(float a=-20.0;a<=48.0;a+=4.0)
        for(float a=-20.0;a<=5.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
@@ -863,7 +869,67 @@ glBegin(GL_TRIANGLES);
                glVertex3f(-18.0+a,-24.0-b,-16.1);
            glEnd();
        }
    }*/
    }

    //jendela BRLAKANG paling bawah
    for(float b=-10.0;b<=-6;b+=4.0)
    {
        for(float a=-20.0;a<=5.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(26.0+a,-24.0-b,-16.1);
                glVertex3f(26.0+a,-22.0-b,-16.1);
                glVertex3f(28.0+a,-22.0-b,-16.1);
                glVertex3f(28.0+a,-24.0-b,-16.1);
            glEnd();
        }
    }

     //jendela belakang kedua dari bawah
    for(float b=10.0;b<=15;b+=10.0)
    {
        for(float a=-20.0;a<=-2.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(27.0+a,3.0-b,-16.1);
                glVertex3f(27.0+a,1.0-b,-16.1);
                glVertex3f(29.0+a,1.0-b,-16.1);
                glVertex3f(29.0+a,3.0-b,-16.1);
            glEnd();
        }
    }

    //jendela belakang kedua dari bawah
    for(float b=10.0;b<=15;b+=10.0)
    {
        for(float a=-20.0;a<=-2.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(-11.0+a,3.0-b,-16.1);
                glVertex3f(-11.0+a,1.0-b,-16.1);
                glVertex3f(-13.0+a,1.0-b,-16.1);
                glVertex3f(-13.0+a,3.0-b,-16.1);
            glEnd();
        }
    }

    //jendela BELAKANG ketiga dari bawah
    for(float b=10.0;b<=15;b+=10.0)
    {
        for(float a=-20.0;a<32.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(-7.0+a,8.0-b,-12.1);
                glVertex3f(-7.0+a,6.0-b,-12.1);
                glVertex3f(-9.0+a,6.0-b,-12.1);
                glVertex3f(-9.0+a,8.0-b,-12.1);
            glEnd();
        }
    }
///////////////////////////////////////////////////////
//pintu belakang
    glBegin(GL_POLYGON);
@@ -962,6 +1028,42 @@ glBegin(GL_TRIANGLES);
    }

    /////////////////////////////////////////////////////
    //kolam
    glBegin(GL_POLYGON);
        glColor3f(0.0,1.0,1.0);
        glVertex3f(-12.0,-19.9,50.0);
        glVertex3f(10.0,-19.9,50.0);
        glVertex3f(10.0,-19.9,35.0);
        glVertex3f(-12.0,-19.9,35.0);
    glEnd();

    //kolam
    glBegin(GL_POLYGON);
        glColor3f(0.0,1.0,1.0);
        glVertex3f(-12.0,-19.9,50.0);
        glVertex3f(-7.0,-19.9,50.0);
        glVertex3f(-7.0,-19.9,30.0);
        glVertex3f(-12.0,-19.9,30.0);
    glEnd();

    //kolam
    glBegin(GL_POLYGON);
        glColor3f(0.0,1.0,1.0);
        glVertex3f(3.0,-19.9,50.0);
        glVertex3f(10.0,-19.9,50.0);
        glVertex3f(10.0,-19.9,30.0);
        glVertex3f(3.0,-19.9,30.0);
    glEnd();

    //jalanan lobi
    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-7.0,-19.9,35.0);
        glVertex3f(3.0,-19.9,35.0);
        glVertex3f(3.0,-19.9,20.0);
        glVertex3f(-7.0,-19.9,20.0);
    glEnd();
    //////////////////////////////////////////////////////

    glPopMatrix();
    glutSwapBuffers();

    ////////////////
    //lantai
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
    glColor3f(0.3f,0.3f,0.3f);
    kotak(0,0,18,25,0.5,0);
    glEnd();
    glPopMatrix();
    //dinding kiri
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glBegin(GL_QUADS);
        glColor3f(0.0f,0.0f,1.0f);
        kotak(0,0.5,18,0.5,10,0);
        glEnd();
        glPopMatrix();
        //dinding belakang
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glBegin(GL_QUADS);
        glColor3f(0.0f,0.0f,1.0f);
        kotak(0.5,0.5,0.5,25,10,0.0);
        glEnd();
        glPopMatrix();

    //meja
    //atas
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_QUADS);
    glColor3f(0.2f,0.1f,0.1f);
    kotak(21,3.5,16,24.8,3.8,9.5);
    //kaki kanan belakang
    kotak(24.3,0.5,15.9,24.6,3.6,15.6);
    //kaki kiri belakang
    kotak(24.3,0.5,9.9,24.6,3.6,9.6);
    //kaki kiri depan
    kotak(21.1,0.5,9.9,21.4,3.6,9.6);
    //kaki kanan depan
    kotak(21.1,0.5,15.9,21.4,3.6,15.6);
    glEnd();
    glPopMatrix();

    //kursi
        //alas
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_QUADS);
    glColor3f(0.2f,0.1f,0.1f);
    kotak(18,2.2,15.5,20.8,2.5,12.8);
    //kiri depan
    kotak(20.5,0.5,15.5,20.8,2.5,15.2);
    //kanan depan
    kotak(20.5,0.5,13.1,20.8,2.5,12.8);
    //kanan belakang
    kotak(18,0.5,13.1,18.3,5.2,12.8);
    //kiri belakang
    kotak(18,0.5,15.5,18.3,5.2,15.2);
    //senderan
    kotak(18,3.8,15.5,18.2,4.9,12.8);
    glEnd();
    glPopMatrix();

    //kasurnya
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[1]);
                glBegin(GL_QUADS);
                    glColor3f(1.1f,1.1f,1.1f);
                        kotak(1.1,2.5,15.4,13.4,3.5,9);
                        //bantal
                    glColor3f(0.6f,0.6f,0.6f);
                        kotak(1.3,3.5,14.4,4,4,10);
                        //selimut
                        glColor3f(0.1f,1.1f,0.1f);
                        kotak(5,3.5,15.4,13.4,3.7,9);
                        //kanan
                        kotak(5,3,9,13.4,3.6,8.9);
                        //kiri
            kotak(5,3,15.5,13.4,3.6,15.4);
                glEnd();
        glPopMatrix();

@@ -993,22 +1095,6 @@ void keyboard(unsigned char key, int a, int b)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0,0.0,3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0,0.0,0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0,0.0,-3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0,0.0,0.0);
        break;
    case '7':
        glTranslatef(0.0,3.0,0.0);//geser atas
        break;
    case '9':
        glTranslatef(0.0,-3.0,0.0);//geser bawah
        break;
    case '2':
        glRotatef(2.0,1.0,0.0,0.0);//rotate bawah
        break;
    case '8':
        glRotatef(-2.0,1.0,0.0,0.0);//rotate atas
        break;
    case '6':
        glRotatef(2.0,0.0,1.0,0.0);//rotate kanan x
        break;
    case '4':
        glRotatef(-2.0,0.0,1.0,0.0);//rotate kiri x
        break;
    case '1':
        glRotatef(2.0,0.0,0.0,1.0);//rotate kiri y
        break;
    case '3':
        glRotatef(-2.0,0.0,0.0,1.0);//rotate kanan y
        break;
    case '5':
        if(is_depth)
        {
            is_depth=0;
            glDisable(GL_DEPTH_TEST);
        }else
        {
            is_depth=1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();
}
void mousemotion(int x, int y)
{
    if(mousedown)
    {
        yrot=x-xdiff;
        xrot=y+ydiff;
        glutPostRedisplay();
    }
}
void ukuran(int lebar, int tinggi)
{
    if(tinggi==0) tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0,lebar/tinggi,5.0,500.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
