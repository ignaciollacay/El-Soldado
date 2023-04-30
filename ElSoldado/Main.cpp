// Ejercicio Practico "El Soldado"
// Aplicaci�n del Patr�n de Dise�o Modelo-Vista-Presentador
// Realizado en el curso de C++ de Quark Academy
// Ignacio Llacay 21/4/2023

#include <iostream>
#include "MenuPresentador.cpp"

int main()
{
	Soldado* soldado = new Soldado();
	MenuVista* menu = new MenuVista();
	MenuPresentador* menuPresentador = new MenuPresentador(soldado, menu);

	delete menuPresentador;
	return 0;
}