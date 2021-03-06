#include <windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>

#define RATIO 1.100 //mendefinisikan rasio dengan perbandingan 1:1.200
#define WW 100 //lebar viewport = 100
#define WH (WW/RATIO) // tinggi viewport
#define HALFX ((int)(WW/2)) //koordinat X min atau max
#define HALFY ((int)(WH/2)) //koordinat Y min atau max
#define deltat .001 //menambahkan nilai t
int lwindow; //lebar window (pixel)
int twindow; //tinggi window (pixel)
void init(void);
void display(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mousemotion(int x, int y);
void balok(void);
float xrot=0.0;
float yrot=0.0;
float xdiff=0.0;
float ydiff=0.0;
bool mousedown = false;
int x;
int is_depth;
int a=0;
GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;//to set the radius of the circle

void timer(int m)
{
//  setAngle(angle)
//  Display();
    glutPostRedisplay();
    glutTimerFunc(700,timer,10);
    glColor3f(1.0,1.0,1.0);
}

void reshape(int l, int t)
{
    glutReshapeWindow(l,(int)(l/RATIO));
    lwindow = l;
    twindow = (int)(l/RATIO);
    init();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,80);
    //inisialisasi lebar dan tinggi window pake rasio
    lwindow = (int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.4);
    twindow = (int)(lwindow/RATIO);

    //membuat window
    glutInitWindowSize(lwindow,twindow);
    glutInitWindowPosition((int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.1),
        (glutGet((GLenum)GLUT_SCREEN_HEIGHT)/2)-(twindow/2));
    glutCreateWindow("Emerald Place Kempinski Dubai");
    timer(0);
    init();
    glutDisplayFunc(display);
     glutReshapeFunc(reshape);
    glutReshapeFunc(ukuran);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
   // glutIdleFunc(display);////////
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(2.5);
    glLineWidth(2.0);
}




void ngon(int n, float cx, float cy, float radius, float rotAngle){
    double angle, angleInc;
    int k;

    if(n<3) return;
    angle=rotAngle*3.14159265/500;
    angleInc=2*3.14159265/n;

    //ini titik pertama
    glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);

    //ini titik berikutnya
    for(k=0;k<n;k++){
        angle+=angleInc;
        glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
    }
}
void display(void) //
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();/////////////
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//untuk mengatur penglihatan mata/penglihatan objek
    glRotatef(xrot, 1.0, 0.0, 0.0);
    glRotatef(yrot, 0.0, 1.0, 0.0);
    //Matahari dengan timer agar berubah warna ketika berputar

    glPushMatrix();
    float frametime = 4;
    glBegin(GL_POLYGON);
    glColor3f(a+=1.0,1.1, 1.0);
    ngon(500,0,30,5,0);
    glPushMatrix();
    glColor3f(a+=0.0,1.1, 1.0);
    glPopMatrix();
    glEnd();

////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////


    //Bagian tanah
    glBegin(GL_QUADS);
       glColor3f(37/255.0f,134/255.0f,22/255.0f);
        glVertex3f(-45.0,-20.0,55.0);
        glVertex3f(40.0,-20.0,55.0);
        glVertex3f(40.0,-20.0,-45.0);
        glVertex3f(-45.0,-20.0,-45.0);
    glEnd();
////////////////////////////////////////////////////////////////////
    //Bagian atap
    glBegin(GL_QUADS);
        glColor3f(229/255.0f,171/255.0f,71/255.0f);
        glVertex3f(-10.0,10.0,11.0);
        glVertex3f(5.0,10.0,11.0);
        glVertex3f(5.0,10.0,-5.0);
        glVertex3f(-10.0,10.0,-5.0);
    glEnd();

    //Bagian atap depan (utama)
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-10.0,10.0,11.0);
        glVertex3f(5.0,10.0,11.0);
        glVertex3f(5.0,5.0,11.0);
        glVertex3f(-10.0,5.0,11.0);
    glEnd();

    //Bagian atap belakang (utama)
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-10.0,10.0,-5.0);
        glVertex3f(5.0,10.0,-5.0);
        glVertex3f(5.0,5.0,-5.0);
        glVertex3f(-10.0,5.0,-5.0);
    glEnd();

    //Bagian atap kiri (utama)
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-10.0,10.0,11.0);
        glVertex3f(-10.0,5.0,11.0);
        glVertex3f(-10.0,5.0,-5.0);
        glVertex3f(-10.0,10.0,-5.0);
    glEnd();

    //Bagian atap kanan (utama)
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(5.0,10.0,11.0);
        glVertex3f(5.0,5.0,11.0);
        glVertex3f(5.0,5.0,-5.0);
        glVertex3f(5.0,10.0,-5.0);
    glEnd();

////////////////////////////////////////////////////////////////////////
    //Bagian atap kiri
    glBegin(GL_QUADS);
        glColor3f(229/255.0f,171/255.0f,71/255.0f);
        glScalef(0.5f, 0.5f, 1.0f);
        glVertex3f(-10.0,10.0,3.0);
        glVertex3f(-15.0,10.0,3.0);
        glVertex3f(-15.0,10.0,-3.0);
        glVertex3f(-10.0,10.0,-3.0);
    glEnd();

    //Bagian atap kiri (2)
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(10.0,5.0,-3.0);
        glVertex3f(10.0,10.0,-3.0);
        glVertex3f(-15.0,10.0,-3.0);
        glVertex3f(-15.0,5.0,-3.0);
    glEnd();

    //Bagian atap kiri (3)
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-15.0,5.0,3.0);//
        glVertex3f(-15.0,10.0,3.0);
        glVertex3f(-15.0,10.0,-3.0);
        glVertex3f(-15.0,5.0,-3.0);//
    glEnd();

    //Bagian atap kanan
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(10.0,10.0,3.0);
        glVertex3f(5.0,10.0,3.0);
        glVertex3f(5.0,10.0,-3.0);
        glVertex3f(10.0,10.0,-3.0);
    glEnd();

    //Bagian atap kanan (2)
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(10.0,5.0,3.0);
        glVertex3f(10.0,10.0,3.0);
        glVertex3f(10.0,10.0,-3.0);
        glVertex3f(10.0,5.0,-3.0);
    glEnd();

    //Bagian atap kanan (2)
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(10.0,5.0,3.0);
        glVertex3f(10.0,10.0,3.0);
        glVertex3f(-15.0,10.0,3.0);
        glVertex3f(-15.0,5.0,3.0);
    glEnd();
/////////////////////////////////////////////////////////////////////////
    //Bagian atap dekorasi depan 1
    for (x=0; x<4; x++){
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-10.0,15.0,9.0);
        glVertex3f(-7.0,15.0,9.0);
        glVertex3f(-7.0,15.0,6.0);
        glVertex3f(-10.0,15.0,6.0);
    glEnd();}

    //Bagian atap dekorasi belakang 1
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-10.0,15.0,-4.0);
        glVertex3f(-7.0,15.0,-4.0);
        glVertex3f(-7.0,15.0,-1.0);
        glVertex3f(-10.0,15.0,-1.0);
    glEnd();

    //Bagian atap dekorasi depan 2
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(5.0,15.0,9.0);
        glVertex3f(2.0,15.0,9.0);
        glVertex3f(2.0,15.0,6.0);
        glVertex3f(5.0,15.0,6.0);
    glEnd();

    //Bagian atap dekorasi belakang 2
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(5.0,15.0,-4.0);
        glVertex3f(2.0,15.0,-4.0);
        glVertex3f(2.0,15.0,-1.0);
        glVertex3f(5.0,15.0,-1.0);
    glEnd();
    ////////////////////////////////////////////////////////////////////////////
    // BAGIAN PILAR ATAS
    for (float a=-10.0; a<=10.0; a+=12.0)
        {
        for (float b=-10.0; b<=10.0; b+=210.0)
        {

    glBegin(GL_TRIANGLES);
        glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(1.5+a,10.0-b,-2.5);
        glVertex3f(0.0+a,5.0-b,-4.0);
        glVertex3f(0.0+a,5.0-b,-1.0);
    glEnd();

    glBegin(GL_TRIANGLES);
       glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(1.5+a,10.0-b,7.5);
        glVertex3f(0.0+a,5.0-b,9.0);
        glVertex3f(0.0+a,5.0-b,6.0);
    glEnd();

    //BAGIAN PILAR ATAS (2)
    glBegin(GL_TRIANGLES);
        glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(1.5+a,10.0-b,-2.5);
        glVertex3f(3.0+a,5.0-b,-4.0);
        glVertex3f(3.0+a,5.0-b,-1.0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(1.5+a,10.0-b,7.5);
        glVertex3f(3.0+a,5.0-b,9.0);
        glVertex3f(3.0+a,5.0-b,6.0);
    glEnd();

    //BAGIAN PILAR ATAS (3)
    glBegin(GL_TRIANGLES);
        glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(1.5+a,10.0-b,-2.5);
        glVertex3f(0.0+a,5.0-b,-1.0);
        glVertex3f(3.0+a,5.0-b,-1.0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(1.5+a,10.0-b,7.5);
        glVertex3f(3.0+a,5.0-b,9.0);
        glVertex3f(0.0+a,5.0-b,9.0);
    glEnd();


    //BAGIAN PILAR (4)
    glBegin(GL_TRIANGLES);
        glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(1.5+a,10.0-b,-2.5);
        glVertex3f(0.0+a,5.0-b,-4.0);
        glVertex3f(3.0+a,5.0-b,-4.0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(1.5+a,10.0-b,7.5);
        glVertex3f(3.0+a,5.0-b,6.0);
        glVertex3f(0.0+a,5.0-b,6.0);
    glEnd();

        }
    }
    /////////////////////////////////////////////////////////////////////////////

    //PILAR NO 2 dari atas
    // BAGIAN PILAR ATAS
    for (float a=-10.0; a<=30.0; a+=33.0)
        {
        for (float b=-10.0; b<=10.0; b+=210.0)
        {
                                                        //glColor3f(255/255.0f,135/255.0f,14/255.0f);
    glBegin(GL_TRIANGLES);
        glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(-9.5+a,0.0-b,-7.5);
        glVertex3f(-11.0+a,-5.0-b,-9.0);
        glVertex3f(-11.0+a,-5.0-b,-6.0);
    glEnd();

    glBegin(GL_TRIANGLES);
       glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(-9.5+a,0.0-b,12.5);
        glVertex3f(-11.0+a,-5.0-b,14.0);
        glVertex3f(-11.0+a,-5.0-b,11.0);
    glEnd();

    //BAGIAN PILAR ATAS (2)
glBegin(GL_TRIANGLES);
        glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(-9.5+a,0.0-b,-7.5);
        glVertex3f(-8.0+a,-5.0-b,-9.0);
        glVertex3f(-8.0+a,-5.0-b,-6.0);
    glEnd();

    glBegin(GL_TRIANGLES);
       glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(-9.5+a,0.0-b,12.5);
        glVertex3f(-8.0+a,-5.0-b,14.0);
        glVertex3f(-8.0+a,-5.0-b,11.0);
    glEnd();

   //BAGIAN PILAR ATAS (3)
    glBegin(GL_TRIANGLES);
        glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(-9.5+a,0.0-b,-7.5);
        glVertex3f(-8.0+a,-5.0-b,-9.0);
        glVertex3f(-11.0+a,-5.0-b,-9.0);
    glEnd();

    glBegin(GL_TRIANGLES);
       glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(-9.5+a,0.0-b,12.5);
        glVertex3f(-8.0+a,-5.0-b,11.0);
        glVertex3f(-11.0+a,-5.0-b,11.0);
    glEnd();


    //BAGIAN PILAR (4)
    glBegin(GL_TRIANGLES);
        glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(-9.5+a,0.0-b,-7.5);
        glVertex3f(-8.0+a,-5.0-b,-6.0);
        glVertex3f(-11.0+a,-5.0-b,-6.0);
    glEnd();

    glBegin(GL_TRIANGLES);
       glColor3f(255/255.0f,135/255.0f,14/255.0f);
        glVertex3f(-9.5+a,0.0-b,12.5);
        glVertex3f(-8.0+a,-5.0-b,14.0);
        glVertex3f(-11.0+a,-5.0-b,14.0);
    glEnd();


        }
    }
///////////////////////////////////////////////////////////////////////////////////
    //bagian pilar atas
    for(int b=-10.0;b<=10;b+=25.0)
    {
        for(int a=-20.0;a<=-2.0;a+=12.0)
        {

            glBegin(GL_POLYGON);
                glColor3f(216/255.0f,206/255.0f,64/255.0f);
                glVertex3f(10.0+a,5.0-b,-4.0);
                glVertex3f(10.0+a,0.0-b,-4.0);
                glVertex3f(13.0+a,0.0-b,-4.0);
                glVertex3f(13.0+a,5.0-b,-4.0);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(216/255.0f,206/255.0f,64/255.0f);
                glVertex3f(10.0+a,5.0-b,-1.0);
                glVertex3f(10.0+a,0.0-b,-1.0);
                glVertex3f(13.0+a,0.0-b,-1.0);
                glVertex3f(13.0+a,5.0-b,-1.0);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(216/255.0f,206/255.0f,64/255.0f);
                glVertex3f(10.0+a,5.0-b,6.0);
                glVertex3f(10.0+a,0.0-b,6.0);
                glVertex3f(13.0+a,0.0-b,6.0);
                glVertex3f(13.0+a,5.0-b,6.0);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(216/255.0f,206/255.0f,64/255.0f);
                glVertex3f(10.0+a,5.0-b,9.0);
                glVertex3f(10.0+a,0.0-b,9.0);
                glVertex3f(13.0+a,0.0-b,9.0);
                glVertex3f(13.0+a,5.0-b,9.0);
            glEnd();


        }
    }

    //bagian pilar atas (2)
    for(int b=-10.0;b<=10;b+=25.0)
    {
        for(int a=-20.0;a<=-2.0;a+=12.0)
        {

            glBegin(GL_POLYGON);
                glColor3f(216/255.0f,206/255.0f,64/255.0f);
                glVertex3f(13.0+a,5.0-b,9.0);
                glVertex3f(13.0+a,0.0-b,9.0);
                glVertex3f(13.0+a,0.0-b,6.0);
                glVertex3f(13.0+a,5.0-b,6.0);
            glEnd();

            glBegin(GL_POLYGON);
               glColor3f(216/255.0f,206/255.0f,64/255.0f);
                glVertex3f(13.0+a,5.0-b,-1.0);
                glVertex3f(13.0+a,0.0-b,-1.0);
                glVertex3f(13.0+a,0.0-b,-4.0);
                glVertex3f(13.0+a,5.0-b,-4.0);
            glEnd();

            glBegin(GL_POLYGON);
              glColor3f(216/255.0f,206/255.0f,64/255.0f);
                glVertex3f(10.0+a,5.0-b,6.0);
                glVertex3f(10.0+a,0.0-b,6.0);
                glVertex3f(10.0+a,0.0-b,9.0);
                glVertex3f(10.0+a,5.0-b,9.0);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(216/255.0f,206/255.0f,64/255.0f);
                glVertex3f(10.0+a,5.0-b,-1.0);
                glVertex3f(10.0+a,0.0-b,-1.0);
                glVertex3f(10.0+a,0.0-b,-4.0);
                glVertex3f(10.0+a,5.0-b,-4.0);
            glEnd();


        }
    }
//////////////////////////////////////////////////////////
     //bagian pilar atas
    for(int b=-10.0;b<=10;b+=25.0)
    {
        for(int a=-20.0;a<=-2.0;a+=12.0)
        {

            glBegin(GL_POLYGON);
                glColor3f(1.0,1.0,1.0);
                glVertex3f(10.0+a,5.0-b,-4.0);
                glVertex3f(10.0+a,0.0-b,-4.0);
                glVertex3f(13.0+a,0.0-b,-4.0);
                glVertex3f(13.0+a,5.0-b,-4.0);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(1.0,1.0,1.0);
                glVertex3f(10.0+a,5.0-b,-1.0);
                glVertex3f(10.0+a,0.0-b,-1.0);
                glVertex3f(13.0+a,0.0-b,-1.0);
                glVertex3f(13.0+a,5.0-b,-1.0);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(1.0,1.0,1.0);
                glVertex3f(10.0+a,5.0-b,6.0);
                glVertex3f(10.0+a,0.0-b,6.0);
                glVertex3f(13.0+a,0.0-b,6.0);
                glVertex3f(13.0+a,5.0-b,6.0);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(1.0,1.0,1.0);
                glVertex3f(10.0+a,5.0-b,9.0);
                glVertex3f(10.0+a,0.0-b,9.0);
                glVertex3f(13.0+a,0.0-b,9.0);
                glVertex3f(13.0+a,5.0-b,9.0);
            glEnd();


        }
    }


////////////////////////////////////////////////////////////////////
    //Bagian paling Atas hotel sebelum atap
    glBegin(GL_QUADS);
        glColor3f(229/255.0f,171/255.0f,71/255.0f);
        glVertex3f(-21.0,5.0,14.0);
        glVertex3f(16.0,5.0,14.0);
        glVertex3f(16.0,5.0,-10.0);
        glVertex3f(-21.0,5.0,-10.0);
    glEnd();

    //Bagian paling Atas hotel belakang sebelum atao
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-21.0,0.0,-10.0);
        glVertex3f(16.0,0.0,-10.0);
        glVertex3f(16.0,5.0,-10.0);
        glVertex3f(-21.0,5.0,-10.0);
    glEnd();

    //Bagian paling Atas hotel depan sebelum atap
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-21.0,0.0,14.0);
        glVertex3f(16.0,0.0,14.0);
        glVertex3f(16.0,5.0,14.0);
        glVertex3f(-21.0,5.0,14.0);
    glEnd();

    //Bagian Atas hotel kiri sebelum atap
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-21.0,5.0,14.0);
        glVertex3f(-21.0,0.0,14.0);
        glVertex3f(-21.0,0.0,-10.0);
        glVertex3f(-21.0,5.0,-10.0);
    glEnd();

    //Bagian Atas hotel kanan sebelum atap
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(16.0,0.0,14.0);
        glVertex3f(16.0,5.0,14.0);
        glVertex3f(16.0,5.0,-10.0);
        glVertex3f(16.0,0.0,-10.0);
    glEnd();
///////////////////////////////////////////////////////////////////////////////////
    //Bagian kedua Atas hotel
    glBegin(GL_QUADS);
        glColor3f(229/255.0f,171/255.0f,71/255.0f);
        glVertex3f(-30.0,0.0,14.0);
        glVertex3f(25.0,0.0,14.0);
        glVertex3f(25.0,0.0,-12.0);
        glVertex3f(-30.0,0.0,-12.0);
    glEnd();

    //Bagian kedua Atas hotel Depan
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-30.0,-5.0,14.0);
        glVertex3f(25.0,-5.0,14.0);
        glVertex3f(25.0,0.0,14.0);
        glVertex3f(-30.0,0.0,14.0);
    glEnd();

    //Bagian kedua Atas hotel belakang
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-30.0,-5.0,-12.0);
        glVertex3f(25.0,-5.0,-12.0);
        glVertex3f(25.0,0.0,-12.0);
        glVertex3f(-30.0,0.0,-12.0);
    glEnd();

    //Bagian kedua Atas hotel kiri
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-30.0,0.0,14.0);
        glVertex3f(-30.0,-5.0,14.0);
        glVertex3f(-30.0,-5.0,-12.0);
        glVertex3f(-30.0,0.0,-12.0);
    glEnd();

    //Bagian kedua Atas hotel kanan
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(25.0,0.0,14.0);
        glVertex3f(25.0,-5.0,14.0);
        glVertex3f(25.0,-5.0,-12.0);
        glVertex3f(25.0,0.0,-12.0);
    glEnd();

//////////////////////////////////////////////////////////////////

    //Bagian ketiga Atas hotel
    glBegin(GL_QUADS);
       glColor3f(229/255.0f,171/255.0f,71/255.0f);
        glVertex3f(-35.0,-5.0,14.0);
        glVertex3f(30.0,-5.0,14.0);
        glVertex3f(30.0,-5.0,-14.0);
        glVertex3f(-35.0,-5.0,-14.0);
    glEnd();

    //Bagian ketiga Atas hotel Depan
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-35.0,-5.0,14.0);
        glVertex3f(30.0,-5.0,14.0);
        glVertex3f(30.0,-10.0,14.0);
        glVertex3f(-35.0,-10.0,14.0);
    glEnd();

    //bagian ketiga atas hotel belakang
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-35.0,-5.0,-14.0);
        glVertex3f(30.0,-5.0,-14.0);
        glVertex3f(30.0,-10.0,-14.0);
        glVertex3f(-35.0,-10.0,-14.0);
    glEnd();

    //Bagian ketiga Atas hotel kiri
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-35.0,-5.0,14.0);
        glVertex3f(-35.0,-10.0,14.0);
        glVertex3f(-35.0,-10.0,-14.0);
        glVertex3f(-35.0,-5.0,-14.0);
    glEnd();

    //Bagian ketiga Atas hotel kanan
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(30.0,-5.0,14.0);
        glVertex3f(30.0,-10.0,14.0);
        glVertex3f(30.0,-10.0,-14.0);
        glVertex3f(30.0,-5.0,-14.0);
    glEnd();


////////////////////////////////////////////////////////////////////
    //Bagian keempat Atas hotel
    glBegin(GL_QUADS);
        glColor3f(229/255.0f,171/255.0f,71/255.0f);
        glVertex3f(-40.0,-10.0,14.0);
        glVertex3f(35.0,-10.0,14.0);
        glVertex3f(35.0,-10.0,-16.0);
        glVertex3f(-40.0,-10.0,-16.0);
    glEnd();

    //Bagian keempat Atas hotel Depan
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-40.0,-10.0,14.0);
        glVertex3f(35.0,-10.0,14.0);
        glVertex3f(35.0,-20.0,14.0);
        glVertex3f(-40.0,-20.0,14.0);
    glEnd();

    //Bagian keempat Atas hotel belakang
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-40.0,-10.0,-16.0);
        glVertex3f(35.0,-10.0,-16.0);
        glVertex3f(35.0,-20.0,-16.0);
        glVertex3f(-40.0,-20.0,-16.0);
    glEnd();

    //Bagian keempat Atas hotel kiri
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-40.0,-10.0,14.0);
        glVertex3f(-40.0,-20.0,14.0);
        glVertex3f(-40.0,-20.0,-16.0);
        glVertex3f(-40.0,-10.0,-16.0);
    glEnd();

    //Bagian keempat Atas hotel kanan
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(35.0,-10.0,14.0);
        glVertex3f(35.0,-20.0,14.0);
        glVertex3f(35.0,-20.0,-16.0);
        glVertex3f(35.0,-10.0,-16.0);
    glEnd();
//////////////////////////////////////////////////////////////////////
//Bagian tampilan depan
    glBegin(GL_QUADS);
        glColor3f(204/255.0f,102/255.0f,44/255.0f);
        glVertex3f(-10.0,5.0,20.0);
        glVertex3f(5.0,5.0,20.0);
        glVertex3f(5.0,-20.0,20.0);
        glVertex3f(-10.0,-20.0,20.0);
    glEnd();

    //Bagian tampilan atas
    glBegin(GL_QUADS);
        glColor3f(255/255.0f,122/255.0f,44/255.0f);
        glVertex3f(-10.0,5.0,20.0);
        glVertex3f(5.0,5.0,20.0);
        glVertex3f(5.0,5.0,14.0);
        glVertex3f(-10.0,5.0,14.0);
    glEnd();

    //Bagian tampilan kiri
    glBegin(GL_QUADS);
        glColor3f(255/255.0f,122/255.0f,44/255.0f);
        glVertex3f(-10.0,5.0,20.0);
        glVertex3f(-10.0,-20.0,20.0);
        glVertex3f(-10.0,-20.0,14.0);
        glVertex3f(-10.0,5.0,14.0);
    glEnd();

    //Bagian tampilan kkanan
    glBegin(GL_QUADS);
        glColor3f(255/255.0f,122/255.0f,44/255.0f);
        glVertex3f(5.0,5.0,20.0);
        glVertex3f(5.0,-20.0,20.0);
        glVertex3f(5.0,-20.0,14.0);
        glVertex3f(5.0,5.0,14.0);
    glEnd();
/////////////////////////////////////////////////////////////


    //pintu
    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-4.0,-20.0,20.1);
        glVertex3f(-1.0,-20.0,20.1);
        glVertex3f(-1.0,-14.0,20.1);
        glVertex3f(-4.0,-14.0,20.1);
    glEnd();
    ///////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
//jendela depan
    for(float b=-10.0;b<=5;b+=4.0)
    {
        for(float a=-20.0;a<=-10.0;a+=5.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(12.0+a,-9.0-b,20.1);
                glVertex3f(12.0+a,-7.0-b,20.1);
                glVertex3f(14.0+a,-7.0-b,20.1);
                glVertex3f(14.0+a,-9.0-b,20.1);
            glEnd();
        }
    }

    //jendela depan bagian paling bawah
    for(float b=10.0;b<=15;b+=4.0)
    {
        for(float a=-20.0;a<=6.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(-16.0+a,-4.0-b,14.1);
                glVertex3f(-16.0+a,-2.0-b,14.1);
                glVertex3f(-18.0+a,-2.0-b,14.1);
                glVertex3f(-18.0+a,-4.0-b,14.1);
            glEnd();
        }
    }

    //jendela depan bagian paling bawah
    for(float b=10.0;b<=15;b+=4.0)
    {
        for(float a=-20.0;a<=6.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
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
        for(float a=-20.0;a<=3.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(27.0+a,3.0-b,14.1);
                glVertex3f(27.0+a,1.0-b,14.1);
                glVertex3f(29.0+a,1.0-b,14.1);
                glVertex3f(29.0+a,3.0-b,14.1);
            glEnd();
        }
    }

    //jendela depan kedua dari bawah
    for(float b=10.0;b<=15;b+=10.0)
    {
        for(float a=-20.0;a<=3.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
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
        for(float a=-20.0;a<=-3.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
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
        for(float a=-20.0;a<=-3.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(29.0+a,8.0-b,14.1);
                glVertex3f(29.0+a,6.0-b,14.1);
                glVertex3f(27.0+a,6.0-b,14.1);
                glVertex3f(27.0+a,8.0-b,14.1);
            glEnd();
        }
    }

    //jendela depan ketiga dari bawah
    for(float b=10.0;b<=15;b+=10.0)
    {
        for(float a=-20.0;a<=-12.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(29.0+a,13.0-b,14.1);
                glVertex3f(29.0+a,11.0-b,14.1);
                glVertex3f(27.0+a,11.0-b,14.1);
                glVertex3f(27.0+a,13.0-b,14.1);
            glEnd();
        }
    }

    //jendela depan ketiga dari bawah
    for(float b=10.0;b<=15;b+=10.0)
    {
        for(float a=-20.0;a<=-12.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(2.0+a,13.0-b,14.1);
                glVertex3f(2.0+a,11.0-b,14.1);
                glVertex3f(0.0+a,11.0-b,14.1);
                glVertex3f(0.0+a,13.0-b,14.1);
            glEnd();
        }
    }

//////////////////////////////////////////////////////////////////
    //jendela BRLAKANG paling bawah
    for(float b=-10.0;b<=-6;b+=4.0)
    {
        for(float a=-20.0;a<=5.0;a+=3.0)
        {
            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(-16.0+a,-24.0-b,-16.1);
                glVertex3f(-16.0+a,-22.0-b,-16.1);
                glVertex3f(-18.0+a,-22.0-b,-16.1);
                glVertex3f(-18.0+a,-24.0-b,-16.1);
            glEnd();
        }
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
                glVertex3f(27.0+a,3.0-b,-14.1);
                glVertex3f(27.0+a,1.0-b,-14.1);
                glVertex3f(29.0+a,1.0-b,-14.1);
                glVertex3f(29.0+a,3.0-b,-14.1);
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
                glVertex3f(-11.0+a,3.0-b,-14.1);
                glVertex3f(-11.0+a,1.0-b,-14.1);
                glVertex3f(-13.0+a,1.0-b,-14.1);
                glVertex3f(-13.0+a,3.0-b,-14.1);
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
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0.0,-13.0,-16.1);
    glVertex3f(0.0,-20.0,-16.1);
    glVertex3f(-5.0,-20.0,-16.1);
    glVertex3f(-5.0,-13.0,-16.1);
    glEnd();
//////////////////////////////////////////////////////

    //kanopi belakang
    glBegin(GL_POLYGON);
    glColor3f(195/255.0f,102/255.0f,31/255.0f);
    glVertex3f(5.0,-10.0,-16.1);
    glVertex3f(5.0,-10.0,-26.1);
    glVertex3f(-10.0,-10.0,-26.1);
    glVertex3f(-10.0,-10.0,-16.1);
    glEnd();

    //kanopi belakang atas
    glBegin(GL_POLYGON);
    glColor3f(195/255.0f,102/255.0f,31/255.0f);
    glVertex3f(5.0,-8.0,-14.1);
    glVertex3f(5.0,-8.0,-24.1);
    glVertex3f(-10.0,-8.0,-24.1);
    glVertex3f(-10.0,-8.0,-14.1);
    glEnd();

    //kanopi belakang kiri
    glBegin(GL_POLYGON);
    glColor3f(195/255.0f,102/255.0f,31/255.0f);
    glVertex3f(-10.0,-8.0,-14.1);
    glVertex3f(-10.0,-8.0,-26.1);
    glVertex3f(-10.0,-10.0,-26.1);
    glVertex3f(-10.0,-10.0,-14.1);
    glEnd();

    //kanopi belakang kanan
    glBegin(GL_POLYGON);
    glColor3f(195/255.0f,102/255.0f,31/255.0f);
    glVertex3f(5.0,-8.0,-14.1);
    glVertex3f(5.0,-8.0,-26.1);
    glVertex3f(5.0,-10.0,-26.1);
    glVertex3f(5.0,-10.0,-14.1);
    glEnd();

     //kanopi belakang ke belakang
    glBegin(GL_POLYGON);
    glColor3f(195/255.0f,102/255.0f,31/255.0f);
    glVertex3f(-10.0,-8.0,-26.1);
    glVertex3f(5.0,-8.0,-26.1);
    glVertex3f(5.0,-10.0,-26.1);
    glVertex3f(-10.0,-10.0,-26.1);
    glEnd();
/////////////////////////////////////////////////
    //Bagian pilar di pintu belakang
    for(float b=-10.0;b<=-7;b+=14.0)
    {
        for(float a=-20.0;a<=-6.0;a+=13.0)
        {


            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(10.0+a,-29.0-b,-24.1);
                glVertex3f(10.0+a,-20.0-b,-24.1);
                glVertex3f(12.0+a,-20.0-b,-24.1);
                glVertex3f(12.0+a,-29.0-b,-24.1);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(10.0+a,-29.0-b,-22.1);
                glVertex3f(10.0+a,-20.0-b,-22.1);
                glVertex3f(10.0+a,-20.0-b,-24.1);
                glVertex3f(10.0+a,-29.0-b,-24.1);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(12.0+a,-29.0-b,-22.1);
                glVertex3f(12.0+a,-20.0-b,-22.1);
                glVertex3f(12.0+a,-20.0-b,-24.1);
                glVertex3f(12.0+a,-29.0-b,-24.1);
            glEnd();

             glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(10.0+a,-29.0-b,-22.1);
                glVertex3f(10.0+a,-20.0-b,-22.1);
                glVertex3f(12.0+a,-20.0-b,-22.1);
                glVertex3f(12.0+a,-29.0-b,-22.1);
            glEnd();
        }
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

    //kolam grs
     glBegin(GL_LINE_STRIP);
        glColor3f(1.0,1.0,102/255.0f);
        glVertex3f(-7.0,-19.9,50.0);
        glVertex3f(-12.0,-19.9,50.0);
        glVertex3f(-12.0,-19.9,30.0);
        glVertex3f(-7.0,-19.9,30.0);
    glEnd();

    //kolam
    glBegin(GL_POLYGON);
        glColor3f(0.0,1.0,1.0);
        glVertex3f(3.0,-19.9,50.0);
        glVertex3f(10.0,-19.9,50.0);
        glVertex3f(10.0,-19.9,30.0);
        glVertex3f(3.0,-19.9,30.0);
    glEnd();

    //kolam grs
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0,1.0,102/255.0f);
        glVertex3f(3.0,-19.9,50.0);
        glVertex3f(10.0,-19.9,50.0);
        glVertex3f(10.0,-19.9,30.0);
        glVertex3f(3.0,-19.9,30.0);
    glEnd();

    //jalanan lobi
    glBegin(GL_POLYGON);
        glColor3f(102/255.0f,51/255.0f,0.0);
        glVertex3f(-7.0,-19.9,35.0);
        glVertex3f(3.0,-19.9,35.0);
        glVertex3f(3.0,-19.9,20.0);
        glVertex3f(-7.0,-19.9,20.0);
    glEnd();
    //////////////////////////////////////////////////////
    //keramik
    for(float b=-10.0;b<=-6;b+=5.0)
    {
        for(float a=-20.0;a<=52.0;a+=2.5)
        {
            for(float c=-20.0; c<=8; c+=2.5){
            glBegin(GL_POLYGON);
                glColor3f(155/255.0f,81/255.0f,6/255.0f);
                glVertex3f(-17.0+a,-30.0-b,6.1+c);
                glVertex3f(-17.0+a,-30.0-b,4.1+c);
                glVertex3f(-19.0+a,-30.0-b,4.1+c);
                glVertex3f(-19.0+a,-30.0-b,6.1+c);
            glEnd();
            }
        }
    }
    ///////////////////////////////////////////////////////////
    //KARPET
    glBegin(GL_POLYGON);
        glColor3f(122/255.0f,211/255.0f,155/255.0f);
        glVertex3f(-5.0,-20.0,7.1);
        glVertex3f(-5.0,-20.0,-11.1);
        glVertex3f(-35.0,-20.0,-11.1);
        glVertex3f(-35.0,-20.0,7.1);
    glEnd();

        //KARPET arah kanan
        glBegin(GL_POLYGON);
            glColor3f(122/255.0f,211/255.0f,155/255.0f);
            glVertex3f(5.0,-20.0,7.1);
            glVertex3f(5.0,-20.0,-11.1);
            glVertex3f(30.0,-20.0,-11.1);
            glVertex3f(30.0,-20.0,7.1);
        glEnd();
    /////////////////////////////////////////////////////////////////////

    //sofa (1)
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(10.0,-20.0,-14.1);
        glVertex3f(10.0,-20.0,-11.1);
        glVertex3f(30.0,-20.0,-11.1);
        glVertex3f(30.0,-20.0,-14.1);
    glEnd();

     //sofa (1)blkng
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(10.0,-16.0,-14.1);
        glVertex3f(10.0,-20.0,-14.1);
        glVertex3f(30.0,-20.0,-14.1);
        glVertex3f(30.0,-16.0,-14.1);
    glEnd();

    //sofa (1)atas
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(10.0,-16.0,-14.1);
        glVertex3f(10.0,-16.0,-13.1);
        glVertex3f(30.0,-16.0,-13.1);
        glVertex3f(30.0,-16.0,-14.1);
    glEnd();

    //sofa (1)dpn
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(10.0,-18.0,-13.1);
        glVertex3f(10.0,-16.0,-13.1);
        glVertex3f(30.0,-16.0,-13.1);
        glVertex3f(30.0,-18.0,-13.1);
    glEnd();

    //sofa (1)maju
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(10.0,-18.0,-13.1);
        glVertex3f(10.0,-18.0,-11.1);
        glVertex3f(30.0,-18.0,-11.1);
        glVertex3f(30.0,-18.0,-13.1);
    glEnd();

    //sofa (1)turun
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(10.0,-18.0,-11.1);
        glVertex3f(10.0,-20.0,-11.1);
        glVertex3f(30.0,-20.0,-11.1);
        glVertex3f(30.0,-18.0,-11.1);
    glEnd();

    //sofa (1)kanan
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(30.0,-18.0,-14.1);
        glVertex3f(30.0,-20.0,-14.1);
        glVertex3f(30.0,-20.0,-11.1);
        glVertex3f(30.0,-18.0,-11.1);
    glEnd();

    //sofa (1) kiri
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(10.0,-18.0,-14.1);
        glVertex3f(10.0,-20.0,-14.1);
        glVertex3f(10.0,-20.0,-11.1);
        glVertex3f(10.0,-18.0,-11.1);
    glEnd();

    //sofa (1)kanan
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(30.0,-16.0,-14.1);
        glVertex3f(30.0,-20.0,-14.1);
        glVertex3f(30.0,-20.0,-13.1);
        glVertex3f(30.0,-16.0,-13.1);
    glEnd();

    //sofa (1) kiri
        glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(10.0,-16.0,-14.1);
        glVertex3f(10.0,-20.0,-14.1);
        glVertex3f(10.0,-20.0,-13.1);
        glVertex3f(10.0,-16.0,-13.1);
    glEnd();

    //lampu
        glBegin(GL_POLYGON);
        glColor3f(51/255.0f,35/255.0f,0.0);
        glVertex3f(2.0,-16.0,-13.1);
        glVertex3f(2.0,-20.0,-13.1);
        glVertex3f(1.0,-20.0,-13.1);
        glVertex3f(1.0,-16.0,-13.1);
    glEnd();

    //lampu dpn
        glBegin(GL_POLYGON);
        glColor3f(51/255.0f,35/255.0f,0.0);
        glVertex3f(2.0,-16.0,-12.1);
        glVertex3f(2.0,-20.0,-12.1);
        glVertex3f(1.0,-20.0,-12.1);
        glVertex3f(1.0,-16.0,-12.1);
    glEnd();

    //lampu kanan
        glBegin(GL_POLYGON);
        glColor3f(51/255.0f,35/255.0f,0.0);
        glVertex3f(2.0,-16.0,-12.1);
        glVertex3f(2.0,-20.0,-12.1);
        glVertex3f(2.0,-20.0,-13.1);
        glVertex3f(2.0,-16.0,-13.1);
    glEnd();

    //lampu kiri
        glBegin(GL_POLYGON);
        glColor3f(51/255.0f,35/255.0f,0.0);
        glVertex3f(1.0,-16.0,-12.1);
        glVertex3f(1.0,-20.0,-12.1);
        glVertex3f(1.0,-20.0,-13.1);
        glVertex3f(1.0,-16.0,-13.1);
    glEnd();

    //lampu atas
    glBegin(GL_POLYGON);
        glColor3f(255/255.0f,255/255.0f,51/255.0f);
        glVertex3f(1.0,-16.0,-12.1);
        glVertex3f(2.0,-16.0,-12.1);
        glVertex3f(2.0,-16.0,-13.1);
        glVertex3f(1.0,-16.0,-13.1);
    glEnd();

    //lampu atas
    glBegin(GL_POLYGON);
        glColor3f(255/255.0f,255/255.0f,51/255.0f);
        glVertex3f(1.0,-14.0,-12.1);
        glVertex3f(2.0,-14.0,-12.1);
        glVertex3f(2.0,-14.0,-13.1);
        glVertex3f(1.0,-14.0,-13.1);
    glEnd();

     //lampu atas dpn
    glBegin(GL_POLYGON);
        glColor3f(255/255.0f,255/255.0f,51/255.0f);
        glVertex3f(1.0,-16.0,-12.1);
        glVertex3f(2.0,-16.0,-12.1);
        glVertex3f(2.0,-14.0,-12.1);
        glVertex3f(1.0,-14.0,-12.1);
    glEnd();

    // lampu dpn blkng
    glBegin(GL_POLYGON);
        glColor3f(255/255.0f,255/255.0f,51/255.0f);
        glVertex3f(1.0,-16.0,-13.1);
        glVertex3f(2.0,-16.0,-13.1);
        glVertex3f(2.0,-14.0,-13.1);
        glVertex3f(1.0,-14.0,-13.1);
    glEnd();

    //lampu atas dpn
    glBegin(GL_POLYGON);
        glColor3f(255/255.0f,255/255.0f,51/255.0f);
        glVertex3f(2.0,-16.0,-13.1);
        glVertex3f(2.0,-16.0,-12.1);
        glVertex3f(2.0,-14.0,-12.1);
        glVertex3f(2.0,-14.0,-13.1);
    glEnd();

    //lampu atas dpn
    glBegin(GL_POLYGON);
        glColor3f(255/255.0f,255/255.0f,51/255.0f);
        glVertex3f(1.0,-16.0,-13.1);
        glVertex3f(1.0,-16.0,-12.1);
        glVertex3f(1.0,-14.0,-12.1);
        glVertex3f(1.0,-14.0,-13.1);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(10.0,-18.0,-13.1);
        glVertex3f(30.0,-18.0,-13.1);
        glEnd();
    ////////////////////////////////////////////////////////////////////

    //oembuatan meja
    glBegin(GL_POLYGON);
        glColor3f(122/255.0f,211/255.0f,155/255.0f);
        glVertex3f(-33.0,-20.0,14.1);
        glVertex3f(-33.0,-20.0,-16.1);
        glVertex3f(-40.0,-20.0,-16.1);
        glVertex3f(-40.0,-20.0,14.1);
    glEnd();

    //oembuatan meja resepsionis \atas
    glBegin(GL_POLYGON);
        glColor3f(51/255.0f,25/255.0f,0/255.0f);
        glVertex3f(-35.0,-17.0,14.1);
        glVertex3f(-35.0,-17.0,-16.1);
        glVertex3f(-33.0,-17.0,-16.1);
        glVertex3f(-33.0,-17.0,14.1);
    glEnd();

    //oembuatan meja resepisionis \depan
    glBegin(GL_POLYGON);
        glColor3f(51/255.0f,25/255.0f,0/255.0f);
        glVertex3f(-33.0,-20.0,14.1);
        glVertex3f(-33.0,-20.0,-16.1);
        glVertex3f(-33.0,-17.0,-16.1);
        glVertex3f(-33.0,-17.0,14.1);
    glEnd();

    //oembuatan meja resepisionis \blkg
    glBegin(GL_POLYGON);
        glColor3f(51/255.0f,25/255.0f,0/255.0f);
        glVertex3f(-35.0,-20.0,14.1);
        glVertex3f(-35.0,-20.0,-16.1);
        glVertex3f(-35.0,-17.0,-16.1);
        glVertex3f(-35.0,-17.0,14.1);
    glEnd();

    //oembuatan meja resepisionis \kanan
    glBegin(GL_POLYGON);
        glColor3f(51/255.0f,25/255.0f,0/255.0f);
        glVertex3f(-35.0,-20.0,13.9);
        glVertex3f(-33.0,-20.0,13.9);
        glVertex3f(-33.0,-17.0,13.9);
        glVertex3f(-35.0,-17.0,13.9);
    glEnd();

    //oembuatan meja resepisionis \kiri
    glBegin(GL_POLYGON);
        glColor3f(51/255.0f,25/255.0f,0/255.0f);
        glVertex3f(-35.0,-20.0,-15.9);
        glVertex3f(-33.0,-20.0,-15.9);
        glVertex3f(-33.0,-17.0,-15.9);
        glVertex3f(-35.0,-17.0,-15.9);
    glEnd();

    ////////////////////////////////////////////

    //AC depan
    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-30.0,-5.0,14.1);
        glVertex3f(-30.0,-5.0,-14.1);
        glVertex3f(-30.0,-7.0,-14.1);
        glVertex3f(-30.0,-7.0,14.1);
    glEnd();

    //AC blkng
    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-34.9,-4.9,14.1);
        glVertex3f(-34.9,-4.9,-14.1);
        glVertex3f(-34.9,-7.0,-14.1);
        glVertex3f(-34.9,-7.0,14.1);
    glEnd();

    //AC bawah
     glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-35.0,-7.0,14.1);
        glVertex3f(-35.0,-7.0,-14.1);
        glVertex3f(-30.0,-7.0,-14.1);
        glVertex3f(-30.0,-7.0,14.1);
    glEnd();

    //AC  atas
     glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-35.0,-5.1,14.1);
        glVertex3f(-35.0,-5.1,-14.1);
        glVertex3f(-30.0,-5.1,-14.1);
        glVertex3f(-30.0,-5.1,14.1);
    glEnd();

    //AC depan
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-29.5,-6.0,14.1);
        glVertex3f(-29.5,-6.0,-14.1);
        glVertex3f(-29.5,-7.0,-14.1);
        glVertex3f(-29.5,-7.0,14.1);
    glEnd();
    ////////////////////////////////////////////////////////


    /////////////////////////////////////////////////////////

    glPopMatrix();
    glutSwapBuffers();
}

void idle()
{
    if(!mousedown)
    {
        xrot+=0.3;
        yrot+=0.4;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        mousedown=true;
        xdiff=x-yrot;
        ydiff=-y+xrot;
    }
    else
    mousedown=false;
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0,0.0,12.0); //KEDEPAN
        break;
    case 'd':
    case 'D':
        glTranslatef(-3.0,0.0,3.0);//KEKANAN
        break;
    case 's':
    case 'S':
        glTranslatef(0.0,0.0,-3.0);//MUNDUR
        break;
    case 'a':
    case 'A':
        glTranslatef(3.0,0.0,3.0);//KEKIRI
        break;
    case'q':
        glTranslatef(0.0,-3.0,3.0);//KEATAS
        break;
    case'e':
        glTranslatef(0.0,3.0,3.0);//KEBAWAH
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
    //glLoadIdentity();///////////////////////////////
    gluPerspective(50.0,lebar/tinggi,5.0,500.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
