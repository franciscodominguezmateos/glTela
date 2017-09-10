/*
 * tela.h
 *
 *  Created on: Oct 12, 2015
 *      Author: francisco
 */

#ifndef SRC_TELA_H_
#define SRC_TELA_H_
#include "hilo.h"

class Tela: public Hilo {
	int width,eight;
public:
	Tela();
	Tela(double l);
	Tela(int w,int h,double xi,double zi,double xf,double zf);
	virtual ~Tela();
	inline int getWidth(){return width;}
	inline int getHeight(){return eight;}
	void setMarcoFijo();
	inline Particula *getParticula(int u,int v){return puntos[getParticulaIndex(u,v)];}
	inline int        getParticulaIndex(int u,int v){return width*v+u;}
	void glRender();
	void quitaFibrasFijas();
	void rompeFibras(double l);
};

#endif /* SRC_TELA_H_ */
