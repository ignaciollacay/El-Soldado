// Interface del Presentador para ser implementada en la Vista
#include <string>

class IVista
{
	virtual void MostrarAcciones(bool cls) = 0;
	virtual void MostrarArmas() = 0;
	virtual char GetInput() = 0;
	virtual void MostrarResultado(std::string x) = 0;
	virtual bool MostrarRegresar() = 0;
	virtual void MostrarSalir() = 0;
};