/*
 * Cuenta.h
 *
 *  Created on: 15 de may. de 2017
 *      Author: Unai Jauregibeitia
 */

#ifndef CUENTA_H_
#define CUENTA_H_
#include <list>
#include <iostream>


class Cuenta {
private:

	int nIdent;			//Numero de persona DNI
	char *nombre;		//Nombre de persona
	int ID_Cuenta;		//Numero identificativo de la cuenta
	int liq;			//Liquided de la cuenta
	char *contrasena;	//Contraseña del usuario

public:

	Cuenta(const int nIdent, const char *nombre, int ID_Cuenta,char* cont);
	Cuenta(const Cuenta &c);
	Cuenta();

	virtual ~Cuenta();
	int getNumeroId();
	int getLiquidacion();
	char* getNombre();
	char* getContrasena();
	int getID();

	void setNumeroId(int a);	//nIdent
	void setLiquidacion(int a);
	void setNombre(char* a);
	void setContrasena(char* a);
	void setID(int a);
};

#endif /* CUENTA_H_ */
