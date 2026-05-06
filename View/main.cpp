#include "pch.h"


using namespace System;
using namespace WinniePOO_Modelos;
using namespace Controller;
using namespace Persistance;

int main() {q

	//Verificamos si existen los 3 arhivos que pusimos en el persistance
	if (Persistance::persistance::exists("UsuariosPersistance.txt")) {
		Console::WriteLine("El archivo de usuarios existe.");
	}
	else {
		Console::WriteLine("El archivo de usuarios no existe.");
	}

	if (Persistance::persistance::exists("ventas.txt")) {
		Console::WriteLine("El archivo de ventas existe.");
	}
	else {
		Console::WriteLine("El archivo de ventas no existe.");
	}

	if (Persistance::persistance::exists("medicamentos.txt")) {
		Console::WriteLine("El archivo de medicamentos existe.");
	}
	else {
		Console::WriteLine("El archivo de medicamentos no existe.");
	}



	return 0;
}