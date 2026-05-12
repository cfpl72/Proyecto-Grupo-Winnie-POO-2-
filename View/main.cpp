#include "pch.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace Controller;
using namespace WinniePOO_Modelos;

void Reset() {
    File::WriteAllText("Pacientes.txt", "");
    File::WriteAllText("Medicamentos.txt", "");
    File::WriteAllText("Ventas.txt", "");
}

int main(array<System::String^>^ args)
{
    Console::WriteLine("=== GENERANDO BASE DE DATOS FICTICIA ===");

    Reset();

    ServicioPacientes^ sp = gcnew ServicioPacientes();
    ServicioMedicamentos^ sm = gcnew ServicioMedicamentos();
    ServicioVentas^ sv = gcnew ServicioVentas();

    // ==============================
    // PACIENTES
    // ==============================
    Console::WriteLine("\n→ Generando pacientes...");

    sp->RegistrarPaciente(1, "t1", "Claudio", "Rios", 21, "Ninguna", "Dolor de cabeza");
    sp->RegistrarPaciente(2, "t2", "Ana", "Lopez", 30, "Penicilina", "Fiebre");
    sp->RegistrarPaciente(3, "t3", "Luis", "Torres", 45, "Aspirina", "Dolor muscular");
    sp->RegistrarPaciente(4, "t4", "Maria", "Perez", 60, "Ninguna", "Presión alta");
    sp->RegistrarPaciente(5, "t5", "Carlos", "Vega", 28, "Polen", "Alergia");

    // ==============================
    // MEDICAMENTOS
    // ==============================
    Console::WriteLine("\n→ Generando medicamentos...");

    sm->RegistrarMedicamento(1, "Paracetamol", "Acetaminofen", 5.0, 100);
    sm->RegistrarMedicamento(2, "Ibuprofeno", "Ibuprofeno", 8.0, 80);
    sm->RegistrarMedicamento(3, "Amoxicilina", "Antibiótico", 12.0, 50);
    sm->RegistrarMedicamento(4, "Loratadina", "Antialérgico", 6.5, 70);
    sm->RegistrarMedicamento(5, "Omeprazol", "Protector gástrico", 10.0, 60);

    // ==============================
    // VENTAS
    // ==============================
    Console::WriteLine("\n→ Generando ventas...");

    sv->RegistrarVenta(100, 1, 1, 2);
    sv->RegistrarVenta(101, 2, 2, 1);
    sv->RegistrarVenta(102, 3, 3, 3);
    sv->RegistrarVenta(103, 4, 4, 2);
    sv->RegistrarVenta(104, 5, 5, 1);
    sv->RegistrarVenta(105, 1, 2, 4);
    sv->RegistrarVenta(106, 2, 1, 2);
    sv->RegistrarVenta(107, 3, 4, 1);

    Console::WriteLine("\n=== BASE DE DATOS LISTA ===");
    Console::WriteLine("Pacientes, medicamentos y ventas cargados.");
    Console::WriteLine("Tus forms ahora tienen un mundo real donde moverse.");

    return 0;
}