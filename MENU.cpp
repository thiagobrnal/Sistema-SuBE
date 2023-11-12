#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "structs.h"
#include "funciones.h"

void MenuUsers();
void MenuSaldo();
void MenuCT();
void subMenuC();
void subMenuT();

main(){
	
	char op;
	int band = 1;
	
	
	while(band!= 0){
		
		
		printf("\n-------------------------------------------------------------------------------\n");
		printf("\t\t\tMENU SISTEMA TRANSPORTE PUBLICO\n");
		printf("-------------------------------------------------------------------------------\n");
		
		printf("1- Registro de Usuarios.\n");
		printf("2- Carga y Consulta de Saldo.\n");
		printf("3- Uso de la tarjeta y/o billetera electronica.\n");
		printf("4- Gestionar Medios de Transporte y Choferes.\n");
		printf("0- Salir.\n");
		
		fflush(stdin);
		scanf("%c", &op);
		printf("\n");
		fflush(stdin);
		
		system("cls");
		
		switch(op){
			
			case '0':
				band=0;
				printf("\n-------------------------------------------------------------------------------");
				puts("\n\t\t\t\tSaliendo...");
				printf("-------------------------------------------------------------------------------\n\n");
			break;
			case '1':
				//Registra ususarios
				MenuUsers();
			break;
			case '2':
				//Saldo
				MenuSaldo();
			break;
			case '3':
				//Usa SUBE
				usoTarjetaoBV();
			break;
			case '4':
				//Gestiona choferes
				MenuCT();
			break;
			
			default:
				printf("\n-------------------------------------------------------------------------------");
				puts("\n\t\t\tOpcion no valida, intente nuevo.");
				printf("-------------------------------------------------------------------------------\n\n");
		}
	}
}

void MenuUsers(){
	
	char op;
	int band = 1;
	
	while(band != 0){
		
		printf("\n-------------------------------------------------------------------------------\n");
		printf("\t\t\t\tMENU Usuarios\n");
		printf("-------------------------------------------------------------------------------\n");
		printf("1- Registro de Usuarios.\n");
		printf("2- Lista de Usuarios\n");
		printf("3- Modificar Usuarios.\n");
		printf("0- Volver.\n");
		
		fflush(stdin);
		scanf("%c", &op);
		printf("\n");
		fflush(stdin);
		
		switch(op){
			case '0':
				band=0;
				system("cls");
				printf("\n-------------------------------------------------------------------------------");
				puts("\n\t\t\t\tVolviendo al Menu.");
				printf("-------------------------------------------------------------------------------\n\n");
			break;
			
			case '1':
				system("cls");				
				altaUsuario(); //Registra un nuevo Usuario				
			break;
			
			case '2':
				system("cls");
				
				listaUsuarios(); //Lista todos los usuarios
				
			break;
			
			case '3':
				system("cls");
				//Modificar Usuarios
			break;
			
			default:
				system("cls");
				printf("\n-------------------------------------------------------------------------------");
				puts("\n\t\t\tOpcion no valida, intente nuevo.");
				printf("-------------------------------------------------------------------------------\n\n");
		}
		
	}
}

void MenuSaldo(){
	
	char op;
	int band = 1;
	
	while(band != 0){
		
	printf("\n-------------------------------------------------------------------------------\n");
		printf("\t\t\t\tMENU SALDO\n");
		printf("-------------------------------------------------------------------------------\n");
		printf("1- Cargar Saldo.\n");
		printf("2- Consultar Saldo.\n");
		printf("3- Ver Movimientos.\n");
		printf("4- Listar Regargas.\n");
		printf("5- Cantidad de Beneficiarios.\n");
		printf("0- Volver.\n");
		
		fflush(stdin);
		scanf("%c", &op);
		printf("\n");
		fflush(stdin);
		
		switch(op){
			case '0':
				band=0;
				system("cls");
				printf("\n-------------------------------------------------------------------------------");
				puts("\n\t\t\t\tVolviendo al Menu.");
				printf("-------------------------------------------------------------------------------\n\n");
			break;
			
			case '1':
				system("cls");								
				cargaSaldo(); //Cargar Saldo				
			break;
			
			case '2':
				system("cls");
				//Consultar Saldo
			break;
			
			case '3':
				system("cls");
				//Ver Movimientos
				//listarCuentas();
			break;
			
			case '4':
				system("cls");
				//Listar Regargas
			break;
			
			case '5':
				system("cls");
				//Cantidad de Beneficiarios
			break;
			
			default:
				system("cls");
				printf("\n-------------------------------------------------------------------------------");
				puts("\n\t\t\tOpcion no valida, intente nuevo.");
				printf("-------------------------------------------------------------------------------\n\n");
		}
		
	}
}


void MenuCT(){
	
	char op;
	int band = 1;
	
	while(band != 0){
		
		printf("\n-------------------------------------------------------------------------------\n");
		printf("\t\t\tMENU Choferes y Transportes\n");
		printf("-------------------------------------------------------------------------------\n");
		printf("1- Choferes.\n");
		printf("2- Transportes.\n");
		printf("0- Volver.\n");
		
		fflush(stdin);
		scanf("%c", &op);
		printf("\n");
		fflush(stdin);
		
		switch(op){
			case '0':
				band=0;
				system("cls");
				printf("\n-------------------------------------------------------------------------------");
				puts("\n\t\t\t\tVolviendo al Menu.");
				printf("-------------------------------------------------------------------------------\n\n");
			break;
			
			case '1':
				system("cls");
				//Choferes				
				subMenuC();
			break;
			
			case '2':
				system("cls");
				//Transportes
				subMenuT();
			break;
			
			default:
				system("cls");
				printf("\n-------------------------------------------------------------------------------");
				puts("\n\t\t\tOpcion no valida, intente nuevo.");
				printf("-------------------------------------------------------------------------------\n\n");
		}
		
	}
}

void subMenuC(){
	
	char op;
	int band = 1;
	
	while(band != 0){
		
		printf("\n-------------------------------------------------------------------------------\n");
		printf("\t\t\t\tMENU Choferes\n");
		printf("-------------------------------------------------------------------------------\n");
		printf("1- Carga Choferes.\n");
		printf("2- Chofer con mas Pasajeros.\n");
		printf("0- Volver.\n");
		
		fflush(stdin);
		scanf("%c", &op);
		printf("\n");
		fflush(stdin);
		
		switch(op){
			case '0':
				band=0;
				system("cls");
				printf("\n-------------------------------------------------------------------------------");
				puts("\n\t\t\t\tVolviendo al Menu.");
				printf("-------------------------------------------------------------------------------\n\n");
			break;
			
			case '1':
				system("cls");			
				altaChofer(); //Carga Choferes				
			break;
			
			case '2':
				system("cls");
				//Chofer con mas Pasajeros
			break;
			
			/*
			case '3':
				system("cls");
				//Listado Choferes
			break;
			case '4':
				system("cls");
				//Modificar Choferes
			break;
			*/
			
			default:
				system("cls");
				printf("\n-------------------------------------------------------------------------------");
				puts("\n\t\t\tOpcion no valida, intente nuevo.");
				printf("-------------------------------------------------------------------------------\n\n");
		}
		
	}
	
}

void subMenuT(){
	
	char op;
	int band = 1;
	
	while(band != 0){
		
		printf("\n-------------------------------------------------------------------------------\n");
		printf("\t\t\t\tMENU Transportes\n");
		printf("-------------------------------------------------------------------------------\n");
		printf("1- Carga de Transportes.\n");
		printf("2- Porcentaje pasajeros primer turno anual.\n");
		printf("0- Volver.\n");
		
		fflush(stdin);
		scanf("%c", &op);
		printf("\n");
		fflush(stdin);
		
		switch(op){
			case '0':
				band=0;
				system("cls");
				printf("\n-------------------------------------------------------------------------------");
				puts("\n\t\t\t\tVolviendo al Menu.");
				printf("-------------------------------------------------------------------------------\n\n");
			break;
			
			case '1':
				system("cls");
				altaUnidad(); //Carga de Transportes
			break;
			
			case '2':
				system("cls");
				//pasajeros primer turno anual
			break;
			
			/*
			case '3':
				system("cls");
				//Listado Transportes
			break;
			
			case '4':
				system("cls");
				//Modificar Transportes
			break;
			*/
			
			default:
				system("cls");
				printf("\n-------------------------------------------------------------------------------");
				puts("\n\t\t\tOpcion no valida, intente nuevo.");
				printf("-------------------------------------------------------------------------------\n\n");
		}	
	}
}
