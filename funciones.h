#include <stdio.h>
#include <string.h>

void altaUsuario();
void beneficios();
void altaChofer();
void listaUsuarios();

void altaUsuario() {
	FILE *arch1, *arch2;
	int ultId=0, ultId2=0, idaux;
	long ultTarjeta=0, telAux=0;
	
	if((arch1=fopen("usuarios.dat","a+b"))!=NULL ){
		
		fread(&usuario, sizeof(usuario),1,arch1);
		while(!feof(arch1)){
			ultId = usuario.id;
			fread(&usuario, sizeof(usuario),1,arch1);
		}
		
		usuario.id = ultId + 1;
		idaux=usuario.id;
		
		fflush(stdin);
		printf("Ingrese su DNI.\n");
		scanf("%ld", &usuario.dni);
		fflush(stdin);
		printf("Ingrese su nombre y apellido.\n");
		gets(usuario.nomApe);
		fflush(stdin);
		printf("Ingrese su fecha de nacimiento.\n");
		printf("dia:\n");
		scanf("%d", &usuario.fecha.dia);
		fflush(stdin);
		printf("mes:\n");
		scanf("%d", &usuario.fecha.mes);
		fflush(stdin);
		printf("anio:\n");
		scanf("%d", &usuario.fecha.anio);
		fflush(stdin);
		printf("Ingrese su direccion.\n");
		gets(usuario.direccion);
		fflush(stdin);
		printf("Ingrese su numero de telefono.\n");
		scanf("%ld", &usuario.telefono);
		telAux=usuario.telefono;
		fflush(stdin);
		
		beneficios();
		
		fwrite(&usuario,sizeof(usuario),1,arch1);
			
		fclose(arch1);
		puts("usuario cargado exitosamente.");	
				
		
			if((arch2=fopen("cuentas.dat","a+b"))!=NULL){
				
				fread(&cuenta, sizeof(cuenta),1,arch2);
				while(!feof(arch2)){
					ultId2 = cuenta.id;
					ultTarjeta = cuenta.nroTarjeta;
					fread(&cuenta, sizeof(cuenta),1,arch2);
				}
				
				cuenta.id = ultId2 + 1;				
				cuenta.id_usuario=idaux;
				cuenta.saldo=0;
				cuenta.nroTarjeta = ultTarjeta + 1;
				cuenta.nroCel=telAux;
				
				fwrite(&cuenta,sizeof(cuenta),1,arch2);
				fclose(arch2);
				
			}
			else{
			printf("Error de apertura de archivo cuentas.dat");
			printf("\n");
			}		
	}
	else{
		printf("Error de apertura de archivo usuarios.dat");
		printf("\n");
	}

}

void beneficios() {
	
	char op;
	int band=0;
	
	printf("que tipo de sube desea?\n ");
	printf("ingrese 0 para sube normal.\n");
	printf("ingrese 1 para Boleto Estudiantil Gratuito.\n");
	printf("ingrese 2 para Beneficio por discapacidad.\n");
	printf("ingrese 3 para Beneficio de Mayor de Edad.\n");
	printf("ingrese 4 para Beneficio Ex-Combatiente de Malvinas.\n");
	
	scanf("%c", &op);
	fflush(stdin);
	
	switch(op) {
		
		
		case '0':
			strcpy(usuario.tipo,"normal");
		break;
		
		case '1':
			
			printf("posee Constancia de Inscripcion BEEG?\n");
			printf("ingrese 1 para si o 2 para no\n");
			scanf("%d", &band);
			
			if(band==1) {
				strcpy(usuario.tipo,"boleto estudiantil gratuito");
			}
			else if(band==2) {
				printf("no se puede computar el beneficio, debe preesentar la constancia.\n");	
			}
			
		break;
			
		case '2':
			
			printf("posee Certificado Unico de Discapacidad?\n");
			printf("ingrese 1 para si o 2 para no\n");
			scanf("%d", &band);
			
			if(band==1) {
				strcpy(usuario.tipo,"beneficio por discapacidad");
			}
			else if(band==2) {
				printf("no se puede computar el beneficio, debe preesentar la constancia.\n");	
			}
			
		break;
		
		case '3':
			
			printf("tiene 70 anios o mas?\n");
			printf("ingrese 1 para si o 2 para no\n");
			scanf("%d", &band);
			
			if(band==1) {
				strcpy(usuario.tipo,"beneficio de bayor de edad");
			}
			else if(band==2) {
				printf("no se puede computar el beneficio, debe tener la edad solicitada.\n");	
			}
			
		break;
			
		case '4':
			
			printf("posee Certificado de Ex-Combatiende?\n");
			printf("ingrese 1 para si o 2 para no\n");
			scanf("%d", &band);
			
			if(band==1) {
				strcpy(usuario.tipo,"beneficio ex-combatiente de malvinas");
			}
			else if(band==2) {
				printf("no se puede computar el beneficio, debe preesentar la constancia.\n");	
			}
						
		break;
			
		
		default:
			printf("\n-------------------------------------------------------------------------------");
			puts("\n\t\tOpcion no valida.");
			printf("-------------------------------------------------------------------------------\n\n");
		break;
	}
	
	
}


void altaChofer() {
	
	FILE *arch1;
	int ultId=0;
	
	if((arch1=fopen("choferes.dat","a+b"))!=NULL ){
		
		fread(&chofer, sizeof(chofer),1,arch1);
		while(!feof(arch1)){
			ultId = chofer.id;
			fread(&chofer, sizeof(chofer),1,arch1);
		}
		
		chofer.id = ultId + 1;
		
		fflush(stdin);
		printf("Ingrese su DNI.\n");
		scanf("%ld", &chofer.dni);
		fflush(stdin);
		printf("Ingrese su nombre y apellido.\n");
		gets(chofer.nomApe);
		fflush(stdin);
		printf("Ingrese su fecha de nacimiento.\n");
		printf("dia:\n");
		scanf("%d", &chofer.nacimiento.dia);
		fflush(stdin);
		printf("mes:\n");
		scanf("%d", &chofer.nacimiento.anio);
		fflush(stdin);
		printf("anio:\n");
		scanf("%d", &chofer.nacimiento.dia);
		fflush(stdin);
		printf("Ingrese su direccion.\n");
		gets(chofer.direccion);
		fflush(stdin);
		printf("Ingrese su numero de telefono.\n");
		scanf("%ld", &chofer.telefono);
		fflush(stdin);
		printf("Ingrese su correo electronico.\n");
		gets(chofer.correo);
		fflush(stdin);
		
		fwrite(&chofer,sizeof(chofer),1,arch1);
			
		fclose(arch1);
		puts("chofer cargado exitosamente.");
				
	}
	else{
		printf("Error de apertura de archivo usuarios.dat");
		printf("\n");
	}

}

void listaUsuarios() {
	
	FILE *arch;
	
	arch=fopen("usuarios.dat","rb");
	if(arch==NULL){
		printf("\nError al crear el archivo clase.bin");
		
	}
	else{
		fread(&usuario, sizeof(usuario),1,arch);
		
		while(!feof(arch)){

			printf("\nID: %d",usuario.id);
			printf("\nDNI: %ld", usuario.dni);
			printf("\nNombre: ");
			puts(usuario.nomApe);
			printf("fecha nacimiento: ");
			printf("%d/", usuario.fecha.dia);
			printf("%d/", usuario.fecha.mes);
			printf("%d", usuario.fecha.anio);
			printf("\ndireccion: ");
			puts(usuario.direccion);
			printf("telefono: %ld",usuario.telefono);
			printf("\ntipo usuario: ");
			puts(usuario.tipo);
			printf("\n----------------");	
				
				
			fread(&usuario, sizeof(usuario),1,arch);
		}
		
		fclose(arch);
		
	}
				
			
}
