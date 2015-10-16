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
public:
	Tela();
	Tela(int w,int h,float xi,float zi,float xf,float zf);
	virtual ~Tela();
};

#endif /* SRC_TELA_H_ */
