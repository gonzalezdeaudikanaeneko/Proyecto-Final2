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

using namespace std;

int main(void) {
	char funcMenu;
	char resultado;
	bool repetir;
	Cuenta* n;
	string  statement;
	string result;
	int noticia;
	do {
		repetir = true;
		printf("MENU PRINCIPAL\n"
				"1.\tTRABAJADOR\n"
				"2.\tCLIENTE\n"
				"3.\tSALIR\n"
				"Introduzca numero de la funcion deseada:\n");
		fflush(stdout);
		resultado = getchar();
		fflush(stdin);
		switch (resultado) {
		case '1':
		{
			printf("Opcion 1");
			statement = "SELECT * from CUENTA;";
			const char *csql2 = statement.c_str();
			char *csql3=(char*) csql2;
//			ejecutarComando(csql3);
//			ejecutarComando(csql3);
			printf("Introduce DNI del titular de la cuenta: \n");
			fflush(stdout);
			char dni[10];
			scanf("%s", dni);
			fflush(stdin);
			printf("%s", dni);
			statement = "SELECT * from CUENTA where DNI like '";
			statement.append(dni);
			statement.append("';");
			csql2 = statement.c_str();
			csql3=(char*) csql2;
//			ejecutarComando(csql3);
			printf("\n");

			}
			break;
		case '2':{
//
//			bool continuar;
//			continuar = true;
//			char respuesta;
//			string modificacion;
//			bool repetir2;
//			repetir2 = true;
//			do
//			{
//			statement = "SELECT COD_NOT,TITULO from NOTICIA;";
//			const char *csql2 = statement.c_str();
//			char *csql3=(char*) csql2;
//			ejecutarComandoBD(csql3);
//			//getTableData(csql3,noticias);
//			printf("\nIntroduzca el codigo de la noticia que desea modificar");
//			fflush(stdout);
//			cin >> noticia ;
//			cout << endl;
//			//scanf("%i",noticia);
//			printf( "\n ");
//			statement = "SELECT * from NOTICIA where COD_NOT =  ";
//
//
//
//			ostringstream convert;
//
//			convert << noticia;
//
//			result = convert.str();
//			statement.append(result);
//			statement.append(";");
//			cout << statement;
//			csql2 = statement.c_str();
//			csql3=(char*) csql2;
//			getTableDataNoticia(csql3);
//
//			cout << "\n�Es esta la noticia que quieres modificar? (s/n) ";
//			cin >> respuesta;
//			if (respuesta = 's') continuar = false;
//
//			} while(continuar);
//			do
//			{
//				cout <<"\n�Que desea modificar?  ";
//				cout <<"\n"
//					"1.\tTitulo\n"
//					"2.\tAutor\n"
//					"3.\tDescripcion\n"
//					"4.\tSalir\n\n"
//					"Introduzca numero de la funcion deseada:\n";
//
//			char resultado;
//			cin >> respuesta;
//			switch(respuesta)
//			{
//			case '1':
//				cout << "\nIntroduzca el nuevo titulo : ";
//
//				cin >> modificacion;
//				statement = "UPDATE NOTICIA SET TITULO = '";
//				statement.append(modificacion);
//				statement.append("' WHERE COD_NOT = ");
//				statement.append(result);
//				statement.append(";");
//				ejecutarComandoBD(&statement[0u]);
//				cout << "\nEl titulo ha sido modificado ";
//
//				break;
//			case '2':
//				cout << "\nIntroduzca el nuevo autor : ";
//				cin >> modificacion;
//				statement = "UPDATE NOTICIA SET AUTOR = '";
//				statement.append(modificacion);
//				statement.append("' WHERE COD_NOT  = ");
//				statement.append(result);
//				statement.append(";");
//				ejecutarComandoBD(&statement[0u]);
//				cout << "\nEl autor  ha sido modificado ";
//				break;
//			case '3':
//				cout << "\nIntroduzca la nueva descripcion : ";
//					cin >> modificacion;
//					statement =	"UPDATE NOTICIA SET DESC = '";
//					statement.append(modificacion);
//					statement.append("' WHERE COD_NOT  = ");
//					statement.append(result);
//					statement.append(";");
//					ejecutarComandoBD(&statement[0u]);
//					cout << "\nLa descripcion ha sido modificada ";
//					break;
//			case '4':
//				repetir2 = false;
//			break;
//			default:
//				printf("\n�Opcion incorrecta!\n\n");
//				break;
//			}
//			}while(repetir2);
//
			break;
		}
		case '3':
		{
//			list<Noticia*> noticias;
//			string tituloRSS;
//			printf("Introduce titulo del RSS: \n");
//			fflush(stdout);
//
////			getline(cin, tituloRSS);
//			/*scanf("%s", tituloRSS.c_str());
//			fflush(stdin);*/
//			cin >> tituloRSS;
//			cout << endl;
//			crearRss(tituloRSS, &noticias);
//			//mostrarNoticia(nuevaNoticia());
//			int i;
//			for(i=0;i<noticias.size();i++)
//			{
//				mostrarNoticia(get(&noticias,i));
//			}
		}
			break;
		case '4':
			//exportarXML();
			repetir = false;
			break;
		default:
			printf("\n�Opcion incorrecta!\n\n");
			break;
		}
	} while (repetir);

	return 0;
}

