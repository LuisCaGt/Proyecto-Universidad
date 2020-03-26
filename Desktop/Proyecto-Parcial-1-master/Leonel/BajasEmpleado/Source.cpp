#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

ofstream  archivoTemporal, guardarArchivo, guardarEmpleado;
ifstream baseUsuarios;
fstream baseEmpleados, historialUsuarios;
struct usuarios
{
	string codigoUsuario, contrasenaUsuario, nombreUsuario, codigoBusqueda, contrasenaBusqueda;
};
usuarios datosUsuarios;
struct empleados
{
	string codigoEmpleado, nombreEmpleado, nuevoNombre, apellidoEmpleado, nuevoApellido, puestoEmpleado, nuevoPuesto, estadoEmpleado, nuevoEstadoLab, codigoBusqueda, confirmarModificacion;
	float sueldoEmpleado, nuevoSueldo;
};
empleados datosEmpleados;
int opcion;
void gotoxy(int x, int y)//se manda a llamar la libreria de gotoxy y sirve para el posiconamiento de texto
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void AltasEmpleados()
{

	baseEmpleados.open("baseEmpleados.txt", ios::in);
	guardarEmpleado.open("baseEmpleados.txt", ios::app);
	if (baseEmpleados.is_open()) {
		baseEmpleados >> datosEmpleados.codigoEmpleado;
		cout << "ingrese codigo de empleado" << endl;
		cin >> datosEmpleados.codigoBusqueda;
		bool encontrado = false;
		while (!baseEmpleados.eof())
		{
			baseEmpleados >> datosEmpleados.nombreEmpleado >> datosEmpleados.apellidoEmpleado >> datosEmpleados.puestoEmpleado >> datosEmpleados.sueldoEmpleado >> datosEmpleados.estadoEmpleado;
			if (datosEmpleados.codigoBusqueda == datosEmpleados.codigoEmpleado)
			{
				cout << "codigo ya existe";
				baseEmpleados.close();
			}
			baseEmpleados >> datosEmpleados.codigoEmpleado;
			if (datosEmpleados.codigoBusqueda != datosEmpleados.codigoEmpleado)
			{
				cout << "ingrese Nombre " << endl;
				cin >> datosEmpleados.nombreEmpleado;
				cout << "ingrese apellido" << endl;
				cin >> datosEmpleados.apellidoEmpleado;
				cout << "ingrese  puesto" << endl;
				cin >> datosEmpleados.puestoEmpleado;
				cout << "ingrese sueldo" << endl;
				cin >> datosEmpleados.sueldoEmpleado;
				cout << "ingrese estado" << endl;
				cin >> datosEmpleados.estadoEmpleado;
				guardarEmpleado << datosEmpleados.codigoBusqueda << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl;
			}
		}
	}
	baseEmpleados.close();
	guardarEmpleado.close();
};
void BajasEmpleados() {
	baseEmpleados.close();
	baseEmpleados.open("baseEmpleados.txt");
	archivoTemporal.open("archivoTemporal.txt");
	if (baseEmpleados.is_open() && archivoTemporal.is_open())
	{
		baseEmpleados >> datosEmpleados.codigoEmpleado;
		bool encontrado = false;
		cout << "Escriba el codigo del empleado a buscar:  ";
		cin >> datosEmpleados.codigoBusqueda;
		while (!baseEmpleados.eof())
		{
			baseEmpleados >> datosEmpleados.nombreEmpleado >> datosEmpleados.apellidoEmpleado >> datosEmpleados.puestoEmpleado >> datosEmpleados.sueldoEmpleado >> datosEmpleados.estadoEmpleado;
			if (datosEmpleados.codigoEmpleado == datosEmpleados.codigoBusqueda) {
				encontrado = true;
				cout << "Nombre: " << datosEmpleados.nombreEmpleado << endl;
				cout << "Apellido: " << datosEmpleados.apellidoEmpleado << endl;
				cout << "Puesto: " << datosEmpleados.puestoEmpleado << endl;
				cout << "Sueldo: " << datosEmpleados.sueldoEmpleado << endl;
				cout << "Estado: " << datosEmpleados.estadoEmpleado << endl;
				cout << "Ingrese nuevo estado laboral del empleado" << endl;
				cin >> datosEmpleados.nuevoEstadoLab;
				cout << "Desea confirmar para darle de baja al empleado con el codigo: " << datosEmpleados.codigoBusqueda << endl;
				cin >> datosEmpleados.confirmarModificacion;
				if (datosEmpleados.confirmarModificacion == "si"
					&&"SI")
				{
					archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.nuevoEstadoLab << endl;
				}
				else
				{
					archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl;
				}
			}
			baseEmpleados >> datosEmpleados.codigoEmpleado;
		}
		if (encontrado == false) {
			cout << "Codigo no encontrado en la base de datos" << endl;
		}
		baseEmpleados.close();
		archivoTemporal.close();
		remove("baseEmpleados.txt");
		rename("archivoTemporal.txt", "baseEmpleados.txt");
	}
};

void login()
{
	do
	{
		system("cls");
		baseUsuarios.open("log.txt", ios::in);
		gotoxy(45, 10); cout << "CODIGO DE USUARIO: " << endl;
		gotoxy(45, 11); cout << "CONTRASEÑA: " << endl;
		gotoxy(66, 10); cin >> datosUsuarios.codigoBusqueda;//pide el nombre de usuario
		if (baseUsuarios.is_open())
		{
			while (!baseUsuarios.eof())
			{
				baseUsuarios >> datosUsuarios.codigoUsuario >> datosUsuarios.nombreUsuario >> datosUsuarios.contrasenaUsuario;
				if (!baseUsuarios.eof())
				{
					if (datosUsuarios.codigoUsuario == datosUsuarios.codigoBusqueda)
					{
						gotoxy(64, 11); cin >> datosUsuarios.contrasenaBusqueda;//pide ingresar contraseña
						if (datosUsuarios.contrasenaUsuario == datosUsuarios.contrasenaBusqueda)
						{
							do {
								system("cls");
								cout << "ingrese la opcion deseada" << endl;
								cout << "altas...................1" << endl;
								cout << "bajas...................2" << endl;
								cout << "modificacion............3" << endl;
								cout << "salir...................0" << endl;
								cin >> opcion;
								switch (opcion)
								{
								case 1:
									system("cls");
									AltasEmpleados();
									system("pause");
									break;
								case 2:
									system("cls");
									BajasEmpleados();
									system("pause");
									break;
								case 3:
									system("cls");
									
									system("pause");
									break;
								case 0:
									system("cls");
									cout << "usted esta saliendo" << endl;
									system("pause");
									break;
								default:
									system("cls");
									cout << "opcion no disponible" << endl;
									system("pause");
									break;
								}
							} while (opcion != 0);
						}
					}
				}
			}
			baseUsuarios.close();
		}
		else
		{
			cout << "El archivo no existe o tiene algun error";
		}

	} while (datosUsuarios.codigoBusqueda != datosUsuarios.codigoUsuario);
}

int main()
{
	login();
}