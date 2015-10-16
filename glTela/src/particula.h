/*
 * particula.h
 *
 *  Created on: Aug 15, 2015
 *      Author: francisco
 */

#ifndef PARTICULA_H_
#define PARTICULA_H_

#include <iostream>
#include <GL/glut.h>
#include "vector3d.h"

class Particula {
	double masa;
	Vector3D posicion;
	Vector3D velocidad;
	Vector3D fuerza;
	bool fija;
public:
	inline Particula(double x=0.0,double y=0.0,double z=0.0):masa(1.0),posicion(x,y,z),fija(false){}
	virtual ~Particula();
	inline Vector3D& getPosicion() {return posicion;}
	inline Vector3D& getVelocidad(){return velocidad;}
	inline Vector3D& getFuerza(){return fuerza;}
	inline void setMasa(float m){masa=m;}
	inline void setFija(){fija=true;}
	inline void setLibre(){fija=false;}
	inline void glRender(){
		double tx,ty,tz;
		tx=posicion.getX();
		ty=posicion.getY();
		tz=posicion.getZ();
		glPushMatrix();
		glTranslatef(tx,ty,tz);
	    glColor3f(1.0f, 1.0f, 0.0f);
		//glutWireSphere(0.01f, 8, 8);
		glutSolidSphere(0.001f, 4, 4);
		glPopMatrix();
	}
	inline void limpiaFuerza(){fuerza=Vector3D(0,0,0);}
	inline void acumulaFuerza(Vector3D f){fuerza+=f;}
	inline void aplicaFuerza(){
		if(!fija) {
			float dt=0.001;
			Vector3D aceleracion=fuerza/masa;
			velocidad+=aceleracion*dt;
			actualiza();
		}
	}
	inline void actualiza(){
		float vx,vy,vz;
		Vector3D p=Vector3D(posicion+velocidad);
		if (p.getY()<0){
			vx=velocidad.getX();
			vy=velocidad.getY();
			vz=velocidad.getZ();
			velocidad.set(vx,-vy*0.95,vz);
		}
		else if (fabs(p.getX())>2)
			    velocidad*=-0.95;
		     else
			    posicion=p;
	}
	friend std::ostream &operator << (std::ostream &os, const Particula &p);

};
inline std::ostream &operator<<(std::ostream &os, const Particula &p){
 os << '(' << p.masa << ',' << p.posicion << ',' << p.velocidad << ')';
 return os;
}

#endif /* PARTICULA_H_ */
