#include <iostream>."
#include "Arma.cpp"
using namespace std;

// Modelo
class Soldado
{
public:
	Soldado() { arma = nullptr; }
	~Soldado() { delete arma; }
	string Recoger(Arma* arma) {
		if (this->arma == nullptr)
		{
			this->arma = arma;
			return "Recoges un arma.";
		}
		else
			return "Solo puede tener un arma al mismo tiempo.";
	}
	string Dejar() {
		if (this->arma != nullptr)
		{
			this->arma = nullptr;
			return "Dejas tu arma.";
		}
		else
			return "No tienes una arma en tu poder para dejar.";
	}
	string VerArma() {
		if (this->arma != nullptr)
			return "Tienes " + arma->GetNombre() + " en tu poder.";
		else
			return "No tiene ningun arma en su poder.";
	}
	string Disparar() {
		if (this->arma != nullptr)
			return arma->GetDisparo();
		else
			return "Debes recoger un arma para poder disparar.";
	}
private:
	Arma* arma; 
};