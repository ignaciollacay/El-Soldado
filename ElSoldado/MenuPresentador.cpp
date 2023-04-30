#include "Soldado.cpp" // Modelo
#include "MenuVista.cpp" // interface del menu presentador

// Presentador
class MenuPresentador
{
public:
	MenuPresentador(Soldado* soldado, MenuVista* menuVista) {
		this->soldado = soldado;
		this->menuVista = menuVista;
		ActivarMenu(false);
	}
	~MenuPresentador() {
		menuVista->MostrarSalir();
		delete soldado;
		delete menuVista;
	}

	void ActivarMenu(bool cls = true) {
		if (menu == 0)
		{
			menuVista->MostrarAcciones(cls);
			AccionSoldado();
		}
		else if (menu == 1) 
		{
			menuVista->MostrarArmas();
			EleccionArma();
		}
	}
	void AccionSoldado() {
		char input;
		bool isValid = false;
		do
		{
			input = menuVista->GetInput();

			if (input == '1') {
				isValid = true;
				menu = 1;
				cout << "\n";
				ActivarMenu();
			}
			else if (input == '2') {
				isValid = true;
				string resultado = soldado->Dejar();
				menuVista->MostrarResultado(resultado);
				SolicitarRegresar();
			}
			else if (input == '3') {
				isValid = true;
				string resultado = soldado->Disparar();
				menuVista->MostrarResultado(resultado);
				SolicitarRegresar();
			}
			else if (input == '4') {
				isValid = true;
				string resultado = soldado->VerArma();
				menuVista->MostrarResultado(resultado);
				SolicitarRegresar();
			}
			else if (input == 'x') {
				isValid = true;
				menu = 2;
				ActivarMenu();
			}
		} while (!isValid);
	}
	void EleccionArma() {
		char input;
		bool isValid = false;
		do
		{
			input = menuVista->GetInput();

			if (input == '1') {
				string resultado = soldado->Recoger(new Revolver());
				menuVista->MostrarResultado(resultado);
				isValid = true;
				SolicitarRegresar();
			}
			else if (input == '2') {
				string resultado = soldado->Recoger(new Rifle());
				menuVista->MostrarResultado(resultado);
				isValid = true;
				SolicitarRegresar();

			}
			else if (input == '3') {
				string resultado = soldado->Recoger(new Escopeta());
				menuVista->MostrarResultado(resultado);
				isValid = true;
				SolicitarRegresar();
			}
			else if (input == 'x') {
				cout << "\n";
				isValid = true;
				menu = 0;
				ActivarMenu();
			}
		} while (!isValid);
	}

	void SolicitarRegresar() {
		if (menuVista->MostrarRegresar())
		{
			menu = 0;
			ActivarMenu();
		}
	}
private:
	Soldado* soldado;
	MenuVista* menuVista;
	int menu = 0;
};