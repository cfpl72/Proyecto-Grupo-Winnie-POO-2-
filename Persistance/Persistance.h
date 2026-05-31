#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace WinniePOO_Modelos;

namespace Persistance {

    public ref class PersistanceManager {
    public:

        // =========================
        // PACIENTES
        // =========================
        void SavePacientes(String^ filePath, Dictionary<int, Paciente^>^ dic);
        Dictionary<int, Paciente^>^ LoadPacientes(String^ filePath);

        // =========================
        // MEDICAMENTOS
        // =========================
        void SaveMedicamentos(String^ filePath, Dictionary<int, Medicamento^>^ dic);
        Dictionary<int, Medicamento^>^ LoadMedicamentos(String^ filePath);

        // =========================
        // VENTAS
        // =========================
        void SaveVentas(String^ filePath, Dictionary<int, Venta^>^ dic);
        Dictionary<int, Venta^>^ LoadVentas(String^ filePath);
    };

}