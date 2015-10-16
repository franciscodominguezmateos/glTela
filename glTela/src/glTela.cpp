//============================================================================
// Name        : glBotaPelota.cpp
// Author      : Francico Dominguez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <vector>
#include <utility>
#include <unistd.h>
#include <GL/glut.h>
#include "particula.h"
#include "fuerzaElastica.h"
#include "rozamientoViscoso.h"
#include "hilo.h"
#include "tela.h"

using namespace std;

GLint ancho=400;

GLint alto=400;
int hazPerspectiva = 1;
GLfloat angle = 0.0;
GLfloat yaw = 0.0;
GLfloat roll = 0.0;
GLfloat pitch = 0.0;

Vector3D gravedad(0.0,-0.98,0.0);
RozamientoViscoso rv;
Hilo h(20.0,1.0,0.0);
Tela t(40*1,30*1,-1,-1,1,1);

void displayMe(void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt (0.0, 1.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    GLfloat lightpos[] = {5.0, 15., 5., 0.};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
//    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(yaw  ,0.0,1.0,0.0);
    glRotatef(pitch,1.0,0.0,0.0);
    glRotatef(roll ,0.0,0.0,1.0);

    h.glRender();
    t.glRender();

    glPushMatrix();
     glColor3f(1.0f, 1.0f, 0.0f);
     glRotatef(angle*2,0.0,1.0,0.0);
     glTranslatef(0.8,0.5,0.0);
     glutSolidCube(0.35);
      glPushMatrix();
       glColor3f(1.0f, 0.0f, 0.0f);
       glRotatef(angle*2,0.0,1.0,0.0);
       glTranslatef(0.5,0.0,0.0);
       glutSolidSphere(0.1,20,20);
      glPopMatrix();
    glPopMatrix();
    glPushMatrix();
     glColor3f(0.0f, 1.0f, 1.0f);
     glTranslatef(-0.8,0.05,-0.8);
     glutSolidSphere(0.1,10,20);
    glPopMatrix();
    //glColor3f(0.0f, 1.0f, 0.0f);
    //glutSolidTeapot(0.5);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
    glEnd();
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-1.0, 0.0, -1.0);
        glVertex3f( 1.0, 0.0, -1.0);
        glVertex3f( 1.0, 0.0,  1.0);
        glVertex3f(-1.0, 0.0,  1.0);
    glEnd();
    //glFlush();
    glutSwapBuffers();
    angle++;
}

void init (void) {
    glEnable (GL_DEPTH_TEST);
    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor (0.0,0.0,0.0,0.0);
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, (GLfloat)width/(GLfloat)height, 1.0f, 200.0f);

    glMatrixMode(GL_MODELVIEW);
    ancho = width;
    alto = height;
}
void idle()
{
    displayMe();
    h.limpiaFuerza();
    h.acumulaFuerza(gravedad);
    for(Particula *p:h.getPuntos()){
    	Vector3D fr=rv.getFuerza(p);
    	p->acumulaFuerza(fr);
    }
    h.aplicaFuerza();
    t.limpiaFuerza();
    t.acumulaFuerza(gravedad);
    t.aplicaFuerza();
    usleep(1000000*Particula::dt);
}
void keyPressed (unsigned char key, int x, int y) {
	x++;
	y++;
	//printf("%c %d,",key,key);
    switch(key)
    {
    case 'p':
    case 'P':
      yaw++;
      break;

    case 'o':
    case 'O':
      yaw--;
      break;
    case 'q':
    case 'Q':
      pitch++;
      break;

    case 'a':
    case 'A':
      pitch--;
      break;
    case 'w':
    case 'W':
      roll++;
      break;

    case 's':
    case 'S':
      roll--;
      break;

    case 27:   // escape
      exit(0);
      break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    //glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(250, 250);
    glutCreateWindow("Teacup");
    init();
    glutDisplayFunc(displayMe);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses
    glutMainLoop();
    return 0;
}
