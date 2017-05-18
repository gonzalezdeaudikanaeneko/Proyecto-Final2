/*
 * Funciones.cpp
 *
 *  Created on: 18 de may. de 2017
 *      Author: Eneko
 */

#include "Funciones.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Cuenta.h"
#include <list>
#include "sqlite3.h"
#include <iostream>
#include <sstream>
#include <typeinfo>
using namespace std;
FILE *doc;

char mostrarMenu() {
	printf("MENU PRINCIPAL\n"
			"1.\tTRABAJADOR\n"
			"2.\tCLIENTE\n"
			"3.\tSALIR\n"
			"Introduzca numero de la funcion deseada:\n");
	fflush(stdout);
	char resultado;
	resultado = getchar();
	fflush(stdin);
	return resultado;
}

char mostrarMenuCliente() {
	printf("MENU PRINCIPAL\n"
			"1.\tIngresar Dinero\n"
			"2.\tRetirar dinero\n"
			"4.\tSalir\n\n"
			"Introduzca numero de la funcion deseada:\n");
	fflush(stdout);
	char resultado;
	resultado = getchar();
	fflush(stdin);
	return resultado;
}
char mostrarMenuTrabajador() {
	printf("MENU PRINCIPAL\n"
			"1.\tAñadir Cuenta\n"
			"2.\tEliminar Cuenta\n"
			"3.\tMovimiento de saldo\n"
			"4.\tMostrar datos de un cuenta\n"
			"5.\tMostrar todas las cuentas\n\n"
			"Introduzca numero de la funcion deseada:\n");
	fflush(stdout);
	char resultado;
	resultado = getchar();
	fflush(stdin);
	return resultado;
}

void mostrarCuenta(Cuenta* n) {
	printf("Titulo de la noticia: %s\n", n->getNombre());
	fflush(stdout);
	printf("Contraseña de la cuenta: %s\n", n->getContrasena());
	fflush(stdout);
	printf("Cantidad de saldo: %f\n", n->getLiquidacion());
	fflush(stdout);
}

//void abrirBD() {
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//
//	rc = sqlite3_open("Cuentas"
//			".db", &db);
//
//	if (rc) {
//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		//return(0);
//	} else {
//		fprintf(stderr, "Opened database successfully\n");
//	}
//	sqlite3_close(db);
//
//}

//int ejecutarComandoBD(char * statement) {
//	int devolver;
//	int rc;
//
//	sqlite3* db;
//	rc = sqlite3_open("xmldb.s3db", &db);
//
//	if (rc) {
//		//cambiar stderr por stdout para mostrar por consola
//		fprintf(stdout, "Error al abrir BD: %s\n", sqlite3_errmsg(db));
//		exit(0);
//	} else {
//		fprintf(stdout, "Base de datos abierta exitosamente\n");
//	}
//
//	char *zErrMsg = 0;
//	const char* data = "Callback function called";
//	rc = sqlite3_exec(db, statement, callback, (void*) data, &zErrMsg);
//	if (rc != SQLITE_OK) {
//		fprintf(stderr, "SQL error: %s\n", zErrMsg);
//		fflush(stdout);
//		sqlite3_free(zErrMsg);
//		devolver = 1;
//	} else {
//		fprintf(stdout, "Operacion correcta\n");
//		devolver = 0;
//
//	}
//	sqlite3_close(db);
//	return devolver;
//
//}
void cerrarBD(sqlite3* db) {
	sqlite3_close(db);
}

void crearTabla() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;

	/* Open database */
	rc = sqlite3_open("xmlbd.s3db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	} else {
		fprintf(stdout, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sql = "CREATE TABLE CUENTA("
			"N_IDENT INT PRIMARY KEY     NOT NULL,"
			"NOMBRE           CHAR(30)    NOT NULL,"
			"CONTRASEÑA        CHAR(20)     NOT NULL,"
			"ID_CUENTA        CHAR(25),"
			"SUELDO         INT );";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);
}
//
//void ejecutarComando(char * statement) {
//	int devolver;
//	int rc;
//
//	sqlite3* db;
//	//rc = sqlite3_open("xmlbd.s3db", &db);
//	rc = sqlite3_open("Cuentas.db", &db);
//
//	if (rc) {
//		//cambiar stderr por stdout para mostrar por consola
//		fprintf(stdout, "Error al abrir BD: %s\n", sqlite3_errmsg(db));
//		exit(0);
//	} else {
//		fprintf(stdout, "Base de datos abierta exitosamente\n");
//	}
//
//	char *zErrMsg = 0;
//	const char* data = "Callback function called";
//	rc = sqlite3_exec(db, statement, callback, (void*) data, &zErrMsg);
//	if (rc != SQLITE_OK) {
//		fprintf(stderr, "SQL error: %s\n", zErrMsg);
//		fflush(stdout);
//		sqlite3_free(zErrMsg);
//		devolver = 1;
//	} else {
//		fprintf(stdout, "Operacion correcta\n");
//		devolver = 0;
//
//	}
//	sqlite3_close(db);
//	//return devolver;
//
//}
//void cerrarBD(sqlite3* db) {
//	sqlite3_close(db);
//}
//int callback(void *NotUsed, int argc, char **argv, char **azColName) {
//
//	NotUsed = 0;
//
//	for (int i = 0; i < argc; i++) {
//
//		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//	}
//
//	printf("\n");
//
//	return 0;
//}

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

Cuenta* get(list<Cuenta*>* _list, int _i) {
	list<Cuenta*>::iterator it = _list->begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}

Cuenta* get2(list<Cuenta*>* _list, int _i) {
	list<Cuenta*>::iterator it = _list->begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}

void almacenarEnBD(list<Cuenta*>* noticias) {
	sqlite3* db;
	int rc;
	char *zErrMsg = 0;
	//conectarBD();
	rc = sqlite3_open("xmlbd.s3db", &db);
	if (rc) {
		//cambiar stderr por stdout para mostrar por consola
		fprintf(stdout, "Error al abrir BD: %s\n", sqlite3_errmsg(db));
		exit(0);
	} else {
		fprintf(stdout, "Base de datos abierta exitosamente\n");
	}
	string sql = "";
	unsigned int i;

	for (i = 0; i < noticias->size(); i++) {

		Cuenta* c1 = get(noticias, i);
		char* nombre = c1->getNombre();
		char* nIdent = (char*) c1->getNumeroId();

		sql.append("INSERT INTO CUENTAS (N_IDENT,NOMBRE,CONTRASEÑA,SUELDO) VALUES ( '");
		sql.append(nIdent);
		sql.append("', '");
		sql.append(nombre);
		sql.append("', '");
		sql.append(c1->getContrasena());
		sql.append("', '");
		sql.append((char*) c1->getLiquidacion());
		sql.append("', '");

	}
	const char *csql = sql.c_str();
	rc = sqlite3_exec(db, csql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Noticias insertadas\n");
	}
	cerrarBD(db);
}

