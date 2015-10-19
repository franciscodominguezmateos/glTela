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
	Vector3D color;
	bool fija;
public:
	static constexpr float dt=0.005;
	inline Particula(double x=0.0,double y=0.0,double z=0.0):masa(0.01),posicion(x,y,z),color(1.0,1.0,0.0),fija(false){}
	virtual ~Particula();
	inline Vector3D& getPosicion() {return posicion;}
	inline Vector3D& getVelocidad(){return velocidad;}
	inline Vector3D& getFuerza(){return fuerza;}
	inline Vector3D& getColor(){return color;}
	inline void setMasa(float m){masa=m;}
	inline void setFija(){fija=true;}
	inline void setLibre(){fija=false;}
	inline void setColor(Vector3D c){color=c;}
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
			Vector3D aceleracion=fuerza/masa;
			Vector3D dv=aceleracion*dt;
			velocidad+=dv;
			//try to avoid numerical unstability
//			if(velocidad.length()>5.0)
//				velocidad=Vector3D(0,0,0);
			actualiza();
		}
	}
	inline void actualiza(){
		//float vx,vy,vz;
		Vector3D dp=velocidad*dt;
		Vector3D p=posicion+dp;
//		if (p.getY()<0){
//			vx=velocidad.getX();
//			vy=velocidad.getY();
//			vz=velocidad.getZ();
//			velocidad.set(vx,-vy*0.5,vz);
//			p.setY(0.0);
//		}
//		else if (fabs(p.getX())>2){
//			    velocidad*=-0.5;
//			    p.setX(0.0);
//		}
//		     else
//			    posicion=p;
		posicion=p;
	}
	friend std::ostream &operator << (std::ostream &os, const Particula &p);

};
inline std::ostream &operator<<(std::ostream &os, const Particula &p){
 os << '(' << p.masa << ',' << p.posicion << ',' << p.velocidad << ')';
 return os;
}

#endif /* PARTICULA_H_ */
