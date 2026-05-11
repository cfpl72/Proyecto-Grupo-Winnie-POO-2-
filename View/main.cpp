#include "pch.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace Controller;
using namespace WinniePOO_Modelos;
using namespace Persistance;

void Esperar() {
    Console::WriteLine("\nPresiona ENTER para continuar...");
    Console::ReadLine();
}

void MostrarPacientes(Controller::PacienteController^ pc) {
    auto dic = pc->LeerTodos();

    Console::WriteLine("\n--- PACIENTES ---");
    for each (KeyValuePair<int, Paciente^> kvp in dic) {
        auto p = kvp.Value;
        Console::WriteLine("ID:{0} | {1} {2} | Edad:{3}",
            p->id, p->nombre, p->apellido, p->edad);
    }
}

void MostrarMedicamentos(Dictionary<int, Medicamento^>^ dic) {
    Console::WriteLine("\n--- MEDICAMENTOS ---");
    for each (KeyValuePair<int, Medicamento^> kvp in dic) {
        auto m = kvp.Value;
        Console::WriteLine("ID:{0} | {1} | Precio:{2} | Stock:{3}",
            m->idMedicamento, m->nombre, m->precio, m->stock);
    }
}

void MostrarVentas(Dictionary<int, Venta^>^ dic) {
    Console::WriteLine("\n--- VENTAS ---");
    for each (KeyValuePair<int, Venta^> kvp in dic) {
        auto v = kvp.Value;
        Console::WriteLine("ID:{0} | Paciente:{1} | Med:{2} | Cant:{3} | Fecha:{4}",
            v->id, v->idPaciente, v->idMedicamento,
            v->cantidadVendida, v->fecha->ToShortDateString());
    }
}

int main(array<System::String^>^ args)
{
    
   

    String^ pathPac = "Pacientes.txt";
    String^ pathMed = "Medicamentos.txt";
    String^ pathVen = "Ventas.txt";

    Controller::PacienteController^ pc = gcnew Controller::PacienteController(pathPac);

    Console::WriteLine("=== INICIO ESCENARIO INTEGRADO ===");

    // 🔹 1. Limpiar todo
    File::WriteAllText(pathPac, "");
    File::WriteAllText(pathMed, "");
    File::WriteAllText(pathVen, "");

    Esperar();

    // 🔹 2. Registrar pacientes
    Console::WriteLine("Registrando pacientes...");

    for (int i = 1; i <= 3; i++) {
        Paciente^ p = gcnew Paciente(i, "token" + i);
        p->nombre = "Paciente" + i;
        p->apellido = "Test";
        p->edad = 20 + i;
        p->alergias = "Ninguna";
        p->sintomas = "Leve";

        pc->Registrar(p);
    }

    MostrarPacientes(pc);
    Esperar();

    // 🔹 3. Registrar medicamentos
    Console::WriteLine("Registrando medicamentos...");

    Dictionary<int, Medicamento^>^ meds = gcnew Dictionary<int, Medicamento^>();

    meds->Add(1, gcnew Medicamento(1, "Paracetamol", "Acetaminofen", 5.5, 100));
    meds->Add(2, gcnew Medicamento(2, "Ibuprofeno", "Ibuprofeno", 8.0, 50));
    meds->Add(3, gcnew Medicamento(3, "Amoxicilina", "Amoxicilina", 12.0, 30));

    Persistance::persistance::GuardarMedicamentos(pathMed, meds);

    meds = Persistance::persistance::LeerMedicamentos(pathMed);
    MostrarMedicamentos(meds);

    Esperar();

    // 🔹 4. Registrar ventas
    Console::WriteLine("Registrando ventas...");

    Dictionary<int, Venta^>^ ventas = gcnew Dictionary<int, Venta^>();

    ventas->Add(1, gcnew Venta(1, 1, 2, DateTime::Now, meds[1]));
    ventas->Add(2, gcnew Venta(2, 2, 1, DateTime::Now, meds[2]));
    ventas->Add(3, gcnew Venta(3, 3, 3, DateTime::Now, meds[3]));

    Persistance::persistance::GuardarVentas(pathVen, ventas);

    ventas = Persistance::persistance::LeerVentas(pathVen);
    MostrarVentas(ventas);

    Esperar();

    // 🔹 5. Flujo real: modificar + vender
    Console::WriteLine("Actualizando stock y registrando nueva venta...");

    meds[1]->ActualizarStock(meds[1]->stock - 5);

    ventas->Add(4, gcnew Venta(4, 1, 5, DateTime::Now, meds[1]));

    Persistance::persistance::GuardarMedicamentos(pathMed, meds);
    Persistance::persistance::GuardarVentas(pathVen, ventas);

    MostrarMedicamentos(meds);
    MostrarVentas(ventas);

    Esperar();

    Console::WriteLine("=== FIN ESCENARIO ===");

    return 0;
}