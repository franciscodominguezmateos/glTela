/*
 * hilo.h
 *
 *  Created on: Oct 11, 2015
 *      Author: francisco
 */

#ifndef HILO_H_
#define HILO_H_
#include <vector>
#include "particula.h"
#include "fuerzaElastica.h"

using namespace std;

class Hilo {
protected:
	vector<Particula *> puntos;
	vector<FuerzaElastica *> fibras;
public:
	Hilo();
	Hilo(float maxX,float Y,float Z);
	virtual ~Hilo();
	void filaX(float maxX,float Y,float Z);
	inline vector<Particula *> getPuntos(){return puntos;}
	inline void setPuntos(vector<Particula *> pts){puntos=pts;}
	inline Particula *getPrimeraParticula(){return puntos[0];}
	inline Particula *getUltimaParticula(){
		int ultimaPos=puntos.size()-1;
		return puntos[ultimaPos];
	}
	inline void glSetColor(Vector3D &col){
		float r=col.getX();
		float g=col.getY();
		float b=col.getZ();
	    glColor4f(r, g, b,0.9f);
	}
	inline void glRender(){
//	    glColor3f(1.0f, 1.0f, 0.0f);
//	    glBegin(GL_POINTS);
//		for(Particula *p:puntos){
//			//p->glRender();
//			Vector3D pos1=p->getPosicion();
//		    glVertex3f(pos1.getX(),pos1.getY(),pos1.getZ());
//		}
//		glEnd();
		int s=fibras.size();
		for(int i=0;i<s;i++){
			Particula p1=*(fibras[i]->getParticula1());
			Particula p2=*(fibras[i]->getParticula2());
			Vector3D pos1=p1.getPosicion();
			Vector3D pos2=p2.getPosicion();
			Vector3D col=p1.getColor();
			glSetColor(col);
		    glBegin(GL_LINES);
		      glVertex3f(pos1.getX(),pos1.getY(),pos1.getZ());
		      glVertex3f(pos2.getX(),pos2.getY(),pos2.getZ());
		    glEnd();
		}
	}
	inline void limpiaFuerza(){
		for(Particula *p:puntos)
			p->limpiaFuerza();
	}
	inline void acumulaFuerza(Vector3D f){
		for(Particula *p:puntos)
			p->acumulaFuerza(f);
	}
	inline void aplicaFuerza(){
		for(FuerzaElastica *fe:fibras){
			Particula *p1=fe->getParticula1();
			Particula *p2=fe->getParticula2();
			Vector3D elastica=fe->evalua();
			p1->acumulaFuerza(elastica);
			p2->acumulaFuerza(-elastica);
		}
		for(Particula *p:puntos)
			p->aplicaFuerza();
	}
	void calculaLongitudReposo(float s){
		for(FuerzaElastica *f:fibras){
			Particula *p1,*p2;
			p1=f->getParticula1();
			p2=f->getParticula2();
			Vector3D pos1=p1->getPosicion();
			Vector3D pos2=p2->getPosicion();
			float l=(pos1-pos2).length();
			f->setLongitudReposo(l*s);
		}
	}
};

#endif /* HILO_H_ */
