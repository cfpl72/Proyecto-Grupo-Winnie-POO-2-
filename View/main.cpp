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
    PrintLine("PACIENTES");

    Paciente^ p1 = gcnew Paciente(1, "t1");
    p1->nombre = "Claudio"; p1->apellido = "Rios";
    p1->edad = 21; p1->alergias = "Ninguna"; p1->sintomas = "Dolor";

    Console::WriteLine("→ Registrando p1");
    sp->Registrar(p1);
    PrintPacientes(sp);

    Paciente^ p2 = gcnew Paciente(2, "t2");
    p2->nombre = "Ana"; p2->apellido = "Lopez";
    p2->edad = 30; p2->alergias = "Penicilina"; p2->sintomas = "Fiebre";

    Console::WriteLine("→ Registrando p2");
    sp->Registrar(p2);
    PrintPacientes(sp);

    Console::WriteLine("→ Modificando edad de p1 → 25");
    sp->Modificar(1, "edad", "25");
    PrintPacientes(sp);

    Console::WriteLine("→ Eliminando p2");
    sp->Eliminar(2);
    PrintPacientes(sp);

    // ==============================
    // MEDICAMENTOS
    // ==============================
    PrintLine("MEDICAMENTOS");

    Medicamento^ m1 = gcnew Medicamento(1, "Paracetamol", "Acetaminofen", 5, 50);
    Medicamento^ m2 = gcnew Medicamento(2, "Ibuprofeno", "Ibuprofeno", 8, 30);

    Console::WriteLine("→ Registrando m1");
    sm->RegistrarMedicamento(m1);
    PrintMedicamentos(sm);

    Console::WriteLine("→ Registrando m2");
    sm->RegistrarMedicamento(m2);
    PrintMedicamentos(sm);

    Console::WriteLine("→ Actualizando m1 (precio=6.5, stock=40)");
    sm->ActualizarMedicamento(1, 6.5, 40);
    PrintMedicamentos(sm);

    // ==============================
    // VENTAS
    // ==============================
    PrintLine("VENTAS");

    Venta^ v1 = gcnew Venta(100, 1, 5, m1, DateTime::Now);
    v1->idMedicamento = 1;

    Console::WriteLine("→ Registrando v1");
    sv->RegistrarVenta(v1);
    PrintVentas(sv);
    PrintMedicamentos(sm); // ver impacto en stock

    Venta^ v2 = gcnew Venta(101, 1, 3, m2, DateTime::Now);
    v2->idMedicamento = 2;

    Console::WriteLine("→ Registrando v2");
    sv->RegistrarVenta(v2);
    PrintVentas(sv);
    PrintMedicamentos(sm);

    Console::WriteLine("→ Intentando venta inválida (stock excesivo)");
    Venta^ vError = gcnew Venta(102, 1, 999, m2, DateTime::Now);
    vError->idMedicamento = 2;
    sv->RegistrarVenta(vError);
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