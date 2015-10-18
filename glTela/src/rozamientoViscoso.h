/*
 * rozamientoVizcoso.h
 *
 *  Created on: Oct 12, 2015
 *      Author: francisco
 */

#ifndef SRC_ROZAMIENTOVISCOSO_H_
#define SRC_ROZAMIENTOVISCOSO_H_
#include "vector3d.h"
#include "particula.h"

class RozamientoViscoso {
	float kv;
public:
	RozamientoViscoso():kv(0.05){}
	virtual ~RozamientoViscoso();
	inline Vector3D getFuerza(Particula *p){
		Vector3D v=p->getVelocidad();
		return -v*kv;
	}
};

#endif /* SRC_ROZAMIENTOVISCOSO_H_ */
