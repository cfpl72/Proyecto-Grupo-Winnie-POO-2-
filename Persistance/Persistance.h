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

        // =========================
        // HISTORIAL RECETAS
        // =========================
        void CrearHistorialSiNoExiste(String^ filePath);

        void SaveHistorialRecetas(String^ filePath, List<Receta^>^ lista);

        void AppendReceta(
            String^ filePath,
            int idReceta,
            int dosis,
            DateTime fecha,
            String^ nombreMedicamento,
            bool entregado
        );

        List<Receta^>^ LoadHistorialRecetas(String^ filePath);
    };

}

namespace Persistance1 {

    public ref class PersistanceManager {
    public:

        String^ GetConnectionString();

        // =========================
        // PACIENTES
        // =========================
        bool InsertPaciente(Paciente^ p);
        Dictionary<int, Paciente^>^ GetAllPacientes();
        Paciente^ GetPacienteById(int id);
        bool UpdatePaciente(Paciente^ p);
        bool DeletePaciente(int id);

        // =========================
        // MEDICAMENTOS
        // =========================
        bool InsertMedicamento(Medicamento^ m);
        Dictionary<int, Medicamento^>^ GetAllMedicamentos();
        Medicamento^ GetMedicamentoById(int id);
        bool UpdateMedicamento(int id, double precio, int stock);
        bool DeleteMedicamento(int id);

        // =========================
        // VENTAS
        // =========================
        bool InsertVenta(Venta^ v);
        Dictionary<int, Venta^>^ GetAllVentas();
        Venta^ GetVentaById(int id);
        bool DeleteVenta(int id);

        // =========================
        // HISTORIAL RECETAS
        // =========================
        void CrearHistorialSiNoExiste(String^ filePath);

        void SaveHistorialRecetas(String^ filePath, List<Receta^>^ lista);

        void AppendReceta(
            String^ filePath,
            int idReceta,
            int dosis,
            DateTime fecha,
            String^ nombreMedicamento,
            bool entregado
        );

        List<Receta^>^ LoadHistorialRecetas(String^ filePath);
    };

}