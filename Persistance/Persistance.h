#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace WinniePOO_Modelos;
using namespace System::IO;

namespace Persistance {

    public ref class persistance {
    public:

        static bool exists(String^ filePath);

        // ================= PACIENTE =================
        static void RegistrarPaciente(String^ filePath, Paciente^ p);
        static void GuardarPacientes(String^ filePath, Dictionary<int, Paciente^>^ diccionario);
        static Paciente^ LeerPaciente(String^ filePath, int idPaciente);
        static void EliminarPaciente(String^ filePath, int idPaciente);

        // ================= MEDICAMENTO =================
        static void RegistrarMedicamento(String^ filePath, Medicamento^ med);
        static void GuardarMedicamentos(String^ filePath, Dictionary<int, Medicamento^>^ diccionario);
        static Dictionary<int, Medicamento^>^ LeerMedicamentos(String^ filePath);

        // ================= VENTA =================
        static void RegistrarVenta(String^ filePath, Venta^ v);
        static void GuardarVentas(String^ filePath, Dictionary<int, Venta^>^ diccionario);
        static Dictionary<int, Venta^>^ LeerVentas(String^ filePath);

    };
}