/*
 * Trabajador.h
 *
 *  Created on: 18 de may. de 2017
 *      Author: Txus
 */

#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_
#include "Cuenta.h"
#include <list>

using namespace std;

class Trabajador {
public:
	char *nombre;
	char *contrasena;
	int edad;
	int Id_Trabajador;
	Trabajador();
	virtual ~Trabajador();
	void anadirCuenta(Cuenta * CuentasB, float liq, int cli);
	void eliminarCuenta(list<Cuenta*>* cuentasB, int cli);
};



#endif /* TRABAJADOR_H_ */
