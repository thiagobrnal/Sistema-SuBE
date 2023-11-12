#include <stdio.h>
#include <string.h>

struct fech {
	int dia, mes, anio;
};

struct datChoferes {
	int id;
	long dni, telefono;
	char nomApe[30], direccion[40], correo[30];	
	struct fech nacimiento;
}chofer;

struct datTransporte{
	int id, numUnidad, canAsientos, km;
	char marca[20], modelo[20], discapacitados[20];
	struct fech alta; 
}unidad;

struct datAsignaciones{
	int id, id_unidad, id_chofer, turno;
	long dni_chofer;
}asignacion;

main() {
	
	FILE *arch;
	
	arch=fopen("asignaciones.dat","rb");
	if(arch==NULL){
		printf("\nError al crear el archivo clase.bin");
		return 0;
	}
	else{		
		fread(&asignacion, sizeof(asignacion),1,arch);
		while(!feof(arch)){

			printf("\nID: %d",asignacion.id);			
			printf("\nID unidad: %d",asignacion.id_unidad);			
			printf("\nID chofer: %d",asignacion.id_chofer);
			printf("\nDNI chofer: %ld",asignacion.dni_chofer);
			
			if (asignacion.turno == 1) {
				printf("\nTurno 1: 00:00hs a 11:59");
			}
			else {
				printf("\nTurno 2: 12:00 a 23:59hs");				
			}									
			printf("\n----------------");	
				
				
			fread(&asignacion, sizeof(asignacion),1,arch);
		}
	
		fclose(arch);	
	}
			
	
		
	
}
