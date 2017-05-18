/*
 * Funciones.h
 *
 *  Created on: 18 de may. de 2017
 *      Author: Eneko
 */
#include "sqlite3.h"
#include <list>
#include <string.h>
#include <string>
#include "Cuenta.h"
#include <stdlib.h>

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
using namespace std;

class Funciones {
public:

	int callback(void *NotUsed, int argc, char **argv, char **azColName);
	int ejecutarComandoBD(char * statement);
	void ejecutarComando(char * statement);
	void cerrarBD(sqlite3* db);
	char mostrarMenu() ;
	void abrirBD();
	char mostrarMenuTrabajador();
	char mostrarMenuCliente();
	void almacenarEnBD(list<Cuenta> noticias);

private:
};
#endif /* FUNCIONES_H_ */
