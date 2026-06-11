#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace WinniePOO_Modelos;
using namespace Persistance;

namespace Controller {

    // =========================
    // PACIENTES
    // =========================
    public ref class ServicioPacientes {
    private:
        PersistanceManager^ repo;
        String^ filePath;

    public:
        ServicioPacientes() {
            repo = gcnew PersistanceManager();
            filePath = "Pacientes.txt";
        }

        Dictionary<int, Paciente^>^ LeerTodos();
        Paciente^ ObtenerPorId(int id);
        bool RegistrarPaciente(int id, String^ token, String^ nombre, String^ apellido,
            int edad, String^ alergias, String^ sintomas);
        void ModificarPaciente(int id, String^ atributo, String^ nuevoValor);
        void EliminarPaciente(int id);

    private:
        String^ GetHistorialPath(int idPaciente);

    public:
        void RegistrarReceta(int idPaciente, int idReceta, int dosis,
            DateTime fecha, String^ nombreMedicamento, bool entregado);
        List<Receta^>^ ObtenerHistorial(int idPaciente);
        void ModificarReceta(int idPaciente, int idReceta, int nuevaDosis, bool nuevoEstado);
        void EliminarReceta(int idPaciente, int idReceta);
        List<String^>^ ExaminarHistorialReceta(int idPaciente);
        List<String^>^ ObtenerNombresPacientes();
    };

    // =========================
    // FARMACÉUTICO
    // =========================
    public ref class ServicioFarmaceutico {
    public:
        static void AlertarPaciente(String^ nombre, String^ mensaje) {
            String^ archivo = "alertas_" + nombre->Replace(" ", "_") + ".txt";
            System::IO::File::AppendAllText(archivo,
                "[" + DateTime::Now.ToString("dd/MM/yyyy HH:mm") + "] " + mensaje + "\n");
        }

        static String^ LeerAlertas(String^ nombre) {
            String^ archivo = "alertas_" + nombre->Replace(" ", "_") + ".txt";
            if (!System::IO::File::Exists(archivo)) return nullptr;
            return System::IO::File::ReadAllText(archivo);
        }
    };

    // =========================
    // MEDICAMENTOS
    // =========================
    public ref class ServicioMedicamentos {
    private:
        PersistanceManager^ repo;
        String^ filePath;

    public:
        ServicioMedicamentos() {
            repo = gcnew PersistanceManager();
            filePath = "Medicamentos.txt";
        }

        bool RegistrarMedicamento(int id, String^ nombre, String^ principioActivo, double precio, int stock);
        List<Medicamento^>^ ObtenerInventarioCompleto();
        Dictionary<int, Medicamento^>^ ObtenerDiccionarioCompleto();
        bool ActualizarMedicamento(int id, double nuevoPrecio, int nuevoStock);

        // ── SEED: puebla Medicamentos.txt si está vacío ──────────────────────
        void SeedMedicamentosDemo();
    };

    // =========================
    // VENTAS
    // =========================
    public ref class ServicioVentas {
    private:
        PersistanceManager^ repo;
        String^ filePath;

    public:
        ServicioVentas() {
            repo = gcnew PersistanceManager();
            filePath = "Ventas.txt";
        }

        bool RegistrarVenta(int idVenta, int idPaciente, int idMedicamento, int cantidad);
        Venta^ LeerVenta(int idVenta);
        List<Venta^>^ ObtenerTodasLasVentas();
        bool ModificarVenta(int idVenta, int nuevaCantidadVendida);
        bool EliminarVenta(int idVenta);
        String^ MostrarBoletaVenta(int idVenta);

        // ── SEED: puebla Ventas.txt si está vacío ────────────────────────────
        void SeedVentasDemo();
    };

    // =========================
    // AUTENTICACIÓN (LOGIN)
    // =========================
    public ref class ServicioAutenticacion {
    private:
        ServicioPacientes^ pacientesService;

    public:
        ServicioAutenticacion() {
            pacientesService = gcnew ServicioPacientes();
        }

        bool ValidarAcceso(String^ rol, String^ usuarioDNI, String^ password);
    };

} // FIN DEL NAMESPACE CONTROLLER