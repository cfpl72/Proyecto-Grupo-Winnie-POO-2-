#pragma once
using namespace System;
using namespace System::Collections::Generic;


namespace Controller {

    using namespace WinniePOO_Modelos;
    using namespace Persistance;

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


        // Sección Pacientes
        Dictionary<int, Paciente^>^ LeerTodos();
        Paciente^ ObtenerPorId(int id);
        bool RegistrarPaciente(int id, String^ token, String^ nombre, String^ apellido,
            int edad, String^ alergias, String^ sintomas);
        void ModificarPaciente(int id, String^ atributo, String^ nuevoValor);
        void EliminarPaciente(int id);

        // Sección Recetas
    private:
        String^ GetHistorialPath(int idPaciente);

    public:
        void RegistrarReceta(
            int idPaciente,
            int idReceta,
            int dosis,
            DateTime fecha,
            String^ nombreMedicamento,
            bool entregado
        );

        List<Receta^>^ ObtenerHistorial(int idPaciente);

        void ModificarReceta(
            int idPaciente,
            int idReceta,
            int nuevaDosis,
            bool nuevoEstado
        );

        void EliminarReceta(
            int idPaciente,
            int idReceta
        );


        List<String^>^ ExaminarHistorialReceta(int idPaciente);
        List<String^>^ ObtenerNombresPacientes();

    }; // FIN DE LA CLASE SERVICIO PACIENTES

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
            if (!System::IO::File::Exists(archivo))
                return nullptr;

            String^ contenido = System::IO::File::ReadAllText(archivo);
            System::IO::File::Delete(archivo);
            return contenido;
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

        // Para validar el acceso
        bool ValidarAcceso(String^ rol, String^ usuarioDNI, String^ password);
    };

} // FIN DEL NAMESPACE CONTROLLER

namespace Controller1 {

    using namespace WinniePOO_Modelos1;
    using namespace Persistance1;

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


        // Sección Pacientes
        Dictionary<int, Paciente^>^ LeerTodos();
        Paciente^ ObtenerPorId(int id);
        bool RegistrarPaciente(int id, String^ token, String^ nombre, String^ apellido,
            int edad, String^ alergias, String^ sintomas);
        void ModificarPaciente(int id, String^ atributo, String^ nuevoValor);
        void EliminarPaciente(int id);

        // Sección Recetas
    private:
        String^ GetHistorialPath(int idPaciente);

    public:
        void RegistrarReceta(int idPaciente, int idReceta, int idMedicamento, int dosis, DateTime fecha, bool entregado);

        List<Receta^>^ ObtenerHistorial(int idPaciente);

        void ModificarReceta(int idReceta, int nuevaDosis, bool nuevoEstado);

        void EliminarReceta(int idReceta);

        List<String^>^ ExaminarHistorialReceta(int idPaciente);

        List<String^>^ ObtenerNombresPacientes();

    }; // FIN DE LA CLASE SERVICIO PACIENTES

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

        // ── NUEVO: Lee y devuelve todas las alertas de un paciente ─────────────
        static String^ LeerAlertas(String^ nombre) {
            String^ archivo = "alertas_" + nombre->Replace(" ", "_") + ".txt";
            if (!System::IO::File::Exists(archivo))
                return nullptr;   // sin alertas
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
        bool EliminarMedicamento(int id);
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

        // Para validar el acceso
        bool ValidarAcceso(String^ rol, String^ usuarioDNI, String^ password);
    };

} // FIN DEL NAMESPACE CONTROLLER