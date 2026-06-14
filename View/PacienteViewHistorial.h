#pragma once

namespace WinniePOOview {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Controller;

	/// <summary>
	/// Resumen de PacienteViewHistorial
	/// </summary>
	public ref class PacienteViewHistorial : public System::Windows::Forms::Form
	{
	public:

		int idPaciente;
		ServicioPacientes^ servPacientes;
		List<WinniePOO_Modelos::Receta^>^ historialRecetas;

		PacienteViewHistorial(int idBus)
		{
			InitializeComponent();
			
			this->idPaciente = idBus;
			this->servPacientes = gcnew ServicioPacientes();

			this->historialRecetas = servPacientes->ObtenerHistorial(idPaciente);

			CargarHistorial(historialRecetas);
		}
	
//Función para cargar el historial
	public: void CargarHistorial(List<WinniePOO_Modelos::Receta^>^ historialRecetas)
	{
		dataGridView2->Rows->Clear();

		for each (WinniePOO_Modelos::Receta ^ receta in historialRecetas)
		{
			String^ nombreMedicamento = receta->medicamento->nombre;
			int cantidad = receta->dosis;
			//String^ fecha = receta->fecha.ToString("dd/MM/yyyy"); Este para cuando actualice a SQL y a Controller1
			String^ fecha = "01/01/26";

			dataGridView2->Rows->Add(
				nombreMedicamento,
				cantidad.ToString(),
				fecha
			);
		}
	}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~PacienteViewHistorial()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MEDICAMENTO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CANTIDAD;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ FECHA;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->MEDICAMENTO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CANTIDAD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FECHA = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->MEDICAMENTO,
					this->CANTIDAD, this->FECHA
			});
			this->dataGridView2->Location = System::Drawing::Point(59, 151);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(664, 150);
			this->dataGridView2->TabIndex = 1;
			// 
			// MEDICAMENTO
			// 
			this->MEDICAMENTO->HeaderText = L"MEDICAMENTO";
			this->MEDICAMENTO->MinimumWidth = 6;
			this->MEDICAMENTO->Name = L"MEDICAMENTO";
			this->MEDICAMENTO->Width = 125;
			// 
			// CANTIDAD
			// 
			this->CANTIDAD->HeaderText = L"CANTIDAD";
			this->CANTIDAD->MinimumWidth = 6;
			this->CANTIDAD->Name = L"CANTIDAD";
			this->CANTIDAD->Width = 125;
			// 
			// FECHA
			// 
			this->FECHA->HeaderText = L"FECHA";
			this->FECHA->MinimumWidth = 6;
			this->FECHA->Name = L"FECHA";
			this->FECHA->Width = 125;
			// 
			// PacienteViewHistorial
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(802, 365);
			this->Controls->Add(this->dataGridView2);
			this->Name = L"PacienteViewHistorial";
			this->Text = L"PacienteViewHistorial";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
