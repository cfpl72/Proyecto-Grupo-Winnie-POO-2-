#include "pch.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace Controller;
using namespace WinniePOO_Modelos;

void LimpiarArchivos() {
    File::WriteAllText("Pacientes.txt", "");
    File::WriteAllText("Medicamentos.txt", "");
    File::WriteAllText("Ventas.txt", "");
}

void ImprimirTodo() {

    ServicioPacientes^ sp = gcnew ServicioPacientes("Pacientes.txt");
    ServicioMedicamentos^ sm = gcnew ServicioMedicamentos("Medicamentos.txt");
    ServicioVentas^ sv = gcnew ServicioVentas("Ventas.txt");

    auto pacientes = sp->LeerTodos();
    auto meds = sm->ObtenerDiccionarioCompleto();
    auto ventas = sv->ObtenerTodasLasVentas();

    Console::WriteLine("\n===============================");
    Console::WriteLine("ESTADO ACTUAL");
    Console::WriteLine("===============================");

    Console::WriteLine("\nPACIENTES:");
    for each(KeyValuePair<int, Paciente^> kvp in pacientes) {
        auto p = kvp.Value;
        Console::WriteLine("ID:{0} Nombre:{1} {2} Edad:{3}",
            p->id, p->nombre, p->apellido, p->edad);
    }

    Console::WriteLine("\nMEDICAMENTOS:");
    for each(KeyValuePair<int, Medicamento^> kvp in meds) {
        auto m = kvp.Value;
        Console::WriteLine("ID:{0} Nombre:{1} Stock:{2} Precio:{3}",
            m->id, m->nombre, m->stock, m->precio);
    }

    Console::WriteLine("\nVENTAS:");
    for each(Venta ^ v in ventas) {
        Console::WriteLine("Venta:{0} Paciente:{1} Med:{2} Cant:{3} Total:{4}",
            v->id, v->idPaciente, v->idMedicamento, v->cantidadVendida, v->totalVenta);
    }

    Console::WriteLine("\n--------------------------------\n");
}

int main() {

    Console::WriteLine("INICIO TEST COMPLETO");

    LimpiarArchivos();

    ServicioPacientes^ sp = gcnew ServicioPacientes("Pacientes.txt");
    ServicioMedicamentos^ sm = gcnew ServicioMedicamentos("Medicamentos.txt");
    ServicioVentas^ sv = gcnew ServicioVentas("Ventas.txt");

    Persistance::persistance repo;

    // =========================
    // PACIENTES
    // =========================

    Console::WriteLine("\nAgregar pacientes");

    Paciente^ p1 = gcnew Paciente(101, "tok1");
    p1->nombre = "Claudio";
    p1->apellido = "A";
    p1->edad = 21;

    Paciente^ p2 = gcnew Paciente(102, "tok2");
    p2->nombre = "Lucia";
    p2->apellido = "B";
    p2->edad = 25;

    sp->Registrar(p1);
    ImprimirTodo();

    sp->Registrar(p2);
    ImprimirTodo();

    Console::WriteLine("\nModificar paciente 101 (edad -> 30)");
    sp->Modificar(101, "edad", "30");
    ImprimirTodo();

    Console::WriteLine("\nEliminar paciente 102");
    sp->Eliminar(102);
    ImprimirTodo();

    // =========================
    // MEDICAMENTOS
    // =========================

    Console::WriteLine("\nAgregar medicamentos");

    Dictionary<int, Medicamento^>^ meds = gcnew Dictionary<int, Medicamento^>();

    Medicamento^ m1 = gcnew Medicamento(1, "Paracetamol", "A", 10, 50);
    Medicamento^ m2 = gcnew Medicamento(2, "Ibuprofeno", "B", 20, 30);

    meds->Add(1, m1);
    meds->Add(2, m2);

    repo.GuardarMedicamentos("Medicamentos.txt", meds);
    ImprimirTodo();

    Console::WriteLine("\nModificar medicamento 1 (precio 12, stock 60)");
    sm->ActualizarMedicamento(1, 12, 60);
    ImprimirTodo();

    // =========================
    // VENTAS
    // =========================

    Console::WriteLine("\nRegistrar ventas");

    sv->RegistrarVenta(1, 101, 1, 5);
    ImprimirTodo();

    sv->RegistrarVenta(2, 101, 2, 3);
    ImprimirTodo();

    Console::WriteLine("\nModificar venta 1 (5 -> 8)");
    sv->ModificarVenta(1, 8);
    ImprimirTodo();

    Console::WriteLine("\nEliminar venta 2");
    sv->EliminarVenta(2);
    ImprimirTodo();

    Console::WriteLine("\nEliminar venta 1");
    sv->EliminarVenta(1);
    ImprimirTodo();

    Console::WriteLine("\nFIN TEST COMPLETO");

    return 0;
}