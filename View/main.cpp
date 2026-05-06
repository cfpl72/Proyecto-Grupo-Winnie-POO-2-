#include "pch.h"


using namespace System;
using namespace WinniePOO_Modelos;
using namespace Controller;

int main() {

    ServicioUsuarios^ servicio = gcnew ServicioUsuarios();

    Console::WriteLine("=== REGISTRO DE PACIENTE ===");

    // Variables
    int id;
    String^ nombre;
    String^ apellido;
    String^ contrasenia;
    int edad;
    String^ alergias;
    String^ sintomas;

    // Entrada de datos
    Console::Write("ID: ");
    id = Int32::Parse(Console::ReadLine());

    Console::Write("Nombre: ");
    nombre = Console::ReadLine();

    Console::Write("Apellido: ");
    apellido = Console::ReadLine();

    Console::Write("Contraseña: ");
    contrasenia = Console::ReadLine();

    Console::Write("Edad: ");
    edad = Int32::Parse(Console::ReadLine());

    Console::Write("Alergias: ");
    alergias = Console::ReadLine();

    Console::Write("Síntomas: ");
    sintomas = Console::ReadLine();

    // Llamada al servicio
    servicio->RegistrarPaciente(id, nombre, apellido, contrasenia, edad, alergias, sintomas);

    Console::WriteLine("\nPaciente registrado. Presiona cualquier tecla para salir...");
    Console::ReadKey();

    return 0;
}