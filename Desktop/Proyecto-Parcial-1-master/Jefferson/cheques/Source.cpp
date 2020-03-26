#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

ofstream  archivoTemporal, guardarArchivo, guardarEmpleado, guardarCheque;
ifstream baseUsuarios, datosCheque, mostrarNomina;
fstream baseEmpleados, historialUsuarios;
struct usuarios
{
	string codigoUsuario, contrasenaUsuario, nombreUsuario, codigoBusqueda, contrasenaBusqueda;
};
usuarios datosUsuarios;
struct empleados
{
	string codigoEmpleado, nombreEmpleado, apellidoEmpleado, puestoEmpleado, estadoEmpleado, nuevoEstadoLab, codigoBusqueda, codigoBusquedaII, confirmarModificacion, nuevoNombre, nuevoApellido, nuevoPuesto;
	float sueldoEmpleado, nuevoSueldo;
};
empleados datosEmpleados;
struct cheques
{
	float sueldoextraEmpleado, bonificacionEmpleado, comisionEmpleado, otrosEmpleado, totalEmpleado = 0, anticipoEmpleado, descuentojudicialEmpleado, totaldescuentoEmpleado = 0, totaliquidoEmpleado = 0;
};
cheques salarioEmpleados;
int opcion, opModificacion;
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
		gotoxy(20, 9);cout << "ingrese codigo de empleado" << endl;
		gotoxy(20, 10);cin >> datosEmpleados.codigoBusqueda;
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
		}
		if (datosEmpleados.codigoBusqueda != datosEmpleados.codigoEmpleado)
		{
			gotoxy(20, 11);cout << "ingrese Nombre " << endl;
			gotoxy(20, 12);cin >> datosEmpleados.nombreEmpleado;
			gotoxy(20, 13);cout << "ingrese apellido" << endl;
			gotoxy(20, 14);cin >> datosEmpleados.apellidoEmpleado;
			gotoxy(20, 15);cout << "ingrese  puesto" << endl;
			gotoxy(20, 16);cin >> datosEmpleados.puestoEmpleado;
			gotoxy(20, 17);cout << "ingrese sueldo" << endl;
			gotoxy(20, 18);cin >> datosEmpleados.sueldoEmpleado;
			gotoxy(20, 19);cout << "ingrese estado" << endl;
			cin >> datosEmpleados.estadoEmpleado;
			guardarEmpleado << datosEmpleados.codigoBusqueda << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl;
		}
	}
	baseEmpleados.close();
	guardarEmpleado.close();
};
void BajasEmpleados() {
	baseEmpleados.open("baseEmpleados.txt");//se manda a llamar la funcion para poder leer el archivo
	archivoTemporal.open("archivoTemporal.txt");//se manda a llamar la funcion para poder modificar el archivo
	for (int x = 13; x <= 85; x++)//se utiliza un putchar para realizar un marco en linea horizontal
	{
		gotoxy(x, 2);
		putchar('-');
		gotoxy(x, 11);
		putchar('-');
	}
	if (baseEmpleados.is_open() && archivoTemporal.is_open())//si ambos archivos existen y estan abierto realizar los procesos
	{
		baseEmpleados >> datosEmpleados.codigoEmpleado;
		bool encontrado = false;//se declara un booleano para saber que se encontro o no la informacion
		gotoxy(15, 3);cout << "Escriba el codigo del empleado a buscar:  ";
		gotoxy(75,3);cin >> datosEmpleados.codigoBusqueda;//se introduce el codigo a buscar en una funcion que se usa para almacenar la informacion de empleados
		while (!baseEmpleados.eof())//si el archivo no ah terminado que siga leyendo el archivo
		{
			baseEmpleados >> datosEmpleados.nombreEmpleado >> datosEmpleados.apellidoEmpleado >> datosEmpleados.puestoEmpleado >> datosEmpleados.sueldoEmpleado >> datosEmpleados.estadoEmpleado;//se guarda la informacion en forma de variables
			if (datosEmpleados.codigoEmpleado == datosEmpleados.codigoBusqueda) {//compara el dato introducido con el dato capturado
				encontrado = true;//si lo encuentra envia un mensaje al booleano que se encontro
				gotoxy(15, 4);cout << "Nombre:";//se utiliza el gotoxy para poder centrar el texto
				gotoxy(25, 4);cout << datosEmpleados.nombreEmpleado;
				gotoxy(15, 5);cout << "Apellido:";
				gotoxy(25, 5);cout << datosEmpleados.apellidoEmpleado;
				gotoxy(15, 6);cout << "Puesto:";
				gotoxy(25, 6);cout << datosEmpleados.puestoEmpleado;
				gotoxy(15, 7);cout << "Sueldo:";
				gotoxy(25, 7);cout << datosEmpleados.sueldoEmpleado;
				gotoxy(15, 8);cout << "Estado:";
				gotoxy(25, 8);cout << datosEmpleados.estadoEmpleado;
				gotoxy(15, 9);cout << "Ingrese nuevo estado laboral del empleado";
				gotoxy(57, 9);cin >> datosEmpleados.nuevoEstadoLab;
				gotoxy(15, 10);cout << "Desea confirmar para darle de baja al empleado con el codigo: " << datosEmpleados.codigoBusqueda << endl;
				gotoxy(80, 10);cin >> datosEmpleados.confirmarModificacion;
				if (datosEmpleados.confirmarModificacion == "si" && "SI")//si la desicion es si, se guarda la modificacion
				{
					archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.nuevoEstadoLab << endl;
				}
				if (datosEmpleados.confirmarModificacion == "no" && "NO")//si la decicion es no, no guarda ninguna modificacion
				{
					archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl;
				}
			}
			else//si no se encuentra el codigo se guarda en un archivo temporal
			{
				archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl;
			}
			baseEmpleados >> datosEmpleados.codigoEmpleado;
		}
		if (encontrado == false) {//si no se encuentra el booleano es envia un mensaje de archivo no encontrado
			system("cls");
			gotoxy(35, 5);cout << "archivo no encontrado en la base de datos" << endl;
		}
		baseEmpleados.close();
		archivoTemporal.close();//cerramos ambos archivos para mayor seguridad
		remove("baseEmpleados.txt");//eliminamos el archivo txt
		rename("archivoTemporal.txt", "baseEmpleados.txt");//el archivo temporal lo renombramos y sera ahora el que contenga la base de datos de empleados
	}
};//Hecho por Leonel Dominguez
void ModificaionEmpleados() {
	do {
		system("cls");
		gotoxy(20, 9);cout << "************************************" << endl;
		gotoxy(20, 10);cout << "* ingrese opcion deseada modificar *" << endl;
		gotoxy(20, 11);cout << "* nombre.........................1 *" << endl;
		gotoxy(20, 12);cout << "* apellido.......................2 *" << endl;
		gotoxy(20, 13);cout << "* puesto.........................3 *" << endl;
		gotoxy(20, 14);cout << "* sueldo.........................4 *" << endl;
		gotoxy(20, 15);cout << "* salir..........................0 *" << endl;
		gotoxy(20, 16);cout << "*                                  *" << endl;
		gotoxy(20, 17);cout << "*                                  *" << endl;
		gotoxy(20, 18);cout << "************************************" << endl;
		gotoxy(29, 17);cin >> opModificacion;
		switch (opModificacion)//abre switch para relizar modificaciones en donde se deseen realizar
		{
		case 1:
			system("cls");
			baseEmpleados.close();//cierra el archivo de base de empleados en caso que se encuentre abierto y asi evitar errores
			baseEmpleados.open("baseEmpleados.txt");//abre el archivo de base de datos
			archivoTemporal.open("archivoTemporal.txt");//abre el archivo temporal 
			if (baseEmpleados.is_open() && archivoTemporal.is_open()) //verifica si ya se abrieron los dos archivos anteriores
			{
				baseEmpleados >> datosEmpleados.codigoEmpleado; //lee la variable de empleados 
				bool encontrado = false;//declara una variable del tipo bool para poder verificar si se encontro la variable deseada
				gotoxy(20, 9);cout << "Escriba el codigo del empleado a buscar:  ";
				cin >> datosEmpleados.codigoBusqueda;//pide codigo para buscarlos


				while (!baseEmpleados.eof())//lee el documento de principio a fin
				{
					baseEmpleados >> datosEmpleados.nombreEmpleado >> datosEmpleados.apellidoEmpleado >> datosEmpleados.puestoEmpleado >> datosEmpleados.sueldoEmpleado >> datosEmpleados.estadoEmpleado;//de esta manera leera el documento con respecto a las pociciones d elas variables
					if (datosEmpleados.codigoEmpleado == datosEmpleados.codigoBusqueda) {
						encontrado = true;
						cout << "Nombre: " << datosEmpleados.nombreEmpleado << endl;
						cout << "Ingrese nuevo nombre del empleado" << endl;
						cin >> datosEmpleados.nuevoNombre;
						cout << "Desea confirmar cambios en el empleado con el codigo: " << datosEmpleados.codigoBusqueda << endl;
						cin >> datosEmpleados.confirmarModificacion;
						if (datosEmpleados.confirmarModificacion == "si" && "SI")//esta condicion es la confirmacion o no confirmacion de los cambios en el archivo
						{
							archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nuevoNombre << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl; //efectua los cambios en la variable deseada y deja el resto como estaban
						}
					}
					else
					{
						archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl; //si no se cumple la condicion de confirmacion los datos son vueltos a escribir sin realizar cambios en ellos
					}
					baseEmpleados >> datosEmpleados.codigoEmpleado;
				}

				if (encontrado == false) { //si la variable tipo boole no cambia a true entonces se cumpliria esta validacion
					cout << "Codigo no encontrado en la base de datos" << endl;
				}
				baseEmpleados.close();//cierra el archivo empleados
				archivoTemporal.close();//cierra el archivo temporal
				remove("baseEmpleados.txt");//elimina el archivo de empleados
				rename("archivoTemporal.txt", "baseEmpleados.txt");//cambia el nombre al archivo temporal por archihvo de empleados para suplantar al que fue eliminado ya con los cambios que se deseaban hacer
			}

			system("pause");
			break;
		case 2:
			system("cls");
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
						cout << "Apellido: " << datosEmpleados.apellidoEmpleado << endl;
						cout << "Ingrese nuevo apellido del empleado" << endl;
						cin >> datosEmpleados.nuevoApellido;
						cout << "Desea confirmar cambios en el empleado con el codigo: " << datosEmpleados.codigoBusqueda << endl;
						cin >> datosEmpleados.confirmarModificacion;
						if (datosEmpleados.confirmarModificacion == "si" && "SI")
						{
							archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.nuevoApellido << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl;
						}
					}
					else
					{
						archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl;
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

			system("pause");
			break;
		case 3:
			system("cls");
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
						cout << "Puesto: " << datosEmpleados.puestoEmpleado << endl;
						cout << "Ingrese nuevo puesto del empleado" << endl;
						cin >> datosEmpleados.nuevoPuesto;
						cout << "Estado: " << datosEmpleados.estadoEmpleado << endl;
						cout << "Desea confirmar cambios en el empleado con el codigo: " << datosEmpleados.codigoBusqueda << endl;
						cin >> datosEmpleados.confirmarModificacion;
						if (datosEmpleados.confirmarModificacion == "si" && "SI")
						{
							archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.nuevoPuesto << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl;
						}
					}
					else
					{
						archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl;
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

			system("pause");
			break;
		case 4:
			system("cls");
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
						cout << "Sueldo: " << datosEmpleados.sueldoEmpleado << endl;
						cout << "Ingrese nuevo sueldo del empleado" << endl;
						cin >> datosEmpleados.nuevoSueldo;
						cout << "Estado: " << datosEmpleados.estadoEmpleado << endl;
						cout << "Desea confirmar cambios en el empleado con el codigo: " << datosEmpleados.codigoBusqueda << endl;
						cin >> datosEmpleados.confirmarModificacion;
						if (datosEmpleados.confirmarModificacion == "si" && "SI")
						{
							archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.nuevoSueldo << "\t\t" << datosEmpleados.estadoEmpleado << endl;
						}
					}
					else
					{
						archivoTemporal << datosEmpleados.codigoEmpleado << "\t\t" << datosEmpleados.nombreEmpleado << "\t\t" << datosEmpleados.apellidoEmpleado << "\t\t" << datosEmpleados.puestoEmpleado << "\t\t" << datosEmpleados.sueldoEmpleado << "\t\t" << datosEmpleados.estadoEmpleado << endl;
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
	} while (opModificacion != 0); //cierrra el do while hasta que la opcion en el menu sea igual a cero, de lo contrario seguira en el ciclo para poder realizar mas modificaciones
}; //codigo crado por Fernando Daniel Tobar Arevalo
void Cheques()
{
	baseEmpleados.open("baseEmpleados.txt", ios::in);
	guardarCheque.open("datosCheque.txt", ios::app);
	if (baseEmpleados.is_open()) {
		baseEmpleados >> datosEmpleados.codigoEmpleado;
		bool encontrado = false;
		gotoxy(45, 10);cout << "Ingrese codigo del empleado" << endl;
		gotoxy(85, 10);cin >> datosEmpleados.codigoBusqueda;
		while (!baseEmpleados.eof())
		{
			baseEmpleados >> datosEmpleados.nombreEmpleado >> datosEmpleados.apellidoEmpleado >> datosEmpleados.puestoEmpleado >> datosEmpleados.sueldoEmpleado >> datosEmpleados.estadoEmpleado;
			if (datosEmpleados.codigoBusqueda == datosEmpleados.codigoEmpleado)
			{
				encontrado = true;
				gotoxy(45, 12);cout << "Nombre: " << datosEmpleados.nombreEmpleado << endl;
				gotoxy(45, 13);cout << "Apellido: " << datosEmpleados.apellidoEmpleado << endl;
				gotoxy(45, 14);cout << "Sueldo ordinario: " << datosEmpleados.sueldoEmpleado << endl;
				gotoxy(45, 15);cout << "Estado del trabajador: " << datosEmpleados.estadoEmpleado << "\n\n";
				if (datosEmpleados.estadoEmpleado != "inactivo") {
					gotoxy(45, 17);cout << "Ingresos" << endl;
					gotoxy(45, 18);cout << "Sueldo extraordinario: "; cin >> salarioEmpleados.sueldoextraEmpleado;
					gotoxy(45, 19);cout << "Bonificacion: "; cin >> salarioEmpleados.bonificacionEmpleado;
					gotoxy(45, 20);cout << "Comisiones: "; cin >> salarioEmpleados.comisionEmpleado;
					gotoxy(45, 21);cout << "Otros Ingresos: "; cin >> salarioEmpleados.otrosEmpleado;

					salarioEmpleados.totalEmpleado = salarioEmpleados.sueldoextraEmpleado + salarioEmpleados.bonificacionEmpleado + salarioEmpleados.comisionEmpleado + salarioEmpleados.otrosEmpleado;
					gotoxy(45, 22);cout << "Total Devengado: "; cout << salarioEmpleados.totalEmpleado;

					gotoxy(45, 24);cout << "Descuentos" << endl;
					gotoxy(45, 25);cout << "Anticipo de sueldo: "; cin >> salarioEmpleados.anticipoEmpleado;
					gotoxy(45, 26);cout << "Descuentos Judiciales: "; cin >> salarioEmpleados.descuentojudicialEmpleado;

					salarioEmpleados.totaldescuentoEmpleado = salarioEmpleados.anticipoEmpleado + salarioEmpleados.descuentojudicialEmpleado;
					gotoxy(45, 27);cout << "Total de descuentos: " << salarioEmpleados.totaldescuentoEmpleado;

					salarioEmpleados.totaliquidoEmpleado = datosEmpleados.sueldoEmpleado + salarioEmpleados.totalEmpleado - salarioEmpleados.totaldescuentoEmpleado;

					if (salarioEmpleados.totaliquidoEmpleado >= 0)
					{
						gotoxy(45, 29);cout << "Total Liquido: " << salarioEmpleados.totaliquidoEmpleado;
						cout << endl;
						guardarCheque << datosEmpleados.codigoBusqueda << "\t" << datosEmpleados.nombreEmpleado << "\t" << datosEmpleados.apellidoEmpleado << "\t"
							<< datosEmpleados.sueldoEmpleado << "\t" << salarioEmpleados.sueldoextraEmpleado << "\t" << salarioEmpleados.bonificacionEmpleado
							<< "\t" << salarioEmpleados.comisionEmpleado << "\t" << salarioEmpleados.otrosEmpleado << "\t" << salarioEmpleados.totalEmpleado
							<< "\t" << salarioEmpleados.anticipoEmpleado << "\t" << salarioEmpleados.descuentojudicialEmpleado << "\t" << salarioEmpleados.totaldescuentoEmpleado
							<< "\t" << salarioEmpleados.totaliquidoEmpleado << endl;
					}
					else
					{
						gotoxy(45, 29);cout << "El trabajador no recibira salario";
						cout << endl;
					}


				}
				else {
					gotoxy(45, 30);cout << "El usuario esta inactivo" << endl;
				}
			}
			baseEmpleados >> datosEmpleados.codigoEmpleado;
		}
		if (encontrado == false)
		{
			gotoxy(45, 31);cout << "Codigo del trabajador no encontrado" << endl;
		}
		baseEmpleados.close();
		guardarEmpleado.close();
	}
	else {
		cout << "Error en el Archivo" << endl;
	}
}
void MostrarNomina()
{
	system("cls");
	for (int x = 5; x <= 155; x++)
	{
		gotoxy(x, 17);
		putchar('-');
		gotoxy(x, 20);
		putchar('-');
		gotoxy(x, 24);
		putchar('-');
	}//este for realiza el marco de la factura
	for (int y = 18; y <= 23; y++)
	{
		gotoxy(5, y);
		putchar('|');
		gotoxy(15, y);
		putchar('|');
		gotoxy(35, y);
		putchar('|');
		gotoxy(55, y);
		putchar('|');
		gotoxy(65, y);
		putchar('|');
		gotoxy(75, y);
		putchar('|');
		gotoxy(85, y);
		putchar('|');
		gotoxy(95, y);
		putchar('|');
		gotoxy(105, y);
		putchar('|');
		gotoxy(115, y);
		putchar('|');
		gotoxy(125, y);
		putchar('|');
		gotoxy(135, y);
		putchar('|');
		gotoxy(145, y);
		putchar('|');
		gotoxy(155, y);
		putchar('|');
	}//este for realiza el marco de la factura
	gotoxy(7, 19);cout << "CODIGO";
	gotoxy(20, 19);cout << "NOMBRE";
	gotoxy(40, 19);cout << "APELLIDO";
	mostrarNomina.open("datosCheque.txt", ios::in);
	if (mostrarNomina.is_open())
	{
		mostrarNomina >> datosEmpleados.codigoBusqueda;
		bool encontrado = false;
		gotoxy(7, 22);cin >> datosEmpleados.codigoBusquedaII;
		while (!mostrarNomina.eof())
		{
			mostrarNomina >> datosEmpleados.nombreEmpleado >> datosEmpleados.apellidoEmpleado
				>> datosEmpleados.sueldoEmpleado >> salarioEmpleados.sueldoextraEmpleado >> salarioEmpleados.bonificacionEmpleado
				>> salarioEmpleados.comisionEmpleado >> salarioEmpleados.otrosEmpleado >> salarioEmpleados.totalEmpleado
				>> salarioEmpleados.anticipoEmpleado >> salarioEmpleados.descuentojudicialEmpleado
				>> salarioEmpleados.totaldescuentoEmpleado >> salarioEmpleados.totaliquidoEmpleado;
			if (datosEmpleados.codigoBusquedaII == datosEmpleados.codigoBusqueda) {
				encontrado = true;
				gotoxy(16, 22);cout << datosEmpleados.nombreEmpleado;
				gotoxy(36, 22);cout << datosEmpleados.apellidoEmpleado;
				gotoxy(56, 22);cout << datosEmpleados.sueldoEmpleado;
				gotoxy(66, 22);cout << salarioEmpleados.sueldoextraEmpleado;
				gotoxy(76, 22);cout << salarioEmpleados.bonificacionEmpleado;
				gotoxy(86, 22);cout << salarioEmpleados.comisionEmpleado;
				gotoxy(96, 22);cout << salarioEmpleados.otrosEmpleado;
				gotoxy(106, 22);cout << salarioEmpleados.totalEmpleado;
				gotoxy(116, 22);cout << salarioEmpleados.anticipoEmpleado;
				gotoxy(126, 22);cout << salarioEmpleados.descuentojudicialEmpleado;
				gotoxy(136, 22);cout << salarioEmpleados.totaldescuentoEmpleado;
				gotoxy(146, 22);cout << salarioEmpleados.totaliquidoEmpleado;
			}
			mostrarNomina >> datosEmpleados.codigoBusqueda;
		}
		if (encontrado == false)
		{
			system("cls");
			gotoxy(50, 22);cout << "Codigo no encontrado :(\a" << endl;
		}
		mostrarNomina.close();
	}
	else {
		cout << "Error en archivo\a";
	}
}
void login()
{
	do//login hecho por Leonel Dominguez
	{
		system("cls");//se limpia la pantalla
		baseUsuarios.open("log.txt", ios::in);
		gotoxy(45, 10);cout << "CODIGO DE USUARIO: ";
		gotoxy(45, 11);cout << "CONTRASEÑA: ";
		gotoxy(66, 10);cin >> datosUsuarios.codigoBusqueda;//pide el codigo de usuario
		if (baseUsuarios.is_open())//mira si el archivo txt esta abierto
		{
			while (!baseUsuarios.eof())
			{
				baseUsuarios >> datosUsuarios.codigoUsuario >> datosUsuarios.nombreUsuario >> datosUsuarios.contrasenaUsuario;//se captura los datos en forma de variables
				if (!baseUsuarios.eof())//si el archivo txt no ah terminado que siga comparando
				{
					if (datosUsuarios.codigoUsuario == datosUsuarios.codigoBusqueda)//compara si el codigo introducido existe en la base de datos
					{
						gotoxy(64, 11);cin >> datosUsuarios.contrasenaBusqueda;//pide ingresar contraseña
						if (datosUsuarios.contrasenaUsuario == datosUsuarios.contrasenaBusqueda)//compara si la contraseña introducida es correcta en la base de datos
						{
							do {
								system("cls");
								gotoxy(20, 9);cout << "Ingrese la opcion deseada" << endl;
								gotoxy(20, 10);cout << "Altas...................1" << endl;
								gotoxy(20, 11);cout << "Bajas...................2" << endl;
								gotoxy(20, 12);cout << "Modificacion............3" << endl;
								gotoxy(20, 13);cout << "Cheques.................4" << endl;
								gotoxy(20, 14);cout << "Mostrar.................5" << endl;
								gotoxy(20, 15);cout << "Salir...................0" << endl;
								gotoxy(20, 16);cin >> opcion;
								switch (opcion)//se hizo el switch para segmentar los procesos del programa
								{
								case 1:
									system("cls");
									AltasEmpleados();
									system("pause");
									break;
								case 2:
									system("cls");
									BajasEmpleados();//se manda a llamar la funcion de bajas de empleados
									system("pause");
									break;
								case 3:
									system("cls");
									ModificaionEmpleados();
									system("pause");
									break;
								case 4:
									system("cls");
									Cheques();
									system("pause");
									break;
								case 5:
									system("cls");
									MostrarNomina();
									system("pause>null");
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
		else//si el archivo nos e encuentra entonces mostramos un mensaje del error
		{
			cout << "El archivo no existe o tiene algun error";
		}

	} while (datosUsuarios.codigoUsuario != datosUsuarios.codigoBusqueda);//creamos el bucle para que si escribe el usuario o contraseña incorrecto lo siga intentando
}
int main()
{
	login();
}