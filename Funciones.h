/*
 * Funciones.h
 *
 *  Created on: 18 de may. de 2017
 *      Author: Eneko
 */
#include "sqlite3.h"
#include <list>

#ifndef FUNCIONES_H_
#define FUNCIONES_H_



	//int callback(void *NotUsed, int argc, char **argv, char **azColName);
	int callback(void *NotUsed, int argc, char **argv, char **azColName);
	int ejecutarComandoBD(char * statement);
	void ejecutarComando(char * statement);
	void cerrarBD(sqlite3* db);
	char mostrarMenu() ;
	void abrirBD();
	char mostrarMenuTrabajador();
	char mostrarMenuCliente();
#endif /* FUNCIONES_H_ */
