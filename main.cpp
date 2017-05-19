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

using namespace std;

int main(void) {
	char funcMenu, menuT, menuA, menuD, menuC;
	bool repetir;
	string statement;
	string result;
	int noticia;
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

