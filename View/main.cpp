#include "pch.h"
#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace WinniePOOview;
using namespace IA_CLASS;
using namespace Controller;

//[STAThreadAttribute]
//int main(array<System::String^>^ args)
//{
//    Application::EnableVisualStyles();
//    Application::SetCompatibleTextRenderingDefault(false);
//    Application::Run(gcnew LoginForm());
//    return 0;
//}


int main(array<System::String^>^ args)
{
    Console::WriteLine("=== INICIO TEST SISTEMA ===");

    ServicioPacientes^ servPac = gcnew ServicioPacientes();
    ServicioMedicamentos^ servMed = gcnew ServicioMedicamentos();
    ServicioVentas^ servVen = gcnew ServicioVentas();

    // =========================
    // 👤 PACIENTES
    // =========================
    Console::WriteLine("\n=== PACIENTES ===");

    bool creadoPac = servPac->RegistrarPaciente(1, "token1", "Claudio", "Test", 25, "Ninguna", "Fiebre");
    Console::WriteLine("Crear paciente: " + creadoPac);

    Paciente^ p = servPac->ObtenerPorId(1);
    if (p != nullptr)
        Console::WriteLine("Paciente leído: " + p->nombre);

    servPac->ModificarPaciente(1, "edad", "30");
    p = servPac->ObtenerPorId(1);
    if (p != nullptr)
        Console::WriteLine("Edad actualizada: " + p->edad);

    // =========================
    // 💊 MEDICAMENTOS
    // =========================
    Console::WriteLine("\n=== MEDICAMENTOS ===");

    bool creadoMed = servMed->RegistrarMedicamento(10, "Paracetamol", "Acetaminofén", 2.5, 100);
    Console::WriteLine("Crear medicamento: " + creadoMed);

    auto meds = servMed->ObtenerInventarioCompleto();
    for each (Medicamento ^ m in meds) {
        Console::WriteLine("Med: " + m->id + " | " + m->nombre + " | Stock: " + m->stock);
    }

    servMed->ActualizarMedicamento(10, 3.0, 80);

    auto dicMed = servMed->ObtenerDiccionarioCompleto();
    if (dicMed->ContainsKey(10))
        Console::WriteLine("Precio actualizado: " + dicMed[10]->precio);

    // =========================
    // 💰 VENTAS
    // =========================
    Console::WriteLine("\n=== VENTAS ===");

    bool ventaOk = servVen->RegistrarVenta(100, 1, 10, 5);
    Console::WriteLine("Registrar venta: " + ventaOk);

    Venta^ v = servVen->LeerVenta(100);
    if (v != nullptr) {
        Console::WriteLine("Venta leída:");
        Console::WriteLine("ID: " + v->id);
        Console::WriteLine("Paciente: " + v->idPaciente);
        Console::WriteLine("Medicamento: " + v->nombreMedicamento);
        Console::WriteLine("Cantidad: " + v->cantidadVendida);
        Console::WriteLine("Total: " + v->totalVenta);
    }

    // Verificar reducción de stock
    dicMed = servMed->ObtenerDiccionarioCompleto();
    if (dicMed->ContainsKey(10))
        Console::WriteLine("Stock después de venta: " + dicMed[10]->stock);

    // =========================
    // 📋 LISTAR TODO
    // =========================
    Console::WriteLine("\n=== LISTAR VENTAS ===");

    auto ventas = servVen->ObtenerTodasLasVentas();
    for each (Venta ^ venta in ventas) {
        Console::WriteLine("Venta ID: " + venta->id + " | Total: " + venta->totalVenta);
    }

    // =========================
    // 🔴 DELETE
    // =========================
    Console::WriteLine("\n=== ELIMINACIONES ===");

    bool delVenta = servVen->EliminarVenta(100);
    Console::WriteLine("Eliminar venta: " + delVenta);

    bool delMed = servMed->EliminarMedicamento(10);
    Console::WriteLine("Eliminar medicamento: " + delMed);

    servPac->EliminarPaciente(1);
    Console::WriteLine("Paciente eliminado");

    Console::WriteLine("\n=== FIN TEST ===");
    Console::ReadKey();

    return 0;
}