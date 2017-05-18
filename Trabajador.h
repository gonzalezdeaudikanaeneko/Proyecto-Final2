/*
 * Trabajador.h
 *
 *  Created on: 18 de may. de 2017
 *      Author: Txus
 */

#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_

class Trabajador {
public:
	char *nombre;
	char *contrasena;
	int edad;
	int Id_Trabajador;
	Trabajador();
	virtual ~Trabajador();

};



#endif /* TRABAJADOR_H_ */
