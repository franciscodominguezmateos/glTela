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
#include "depthImage.h"

using namespace std;

GLint ancho=400;

GLint alto=400;
int hazPerspectiva = 1;
GLfloat angle = 0.0;
GLfloat yaw = 0.0;
GLfloat roll = 0.0;
GLfloat pitch = 0.0;

Vector3D gravedad(0.0,0.0,-0.98/10);
RozamientoViscoso rv;
Hilo h(20.0,1.0,0.0);
Tela t(40*16,30*16,-1,-1,1,1);
DepthImage di;

bool wires=true;
bool friccion=true;

void displayMe(void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt (0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    GLfloat lightpos[] = {5.0, 15., 5., 0.};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
//    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(yaw  ,0.0,1.0,0.0);
    glRotatef(pitch,1.0,0.0,0.0);
    glRotatef(roll ,0.0,0.0,1.0);

    h.glRender();
    glPushMatrix();
      glTranslatef(-di.getCentroid().x, di.getCentroid().y, di.getCentroid().z);
      if(wires)
    	  t.glRender();
      di.glRender();
    glPopMatrix();

//    glPushMatrix();
//     glColor3f(1.0f, 1.0f, 0.0f);
//     glRotatef(angle*2,0.0,1.0,0.0);
//     glTranslatef(0.8,0.5,0.0);
//     glutSolidCube(0.35);
//      glPushMatrix();
//       glColor3f(1.0f, 0.0f, 0.0f);
//       glRotatef(angle*2,0.0,1.0,0.0);
//       glTranslatef(0.5,0.0,0.0);
//       glutSolidSphere(0.1,20,20);
//      glPopMatrix();
//    glPopMatrix();
//    glPushMatrix();
//     glColor3f(0.0f, 1.0f, 1.0f);
//     glTranslatef(-0.8,0.05,-0.8);
//     glutSolidSphere(0.1,10,20);
//    glPopMatrix();
    //glColor3f(0.0f, 1.0f, 0.0f);
    //glutSolidTeapot(0.5);
//    glBegin(GL_POLYGON);
//        glColor3f(1.0f, 0.0f, 0.0f);
//        glVertex3f(0.0, 0.0, 0.0);
//        glColor3f(1.0f, 1.0f, 0.0f);
//        glVertex3f(0.5, 0.0, 0.0);
//        glColor3f(1.0f, 0.0f, 1.0f);
//        glVertex3f(0.5, 0.5, 0.0);
//        glColor3f(0.0f, 0.0f, 1.0f);
//        glVertex3f(0.0, 0.5, 0.0);
//    glEnd();
//    glColor3f(0.0f, 1.0f, 1.0f);
//    glBegin(GL_POLYGON);
//        glVertex3f(-1.0, 0.0, -1.0);
//        glVertex3f( 1.0, 0.0, -1.0);
//        glVertex3f( 1.0, 0.0,  1.0);
//        glVertex3f(-1.0, 0.0,  1.0);
//    glEnd();
    //glFlush();
    glutSwapBuffers();
    angle++;
}

void init (void) {
    glEnable (GL_DEPTH_TEST);
    //glEnable (GL_LIGHTING);
    //glEnable (GL_LIGHT0);
    //glEnable(GL_COLOR_MATERIAL);
    glClearColor (0.0,0.0,0.0,0.0);
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0f, (GLfloat)width/(GLfloat)height, 0.5f, 200.0f);

    glMatrixMode(GL_MODELVIEW);
    ancho = width;
    alto = height;
}
void idle()
{
    displayMe();
    /*
    h.limpiaFuerza();
    h.acumulaFuerza(gravedad);
    for(Particula *p:h.getPuntos()){
    	Vector3D fr=rv.getFuerza(p);
    	p->acumulaFuerza(fr);
    }
    h.aplicaFuerza();
    t.limpiaFuerza();
    if(friccion)
    	for(Particula *p:t.getPuntos()){
    		Vector3D fr=rv.getFuerza(p);
    	    p->acumulaFuerza(fr);
    	}
    //t.acumulaFuerza(gravedad);
    //t.aplicaFuerza();
     *
     */
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
    case 'v':
    case 'V':
      wires=true;
      break;
    case 'b':
    case 'B':
      wires=false;
      break;
    case 'f':
    case 'F':
      friccion=true;
      break;
    case 'g':
    case 'G':
      friccion=false;
      break;
    case 'r':
    case 'R':
      cout << t.getFibras().size() << " before R"<<endl;
      t.rompeFibras(0.05);
  	  cout << t.getFibras().size() << " after R"<<endl;

      break;

    case 27:   // escape
      exit(0);
      break;
    }
}
int findPartiulaFijaIdxInCol(int u,int v){
	int j=v;
	for(;j<t.getEight();j++){
		Particula *p=t.getParticula(u,j);
		if(p->esFija())
			return j;
	}
	return j-1;
}
void estimateDepth(int u,int v0,int v1){
	Particula *p0=t.getParticula(u,v0);
	Particula *p1=t.getParticula(u,v1);
	double z0=-p0->getPosicion().getZ();
	double z1=-p1->getPosicion().getZ();
	float n=v1-v0;
	double slope=(z1-z0)/n;
	for(int v=v0+1;v<v1;v++){
		Particula *p=t.getParticula(u,v);
		double Zestimated=z0+slope*(v-v0);
		Point3f point=di.getPoint3Ddeep(u,v,Zestimated);
		p->getPosicion().set(point.x,-point.y,-point.z);
	}
}
void densifica(){
	for(int u=0;u<t.getWidth();u++){
		int idx0=findPartiulaFijaIdxInCol(u,0);
		for(int v=idx0;v<t.getEight()-1;){
			int idx1=findPartiulaFijaIdxInCol(u,v+1);
			estimateDepth(u,v,idx1);
			v=idx1;
		}
	}
}
int main(int argc, char** argv)
{
	string basepath;
	if ( argc != 2 )
		{
	        printf("usage: cRGB pathToRGBDdataset \n");
	        return -1;
	}
	basepath=argv[1];
	DepthImage dImg(basepath,10);
    di=dImg.sparse();
    cout << di.getCentroid()<< " centroid"<<endl;
    cout << di.getPoints3D().size()/1000 << "mil filtered points" <<endl;

//	int u=80,v=60;
//	t.getParticula(u,v)->setFija();
//	t.getParticula(u-20,v)->setFija();
//	t.getParticula(u+20,v)->setFija();
	for(int v=0;v<t.getEight();v++)
		for(int u=0;u<t.getWidth();u++){
			Particula *p=t.getParticula(u,v);
			int udi=u<<0;
			int vdi=v<<0;
			Vec3b col=di.getColor(udi,vdi);
			float b=col.val[0]/255.0;
			float g=col.val[1]/255.0;
			float r=col.val[2]/255.0;
			p->setColor(Vector3D(r,g,b));
			if(di.isGoodDepthPixel(udi,vdi)){
				p->setFija();
				Point3f point=di.getPoint3D(udi,vdi);
				p->getPosicion().set(point.x,-point.y,-point.z);
			}
			else{
				Point3f point=di.getPoint3Ddeep(udi,vdi,di.getCentroid().z);
				//p->getPosicion().set(point.x,-point.y,-di.getCentroid().z);
				p->getPosicion().set(point.x,-point.y,-point.z);
			}
		}
	cout << t.getFibras().size() << " before"<<endl;
	t.quitaFibrasFijas();
	cout << t.getFibras().size() << " after"<<endl;
    t.calculaLongitudReposo(0.1);
    densifica();

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
