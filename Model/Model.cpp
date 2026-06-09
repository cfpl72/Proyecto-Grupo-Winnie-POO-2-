#include "pch.h"

#include "Model.h"
#include "utils.h"


bool WinniePOO_Modelos::Usuario::autentificar(String^ contrasena) {
	this->contrasenia = contrasena;
	if (this->verificationToken == WinniePOO_Modelos::Utils::GetMD5Hash(this->nombre + this->contrasenia)) {
		Console::WriteLine("Autenticación exitosa para el usuario: " + this->nombre);
		return true;
	}
	else {
		Console::WriteLine("Autenticación fallida para el usuario: " + this->nombre);
		return false;
	}
}

bool WinniePOO_Modelos1::Usuario::autentificar(String^ contrasena) {
	this->contrasenia = contrasena;
	if (this->verificationToken == WinniePOO_Modelos::Utils::GetMD5Hash(this->nombre + this->contrasenia)) {
		Console::WriteLine("Autenticación exitosa para el usuario: " + this->nombre);
		return true;
	}
	else {
		Console::WriteLine("Autenticación fallida para el usuario: " + this->nombre);
		return false;
	}
}