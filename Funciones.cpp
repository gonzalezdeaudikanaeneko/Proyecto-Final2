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
#include "Usuario.h"
#include "Banco.h"
#include <list>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include "sqlite3.h"

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
/**
 	int nIdent;
	char *nombre;
	int ID_Cuenta;
	float liq;
	int numCuentas;
	char *contrasena;
 **/
//Cuenta* nuevaCuenta() {
//
//	Cuenta* n = new Cuenta();
//	printf("Introduce nombre del titular: \n");
//	fflush(stdout);
//	char* titulo;
//	cin >> titulo;
//	cout << endl;
//	n->setNombre(titulo);
//	//////titulo//////
//	printf("Introduce el numero de identificacion: \n");
//	fflush(stdout);
//	int autor;
//	cin >> autor;
//	cout << endl;
//	n->setNumeroId(autor);
//	//////autor//////
//	printf("Introduce la contraseña: \n");
//	fflush(stdout);
//	char* desc;
//	cin >> desc;
//	cout << endl;
//	n->setContrasena(desc);
//	//////descripcion//////
//	return n;
//}
void mostrarCuenta(Cuenta* n) {
	printf("Titulo de la noticia: %s\n", n->getNombre());
	fflush(stdout);
	printf("Contraseña de la cuenta: %s\n", n->getContrasena());
	fflush(stdout);
	printf("Cantidad de saldo: %f\n", n->getLiquidacion());
	fflush(stdout);
}

//void abrirBD(){
//	sqlite3 *db;
//	   char *zErrMsg = 0;
//	   int rc;
//
//	   rc = sqlite3_open("Cuentas"
//			   ".db", &db);
//
//	   if( rc ){
//	      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//	      //return(0);
//	   }else{
//	      fprintf(stderr, "Opened database successfully\n");
//	   }
//	   sqlite3_close(db);
//
//}
//int ejecutarComandoBD(char * statement) {
//	int devolver;
//	int rc;
//
//	sqlite3* db;
//	//rc = sqlite3_open("xmlbd.s3db", &db);
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
//int callback(void *NotUsed, int argc, char **argv, char **azColName){
//   int i;
//   for(i=0; i<argc; i++){
//      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//   }
//   printf("\n");
//   return 0;
//}

//void almacenarEnBD(string nombreRSS, list<Noticia*>* noticias) {
//	sqlite3* db;
//	int rc;
//	char *zErrMsg = 0;
//	//conectarBD();
//
//	rc = sqlite3_open("xmlbd.s3db", &db);
//
//	if (rc) {
//		//cambiar stderr por stdout para mostrar por consola
//		fprintf(stdout, "Error al abrir BD: %s\n", sqlite3_errmsg(db));
//		exit(0);
//	} else {
//		fprintf(stdout, "Base de datos abierta exitosamente\n");
//	}
//
//
//	string sql = "";
//	string sql2 = "INSERT INTO XML (NOM_XML, RUTA)VALUES ('" + nombreRSS
//			+ "', 'Lector Rss C++/src/" + nombreRSS + ".xml');";
//
//	const char *csql2 = sql2.c_str();
//	rc = sqlite3_exec(db, csql2, callback, 0, &zErrMsg);
//
//	if (rc != SQLITE_OK) {
//		fprintf(stdout, "SQL error: %s\n", zErrMsg);
//		sqlite3_free(zErrMsg);
//	} else {
//		fprintf(stdout, "XML creado\n");
//	}
//	int a;
//	a = getTableDataID(
//			(char*) ("SELECT COD_XML FROM XML WHERE NOM_XML LIKE '" + nombreRSS
//					+ "';").c_str());
//
//	unsigned int i;
//
//	string result;
//
//	ostringstream convert;
//
//	convert << a;
//
//	result = convert.str();
//
//	for (i = 0; i < noticias->size(); i++) {
//
//		sql += "INSERT INTO NOTICIA (TITULO,AUTOR,DESC, COD_XML)VALUES ( '"
//				+ get(noticias, i)->getTitulo() + "', '"
//				+ get(noticias, i)->getAutor() + "', '"
//				+ get(noticias, i)->getDescripcion() + "'," + result + ");";
//	}
//	const char *csql = sql.c_str();
//	rc = sqlite3_exec(db, csql, callback, 0, &zErrMsg);
//	if (rc != SQLITE_OK) {
//		fprintf(stderr, "SQL error: %s\n", zErrMsg);
//		sqlite3_free(zErrMsg);
//	} else {
//		fprintf(stdout, "Noticias insertadas\n");
//	}
//	cerrarBD(db);
//}



