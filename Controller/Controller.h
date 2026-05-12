#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace WinniePOO_Modelos;
using namespace Persistance;
using namespace System::IO;

namespace Controller {

    public ref class ServicioPacientes {
    private:
        Persistance::persistance^ repo;
        String^ filePath;

    public:
        ServicioPacientes() {
            repo = gcnew Persistance::persistance();
            filePath = "Pacientes.txt";
        }

        Dictionary<int, Paciente^>^ LeerTodos();
        Paciente^ ObtenerPorId(int id);
        bool RegistrarPaciente(
            int id, String^ token, String^ nombre, String^ apellido,
            int edad, String^ alergias, String^ sintomas);
        void ModificarPaciente(int id, String^ atributo, String^ nuevoValor);
        void EliminarPaciente(int id);
        bool ValidarPaciente(Paciente^ p, String^% error);
    };

    public ref class ServicioMedicamentos {
    private:
        Persistance::persistance^ repo;
        String^ filePath;

    public:
        ServicioMedicamentos() {
            repo = gcnew Persistance::persistance();
            filePath = "Medicamentos.txt";
        }

        bool RegistrarMedicamento(
            int id, String^ nombre, String^ principioActivo,
            double precio, int stock);
        List<Medicamento^>^ ObtenerInventarioCompleto();
        Dictionary<int, Medicamento^>^ Controller::ServicioMedicamentos::ObtenerDiccionarioCompleto();
        bool ActualizarMedicamento(int id, double nuevoPrecio, int nuevoStock);
    };

    public ref class ServicioVentas {
    private:
        Persistance::persistance^ repo;
        String^ filePath;

    public:
        ServicioVentas() {
            repo = gcnew Persistance::persistance();
            filePath = "Ventas.txt";
        }

        bool RegistrarVenta(
            int idVenta, int idPaciente, int idMedicamento, int cantidad);
        Venta^ Controller::ServicioVentas::LeerVenta(int idVenta);
        List<Venta^>^ ObtenerTodasLasVentas();
        bool ModificarVenta(int idVenta, int nuevaCantidadVendida);
        bool EliminarVenta(int idVenta);
        String^ Controller::ServicioVentas::MostrarBoletaVenta(int idVenta);

    };
}

