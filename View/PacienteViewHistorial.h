#pragma once

namespace ViewPacienteHistorial {

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

	//Declaración de los componentes estéticos del formulario
	private: System::Windows::Forms::Panel^ panelSuperior;
	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblSubtitulo;
	private: System::Windows::Forms::Panel^ panelContenido;
	private: System::Windows::Forms::Button^ btnVolver;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   this->panelSuperior = (gcnew System::Windows::Forms::Panel());
			   this->lblTitulo = (gcnew System::Windows::Forms::Label());
			   this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			   this->panelContenido = (gcnew System::Windows::Forms::Panel());
			   this->btnVolver = (gcnew System::Windows::Forms::Button());
			   this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			   this->MEDICAMENTO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->CANTIDAD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->FECHA = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->panelSuperior->SuspendLayout();
			   this->panelContenido->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			   this->SuspendLayout();

			   // =========================
			   // PANEL SUPERIOR
			   // =========================
			   this->panelSuperior->BackColor = System::Drawing::Color::CadetBlue;
			   this->panelSuperior->Controls->Add(this->lblTitulo);
			   this->panelSuperior->Controls->Add(this->lblSubtitulo);
			   this->panelSuperior->Location = System::Drawing::Point(0, 0);
			   this->panelSuperior->Name = L"panelSuperior";
			   this->panelSuperior->Size = System::Drawing::Size(800, 60);

			   // 
			   // lblTitulo
			   // 
			   this->lblTitulo->AutoSize = true;
			   this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular));
			   this->lblTitulo->ForeColor = System::Drawing::Color::White;
			   this->lblTitulo->Location = System::Drawing::Point(12, 20);
			   this->lblTitulo->Text = L"HISTORIAL";

			   // 
			   // lblSubtitulo
			   // 
			   this->lblSubtitulo->AutoSize = true;
			   this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Bold));
			   this->lblSubtitulo->ForeColor = System::Drawing::Color::Teal;
			   this->lblSubtitulo->Location = System::Drawing::Point(13, 5);
			   this->lblSubtitulo->Text = L"Portal de Autoconsulta";

			   // =========================
			   // PANEL CONTENIDO
			   // =========================
			   this->panelContenido->BackColor = System::Drawing::Color::FromArgb(245, 245, 250);
			   this->panelContenido->Controls->Add(this->btnVolver);
			   this->panelContenido->Controls->Add(this->dataGridView2);
			   this->panelContenido->Location = System::Drawing::Point(0, 60);
			   this->panelContenido->Name = L"panelContenido";
			   this->panelContenido->Size = System::Drawing::Size(800, 340);

			   // =========================
			   // DATAGRID
			   // =========================
			   this->dataGridView2->AllowUserToAddRows = false;
			   this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->dataGridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;

			   dataGridViewCellStyle1->BackColor = System::Drawing::Color::Gainsboro;
			   dataGridViewCellStyle1->ForeColor = System::Drawing::Color::DimGray;
			   this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;

			   this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^ >(3) {
				   this->MEDICAMENTO, this->CANTIDAD, this->FECHA
			   });

			   dataGridViewCellStyle2->BackColor = System::Drawing::Color::White;
			   dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Gray;
			   dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::CadetBlue;
			   dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;

			   this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle2;
			   this->dataGridView2->Location = System::Drawing::Point(50, 40);
			   this->dataGridView2->Name = L"dataGridView2";
			   this->dataGridView2->RowHeadersVisible = false;
			   this->dataGridView2->Size = System::Drawing::Size(700, 180);

			   // =========================
			   // COLUMNAS
			   // =========================
			   this->MEDICAMENTO->HeaderText = L"MEDICAMENTO";
			   this->MEDICAMENTO->Width = 250;

			   this->CANTIDAD->HeaderText = L"CANTIDAD";
			   this->CANTIDAD->Width = 150;

			   this->FECHA->HeaderText = L"FECHA";
			   this->FECHA->Width = 200;

			   // =========================
			   // BOTÓN VOLVER
			   // =========================
			   this->btnVolver->BackColor = System::Drawing::Color::SeaGreen;
			   this->btnVolver->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnVolver->ForeColor = System::Drawing::Color::White;
			   this->btnVolver->Location = System::Drawing::Point(600, 250);
			   this->btnVolver->Name = L"btnVolver";
			   this->btnVolver->Size = System::Drawing::Size(150, 40);
			   this->btnVolver->Text = L"Volver";
			   this->btnVolver->UseVisualStyleBackColor = false;
			   this->btnVolver->Click += gcnew System::EventHandler(this, &PacienteViewHistorial::btnVolver_Click);

			   // =========================
			   // FORM
			   // =========================
			   this->ClientSize = System::Drawing::Size(800, 400);
			   this->Controls->Add(this->panelContenido);
			   this->Controls->Add(this->panelSuperior);
			   this->Text = L"Historial del Paciente";

			   this->panelSuperior->ResumeLayout(false);
			   this->panelSuperior->PerformLayout();
			   this->panelContenido->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			   this->ResumeLayout(false);
		   }
#pragma endregion

		private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Owner->Show();
			this->Close();
		}
	};
}
