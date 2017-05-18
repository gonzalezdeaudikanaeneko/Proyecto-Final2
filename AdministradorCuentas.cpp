/*
 * AdministradorCuentas.cpp
 *
 *  Created on: 18 de may. de 2017
 *      Author: Txus
 */

#include "AdministradorCuentas.h"
#include "Banco.h"
#include "Cuenta.h"
#include "Funciones.h"
#include "Trabajador.h"

#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;


AdministradorCuentas::AdministradorCuentas() {
	// TODO Auto-generated constructor stub

}

AdministradorCuentas::~AdministradorCuentas() {
	// TODO Auto-generated destructor stub
}

void AdministradorCuentas::anadirCuenta(list<Cuenta> cuentasB, float liq, int cli) {

	Cuenta c;
	c.setLiquidacion(liq);
	c.setNombre("Halo");
	cuentasB.push_back(c);
	cout << "Exito\n";
}
void AdministradorCuentas::eliminarCuenta(list<Cuenta*>* cuentasB, int cli) {
//	unsigned int i = 0, enc = 0;
//	while (enc == 0 && i < cuentasB->size()) {
//		if (get(cuentasB, i)->getNumeroId() == cli) {
//			enc = 1;
//		} else {
//			i++;
//		}
//	}
//	if (enc == 1) {
//		while (i < cuentasB->size()) {
//			remove(cuentasB[i]);
//			i++;
//		}
//		printf("eliminado\n\n");
//
//		CuentasB->numCuentas = CuentasB->numCuentas - 1;
//	} else {
//		printf("no encontrado\n\n");
//	}
}
