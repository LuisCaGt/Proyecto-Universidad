#include<iostream>
#include<fstream>
using namespace std;

struct empleados
{
	string codigoEmpleado, nombreEmpleado, apellidoEmpleado, puestodeEmpleado, sueldoEmpleado, estadoEmpleado,codigoBusqueda;
};
empleados datosEmpleados;
ifstream baseEmpleados;
ofstream guardarEmpleado;
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
			baseEmpleados >> datosEmpleados.nombreEmpleado >> datosEmpleados.apellidoEmpleado >> datosEmpleados.puestodeEmpleado >> datosEmpleados.sueldoEmpleado >> datosEmpleados.estadoEmpleado;
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
				cin >> datosEmpleados.puestodeEmpleado;
				cout << "ingrese sueldo" << endl;
				cin >> datosEmpleados.sueldoEmpleado;
				cout << "ingrese estado" << endl;
				cin >> datosEmpleados.estadoEmpleado;
				guardarEmpleado << datosEmpleados.codigoBusqueda << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestodeEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl;
			}
		}	
		
	}
	guardarEmpleado.close();
	};
int main()
{
	AltasEmpleados();
	
}
