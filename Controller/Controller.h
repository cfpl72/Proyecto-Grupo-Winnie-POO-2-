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
}