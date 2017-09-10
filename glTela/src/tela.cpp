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
Tela::Tela(double l){
	Particula *p;
	p=new Particula( l, l, l);
	puntos.push_back(p);
	p=new Particula( l, l,-l);
	puntos.push_back(p);
	p=new Particula( l,-l,-l);
	puntos.push_back(p);
	p=new Particula( l,-l, l);
	puntos.push_back(p);
	p=new Particula(-l, l, l);
	puntos.push_back(p);
	p=new Particula(-l, l,-l);
	puntos.push_back(p);
	p=new Particula(-l,-l,-l);
	puntos.push_back(p);
	p=new Particula(-l,-l, l);
	puntos.push_back(p);
	Particula *p1,*p2;
	for(int i=0;i<this->getPuntos().size();i++){
		for(int j=i+1;j<this->getPuntos().size();j++){
			p1=getPuntos()[i];
			p2=getPuntos()[j];
			Vector3D d=p2->getPosicion()-p1->getPosicion();
			double length=d.length();
			FuerzaElastica *f1=new FuerzaElastica();
			f1->setLongitudReposo(length);
			f1->setKm(1000);
			f1->setKa(1);
			f1->setParticula1(p1);
			f1->setParticula2(p2);
			fibras.push_back(f1);
		}
	}
	for(Particula *p:this->getPuntos()){
		Vector3D iy(0.1,2,0);
		p->getPosicion()+=iy;
	}
}
Tela::Tela(int w,int h,double xi=-1,double zi=-1,double xf=1,double zf=1) {
	width=w;
	eight=h;
	double sx=(xf-xi)/w;
	double sz=(zf-zi)/h;
	double zc=zi;
	//crea particulas
	for(int k=0;k<h;k++){
		double xc=xi;
		for(int i=0;i<w;i++){
			Particula *p=new Particula(xc,1.0,zc);
			puntos.push_back(p);
			xc+=sx;
		}
		zc+=sz;
	}
	//conecta particulas
	Particula *p1,*p2,*p3,*p4;
	for(int k=0;k<h-1;k++){
		for(int i=0;i<w-1;i++){
			p1=getParticula(i+0,k+0);
			p2=getParticula(i+1,k+0);
			p3=getParticula(i+1,k+1);
			p4=getParticula(i+0,k+1);
			Vector3D pos1=p1->getPosicion();
			Vector3D pos2=p2->getPosicion();
			Vector3D pos3=p3->getPosicion();
			Vector3D pos4=p4->getPosicion();
			//   ->
			FuerzaElastica *f1=new FuerzaElastica();
			f1->setParticula1(p1);
			f1->setParticula2(p2);
			//
			FuerzaElastica *f2=new FuerzaElastica();
			f2->setParticula1(p1);
			f2->setParticula2(p3);
			//   |
			FuerzaElastica *f3=new FuerzaElastica();
			f3->setParticula1(p1);
			f3->setParticula2(p4);
			//   /
			FuerzaElastica *f4=new FuerzaElastica();
			f4->setParticula1(p2);
			f4->setParticula2(p4);
			fibras.push_back(f1);
			//fibras.push_back(f2);
			fibras.push_back(f3);
			//fibras.push_back(f4);
		}
		p1=getParticula(w-1,k+0);
		p2=getParticula(w-1,k+1);
		Vector3D pos1=p1->getPosicion();
		Vector3D pos2=p2->getPosicion();
		FuerzaElastica *f=new FuerzaElastica();
		f->setParticula1(p1);
		f->setParticula2(p2);
		fibras.push_back(f);
	}
	int k=h-1;
	for(int i=0;i<w-1;i++){
		p1=getParticula(i+0,k+0);
		p2=getParticula(i+1,k+0);
		FuerzaElastica *f1=new FuerzaElastica();
		f1->setParticula1(p1);
		f1->setParticula2(p2);
		fibras.push_back(f1);
	}
}

Tela::~Tela() {
	// TODO Auto-generated destructor stub
}
void Tela::glRender(){
	int h=eight;
	int w=width;

	for(int k=0;k<h-1;k++){
		for(int i=0;i<w-1;i++){
			Particula *p1,*p2,*p3,*p4;
			p1=getParticula(i+0,k+0);
			p2=getParticula(i+1,k+0);
			p3=getParticula(i+1,k+1);
			p4=getParticula(i+0,k+1);
			Vector3D pos1,pos2,pos3,pos4;
			pos1=p1->getPosicion();
			pos2=p2->getPosicion();
			pos3=p3->getPosicion();
			pos4=p4->getPosicion();
			Vector3D col1,col2,col3,col4;
			col1=p1->getColor();
			col2=p2->getColor();
			col3=p3->getColor();
			col4=p4->getColor();
		    glBegin(GL_TRIANGLES);
		      glSetColor(col1);
		      glVertex3f(pos1.getX(),pos1.getY(),pos1.getZ());
		      glSetColor(col2);
		      glVertex3f(pos2.getX(),pos2.getY(),pos2.getZ());
		      glSetColor(col3);
		      glVertex3f(pos3.getX(),pos3.getY(),pos3.getZ());
		    glEnd();
		    glBegin(GL_TRIANGLES);
		      glSetColor(col3);
		      glVertex3f(pos3.getX(),pos3.getY(),pos3.getZ());
		      glSetColor(col4);
		      glVertex3f(pos4.getX(),pos4.getY(),pos4.getZ());
		      glSetColor(col1);
		      glVertex3f(pos1.getX(),pos1.getY(),pos1.getZ());
		    glEnd();
		}
	}

	Hilo::glRender();
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
void Tela::quitaFibrasFijas(){
	vector<FuerzaElastica *> newFibras;
	for(FuerzaElastica *f:fibras){
		if(!(      f->getParticula1()->esFija()
				&& f->getParticula2()->esFija()))
			newFibras.push_back(f);
	}
	fibras=newFibras;
}
void Tela::rompeFibras(double l){
	Particula *p1,*p2;
	double len;
	vector<FuerzaElastica *> newFibras;
	for(FuerzaElastica *f:fibras){
		p1=f->getParticula1();
		p2=f->getParticula2();
		len=(p2->getPosicion()-p1->getPosicion()).length();
		if(len<l)
			newFibras.push_back(f);
	}
	fibras=newFibras;
}
