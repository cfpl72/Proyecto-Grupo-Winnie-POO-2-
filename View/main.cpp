#include "pch.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace Controller;
using namespace WinniePOO_Modelos;
using namespace System::IO;

// ================= RESET =================
void ResetVentas()
{
    File::WriteAllText("Ventas.txt", "");
    File::WriteAllText("Medicamentos.txt", "");
}

// ================= MAIN =================
int main(array<System::String^>^ args)
{
    ResetVentas();

    Persistance::persistance^ repo = gcnew Persistance::persistance();

    // ================= CREAR MEDICAMENTOS =================
    Dictionary<int, Medicamento^>^ dicMed = gcnew Dictionary<int, Medicamento^>();

    for (int i = 1; i <= 3; i++) {
        Medicamento^ m = gcnew Medicamento(
            i,
            "Med" + i,
            "Compuesto" + i,
            10.0 * i,
            100
        );
        dicMed->Add(i, m);
    }

    repo->GuardarMedicamentos("Medicamentos.txt", dicMed);

    // ================= CREAR VENTAS =================
    Dictionary<int, Medicamento^>^ meds = repo->LeerMedicamentos("Medicamentos.txt");
    Dictionary<int, Venta^>^ dicVentas = gcnew Dictionary<int, Venta^>();

    for (int i = 1; i <= 3; i++) {

        Venta^ v = gcnew Venta(
            i,                  // idVenta
            i,                  // idPaciente
            i + 1,              // cantidadVendida
            meds[i],            // 🔥 Medicamento completo
            DateTime::Now
        );

        dicVentas->Add(i, v);
    }

    repo->GuardarVentas("Ventas.txt", dicVentas);

    // ================= MOSTRAR MEDICAMENTOS =================
    Console::WriteLine("=== INVENTARIO ===");

    for each (KeyValuePair<int, Medicamento^> kvp in dicMed) {
        Medicamento^ m = kvp.Value;

        Console::WriteLine(
            "ID: " + m->id +
            " | Nombre: " + m->nombre +
            " | Precio: " + m->precio +
            " | Stock: " + m->stock
        );
    }

    // ================= MOSTRAR VENTAS =================
    Console::WriteLine("\n=== VENTAS ===");

    Dictionary<int, Venta^>^ ventas = repo->LeerVentas("Ventas.txt");

    for each (KeyValuePair<int, Venta^> kvp in ventas) {
        Venta^ v = kvp.Value;

        Console::WriteLine(
            "Venta ID: " + v->id +
            " | Medicamento: " + v->nombreMedicamento +
            " | Cantidad: " + v->cantidadVendida +
            " | Precio Unitario: " + v->precioMedicamento +
            " | Total: " + v->totalVenta +
            " | Nombre: " + v->nombreMedicamento
        );
    }

    Console::ReadLine();
    return 0;
}