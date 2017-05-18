/*
 * AdministradorCuentas.h
 *
 *  Created on: 18 de may. de 2017
 *      Author: Txus
 */

#ifndef ADMINISTRADORCUENTAS_H_
#define ADMINISTRADORCUENTAS_H_
#include "Trabajador.h"
#include "Cuenta.h"

class AdministradorCuentas : public Trabajador
{
public:
	AdministradorCuentas();
	virtual ~AdministradorCuentas();
	//void AdministradorCuentas::anadirCuenta(Cuenta * CuentasB, float liq, int cli);
};

#endif /* ADMINISTRADORCUENTAS_H_ */
