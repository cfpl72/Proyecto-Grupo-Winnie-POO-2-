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
    Console::WriteLine("=== TEST CRUD COMPLETO ===");

    ServicioPacientes^ servPac = gcnew ServicioPacientes();
    ServicioMedicamentos^ servMed = gcnew ServicioMedicamentos();

    // =========================
    // 🧪 PACIENTES
    // =========================

    Console::WriteLine("\n=== PACIENTES ===");

    // CREATE
    Console::WriteLine("\n--- CREATE PACIENTE ---");
    bool creado = servPac->RegistrarPaciente(1001, "token1001", "Claudio", "Test", 25, "Ninguna", "Fiebre");
    Console::WriteLine("Creado: " + creado);

    // READ ALL
    Console::WriteLine("\n--- READ ALL PACIENTES ---");
    auto pacientes = servPac->LeerTodos();
    for each (auto kv in pacientes) {
        Console::WriteLine("ID: " + kv.Value->id + " | Nombre: " + kv.Value->nombre);
    }

    // READ BY ID
    Console::WriteLine("\n--- READ BY ID ---");
    auto p = servPac->ObtenerPorId(1001);
    if (p != nullptr)
        Console::WriteLine("Encontrado: " + p->nombre);

    // UPDATE
    Console::WriteLine("\n--- UPDATE ---");
    servPac->ModificarPaciente(1001, "edad", "30");
    p = servPac->ObtenerPorId(1001);
    if (p != nullptr)
        Console::WriteLine("Edad actualizada: " + p->edad);

    // DELETE
    Console::WriteLine("\n--- DELETE ---");
    servPac->EliminarPaciente(1001);
    p = servPac->ObtenerPorId(1001);
    Console::WriteLine(p == nullptr ? "Eliminado correctamente" : "Error al eliminar");


    // =========================
    // 💊 MEDICAMENTOS
    // =========================

    Console::WriteLine("\n=== MEDICAMENTOS ===");

    // CREATE
    Console::WriteLine("\n--- CREATE MEDICAMENTO ---");
    bool creadoMed = servMed->RegistrarMedicamento(2001, "TestMed", "ActivoX", 5.5, 20);
    Console::WriteLine("Creado: " + creadoMed);

    // READ ALL
    Console::WriteLine("\n--- READ ALL MEDICAMENTOS ---");
    auto meds = servMed->ObtenerInventarioCompleto();
    for each (Medicamento ^ m in meds) {
        Console::WriteLine("ID: " + m->id + " | Nombre: " + m->nombre + " | Stock: " + m->stock);
    }

    // READ BY ID (usando repo indirectamente)
    Console::WriteLine("\n--- READ BY ID ---");
    auto dic = servMed->ObtenerDiccionarioCompleto();
    if (dic->ContainsKey(2001))
        Console::WriteLine("Encontrado: " + dic[2001]->nombre);

    // UPDATE
    Console::WriteLine("\n--- UPDATE ---");
    servMed->ActualizarMedicamento(2001, 9.9, 99);
    dic = servMed->ObtenerDiccionarioCompleto();
    if (dic->ContainsKey(2001))
        Console::WriteLine("Nuevo Precio: " + dic[2001]->precio + " | Nuevo Stock: " + dic[2001]->stock);

    // DELETE
    Console::WriteLine("\n--- DELETE ---");
    bool eliminadoMed = servMed->EliminarMedicamento(2001);
    Console::WriteLine(eliminadoMed ? "Eliminado correctamente" : "Error al eliminar");

    dic = servMed->ObtenerDiccionarioCompleto();
    Console::WriteLine(dic->ContainsKey(2001) ? "Aún existe" : "Confirmado eliminado");

    Console::WriteLine("\n=== FIN TEST ===");
    Console::ReadKey();

    return 0;
}