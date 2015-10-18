/*
 * tela.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: francisco
 */

#include "tela.h"

Tela::Tela() {
	// TODO Auto-generated constructor stub

}
Tela::Tela(int w,int h,float xi=-1,float zi=-1,float xf=1,float zf=1) {
	width=w;
	eight=h;
	int size=w*h;
	float sx=(xf-xi)/w;
	float sz=(zf-zi)/h;
	float zc=zi;
	//crea particulas
	for(int k=0;k<h;k++){
		float xc=xi;
		for(int i=0;i<w;i++){
			Particula *p=new Particula(xc,1.0,zc);
			puntos.push_back(p);
			xc+=sx;
		}
		zc+=sz;
	}
	//conecta particulas
	for(int k=0;k<h;k++){
		for(int i=0;i<w-1;i++){
			Particula *p1,*p2;
			int idx=i+k*w;
			p1=puntos[idx+0];
			p2=puntos[idx+1];
			Vector3D pos1=p1->getPosicion();
			Vector3D pos2=p2->getPosicion();
			FuerzaElastica *f=new FuerzaElastica();
			float l=(pos1-pos2).length();
			f->setParticula1(p1);
			f->setParticula2(p2);
			f->setLongitudReposo(l*0.1);
			fibras.push_back(f);
		}
		if(k>0){
			for(int i=0;i<w;i++){
				Particula *p1,*p2;
				int idx=i+(k-1)*w;
				p1=puntos[idx];
				p2=puntos[idx+w];
				Vector3D pos1=p1->getPosicion();
				Vector3D pos2=p2->getPosicion();
				FuerzaElastica *f=new FuerzaElastica();
				float l=(pos1-pos2).length();
				f->setParticula1(p1);
				f->setParticula2(p2);
				f->setLongitudReposo(l*0.1);
				fibras.push_back(f);
			}
		}
	}
}

Tela::~Tela() {
	// TODO Auto-generated destructor stub
}
void Tela::setMarcoFijo(){
	int h=eight;
	int w=width;
	for(int i=0;i<w;i++){
		puntos[i]->setFija();
		puntos[i+(h-1)*w]->setFija();
	}
	for(int k=0;k<h-1;k++){
		puntos[k*w]->setFija();
		puntos[k*w+w-1]->setFija();
	}
}

