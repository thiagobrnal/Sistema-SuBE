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
	int id, numUnidad, canAsientos, km;
	char marca[20], modelo[20], discapacitados[20];
	struct fech alta; 
}unidad;

struct datAsignaciones{
	int id, id_unidad, id_chofer, turno;
	long dni_chofer;
}asignacion;

struct datCargas{
	int id, id_usuario;
	long dni_usuario, nroControl;
	char bocaPago[40];
	struct fech tFecha;
	struct hora tHora;
	float monto;
}carga;

struct datMovimientos{
	int id, id_usuario, nroUnidad, tipo;
	char origen[25], destino[25];
	long dni_usuario;
	float saldoUtl;
	struct fech tFecha;
	struct hora tHora;
}movimiento;
