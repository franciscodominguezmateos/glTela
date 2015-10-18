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
	Tela(int w,int h,float xi,float zi,float xf,float zf);
	virtual ~Tela();
	void setMarcoFijo();
	inline Particula *getParticula(int u,int v){return puntos[width*v+u];}
};

#endif /* SRC_TELA_H_ */
