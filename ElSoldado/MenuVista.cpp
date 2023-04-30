#include <iostream>
#include <stdlib.h>
#include "IVista.cpp" // interface del menu presentador

using namespace std;

// Vista
class MenuVista : IVista
{
public:
	MenuVista() {
		cout << "-== Bienvenido al campo de entrenamiento, Soldado ==-" << endl << "\n";
	}
	char GetInput()
	{
		char input;
		cin >> input;
		return input;
	}

	void MostrarAcciones(bool cls) {
		if (cls) system("CLS");
		cout << "Que desea hacer?" << endl << "(presione el numero correspondiente a la opcion del menu)" << endl << "\n"
			<< "1- Recoger arma" << endl
			<< "2- Dejar arma" << endl
			<< "3- Disparar" << endl
			<< "4- Ver arma en uso" << endl
			<< "X- Salir" << endl << linea << endl;
	}
	void MostrarArmas() {
		system("CLS");
		cout << "Por favor escoja el arma que desea utilizar:" << endl << "\n"
			<< "1- Revolver" << endl
			<< "2- Rifle" << endl
			<< "3- Escopeta" << endl
			<< "X- Volver atras" << endl << linea << endl;
	}
	void MostrarResultado(string x) {
		system("CLS");
		cout << x << endl;
	}
	bool MostrarRegresar()
	{
		cout << endl << linea << endl << "X- Volver atras" << endl << linea << endl;

		if (GetInput() == 'x')
			return true;
	}
	void MostrarSalir() {
		system("CLS");
		cout << "Saliendo del programa..." << endl;
	}
private:
	const string linea = "------------------------------------------------";
};