#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "structs.h"
#include "funciones.h"

void porcPasajeros();

main(){
	porcPasajeros();
}

void porcPasajeros(){
	FILE *arch;
	int c=0, contCondicion=0, a;
	float porc=0.00;
	a=obtenerTiempo('a');
	
	arch=fopen("movimientos.dat","rb");
	if(arch==NULL){
		printf("\nError al abrir el archivo movimientos.dat");
	}
	else{		
		fread(&movimiento,sizeof(movimiento),1,arch);
		while(!feof(arch)){
			if(movimiento.tFecha.anio == a)
			c++;
			if((movimiento.tHora.hora>=0) && (movimiento.tHora.hora<12)){
				if((movimiento.tHora.min>=0) && (movimiento.tHora.min<=59)){
					contCondicion++;
				}
			}
			fread(&movimiento,sizeof(movimiento),1,arch);
		}
	
		fclose(arch);	
	}
	/*c--------100%
	  cC-------x= (100*cC)/c */
	
	porc = (100*contCondicion)/c;


	printf("\nEl porcentaje de pasajeros que viajan en el primer turno del a%co actual\n",164);
	printf("Es de %.0f%% entre %d",porc,c);
}
