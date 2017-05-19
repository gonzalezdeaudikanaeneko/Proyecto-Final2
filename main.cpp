/*
 * main.cpp
 *
 *  Created on: 18 de may. de 2017
 *      Author: Eneko
 */

#include <stdio.h>
#include <iostream>
#include "Cuenta.h"
#include "Banco.h"
#include <stdbool.h>
#include <list>
#include <sstream>
#include "Funciones.h"
#include "Usuario.h"
#include "sqlite3.h"
#include "Trabajador.h"
#include "Director.h"
#include "AdministradorCuentas.h"

using namespace std;

int main(void) {
	char funcMenu, menuT, menuA, menuD, menuC;
	bool repetir;
	string statement;
	string result;
	char *csql3;
	const char *csql2;
	Trabajador t;
	Director d;
	Banco b;
	list<Cuenta*>* CB;
	CB = b.LeerFichero();
	do {
		repetir = true;
		funcMenu = mostrarMenu();
		switch (funcMenu) {
		case '1': {
			menuT = mostrarMenuTrabajador();
			switch (menuT) {
			case '1':
				menuD = mostrarMenuDirector();
				break;
			case '2':
				menuA = mostrarMenuAdmin();
				switch (menuA) {
					case 1://Añadir cuenta

						break;
					case 2://Eliminar cuenta
						break;
					case 3://mover saldo
						//b.transaccion(CB,123,123,350);
						break;
					case 4://MOstra 1
						printf("Introduce N_IDENT de la Cuenta: \n");
						fflush(stdout);
						char nombre[20];
						scanf("%s", nombre);
						fflush(stdin);
						printf("%s", nombre);
						statement = "SELECT * from CUENTAS where N_IDENT like '";
						statement.append(nombre);
						statement.append("';");
						csql2 = statement.c_str();
						csql3=(char*) csql2;
						ejecutarComando(csql3);
						printf("\n");
						break;
					case 5://Mostrar todas
						statement = "SELECT * from XML;";
						csql2 = statement.c_str();
						csql3=(char*) csql2;
						ejecutarComando(csql3);
						break;
					case 6://salir
						break;
					default:
						break;
				}
				break;
			case '3':
				printf("Saliendo ...");
				break;
			default:
				printf("\Opcion incorrecta!\n\n");
				break;
			}
		}
			break;
		case '2': {
			menuC = mostrarMenuCliente();
			switch (menuC) {
			case 1:
				//ingresar dinero;
				break;
			case 2:
				//sacar dinero;
				break;
			default:
				break;
			}
		}
			break;
		case '3': {
			printf("Saliendo del programa...\n\n");
			repetir = false;
		}
			break;
		default:
			printf("\Opcion incorrecta!\n\n");
			break;
		}
	} while (repetir);

	return 0;
}

