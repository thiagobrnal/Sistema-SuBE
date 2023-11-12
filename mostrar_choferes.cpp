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

main() {
	
	FILE *arch;
	
	arch=fopen("choferes.dat","rb");
	if(arch==NULL){
		printf("\nError al crear el archivo clase.bin");
		return 0;
	}
	else{
		fread(&chofer, sizeof(chofer),1,arch);
		
		while(!feof(arch)){

			printf("\nID: %d",chofer.id);
			printf("\nDNI: %ld", chofer.dni);
			printf("\nNombre: ");
			puts(chofer.nomApe);
			printf("fecha nacimiento: ");
			printf("%d/", chofer.nacimiento.dia);
			printf("%d/", chofer.nacimiento.mes);
			printf("%d/", chofer.nacimiento.anio);
			printf("\ndireccion: ");
			puts(chofer.direccion);
			printf("telefono: %ld",chofer.telefono);
			printf("\ncorreo: ");
			puts(chofer.correo);
			printf("\n----------------");	
				
				
			fread(&chofer, sizeof(chofer),1,arch);
		}
	
		fclose(arch);	
	}
			
	
		
	
}
