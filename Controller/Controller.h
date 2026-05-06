#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace WinniePOO_Modelos; // Para usar las clases de modelos sin necesidad de prefijo
using namespace Persistance;
using namespace System::Collections::Generic;
using namespace System::IO;

namespace Controller {

	public ref class ServicioVenta {
	public:

		Dictionary<int, Venta^>^ ventas = gcnew Dictionary<int, Venta^>();

		// CREATE
		Venta^ RegistrarNuevaVenta(int idVenta, int idPaciente, Medicamento^ medicamento, int cantidad, DateTime^ fecha) {
			if (ventas->ContainsKey(idVenta)) {
				Console::WriteLine("Error: Ya existe una venta con ese ID.");
				return nullptr;
			}

			Venta^ nuevaVenta = gcnew Venta(idVenta, idPaciente, cantidad, fecha, medicamento);
			ventas->Add(idVenta, nuevaVenta);

			Console::WriteLine("Venta registrada correctamente.");
			return nuevaVenta;
		}

		// READ (por ID)
		Venta^ ObtenerVenta(int id) {
			if (ventas->ContainsKey(id)) {
				return ventas[id];
			}
			else {
				Console::WriteLine("Error: Venta no encontrada.");
				return nullptr;
			}
		}

		// READ (todas)
		void ListarVentas() {
			if (ventas->Count == 0) {
				Console::WriteLine("No hay ventas registradas.");
				return;
			}

			for each (KeyValuePair<int, Venta^> kvp in ventas) {
				Venta^ v = kvp.Value;
				Console::WriteLine("ID: " + v->id +
					" | Paciente: " + v->idPaciente +
					" | Cantidad: " + v->cantidadVendida +
					" | Fecha: " + v->fecha);
			}
		}

		// UPDATE
		void ModificarVenta(int id, int nuevaCantidad, Medicamento^ nuevoMedicamento) {
			if (ventas->ContainsKey(id)) {
				Venta^ venta = ventas[id];
				venta->cantidadVendida = nuevaCantidad;
				venta->medicamento = nuevoMedicamento;

				Console::WriteLine("Venta modificada correctamente.");
			}
			else {
				Console::WriteLine("Error: No se encontró la venta.");
			}
		}

		// DELETE
		void EliminarVenta(int id) {
			if (ventas->ContainsKey(id)) {
				ventas->Remove(id);
				Console::WriteLine("Venta eliminada correctamente.");
			}
			else {
				Console::WriteLine("Error: No se encontró una venta con ese ID.");
			}
		}

		// EXTRA: Historial por paciente
		void VerHistorialPaciente(int idPaciente) {
			bool encontrado = false;

			for each (KeyValuePair<int, Venta^> kvp in ventas) {
				Venta^ v = kvp.Value;
				if (v->idPaciente == idPaciente) {
					Console::WriteLine("ID Venta: " + v->id +
						" | Cantidad: " + v->cantidadVendida +
						" | Fecha: " + v->fecha);
					encontrado = true;
				}
			}

			if (!encontrado) {
				Console::WriteLine("No se encontraron ventas para este paciente.");
			}
		}
	};


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
}