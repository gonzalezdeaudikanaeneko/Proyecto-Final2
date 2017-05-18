/*
 * Cuenta.h
 *
 *  Created on: 15 de may. de 2017
 *      Author: Unai Jauregibeitia
 */

#ifndef CUENTA_H_
#define CUENTA_H_

class Cuenta {
private:

	int nIdent;			//Numero de persona
	char *nombre;		//Nombre de persona
	int ID_Cuenta;		//Numero identificativo de la cuenta
	float liq;			//Liquided de la cuenta
	char *contrasena;	//Contraseña del usuario

public:

	Cuenta(const int nIdent, const char *nombre, int ID_Cuenta,char* cont);
	Cuenta(const Cuenta &c);
	Cuenta();
	virtual ~Cuenta();
	int getNumeroId();
	float getLiquidacion();
	char* getNombre();
	char* getContrasena();

	void setNumeroId(int a);
	void setLiquidacion(float a);
	void setNombre(char* a);
	void setContrasena(char* a);

};

#endif /* CUENTA_H_ */
