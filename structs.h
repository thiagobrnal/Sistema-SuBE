#include <stdio.h>
#include <string.h>

struct fech {
	int dia, mes, anio;
};
struct hora {
	int hora, min;
};

struct datUsuarios {
	int id;
	struct fech fecha;
	long dni, telefono;
	char nomApe[30], direccion[40], tipo[50];
}usuario;

struct datCuentas {
	int id, id_usuario;
	long nroTarjeta, nroCel;
	float saldo;	
}cuenta;

struct datChoferes {
	int id;
	long dni, telefono;
	char nomApe[30], direccion[40], correo[30];	
	struct fech nacimiento;
}chofer;

struct datTransporte{
	int id, numUnidad;
}colectivo;

struct datCargas{
	int id, id_usuario;
	long dni_usuario, nroControl;
	char bocaPago[40];
	struct fech tFecha;
	struct hora tHora;
}carga;
