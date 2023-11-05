#include <stdio.h>
#include <string.h>

void altaUsuario();
void beneficios();
void altaChofer();
void listaUsuarios();
int obtenerTiempo(char);
void cargaSaldo();
void bocaP(char x);

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
	
	printf("\nQue tipo de sube desea?\n ");
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
			
			printf("Posee Constancia de Inscripcion BEEG?\n");
			printf("Ingrese 1 para si o 2 para no\n");
			scanf("%d", &band);
			
			if(band==1) {
				strcpy(usuario.tipo,"boleto estudiantil gratuito");
			}
			else if(band==2) {
				printf("No se puede computar el beneficio, debe preesentar la constancia.\n");	
			}
			
		break;
			
		case '2':
			
			printf("Posee Certificado Unico de Discapacidad?\n");
			printf("ingrese 1 para si o 2 para no\n");
			scanf("%d", &band);
			
			if(band==1) {
				strcpy(usuario.tipo,"beneficio por discapacidad");
			}
			else if(band==2) {
				printf("No se puede computar el beneficio, debe preesentar la constancia.\n");	
			}
			
		break;
		
		case '3':
			
			printf("tiene 70 anios o mas?\n");
			printf("ingrese 1 para si o 2 para no\n");
			scanf("%d", &band);
			
			if(band==1) {
				strcpy(usuario.tipo,"beneficio de mayor de edad");
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

void listarCuentas(){
	
	FILE *arch;
	arch=fopen("cuentas.dat","rb");
	if(arch==NULL){
		printf("\nError al abrir el archivo cuentas.dat");
	}
	else{
		fread(&cuenta, sizeof(cuenta),1,arch);
		
		while(!feof(arch)){

			printf("\nID: %d",cuenta.id);
			printf("\nIdUser: %d",cuenta.id_usuario);
			printf("\nnroTarjeta: %ld", cuenta.nroTarjeta);
			printf("\nnroCel: %ld", cuenta.nroCel);
			printf("\nSaldo: %.2f",cuenta.saldo);
			printf("\n----------------");	
				
				
			fread(&cuenta, sizeof(cuenta),1,arch);
		}
		
	}
			
	fclose(arch);
	
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


int obtenerTiempo(char mensajero){
	
	int hours, minutes, seconds, day, month, year;
 
    // `time_t` es un tipo de tiempo aritm�tico
    time_t now;
 
    // Obtener la hora actual
    // `time()` devuelve la hora actual del sistema como un valor `time_t`
    time(&now);

 
    // localtime convierte un valor de `time_t` a la hora del calendario y
    // devuelve un puntero a una estructura `tm` con sus miembros
    // rellenado con los valores correspondientes
    struct tm *local = localtime(&now);
 
    hours = local->tm_hour;         // obtener horas desde la medianoche (0-23)
    minutes = local->tm_min;        // obtener minutos pasados despu�s de la hora (0-59)
 
    day = local->tm_mday;            // obtener el d�a del mes (1 a 31)
    month = local->tm_mon + 1;      // obtener el mes del a�o (0 a 11)
    year = local->tm_year + 1900;   // obtener el a�o desde 1900
    
    //HORA
    if(mensajero == 'h'){
    	return hours;
	}
	//MINUTOS
	if(mensajero == 's'){
		return minutes;
	}
	//DIA
	if(mensajero == 'd'){
		return day;
	}
	//MES
	if(mensajero == 'm'){
		return month;
	}
	//A�O
	if(mensajero == 'a'){
		return year;
	}
	
}

void cargaSaldo(){
	
	FILE *arch, *arch1, *arch2, *aText;
	int ultId=0, encontro=0, idAux, band = 0;
	long nroControl = 9000;
	char bocaPago, nroC[30];;
	long dniAux, tarjetaAux;
	float monto, montoAnt;
	
	
	puts("Ingrese su DNI: ");
	scanf("%ld", &dniAux);
	fflush(stdin);
	
	
	arch = fopen("usuarios.dat","r+b");
	if(arch==NULL){
		printf("Error de apertura de archivo usuarios.dat");
		printf("\n");
	}else{
		fread(&usuario, sizeof(usuario),1,arch);
		
		while((!feof(arch))&&(encontro == 0)){

			if(dniAux == usuario.dni){
				encontro=1;
				idAux = usuario.id;
			}else{
				fread(&usuario, sizeof(usuario),1,arch);
			}

		}
		fclose(arch);
		
		
		if(encontro==0){
			puts("No se encontro el DNI");
		}else if(encontro == 1){
			
			//Falta testear
		//	do{
				puts("Ingrese Boca de Pago:");
				puts("1.electronico");
				puts("2.rapipago/pagofacil"); 
				puts("3.Tienda");
				puts("4.Sucursal");
				scanf("%c",&bocaPago);
				fflush(stdin);
		//	}while(!(strncmp("1234",bocaPago,1)));
			
		
			puts("Ingrese monto:");
			scanf("%f", &monto);
			fflush(stdin);
			
			arch1 = fopen("cuentas.dat","r+b");
			if(arch1==NULL){
				printf("Error de apertura de archivo cuentas.dat");
				printf("\n");
			}else{
				fread(&cuenta,sizeof(cuenta),1,arch1);
				while((!feof(arch1))&&(band == 0)){
					
					if(idAux==cuenta.id_usuario){
						
						montoAnt = cuenta.saldo;
						monto += cuenta.saldo;
						cuenta.saldo = monto;
						fseek(arch1,sizeof(cuenta)*(-1),SEEK_CUR);
						fwrite(&cuenta,sizeof(cuenta),1,arch1);
						band = 1;
						fclose(arch1);
					}else{
						fread(&cuenta,sizeof(cuenta),1,arch1);
					}
					
				}
				if(band == 1){
					
						arch2 = fopen("cargas.dat","a+b");
						if(arch2==NULL){
							printf("Error de apertura de archivo cuentas.dat");
							printf("\n");
						}else{
							fread(&carga,sizeof(carga),1,arch2);
							while(!feof(arch2)){
								ultId = carga.id;
								nroControl = carga.nroControl;
								fread(&carga,sizeof(carga),1,arch2);
							}
							
							carga.id = ultId + 1;
							carga.id_usuario = idAux;
							carga.dni_usuario = dniAux;
							carga.nroControl = nroControl + 1;
							bocaP(bocaPago);
							carga.tFecha.dia = obtenerTiempo('d');
							carga.tFecha.mes = obtenerTiempo('m');
							carga.tFecha.anio = obtenerTiempo('a');
							carga.tHora.hora = obtenerTiempo('h');
							carga.tHora.min = obtenerTiempo('s');
							
							fwrite(&carga,sizeof(carga),1,arch2);
							
							sprintf(nroC,"%ld_ticket.txt", carga.nroControl);
							if((aText=fopen(nroC,"w"))!=NULL){
								fprintf(aText,"Nro Tarjeta: %ld\n", carga.nroControl);
								fprintf(aText,"Saldo Anterior: %.2f\n", montoAnt);
								fprintf(aText,"Saldo Actual: %.2f\n", monto);
								fprintf(aText,"Fecha: %d/%d/%d\n", carga.tFecha.dia,carga.tFecha.mes,carga.tFecha.anio);
								fprintf(aText,"Hora: %d:%d\n", carga.tHora.hora,carga.tHora.min);
								fclose(aText);
							}else{
								puts("Error al crear el ticket");
							}							
							
							
							fclose(arch2);
							
							
						}
						puts("Saldo cargado exitosamente");
					}
			}
			fclose(arch1);
		}
	}
	fclose(arch);
}

void bocaP(char x){
	switch(x){
		case '1':
			strcpy(carga.bocaPago,"electronico");
		break;
		case '2':
			strcpy(carga.bocaPago,"rapipago/pagofacil");
		break;
		case '3':
			strcpy(carga.bocaPago,"tienda");
		break;
		case '4':
			strcpy(carga.bocaPago,"sucursal");
		break;
		
	}
	
}
