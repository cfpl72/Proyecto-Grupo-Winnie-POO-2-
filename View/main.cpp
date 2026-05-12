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

void PrintPacientes(ServicioPacientes^ sp) {
    Console::WriteLine("\n[BD PACIENTES]");
    for each (auto kvp in sp->LeerTodos()) {
        Paciente^ p = kvp.Value;
        Console::WriteLine("ID: " + p->id + " | " + p->nombre + " " + p->apellido +
            " | Edad: " + p->edad +
            " | Alergias: " + p->alergias);
    }
}

void PrintMedicamentos(ServicioMedicamentos^ sm) {
    Console::WriteLine("\n[BD MEDICAMENTOS]");
    for each (Medicamento ^ m in sm->ObtenerInventarioCompleto()) {
        Console::WriteLine("ID: " + m->id +
            " | " + m->nombre +
            " | Precio: " + m->precio +
            " | Stock: " + m->stock);
    }
}

void PrintVentas(ServicioVentas^ sv) {
    Console::WriteLine("\n[BD VENTAS]");
    for each (Venta ^ v in sv->ObtenerTodasLasVentas()) {
        Console::WriteLine("ID: " + v->id +
            " | Paciente: " + v->idPaciente +
            " | Med: " + v->nombreMedicamento +
            " | Cant: " + v->cantidadVendida +
            " | Total: " + v->totalVenta);
    }
}

void PrintLine(String^ titulo) {
    Console::WriteLine("\n==============================");
    Console::WriteLine(titulo);
    Console::WriteLine("==============================");
}

int main(array<System::String^>^ args)
{
    Reset();

    ServicioPacientes^ sp = gcnew ServicioPacientes();
    ServicioMedicamentos^ sm = gcnew ServicioMedicamentos();
    ServicioVentas^ sv = gcnew ServicioVentas();

    // ==============================
    // PACIENTES
    // ==============================
    PrintLine("PACIENTES (INPUT CRUDO)");

    Console::WriteLine("→ Registrando p1");
    sp->RegistrarPaciente(1, "t1", "Claudio", "Rios", 21, "Ninguna", "Dolor");
    PrintPacientes(sp);

    Console::WriteLine("→ Registrando p2");
    sp->RegistrarPaciente(2, "t2", "Ana", "Lopez", 30, "Penicilina", "Fiebre");
    PrintPacientes(sp);

    Console::WriteLine("→ Intentando registrar paciente inválido");
    sp->RegistrarPaciente(-1, "t3", "", "X", -5, "", "");
    PrintPacientes(sp);

    Console::WriteLine("→ Modificando edad de p1 → 25");
    sp->ModificarPaciente(1, "edad", "25");
    PrintPacientes(sp);

    Console::WriteLine("→ Eliminando p2");
    sp->EliminarPaciente(2);
    PrintPacientes(sp);

    // ==============================
    // MEDICAMENTOS
    // ==============================
    PrintLine("MEDICAMENTOS (INPUT CRUDO)");

    Console::WriteLine("→ Registrando m1");
    sm->RegistrarMedicamento(1, "Paracetamol", "Acetaminofen", 5, 50);
    PrintMedicamentos(sm);

    Console::WriteLine("→ Registrando m2");
    sm->RegistrarMedicamento(2, "Ibuprofeno", "Ibuprofeno", 8, 30);
    PrintMedicamentos(sm);

    Console::WriteLine("→ Intentando registrar duplicado");
    sm->RegistrarMedicamento(1, "Duplicado", "X", 1, 1);
    PrintMedicamentos(sm);

    Console::WriteLine("→ Actualizando m1");
    sm->ActualizarMedicamento(1, 6.5, 40);
    PrintMedicamentos(sm);

    // ==============================
    // VENTAS
    // ==============================
    PrintLine("VENTAS (INPUT CRUDO)");

    Console::WriteLine("→ Registrando venta 100");
    sv->RegistrarVenta(100, 1, 1, 5);
    PrintVentas(sv);
    PrintMedicamentos(sm);

    Console::WriteLine("→ Registrando venta 101");
    sv->RegistrarVenta(101, 1, 2, 3);
    PrintVentas(sv);
    PrintMedicamentos(sm);

    Console::WriteLine("→ Intentando venta inválida (stock excesivo)");
    sv->RegistrarVenta(102, 1, 2, 999);
    PrintVentas(sv);
    PrintMedicamentos(sm);

    Console::WriteLine("→ Modificando venta 100 → cantidad 8");
    sv->ModificarVenta(100, 8);
    PrintVentas(sv);
    PrintMedicamentos(sm);

    Console::WriteLine("→ Eliminando venta 101");
    sv->EliminarVenta(101);
    PrintVentas(sv);
    PrintMedicamentos(sm);

    Console::WriteLine("→ Mostrar boleta venta 100");
    Console::WriteLine(sv->MostrarBoletaVenta(100));

    Console::WriteLine("→ Intentando leer venta inexistente");
    sv->LeerVenta(999);

    PrintLine("FIN");

    return 0;
}