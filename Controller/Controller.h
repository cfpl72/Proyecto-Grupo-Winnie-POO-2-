#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace WinniePOO_Modelos; // Para usar las clases de modelos sin necesidad de prefijo
using namespace Persistance;

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

	public ref class ServicioUsuarios {
	public:

		Dictionary<int, Usuario^>^ usuarios = gcnew Dictionary<int, Usuario^>();


		//=====================Pacientes==================================================
		// CREATE
		void RegistrarPaciente(int id, String^ nombre, String^ apellido,
			String^ contrasenia, int edad, String^ alergias, String^ sintomas) {

			// 1. Generar token
			String^ token = WinniePOO_Modelos::Utils::GetMD5Hash(nombre + contrasenia);

			// 2. Crear paciente
			Paciente^ paciente = gcnew Paciente(nombre, token);

			// 3. Asignar datos
			paciente->id = id;
			paciente->apellido = apellido;
			paciente->contrasenia = contrasenia;
			paciente->edad = edad;
			paciente->alergias = alergias;
			paciente->sintomas = sintomas;

			// 4. Guardar en archivo
			//Persistance::persistance::SaveDataToText("PacientesPersistance.txt", paciente);

			Console::WriteLine("Paciente registrado correctamente: " + nombre);
		}

		// READ (por ID)
		Usuario^ ObtenerUsuario(int id) {
			if (usuarios->ContainsKey(id)) {
				return usuarios[id];
			}
			else {
				Console::WriteLine("Error: Usuario no encontrado.");
				return nullptr;
			}
		}

		// READ (todos)
		void ListarUsuarios() {
			if (usuarios->Count == 0) {
				Console::WriteLine("No hay usuarios registrados.");
				return;
			}

			for each (KeyValuePair<int, Usuario^> kvp in usuarios) {
				Usuario^ u = kvp.Value;
				Console::WriteLine("ID: " + u->id +
					" | Nombre: " + u->nombre +
					" " + u->apellido);
			}
		}

		// UPDATE (genérico)
		void ModificarUsuario(int id, String^ nuevoNombre, String^ nuevoApellido, String^ nuevaContrasenia) {
			if (usuarios->ContainsKey(id)) {
				Usuario^ u = usuarios[id];
				u->nombre = nuevoNombre;
				u->apellido = nuevoApellido;
				u->contrasenia = nuevaContrasenia;

				Console::WriteLine("Usuario modificado correctamente.");
			}
			else {
				Console::WriteLine("Error: Usuario no encontrado.");
			}
		}

		// UPDATE específico para Paciente
		void ModificarPaciente(int id, int nuevaEdad, String^ nuevasAlergias, String^ nuevosSintomas) {
			if (usuarios->ContainsKey(id)) {
				Paciente^ p = dynamic_cast<Paciente^>(usuarios[id]);

				if (p != nullptr) {
					p->edad = nuevaEdad;
					p->alergias = nuevasAlergias;
					p->sintomas = nuevosSintomas;

					Console::WriteLine("Paciente modificado correctamente.");
				}
				else {
					Console::WriteLine("Error: El usuario no es un paciente.");
				}
			}
			else {
				Console::WriteLine("Error: Usuario no encontrado.");
			}
		}

		// DELETE
		void EliminarUsuario(int id) {
			if (usuarios->ContainsKey(id)) {
				usuarios->Remove(id);
				Console::WriteLine("Usuario eliminado correctamente.");
			}
			else {
				Console::WriteLine("Error: No se encontró el usuario.");
			}
		}

		// EXTRA: Filtrar por tipo
		void ListarPacientes() {
			for each (KeyValuePair<int, Usuario^> kvp in usuarios) {
				Paciente^ p = dynamic_cast<Paciente^>(kvp.Value);
				if (p != nullptr) {
					Console::WriteLine("Paciente: " + p->nombre + " | Edad: " + p->edad);
				}
			}
		}

		void ListarFarmaceuticos() {
			for each (KeyValuePair<int, Usuario^> kvp in usuarios) {
				Farmaceutico^ f = dynamic_cast<Farmaceutico^>(kvp.Value);
				if (f != nullptr) {
					Console::WriteLine("Farmacéutico: " + f->nombre);
				}
			}
		}
	};


	}
