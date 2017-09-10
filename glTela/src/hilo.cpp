/*
 * hilo.cpp
 *
 *  Created on: Oct 11, 2015
 *      Author: francisco
 */

#include "hilo.h"

Hilo::Hilo() {
}
Hilo::Hilo(double maxX,double Y,double Z){
	filaX(maxX,Y,Z);
	puntos[0]->setFija();
	puntos[9]->setFija();

}
void Hilo::filaX(double maxX,double Y,double Z) {
	for(int i=0;i<maxX;i++){
		Particula *p=new Particula(-1+i/maxX*2.0,Y,Z);
		puntos.push_back(p);
	}
	for(int i=0;i<maxX-1;i++){
		Particula *p1,*p2;
		p1=puntos[i+0];
		p2=puntos[i+1];
		Vector3D pos1=p1->getPosicion();
		Vector3D pos2=p2->getPosicion();
		FuerzaElastica *f=new FuerzaElastica();
		double l=(pos1-pos2).length();
		f->setParticula1(p1);
		f->setParticula2(p2);
		f->setLongitudReposo(l*0.5);
		fibras.push_back(f);
	}
}
Hilo::~Hilo() {
	// TODO Auto-generated destructor stub
}

