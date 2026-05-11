#include "pch.h"


using namespace System;
using namespace IA_CLASS;


int main(array<String^>^ args)
{
    // Creamos la IA
    IA^ sistemaIA = gcnew IA();

    // Simulación de datos del paciente
    String^ sintomas = "dolor de cabeza intenso y fiebre";
    String^ historial = "alergia a la penicilina";

    // Simulación de stock del sistema (como si viniera de tu archivo Medicamentos.txt)
    String^ listaMedicamentos = "Paracetamol, Ibuprofeno, Aspirina";

    Console::WriteLine("=== SIMULACIÓN FARMACIA ROBÓTICA ===");
    Console::WriteLine("Síntomas: " + sintomas);
    Console::WriteLine("Historial: " + historial);
    Console::WriteLine("Stock disponible: " + listaMedicamentos);
    Console::WriteLine("\nGenerando recomendación...\n");

    // Llamada a la IA
    String^ recomendacion = sistemaIA->GenerarRecomendacion(sintomas, historial, listaMedicamentos);

    // Resultado
    Console::WriteLine("=== RECOMENDACIÓN ===");
    Console::WriteLine(recomendacion);

    Console::WriteLine("\nPresiona cualquier tecla para salir...");
    Console::ReadKey();

    return 0;
}