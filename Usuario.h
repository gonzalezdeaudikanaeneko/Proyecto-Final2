/*
 * Usuario.h
 *
 *  Created on: 17 de may. de 2017
 *      Author: Eneko
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include "Cuenta.h"

class Usuario {

private:

	char *nombre;
	char* direccion;

public:

	Usuario();
	virtual ~Usuario();
	void ingresarDinero(int dinero, Cuenta *c);
	void sacarDinero(int dinero, Cuenta *c);

	char* getNombre();
	char* getContrasena();
	void setNombre(char* a);
	void setContrasena(char* a);
};

#endif /* USUARIO_H_ */
