#include "pch.h"

using namespace System;
using namespace System::Collections::Generic;


namespace WinniePOO_Modelos {
	// 1. CLASES BASE Y DE DATOS (No dependen de otras clases)

	public ref class Medicamento {
	public:
		int idMedicamento;
		String^ nombre;
		String^ principioActivo;
		double precio;
		int stock;
	private:
		// Encapsulamiento: estos métodos son privados según el diagrama
		void SetPrecio(double nuevoPrecio) {
			precio = nuevoPrecio;
		}
		void SetStock(int nuevoStock) {
			stock = nuevoStock;
		}
	public:
		// Constructor para facilitar la creación de medicamentos
		Medicamento(int id, String^ nom, String^ pActivo, double prec, int stk) {
			idMedicamento = id;
			nombre = nom;
			principioActivo = pActivo;
			precio = prec;
			stock = stk;
		}
		// Métodos públicos para que el Operador de Ventas pueda usar los métodos privados
		void ActualizarPrecio(double nuevoPrecio) { SetPrecio(nuevoPrecio); }
		void ActualizarStock(int nuevoStock) { SetStock(nuevoStock); }
	};
	public ref class Receta {
	public:
		int idReceta;
		int dosis;
		DateTime fechaEmision;
		Medicamento^ medicamento; // Relación con el Medicamento
		bool entregado;
		void EmitirReporte() {
			Console::WriteLine("Emitiendo reporte detallado de la receta " + idReceta);
		}
		void MostrarResumenCorto() {
			if (medicamento != nullptr) {
				Console::WriteLine("Resumen: " + medicamento->nombre + " - Dosis: " + dosis);
			}
		}
	};
	// 2. SISTEMA DE USUARIOS (Jerarquía de Herencia)

	public ref class Usuario {
	public:
		int id;
		String^ contrasenia;
		String^ verificationToken;
		String^ nombre;
		String^ apellido;

		// Constructor
		Usuario(String^ nombre, String^ token) {
			this->nombre = nombre;
			this->verificationToken = token;
		}

		bool autentificar(String^ contrasena);
	};


	// ---------------- PACIENTE ----------------

	public ref class Paciente : public Usuario {
	public:
		int edad;
		String^ alergias;
		String^ sintomas;
		List<Receta^>^ historialRecetas;

		Paciente(String^ nombre, String^ token)
			: Usuario(nombre, token)  // 🔥 llamada al constructor base
		{
			historialRecetas = gcnew List<Receta^>();
		}
	};


	// ---------------- FARMACEUTICO ----------------

	public ref class Farmaceutico : public Usuario {
	public:
		Farmaceutico(String^ nombre, String^ token)
			: Usuario(nombre, token) {
		}

		String^ AlertarPaciente() {
			return "ALERTA: Verifique sus alergias antes de consumir el medicamento recomendado.";
		}

		void ExaminarReceta(Paciente^ paciente) {
			Console::WriteLine("Examinando receta del paciente: " + paciente->nombre);
		}
	};


	// ---------------- OPERADOR DE VENTAS ----------------

	public ref class OperadorVentas : public Usuario {
	public:
		OperadorVentas(String^ nombre, String^ token)
			: Usuario(nombre, token) {
		}

		void ActualizarPrecio(Medicamento^ medicamento, double nuevoPrecio) {
			medicamento->ActualizarPrecio(nuevoPrecio);
			Console::WriteLine("Precio actualizado exitosamente.");
		}

		void ModificarStock(Medicamento^ medicamento, int cantidad) {
			medicamento->ActualizarStock(cantidad);
			Console::WriteLine("Stock modificado exitosamente.");
		}
	};

	// 3. TRANSACCIONES, VENTAS Y PAGOS
	public ref class Venta {
	public:
		int id;
		int idPaciente; // Para relacionar la venta con el paciente que la realizó
		int cantidadVendida;
		DateTime^ fecha;
		Medicamento^ medicamento; // Relación con el Medicamento vendido


		//Constructor para facilitar la creación de ventas
        // Constructor para facilitar la creación de ventas
		Venta(int idVenta, int id_paciente, int cantidad, DateTime^ fechaVenta, Medicamento^ med) {
			id = idVenta;
			idPaciente = id_paciente;
			cantidadVendida = cantidad;
			fecha = fechaVenta;
			medicamento = med;
		}

		void MostrarBoleta() {
			Console::WriteLine("Imprimiendo boleta de la venta ID: " + id);
		}
	};
	public ref class Pago {
	public:
		int id;
		double monto;
		String^ metodo;
		String^ estado;
		void ProcesarPago() {
			Console::WriteLine("Conectando con el banco... Procesando pago de: $" + monto);
			estado = "Procesado";
		}
		void ConfirmarTransaccion() {
			Console::WriteLine("Transacción confirmada y aprobada.");
		};
	};
	public ref class BoletaVenta {
	public:
		int nroOperacion;
		void MostrarBoleta() {
			Console::WriteLine("=== BOLETA ELECTRONICA Nro: " + nroOperacion + " ===");
		}
	};
	// 4. HARDWARE Y ROBÓTICA

	public ref class Servomotor {
	public:
		int angulo;
		void ModificarAngulo(int nuevoAngulo) {
			angulo = nuevoAngulo;
			Console::WriteLine("[Hardware] Servomotor movido a " + angulo + " grados.");
		}
	};
	public ref class RobotFarmaceutico {
	public:
		int id;
		bool estado;
		void DispensarMedicamento(int cant) {
			Console::WriteLine("[Hardware] Robot activado. Dispensando " + cant + " unidad(es)...");
		}
		void VerificarEstado() {
			Console::WriteLine("[Hardware] Estado del robot: " + (estado ? "Operativo" : "En Mantenimiento"));
		}
	};
	// 5. SERVICIOS Y LÓGICA (Controladores y APIs Externas)

	// Se usa 'static' para que funcione como un servicio externo (API), no como un objeto.
	public ref class MotorIA {
	public:
		static Receta^ GenerarRecomendacion(Paciente^ p, List<Medicamento^>^ inventarioGlobal) {
			Console::WriteLine("--- INICIANDO CONEXIÓN CON IA EXTERNA ---");
			Console::WriteLine("Analizando síntomas: " + p->sintomas);
			Console::WriteLine("Verificando contraindicaciones por alergias: " + p->alergias);
			// Simulación de respuesta de la IA
			Receta^ nuevaReceta = gcnew Receta();
			nuevaReceta->idReceta = 999; // ID generado automáticamente
			nuevaReceta->fechaEmision = DateTime::Now;
			nuevaReceta->dosis = 1;
			nuevaReceta->entregado = false;
			// Aquí la IA buscaría el medicamento ideal en el inventarioGlobal...
			Console::WriteLine("--- RECOMENDACIÓN GENERADA CON ÉXITO ---");
			return nuevaReceta;
		};
	};


		void RegistrarNuevoFarmaceutico(int id, String^ contrasena, String^ nombre, String^ apellido) {
			Farmaceutico^ f = gcnew Farmaceutico();
			f->id = id;
			f->contrasenia = contrasena;
			f->nombre = nombre;
			f->apellido = apellido;
			Console::WriteLine("Personal Farmacéutico registrado.");
		}
};


