#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace WinniePOO_Modelos; // Para usar las clases de modelos sin necesidad de prefijo
using namespace Persistance;
using namespace System::Collections::Generic;
using namespace System::IO;

namespace Controller {

	/*public ref class FarmaceuticoController {
	private:
		Persistance::persistance^ repo;
		String^ filePath;

	public:
		VentaController(String^ path) {
			repo = gcnew Persistance::persistance();
			filePath = path;
		}


		Venta^ ObtenerPorId(int id);
		void Registrar(Venta^ v);
		void Modificar(int id, String^ atributo, String^ nuevoValor);
		void Eliminar(int id);
		bool ValidarPaciente(Venta^ v, String^% error);
	};*/

	//===================== CONTROLADOR DE PACIENTES =====================
	public ref class PacienteController {
	private:
		Persistance::persistance^ repo;
		String^ filePath;

	public:
		PacienteController(String^ path) {
			repo = gcnew Persistance::persistance();
			filePath = path;
		}

		Dictionary<int, Paciente^>^ Controller::PacienteController::LeerTodos();
		Paciente^ ObtenerPorId(int id);
		void Registrar(Paciente^ p);
		void Modificar(int id, String^ atributo, String^ nuevoValor);
		void Eliminar(int id);
		bool ValidarPaciente(Paciente^ p, String^% error);

	};

    public ref class OperadorDeVentasController
    {
    private:
		Persistance::persistance^ repo;
		String^ filePath;

	public:
		OperadorDeVentasController() {
			repo = gcnew Persistance::persistance();
		}

		List<Medicamento^>^ Controller::OperadorDeVentasController::ObtenerInventarioCompleto();
		List<Venta^>^ Controller::OperadorDeVentasController::ObtenerTodasLasVentas();
		bool BotonActualizar(int id, double nuevoPrecio, int nuevoStock);
		/*Medicamento^ ObtenerPorId(int id);
		void Registrar(Medicamento^ p);
		void Modificar(int id, String^ atributo, String^ nuevoValor);
		void Eliminar(int id);

		List<Medicamento^>^ ObtenerInventarioCompleto();*/
    };
}