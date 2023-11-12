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
	
	arch=fopen("unidades.dat","rb");
	if(arch==NULL){
		printf("\nError al crear el archivo clase.bin");
		return 0;
	}
	else{		
		fread(&unidad, sizeof(unidad),1,arch);
		while(!feof(arch)){

			printf("\nID: %d",unidad.id);
			printf("\nnumero unidad: %d", unidad.numUnidad);
			printf("\nMarca: ");
			puts(unidad.marca);
			printf("\nModelo: ");
			puts(unidad.modelo);
			printf("\nasientos: %d", unidad.canAsientos);
			printf("\nkm: %d", unidad.km);									
			printf("fecha alta: ");
			printf("%d/", unidad.alta.dia);
			printf("%d/", unidad.alta.mes);
			printf("%d\n", unidad.alta.anio);
			puts(unidad.discapacitados);
								
			printf("\n----------------");	
				
				
			fread(&unidad, sizeof(unidad),1,arch);
		}
	
		fclose(arch);	
	}
			
	
		
	
}
