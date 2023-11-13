#include <stdio.h>
#include <string.h>

void altaUsuario();
void beneficios();
void listarCuentas();
void altaChofer();
void listaUsuarios();
int obtenerTiempo(char);
void cargaSaldo();
void bocaP(char x);
void altaUnidad();
void asignaciones(int, int);
int tipoUsos();
void usoTarjetaoBV();
float tarifaUbicacion(char, char);
void RecargasConDNI();
int fechaEstaEntre(struct fech, struct fech, struct fech);
int compararFechas(struct fech, struct fech);
void verMovimientosEntreFechas();
void verMovimientosDeUsuarios();
char elegirOD();
void cantidadBeneficios();
void consultaSaldo();
void porcPasajeros();

//test
void mostar_choferes();
void mostrar_unidades();
void mostrar_asignaciones();
void mostrar_movimientos();

void altaUsuario() {
	FILE *arch1, *arch2;
	int ultId=0, ultId2=0, idaux;
	long ultTarjeta=0, telAux=0, dniAux=0;
	
	printf("Ingrese su DNI o 0 para volver.\n");
	scanf("%ld", &dniAux);
	fflush(stdin);
	if(dniAux != 0){
		if((arch1=fopen("usuarios.dat","a+b"))!=NULL ){
		
		fread(&usuario, sizeof(usuario),1,arch1);
		while(!feof(arch1)){
			ultId = usuario.id;
			fread(&usuario, sizeof(usuario),1,arch1);
		}
		
		usuario.id = ultId + 1;
		idaux=usuario.id;
		
		fflush(stdin);
		usuario.dni = dniAux;
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
		scanf("%d", &chofer.nacimiento.mes);
		fflush(stdin);
		printf("anio:\n");
		scanf("%d", &chofer.nacimiento.anio);
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
	
	int hours, minutes, seconds, day, month, year,dia;
 
    // `time_t` es un tipo de tiempo aritmético
    time_t now;
 
    // Obtener la hora actual
    // `time()` devuelve la hora actual del sistema como un valor `time_t`
    time(&now);

 
    // localtime convierte un valor de `time_t` a la hora del calendario y
    // devuelve un puntero a una estructura `tm` con sus miembros
    // rellenado con los valores correspondientes
    struct tm *local = localtime(&now);
 
    hours = local->tm_hour;         // obtener horas desde la medianoche (0-23)
    minutes = local->tm_min;        // obtener minutos pasados después de la hora (0-59)
 
    day = local->tm_mday;            // obtener el día del mes (1 a 31)
    month = local->tm_mon + 1;      // obtener el mes del año (0 a 11)
    year = local->tm_year + 1900;   // obtener el año desde 1900
    
    dia = local->tm_wday;
    
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
	//AÑO
	if(mensajero == 'a'){
		return year;
	}
	//QUE DIA ES COMO ENTERO del 0 al 6
	if(mensajero == 'x'){
		return dia;
	}
	
	
}

void cargaSaldo(){
	
	FILE *arch, *arch1, *arch2, *aText;
	int ultId=0, encontro=0, idAux, band = 0, band1=0;
	long nroControl = 5000;
	char bocaPago, nroC[30];
	long dniAux, tarjetaAux;
	float monto, montoAnt, aux;
	
	
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
			do{
				puts("Ingrese Boca de Pago:");
				puts("1.electronico");
				puts("2.rapipago/pagofacil"); 
				puts("3.Tienda");
				puts("4.Sucursal");
				scanf("%c",&bocaPago);
				fflush(stdin);
				if((bocaPago=='1') || (bocaPago=='2') || (bocaPago=='3') || (bocaPago=='4')){
					band1=1;
				}
			}while(band1==0);
			
		
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
						
						tarjetaAux = cuenta.nroTarjeta;
						montoAnt = cuenta.saldo;
						aux = monto;
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
							carga.monto = aux;
							bocaP(bocaPago);							
							carga.tFecha.dia = obtenerTiempo('d');
							carga.tFecha.mes = obtenerTiempo('m');
							carga.tFecha.anio = obtenerTiempo('a');
							carga.tHora.hora = obtenerTiempo('h');
							carga.tHora.min = obtenerTiempo('s');
							
							fwrite(&carga,sizeof(carga),1,arch2);
							
							sprintf(nroC,"%ld_ticket.txt", carga.nroControl);
							if((aText=fopen(nroC,"w"))!=NULL){
								fprintf(aText,"REMITO N° %ld\n",carga.nroControl);
								fprintf(aText, "Nro Tarjeta: %ld\n", tarjetaAux);
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

void altaUnidad() {
	FILE *arch;
	int ultId=0, opc=0, numU=0, encontro=0, idAux=0, opCorrecta=0;
	
	fflush(stdin);
	printf("Ingrese numero de unidad: ");
	scanf("%d", &numU);
	fflush(stdin);
	
	arch=fopen("unidades.dat","a+b");
	if(arch==NULL){
		printf("\nError al abrir el archivo unidades.dat");
	}
	else{
		
		fread(&unidad,sizeof(unidad),1,arch);
	
		while((!feof(arch))&&(encontro==0)){
			
			if(numU==unidad.numUnidad) {
				encontro=1;							
			}
			if (encontro==0){
			fread(&unidad,sizeof(unidad),1,arch);
			}					
		}
				
			if(encontro==1){
				fseek(arch,sizeof(unidad)*(-1),SEEK_CUR);

				idAux = unidad.id;
				fclose(arch);
			}									
			else{
				rewind(arch);
				while(!feof(arch)){
				ultId = unidad.id;
				fread(&unidad, sizeof(unidad),1,arch);
				}
				unidad.id = ultId + 1;
				idAux=unidad.id;
				
				unidad.numUnidad=numU;
				fflush(stdin);				
				printf("\nIngrese la marca: ");
				gets(unidad.marca);
				fflush(stdin);
				printf("\nIngrese el modelo: ");
				gets(unidad.modelo);
				fflush(stdin);
				printf("\nIngrese la cantidad de asientos: ");
				scanf("%d", &unidad.canAsientos);
				fflush(stdin);
				printf("\nIngrese el kilometraje: ");
				scanf("%d", &unidad.km);
				fflush(stdin);
				unidad.alta.dia = obtenerTiempo('d');
				unidad.alta.mes = obtenerTiempo('m');
				unidad.alta.anio = obtenerTiempo('a');				
				printf("\nApto para pasajeros discapacitados?, ingrese 1 para si, 2 para no: ");
				scanf("%d", &opc);
				fflush(stdin);
				
				if((opc!=1) && (opc!=2)) {
					while(opCorrecta==0) {
						printf("\nOpcion incorrecta, intente de nuevo: ");
						scanf("%d", &opc);
						fflush(stdin);
						
						if((opc==1) || opc==2){
							opCorrecta=1;
						}																
					}
				}
				
				if(opc==1){
					strcpy(unidad.discapacitados, "Apto");
				}else if(opc==2){
					strcpy(unidad.discapacitados, "No apto");
				}
						
				fwrite(&unidad,sizeof(unidad),1,arch);
				fclose(arch);				
								
			}
			
			asignaciones(idAux, numU);	
	}
		
}

void asignaciones(int idUnidad, int nUni){
	
	FILE *arch1, *arch2;
	int c=0, encontro1=0, encontro2=0, ultId2=0, turnoAux=0, idAuxChofer=0;
	int opCorrecta2=0, opc2=0, encontro3=0;
	long dniAux=0, telAux=0;
	
	arch1=fopen("asignaciones.dat","a+b");
	if(arch1==NULL){
		printf("\nError al abrir el archivo unidades.dat");
	}
	else{
		rewind(arch1);
		fread(&asignacion,sizeof(asignacion),1,arch1);
		
		while((!feof(arch1)) && (encontro1==0)){			
			if(idUnidad==asignacion.id_unidad) {
				c++;
				turnoAux=asignacion.turno;
			}
			if (encontro1==0){
			fread(&asignacion,sizeof(asignacion),1,arch1);
			}	
		}	
		
		if(c==2){
			printf("\nLa linea %d ya tiene 2 turnos cargados", nUni);
			
		}
		else if((c==0) || (c==1)){
			printf("\nIngrese el DNI del chofer a asignar: ");
			scanf("%ld", &dniAux);
			fflush(stdin);
			
			printf("\nIngrese su numero de telefono: ");
			scanf("%ld", &telAux);
			fflush(stdin);
						
			arch2=fopen("choferes.dat","a+b");
			if(arch2==NULL){
				printf("\nError al abrir el archivo choferes.dat");
			}
			else{
				fread(&chofer,sizeof(chofer),1,arch2);
	
				while((!feof(arch2))&&(encontro2==0)){
												
					if((dniAux==chofer.dni) && (telAux==chofer.telefono)) {
						encontro2=1;
						idAuxChofer=chofer.id;					
					}
					if (encontro2==0){
					fread(&chofer,sizeof(chofer),1,arch2);
					}			
				}
				
				fclose(arch2);
				
				if(encontro2==0){
					printf("\nEl DNI ingresado no se encuentra en la base de datos");
					fclose(arch2);						
				}
				else{										
					rewind(arch1);
					fread(&asignacion, sizeof(asignacion),1,arch1);	
									
					while((!feof(arch1))&&(encontro3==0)){
						if(idAuxChofer==asignacion.id_chofer){
							encontro3=1;											
						}
						if (encontro3==0){
						fread(&asignacion,sizeof(asignacion),1,arch1);
						}
					}
			
					if(encontro3==1){
						printf("\nEste chofer ya tiene asignado un turno");				
					}
					else{
						rewind(arch1);
						fread(&asignacion, sizeof(asignacion),1,arch1);
						while(!feof(arch1)){
						ultId2 = asignacion.id;
						fread(&asignacion, sizeof(asignacion),1,arch1);
						}
						
						asignacion.id = ultId2 + 1;
						asignacion.id_unidad = idUnidad;
						asignacion.id_chofer = idAuxChofer;
						asignacion.dni_chofer = dniAux;
							
						if(c==1){							
							if(turnoAux==1){
								asignacion.turno=2;	
								printf("Turno 2 asignado con exito");
							}
							else if(turnoAux==2){
								asignacion.turno=1;
								printf("Turno 1 asignado con exito");	
								
							}							
						}
						else if(c==0) {
							printf("\nIngrese 1 o 2 segun el turno que desea asignar");
							printf("\nTurno 1: 00:00hs a 11:59 o Turno 2: 12:00 a 23:59hs: ");
							scanf("%d", &opc2);
							fflush(stdin);
							
							if((opc2!=1) && (opc2!=2)) {
								while(opCorrecta2==0) {
									printf("\nOpcion incorrecta, intente de nuevo: ");
									scanf("%d", &opc2);
									fflush(stdin);
						
									if((opc2==1) || (opc2==2)){
										asignacion.turno=opc2;									
										printf("\nTurno %d asignado correctamente", opc2);
										opCorrecta2=1;
									}																
								}
							}
							else {
								asignacion.turno=opc2;
								printf("\nTurno %d asignado correctamente", opc2);
							}							
						}
					}																															
				}		
			}			
		}
				
		fwrite(&asignacion,sizeof(asignacion),1,arch1);
		fclose(arch1);
						
	}
}

int tipoUsos(){
	
	int op = 0;
	int band = 0;
	
	do{
		
		printf("\nEliga con que va a pagar el viaje:\n");
		printf("1- SUBE.\n");
		printf("2- Billetera electronica.\n");
		
		fflush(stdin);
		scanf("%d", &op);
		fflush(stdin);
		
		if((op == 1) || (op == 2)){
			band = 1;
		}else{
			system("cls");
			printf("\n-------------------------------------------------------------------------------");
			puts("\n\t\t\tOpcion no valida, intente nuevo.");
			printf("-------------------------------------------------------------------------------\n\n");
		}

	}while(band != 1);
	return op;
}

float tarifaUbicacion(char origen, char destino){
	
	float precio = 0;
	
	if(origen == 'p'){
		if(destino == 'p'){
			precio = 130.00;
		}else if(destino == 'g'){
			precio = 169.00;
		}else if(destino == 'c'){
			precio = 197.60;
		}	
	}

	if(origen == 'g'){
		if(destino == 'p'){
			precio = 169.00;
		}else if(destino == 'g'){
			precio = 139.28;
		}else if(destino == 'c'){
			precio = 220.60;
		}	
	}	
	
	if(origen == 'c'){
		if(destino == 'p'){
			precio = 197.60;
		}else if(destino == 'g'){
			precio = 220.00;
		}else if(destino == 'c'){
			precio = 139.28;
		}	
	}
		
	return precio;

}

void usoTarjetaoBV(){
	
	FILE *arch1, *arch2, *arch3, *arch4;
	int ultId = 0, encontro = 0, idAux, tipo, numUnidadAux, encontro2 = 0;
	long dniAux;
	int band1 = 0, band2 = 0, dia, hora, min, x;
	char orig[25], dest[25], daux, oaux, beneficioAux[50];
	float precio = 0, saldoAux;
	
	printf("\nIngrese su DNI:");
	scanf("%ld", &dniAux);
	fflush(stdin);
	
	arch1 = fopen("usuarios.dat","a+b");
	if(arch1 == NULL){
		puts("No se pudo abrir el archivo usuarios.dat");
	}else{
		
		fread(&usuario, sizeof(usuario),1,arch1);
		while((!feof(arch1))&&(encontro == 0)){
			if(dniAux == usuario.dni){
				encontro = 1;
				idAux = usuario.id;
				strcpy(beneficioAux,usuario.tipo); //BENEFICIO
			}
			if(encontro == 0){
				fread(&usuario, sizeof(usuario),1,arch1);	
			}
		}
		fclose(arch1);
		
		if(encontro == 0){
			puts("El usuario no existe en la bd");
		}else if(encontro == 1){
			tipo = tipoUsos();
			printf("Ingrese el Nro del colectivo:");
			scanf("%d", &numUnidadAux);
			
			arch4 = fopen("unidades.dat","a+b");
			if(arch4 == NULL){
				puts("No se pudo abrir el archivo unidades.dat");
			}else{
				rewind(arch4);
				fread(&unidad, sizeof(unidad),1,arch4);
				while((!feof(arch4))&&(encontro2 == 0)){
					
					if(numUnidadAux == unidad.numUnidad){
						encontro2 = 1;
					}
					
					if(encontro2 == 0){
						fread(&unidad, sizeof(unidad),1,arch4);
					}
				}
				fclose(arch4);
				
				if(encontro2 == 0){
					puts("La unidad ingresada no existe");
				}
				if(encontro2 == 1){
					
					printf("\nIngrese el origen del viaje");
					oaux = elegirOD();
					printf("\nIngrese el destino del viaje");
					daux = elegirOD();
					
					if(oaux == 'p'){
						strcpy(orig,"Posadas");
					}else if(oaux == 'g'){
						strcpy(orig,"Garupa");
					}else if(oaux == 'c'){
						strcpy(orig,"Candelaria");
					}
					if(daux == 'p'){
						strcpy(dest,"Posadas");
					}else if(daux == 'g'){
						strcpy(dest,"Garupa");
					}else if(daux == 'c'){
						strcpy(dest,"Candelaria");
					}
					
					dia = obtenerTiempo('x');
					hora = obtenerTiempo('h');
					min = obtenerTiempo('s');
						
					if(hora >=5 && (hora<=21 && min < 59)){
						precio = 0.00;	
					}	
						
					if((x == 0) || (x == 1) || (strcmp(beneficioAux,"normal")==0)){
						precio = tarifaUbicacion(oaux,daux);				
					}
					
					
					
					arch2 = fopen("cuentas.dat","r+b");
					if(arch2 == NULL){
						puts("No se pudo abrir el archivo cuentas.dat");
					}else{
							fread(&cuenta,sizeof(cuenta),1,arch2);
							while((!feof(arch2))&&(band2 == 0)){
								if(idAux == cuenta.id_usuario){
									saldoAux = cuenta.saldo; 
									band2 = 1;
								}
								if(band2 == 0){
									fread(&cuenta,sizeof(cuenta),1,arch2);
								}
								
							}
							if(band2 == 1){
								if(saldoAux<precio){
									puts("No posee saldo para este viaje");
									printf("\nSaldo: %.2f",saldoAux);
								}else{
									saldoAux = saldoAux - precio;
									cuenta.saldo = saldoAux;
									fseek(arch2,sizeof(cuenta)*(-1),SEEK_CUR);
									fwrite(&cuenta,sizeof(cuenta),1,arch2);
									
									arch3 = fopen("movimientos.dat", "a+b");
									if(arch3 == NULL){
										puts("No se pudo abrir el archivo movimientos.dat");
									}else{
										fread(&movimiento,sizeof(movimiento),1,arch3);
									while(!feof(arch3)){
										ultId = movimiento.id;
										fread(&movimiento,sizeof(movimiento),1,arch3);
									}
									
									
								
									movimiento.id = ultId + 1;
									movimiento.id_usuario = idAux;
									movimiento.dni_usuario = dniAux;
									movimiento.tipo = tipo;
									movimiento.nroUnidad = numUnidadAux;
									strcpy(movimiento.origen,orig);
									strcpy(movimiento.destino,dest);
									movimiento.saldoUtl = precio;
									movimiento.tFecha.dia = obtenerTiempo('d');
									movimiento.tFecha.mes = obtenerTiempo('m');
									movimiento.tFecha.anio = obtenerTiempo('a');
									movimiento.tHora.hora = obtenerTiempo('h');
									movimiento.tHora.min = obtenerTiempo('s');
									fwrite(&movimiento,sizeof(movimiento),1,arch3);
									fclose(arch3);
									
									printf("\nCobro: %.2f", precio);
									printf("\nSaldo Act: %.2f",saldoAux);
									
									}
								}
							}
							fclose(arch2);

					}
					
				}
			}
		}

		
	}
	
}

void RecargasConDNI() {
	
	FILE *arch1, *arch2;
	int ultId, idAux,encontro1=0, encontro2=0;
	long dniAux, telAux;
	
	printf("Ingrese su DNI y numero de telefono. ");
	printf("\nDNI: ");
	scanf("%ld", &dniAux);
	fflush(stdin);
	
	printf("\nTelefono: ");
	scanf("%ld", &telAux);
	fflush(stdin);
			
	arch1 = fopen("usuarios.dat","r+b");
	if(arch1==NULL){
		printf("Error de apertura de archivo usuarios.dat");
		printf("\n");
	}else{		
			
		fread(&usuario, sizeof(usuario),1,arch1);
		
		while((!feof(arch1))&&(encontro1 == 0)){

			if((dniAux == usuario.dni)&& (telAux==usuario.telefono)){
				encontro1=1;
				idAux = usuario.id;
			}else{
				fread(&usuario, sizeof(usuario),1,arch1);
			}
		}
		fclose(arch1);
		
		if(encontro1==0){
			printf("\nNo se encuentra el usuario registrado");
		}else if(encontro1==1){
					
			arch2 = fopen("cargas.dat","r+b");
			if(arch2==NULL){
				printf("Error de apertura de archivo cargas.dat");
				printf("\n");
			}else{
				fread(&carga,sizeof(carga),1,arch2);
				
				while(!feof(arch2)){			
					
					if(idAux==carga.id_usuario){
						encontro2=1;
						
						printf("\n\nDNI usuario: %ld",carga.dni_usuario);
						printf("\nNumero de control: %ld",carga.nroControl);
						printf("\nMonto: %.2f",carga.monto);
						printf("\nBoca de pago: ");
						puts(carga.bocaPago);
						printf("Fecha y hora de pago: ");
						printf("\n%d/", carga.tFecha.dia);
						printf("%d/", carga.tFecha.mes);
						printf("%d", carga.tFecha.anio);
						printf(" - %d:%d hs.", carga.tHora.hora, carga.tHora.min);
																														
					}	
					fread(&carga,sizeof(carga),1,arch2);		
				}
				
					fclose(arch2);
					
					if(encontro2==0){
						printf("\nNo se encuentran regargas de este usuario");
					}
			}
		}						
	}		
}

void verMovimientosDeUsuarios(){
	FILE *arch, *arch2;
	int idAux, encontro = 0, band = 0;
	char nomAp[30], nomApe2[30];
	
	puts("Ingrese Nombre y Apellido de la persona a buscar: ");
	gets(nomAp);
	strlwr(nomAp);
	
	arch2=fopen("usuarios.dat", "rb");
	if(arch2==NULL){
		printf("\nError al abrir el archivo usuarios.dat");
	}else{
		
		fread(&usuario, sizeof(usuario),1,arch2);
		while((!feof(arch2)) && (encontro == 0)){
			
			strcpy(nomApe2,usuario.nomApe);
			strlwr(nomApe2);
			
			if(strcmp(nomAp,nomApe2)==0){
				idAux = usuario.id;
				encontro = 1;	
			}
			if(encontro==0){
				fread(&usuario, sizeof(usuario),1,arch2);
			}
		}
		fclose(arch2);
	}
	
	if(encontro==0){
		puts("No se encontro al usuario ingresado.");
	}else{
		arch=fopen("movimientos.dat","rb");
	if(arch==NULL){
		printf("\nError al abrir el archivo movimientos.dat");
	}
	else{		
		fread(&movimiento,sizeof(movimiento),1,arch);
		while(!feof(arch)){
			
			if(movimiento.id_usuario == idAux){
				band = 1;
				printf("\nNro Unidad: %d", movimiento.nroUnidad);
				printf("\nOrigen: ");
				puts(movimiento.origen);
				printf("Destino: ");
				puts(movimiento.destino);
				printf("DNI usuario: %ld", movimiento.dni_usuario);
				if(movimiento.tipo == 1){
					printf("\nTipo: SUBE");
				}else{
					printf("\nTipo: Billetera Virtual");
				}
				printf("\nSaldo Utilizado: %.2f", movimiento.saldoUtl);
				printf("\nFecha: %d/%d/%d",	movimiento.tFecha.dia,movimiento.tFecha.mes,movimiento.tFecha.anio);
				printf("\nHora: %d:%d",	movimiento.tHora.hora,movimiento.tHora.min);				
				printf("\n----------------");		
			}
			
				
			fread(&movimiento,sizeof(movimiento),1,arch);
		}
	
		fclose(arch);	
		if(band == 0){
			puts("El usuario todavia no posee movimientos.");
		}
	}
	}
	
}

void verMovimientosEntreFechas(){
	struct fech fechaInicio, fechaFin;
	int band = 0, c = 0;
	char opcion;
	do{
		printf("\nIngrese la fecha de inicio con numeros.");
		printf("\nDia:");
		scanf("%d", &fechaInicio.dia);
		printf("Mes:");
		scanf("%d", &fechaInicio.mes);
		printf("A%co:", 164);
		scanf("%d", &fechaInicio.anio);
		printf("\nIngrese la fecha de final con numeros.");
		printf("\nDia:");
		scanf("%d", &fechaFin.dia);
		printf("Mes:");
		scanf("%d", &fechaFin.mes);
		printf("A%co:", 164);
		scanf("%d", &fechaFin.anio);
		
		fflush(stdin);
		
		printf("\nFecha de Inicio: %d/%d/%d",fechaInicio.dia,fechaInicio.mes,fechaInicio.anio);
		printf("\nFecha de Fin: %d/%d/%d",fechaFin.dia,fechaFin.mes,fechaFin.anio);
		printf("\n----------------------");
		printf("\nEsto es correcto? s/n");
		printf("\n----------------------\n");
		scanf("%c", &opcion);
		fflush(stdin);
		
		if(opcion == 's'){
			band= 1;
		}
	}while(band==0);
	
	
	if((compararFechas(fechaInicio,fechaFin))>0){
		puts("Las fechas no son validas.");
	}else{
		FILE *arch;
	
	arch=fopen("movimientos.dat","rb");
	if(arch==NULL){
		printf("\nError al abrir el archivo movimientos.dat");
	}
	else{		
		fread(&movimiento,sizeof(movimiento),1,arch);
		while(!feof(arch)){
			
			if(fechaEstaEntre(movimiento.tFecha,fechaInicio,fechaFin)){
				printf("\nDNI usuario: %ld", movimiento.dni_usuario);
				if(movimiento.tipo == 1){
					printf("\nTipo: SUBE");
				}else{
					printf("\nTipo: Billetera Virtual");
				}
				printf("\nNro Unidad: %d", movimiento.nroUnidad);
				printf("\nOrigen: ");
				puts(movimiento.origen);
				printf("Destino: ");
				puts(movimiento.destino);
				printf("Saldo Utilizado: %.2f", movimiento.saldoUtl);
				printf("\nFecha: %d/%d/%d",	movimiento.tFecha.dia,movimiento.tFecha.mes,movimiento.tFecha.anio);
				printf("\nHora: %d:%d",	movimiento.tHora.hora,movimiento.tHora.min);
				
				printf("\n----------------");
				c++;	
			}
				
			fread(&movimiento,sizeof(movimiento),1,arch);
		}
	
		fclose(arch);
		
		if(c==0){
			puts("No hay registros entre esas fechas.");
		}	
	}
	}
	
}

char elegirOD(){
	char op;
	int band = 1;
	
	while(band == 1){
		
		printf("\n1- Posadas.\n2- Garupa.\n3- Candelaria.\n");
		fflush(stdin);
		scanf("%c", &op);
		printf("\n");
		fflush(stdin);
		
		switch(op){
			
			case '1':
				return 'p';
			break;
			
			case '2':
				return 'g';
			break;
			
			case '3':
				return 'c';
			break;
			
			default:
				puts("Opcion no valida, intente nuevo.");
		}
		
	}
}
// Función para comparar dos fechas
// Devuelve 0 si son iguales, -1 si fecha1 es anterior a fecha2 y 1 si fecha1 es posterior a fecha2
int compararFechas(struct fech fechaInicio, struct fech fechaFin) {
    if (fechaInicio.anio < fechaFin.anio) {
        return -1;
    } else if (fechaInicio.anio > fechaFin.anio) {
        return 1;
    } else {
        if (fechaInicio.mes < fechaFin.mes) {
            return -1;
        } else if (fechaInicio.mes > fechaFin.mes) {
            return 1;
        } else {
            if (fechaInicio.dia < fechaFin.dia) {
                return -1;
            } else if (fechaInicio.dia > fechaFin.dia) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

int fechaEstaEntre(struct fech fechaBuscar, struct fech fechaInicio, struct fech fechaFin) {
    return (compararFechas(fechaBuscar, fechaInicio) >= 0 && compararFechas(fechaBuscar, fechaFin) <= 0);
}

void cantidadBeneficios(){
	FILE *arch;
	int conBeneficios=0;
	
	arch=fopen("usuarios.dat","rb");
	if(arch==NULL){
		printf("\nError al abrir el archivo cuentas.dat");
	}
	else{
		fread(&usuario, sizeof(usuario),1,arch);
		
		while(!feof(arch)){
			
			if(strcmp(usuario.tipo,"normal")!=0) {
				
				conBeneficios++;
			}
			
			fread(&usuario, sizeof(usuario),1,arch);
		}
		
		printf("\nHay %d usuarios registrados que poseen algun beneficio.", conBeneficios);
	}	
}

void consultaSaldo(){
	FILE *arch1, *arch2;
	int idAux, encontro1=0, encontro2=0, dia1, mes, anio, hora, min;
	long dniAux;
	char nomAux[30], nomApe2[30];
	
	printf("Ingrese DNI: ");
	scanf("%ld", &dniAux);
	fflush(stdin);
	
	printf("Nombre y Apellido: ");
	gets(nomAux);
	strlwr(nomAux);
	fflush(stdin);
			
	arch1 = fopen("usuarios.dat","r+b");
	if(arch1==NULL){
		printf("Error de apertura de archivo usuarios.dat");
		printf("\n");
	}else{		
			
		fread(&usuario, sizeof(usuario),1,arch1);
		
		while((!feof(arch1))&&(encontro1 == 0)){
			
			strcpy(nomApe2,usuario.nomApe);
			strlwr(nomApe2);
			
			if((dniAux == usuario.dni)&& (strcmp(nomAux,nomApe2))==0){
				encontro1=1;
				idAux = usuario.id;
			}else{
				fread(&usuario, sizeof(usuario),1,arch1);
			}
		}
		fclose(arch1);
		
		if(encontro1==0){
			printf("\nNo se encuentra el usuario registrado");
		}
		else{
			arch2 = fopen("cuentas.dat","r+b");
			if(arch2==NULL){
				printf("Error de apertura de archivo usuarios.dat");
				printf("\n");
			}else{		
			
				fread(&cuenta, sizeof(cuenta),1,arch2);
		
				while((!feof(arch2)) && (encontro2==0)){
					
					if(idAux==cuenta.id_usuario) {
					
					encontro2=1;
					printf("\nDNI: %ld",dniAux);
					printf("\nSaldo disponible: %.2f", cuenta.saldo);
					dia1 = obtenerTiempo('d');
					mes = obtenerTiempo('m');
					anio = obtenerTiempo('a');
					hora = obtenerTiempo('h');
					min = obtenerTiempo('s');
								
					printf("\nFecha y hora: ");
					printf("\n%d/", dia1);
					printf("%d/", mes);
					printf("%d", anio);
					printf(" - %d:%d hs.", hora, min);
					}
					
				}
			}
						
		}
	}	
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

	printf("El porcentaje de pasajeros que viajan en el primer turno del a%co actual\n",164);
	printf("Es de %.0f%% entre %d",porc,c);
}

//funciones de testeo:

void mostar_choferes() {
	
	FILE *arch;
	
	arch=fopen("choferes.dat","rb");
	if(arch==NULL){
		printf("\nError al crear el archivo clase.bin");
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

void mostrar_unidades() {
	
	FILE *arch;
	
	arch=fopen("unidades.dat","rb");
	if(arch==NULL){
		printf("\nError al crear el archivo clase.bin");
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

void mostrar_asignaciones() {
	
	FILE *arch;
	
	arch=fopen("asignaciones.dat","rb");
	if(arch==NULL){
		printf("\nError al crear el archivo clase.bin");
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

void mostrar_movimientos(){
		FILE *arch;
	
	arch=fopen("movimientos.dat","rb");
	if(arch==NULL){
		printf("\nError al abrir el archivo movimientos.dat");
	}
	else{		
		fread(&movimiento,sizeof(movimiento),1,arch);
		while(!feof(arch)){
			
			printf("\nID: %d",movimiento.id);
			printf("\nID usuario: %d", movimiento.id_usuario);
			printf("\nDNI usuario: %ld", movimiento.dni_usuario);
			if(movimiento.tipo == 1){
				printf("\nTipo: SUBE");
			}else{
				printf("\nTipo: Billetera Virtual");
			}
			printf("\nNro Unidad: %d", movimiento.nroUnidad);
			printf("\nOrigen: ");
			puts(movimiento.origen);
			printf("Destino: ");
			puts(movimiento.destino);
			printf("Saldo Utilizado: %.2f", movimiento.saldoUtl);
			printf("\nFecha: %d/%d/%d",	movimiento.tFecha.dia,movimiento.tFecha.mes,movimiento.tFecha.anio);
			printf("\nHora: %d:%d",	movimiento.tHora.hora,movimiento.tHora.min);
			
								
			printf("\n----------------");	
				
				
			fread(&movimiento,sizeof(movimiento),1,arch);
		}
	
		fclose(arch);	
	}
}
