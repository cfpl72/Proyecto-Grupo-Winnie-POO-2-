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

    for (int i = 1; i <= 3; i++) {
        String^ path = "Repositorio_Historial_Recetas\\Historial_Recetas_" + i + ".txt";
        if (File::Exists(path)) File::Delete(path);
    }
}

void MostrarLista(List<String^>^ lista) {
    for each (String ^ linea in lista) {
        Console::WriteLine(linea);
    }
}

void Pausa() {
    Console::WriteLine("\n(ENTER para continuar)");
    Console::ReadLine();
}

int main(array<System::String^>^ args)
{
    Reset();

    ServicioPacientes^ sp = gcnew ServicioPacientes();

    Console::WriteLine("=== ESCENARIO: VISUALIZACIÓN DE HISTORIAL ===");

    // =========================
    // CREAR PACIENTE
    // =========================
    Console::WriteLine("\n→ Creando paciente...");
    sp->RegistrarPaciente(1, "t1", "Claudio", "Rios", 21, "Ninguna", "Dolor cabeza");
    Pausa();

    // =========================
    // GENERAR RECETAS
    // =========================
    Console::WriteLine("\n→ Generando recetas...");

    sp->RegistrarReceta(1, 1, 1, DateTime(2026, 4, 3), "Ibuprofeno 400mg", true);
    sp->RegistrarReceta(1, 2, 2, DateTime(2026, 4, 4), "Paracetamol 500mg", false);
    sp->RegistrarReceta(1, 3, 1, DateTime(2026, 4, 5), "Amoxicilina 500mg", true);

    Console::WriteLine("\nHistorial inicial:");
    MostrarLista(sp->ExaminarHistorialReceta(1));
    Pausa();

    // =========================
    // MODIFICACIÓN
    // =========================
    Console::WriteLine("\n→ Corrigiendo receta 2...");
    sp->ModificarReceta(1, 2, 1, true);

    Console::WriteLine("\nHistorial tras corrección:");
    MostrarLista(sp->ExaminarHistorialReceta(1));
    Pausa();

    // =========================
    // ELIMINACIÓN
    // =========================
    Console::WriteLine("\n→ Eliminando receta 1...");
    sp->EliminarReceta(1, 1);

    Console::WriteLine("\nHistorial final:");
    MostrarLista(sp->ExaminarHistorialReceta(1));
    Pausa();

    // =========================
    // SEGUNDO PACIENTE
    // =========================
    Console::WriteLine("\n→ Segundo paciente...");

    sp->RegistrarPaciente(2, "t2", "Ana", "Lopez", 30, "Penicilina", "Fiebre");

    sp->RegistrarReceta(2, 10, 1, DateTime(2026, 4, 6), "Loratadina 10mg", true);

    Console::WriteLine("\nHistorial paciente 2:");
    MostrarLista(sp->ExaminarHistorialReceta(2));
    Pausa();

    Console::WriteLine("\n=== FIN ===");

    return 0;
}