#pragma once
#include "PacienteView.h"

namespace ViewPaciente {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace IA_CLASS;
	using namespace Controller;
	using namespace WinniePOO_Modelos;

	public ref class PacienteForm : public System::Windows::Forms::Form
	{
	private: int idPaciente;

	public:
		// Constructor que recibe el nombre
		PacienteForm(int ID)
		{
			InitializeComponent();
			idPaciente = ID;
		}

	protected:
		~PacienteForm()
		{
			if (components)
			{
				delete components;
			}
		}

		// CONTROLES - Panel Superior
	private: System::Windows::Forms::Panel^ panelSuperior;
	private: System::Windows::Forms::Label^ lblTituloPpal;


		   // CONTROLES - Panel Principal Paciente (HU02, HU03, HU04)
	private: System::Windows::Forms::Panel^ panelDashboard;
	private: System::Windows::Forms::Label^ lblSintomas;
	private: System::Windows::Forms::TextBox^ txtSintomas;
	private: System::Windows::Forms::Button^ btnEvaluar;
	private: System::Windows::Forms::Label^ lblRecomendaciones;
	private: System::Windows::Forms::DataGridView^ dgvMedicamentos;



	private: System::Windows::Forms::Button^ btnComprar;

	private: System::Windows::Forms::Label^ lblBienvenida;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colPrecio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colStock;









	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panelSuperior = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			this->lblTituloPpal = (gcnew System::Windows::Forms::Label());
			this->panelDashboard = (gcnew System::Windows::Forms::Panel());
			this->btnComprar = (gcnew System::Windows::Forms::Button());
			this->dgvMedicamentos = (gcnew System::Windows::Forms::DataGridView());
			this->lblRecomendaciones = (gcnew System::Windows::Forms::Label());
			this->btnEvaluar = (gcnew System::Windows::Forms::Button());
			this->txtSintomas = (gcnew System::Windows::Forms::TextBox());
			this->lblSintomas = (gcnew System::Windows::Forms::Label());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPrecio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colStock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panelSuperior->SuspendLayout();
			this->panelDashboard->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvMedicamentos))->BeginInit();
			this->SuspendLayout();
			// 
			// panelSuperior
			// 
			this->panelSuperior->BackColor = System::Drawing::Color::CadetBlue;
			this->panelSuperior->Controls->Add(this->label1);
			this->panelSuperior->Controls->Add(this->lblBienvenida);
			this->panelSuperior->Controls->Add(this->lblTituloPpal);
			this->panelSuperior->Location = System::Drawing::Point(0, 0);
			this->panelSuperior->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelSuperior->Name = L"panelSuperior";
			this->panelSuperior->Size = System::Drawing::Size(952, 62);
			this->panelSuperior->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Cornsilk;
			this->label1->Location = System::Drawing::Point(12, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(133, 29);
			this->label1->TabIndex = 7;
			this->label1->Text = L"PACIENTE";
			this->label1->Click += gcnew System::EventHandler(this, &PacienteForm::label1_Click);
			// 
			// lblBienvenida
			// 
			this->lblBienvenida->AutoSize = true;
			this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBienvenida->ForeColor = System::Drawing::SystemColors::Control;
			this->lblBienvenida->Location = System::Drawing::Point(884, 10);
			this->lblBienvenida->Name = L"lblBienvenida";
			this->lblBienvenida->Size = System::Drawing::Size(56, 38);
			this->lblBienvenida->TabIndex = 6;
			this->lblBienvenida->Text = L"🐻";
			this->lblBienvenida->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblBienvenida->Click += gcnew System::EventHandler(this, &PacienteForm::lblBienvenida_Click);
			// 
			// lblTituloPpal
			// 
			this->lblTituloPpal->AutoSize = true;
			this->lblTituloPpal->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTituloPpal->ForeColor = System::Drawing::Color::Teal;
			this->lblTituloPpal->Location = System::Drawing::Point(13, 10);
			this->lblTituloPpal->Name = L"lblTituloPpal";
			this->lblTituloPpal->Size = System::Drawing::Size(151, 16);
			this->lblTituloPpal->TabIndex = 1;
			this->lblTituloPpal->Text = L"Portal de Autoconsulta";
			this->lblTituloPpal->Click += gcnew System::EventHandler(this, &PacienteForm::lblTituloPpal_Click);
			// 
			// panelDashboard
			// 
			this->panelDashboard->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->panelDashboard->Controls->Add(this->btnComprar);
			this->panelDashboard->Controls->Add(this->dgvMedicamentos);
			this->panelDashboard->Controls->Add(this->lblRecomendaciones);
			this->panelDashboard->Controls->Add(this->btnEvaluar);
			this->panelDashboard->Controls->Add(this->txtSintomas);
			this->panelDashboard->Controls->Add(this->lblSintomas);
			this->panelDashboard->Location = System::Drawing::Point(0, 62);
			this->panelDashboard->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelDashboard->Name = L"panelDashboard";
			this->panelDashboard->Size = System::Drawing::Size(952, 430);
			this->panelDashboard->TabIndex = 2;
			this->panelDashboard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PacienteForm::panelDashboard_Paint);
			// 
			// btnComprar
			// 
			this->btnComprar->BackColor = System::Drawing::Color::SeaGreen;
			this->btnComprar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnComprar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnComprar->ForeColor = System::Drawing::Color::White;
			this->btnComprar->Location = System::Drawing::Point(749, 230);
			this->btnComprar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnComprar->Name = L"btnComprar";
			this->btnComprar->Size = System::Drawing::Size(149, 50);
			this->btnComprar->TabIndex = 5;
			this->btnComprar->Text = L"Realizar Compra";
			this->btnComprar->UseVisualStyleBackColor = false;
			this->btnComprar->Click += gcnew System::EventHandler(this, &PacienteForm::btnComprar_Click);
			// 
			// dgvMedicamentos
			// 
			this->dgvMedicamentos->AllowUserToAddRows = false;
			this->dgvMedicamentos->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dgvMedicamentos->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::DimGray;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::DimGray;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::DimGray;
			this->dgvMedicamentos->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvMedicamentos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvMedicamentos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->ID, this->colNombre,
					this->colPrecio, this->colStock
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Gray;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::CadetBlue;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvMedicamentos->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvMedicamentos->Location = System::Drawing::Point(35, 180);
			this->dgvMedicamentos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dgvMedicamentos->Name = L"dgvMedicamentos";
			this->dgvMedicamentos->RowHeadersVisible = false;
			this->dgvMedicamentos->RowHeadersWidth = 51;
			this->dgvMedicamentos->RowTemplate->Height = 24;
			this->dgvMedicamentos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvMedicamentos->Size = System::Drawing::Size(700, 150);
			this->dgvMedicamentos->TabIndex = 4;
			this->dgvMedicamentos->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &PacienteForm::dgvMedicamentos_CellContentClick);
			// 
			// lblRecomendaciones
			// 
			this->lblRecomendaciones->AutoSize = true;
			this->lblRecomendaciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblRecomendaciones->Location = System::Drawing::Point(29, 150);
			this->lblRecomendaciones->Name = L"lblRecomendaciones";
			this->lblRecomendaciones->Size = System::Drawing::Size(244, 20);
			this->lblRecomendaciones->TabIndex = 3;
			this->lblRecomendaciones->Text = L"Medicamentos Recomendados:";
			// 
			// btnEvaluar
			// 
			this->btnEvaluar->BackColor = System::Drawing::Color::CadetBlue;
			this->btnEvaluar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEvaluar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEvaluar->ForeColor = System::Drawing::Color::White;
			this->btnEvaluar->Location = System::Drawing::Point(749, 60);
			this->btnEvaluar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnEvaluar->Name = L"btnEvaluar";
			this->btnEvaluar->Size = System::Drawing::Size(149, 60);
			this->btnEvaluar->TabIndex = 2;
			this->btnEvaluar->Text = L"Evaluar Malestar";
			this->btnEvaluar->UseVisualStyleBackColor = false;
			this->btnEvaluar->Click += gcnew System::EventHandler(this, &PacienteForm::btnEvaluar_Click);
			// 
			// txtSintomas
			// 
			this->txtSintomas->Location = System::Drawing::Point(35, 60);
			this->txtSintomas->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtSintomas->Multiline = true;
			this->txtSintomas->Name = L"txtSintomas";
			this->txtSintomas->Size = System::Drawing::Size(700, 61);
			this->txtSintomas->TabIndex = 1;
			// 
			// lblSintomas
			// 
			this->lblSintomas->AutoSize = true;
			this->lblSintomas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSintomas->Location = System::Drawing::Point(29, 30);
			this->lblSintomas->Name = L"lblSintomas";
			this->lblSintomas->Size = System::Drawing::Size(324, 20);
			this->lblSintomas->TabIndex = 0;
			this->lblSintomas->Text = L"Describa sus sintomas y malestares aqui:";
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->MinimumWidth = 6;
			this->ID->Name = L"ID";
			this->ID->Width = 125;
			// 
			// colNombre
			// 
			this->colNombre->HeaderText = L"Medicamento";
			this->colNombre->MinimumWidth = 6;
			this->colNombre->Name = L"colNombre";
			this->colNombre->Width = 200;
			// 
			// colPrecio
			// 
			this->colPrecio->HeaderText = L"Precio (S/.)";
			this->colPrecio->MinimumWidth = 6;
			this->colPrecio->Name = L"colPrecio";
			this->colPrecio->Width = 150;
			// 
			// colStock
			// 
			this->colStock->HeaderText = L"Dosis";
			this->colStock->MinimumWidth = 6;
			this->colStock->Name = L"colStock";
			this->colStock->Width = 180;
			// 
			// PacienteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(952, 489);
			this->Controls->Add(this->panelDashboard);
			this->Controls->Add(this->panelSuperior);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"PacienteForm";
			this->Text = L"Sistema de Dispensacion - Paciente";
			this->panelSuperior->ResumeLayout(false);
			this->panelSuperior->PerformLayout();
			this->panelDashboard->ResumeLayout(false);
			this->panelDashboard->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvMedicamentos))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		// HU02 y HU03: Evaluar Sintomas y Mostrar Recomendacion
	private: System::Void btnEvaluar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(txtSintomas->Text)) {
			MessageBox::Show("Por favor, describa sus sintomas para poder evaluarlos.", "Datos incompletos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		Console::WriteLine("\n=== INICIO btnEvaluar_Click ===");

		Controller::ServicioPacientes^ servPacientes = gcnew Controller::ServicioPacientes();
		Controller::ServicioMedicamentos^ servMedicamentos = gcnew Controller::ServicioMedicamentos();

		// =========================
		// 📜 HISTORIAL
		// =========================
		List<String^>^ historialPacienteLista = servPacientes->ExaminarHistorialReceta(idPaciente);

		Console::WriteLine("\n--- HISTORIAL PACIENTE (LISTA) ---");
		for each (String ^ item in historialPacienteLista) {
			Console::WriteLine(item);
		}

		String^ historialPaciente = String::Join("|", historialPacienteLista);

		Console::WriteLine("\n--- HISTORIAL STRING ---");
		Console::WriteLine(historialPaciente);

		// =========================
		// 💊 STOCK MEDICAMENTOS
		// =========================
		List<Medicamento^>^ stockMedicamentosLista = servMedicamentos->ObtenerInventarioCompleto();

		Console::WriteLine("\n--- STOCK MEDICAMENTOS (OBJETOS) ---");
		for each (Medicamento ^ med in stockMedicamentosLista) {
			Console::WriteLine("ID: " + med->id +
				"Nombre: " + med->nombre +
				" | Principio: " + med->principioActivo +
				" | Precio: " + med->precio.ToString() +
				" | Stock: " + med->stock.ToString());
		}

		List<String^>^ medicamentosTexto = gcnew List<String^>();

		for each (Medicamento ^ med in stockMedicamentosLista) {
			String^ item = "ID: " + med->id + " - " + med->nombre + " (" + med->principioActivo + ") - Precio: "
				+ med->precio.ToString() + " - Stock: " + med->stock.ToString();

			medicamentosTexto->Add(item);
		}

		String^ stockMedicamentos = String::Join("|", medicamentosTexto);

		Console::WriteLine("\n--- STOCK STRING ENVIADO A IA ---");
		Console::WriteLine(stockMedicamentos);

		// =========================
		// 🤖 IA
		// =========================
		IA_CLASS::IA^ iaManager = gcnew IA_CLASS::IA();

		Console::WriteLine("\n➡ Enviando a IA...");
		Console::WriteLine("Síntomas: " + txtSintomas->Text);

		MessageBox::Show("Analizando síntomas...", "Evaluación en curso", MessageBoxButtons::OK, MessageBoxIcon::Information);

		String^ respuesta = iaManager->GenerarRecomendacion(
			txtSintomas->Text,
			historialPaciente,
			stockMedicamentos
		);

		Console::WriteLine("\n=== RESPUESTA IA ===");
		Console::WriteLine(respuesta);

		// =========================
		// 🔍 PARSEO
		// =========================

		String^ tagInicioRec = "[INICIO_RECOMENDACION]";
		String^ tagFinRec = "[FIN_RECOMENDACION]";

		int iniRec = respuesta->IndexOf(tagInicioRec);
		int finRec = respuesta->IndexOf(tagFinRec);

		String^ recomendacion = "";

		if (iniRec != -1 && finRec != -1) {
			iniRec += tagInicioRec->Length;
			recomendacion = respuesta->Substring(iniRec, finRec - iniRec)->Trim();
		}

		String^ tagInicioReceta = "[INICIO_RECETA]";
		String^ tagFinReceta = "[FIN_RECETA]";

		int iniReceta = respuesta->IndexOf(tagInicioReceta);
		int finReceta = respuesta->IndexOf(tagFinReceta);

		String^ receta = "";

		if (iniReceta != -1 && finReceta != -1) {
			iniReceta += tagInicioReceta->Length;
			receta = respuesta->Substring(iniReceta, finReceta - iniReceta)->Trim();
		}

		Console::WriteLine("\n--- RECETA CRUDA ---");
		Console::WriteLine(receta);

		MessageBox::Show(recomendacion, "Recomendación médica", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// =========================
		// 📊 DATAGRID (NUEVO PARSEO)
		// =========================

		dgvMedicamentos->Rows->Clear();

		if (receta != "SIN_STOCK") {

			Console::WriteLine("\n--- DIVIDIENDO POR [SEPARADOR] ---");

			array<String^>^ items = receta->Split(gcnew array<String^>{"[SEPARADOR]"}, StringSplitOptions::RemoveEmptyEntries);

			for each (String ^ item in items) {

				String^ linea = item->Trim();

				if (String::IsNullOrWhiteSpace(linea)) continue;

				Console::WriteLine("\nProcesando item:");
				Console::WriteLine(linea);

				array<String^>^ campos = linea->Split('|');

				if (campos->Length >= 4) {
					Console::WriteLine("✔ Parse correcto");

					dgvMedicamentos->Rows->Add(
						campos[0], // id
						campos[1], // nombre
						campos[2], // principio activo
						campos[3]  // dosis
					);
				}
				else {
					Console::WriteLine("❌ Item mal formado");
				}
			}
		}
		else {
			Console::WriteLine("⚠ SIN STOCK");
			MessageBox::Show("No hay medicamentos disponibles en stock.", "Sin stock", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

		   // HU04 (Extension): Compra del medicamento
	private: System::Void btnComprar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dgvMedicamentos->SelectedRows->Count > 0 || dgvMedicamentos->CurrentCell != nullptr) {
			MessageBox::Show("Compra procesada con exito!\nPor favor, retire su medicamento del dispensador.", "Operacion Exitosa", MessageBoxButtons::OK, MessageBoxIcon::Information);
			txtSintomas->Text = "";
			dgvMedicamentos->Rows->Clear();
		}
		else {
			MessageBox::Show("Seleccione un medicamento de la tabla para realizar la compra.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	private: System::Void lblUsuarioActivo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void lblBienvenida_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblTituloPpal_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panelDashboard_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
 private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		   // ... tu código existente de carga ...
	 Controller::ServicioPacientes^ servPacientes = gcnew ServicioPacientes();

		   // ── Verificar alertas pendientes del farmacéutico ─────────────────────
		   String^ alertas = Controller::ServicioFarmaceutico::LeerAlertas(servPacientes->ObtenerPorId(idPaciente)->nombre);

		   if (alertas != nullptr && alertas->Trim() != String::Empty) {
			   MessageBox::Show(
				   "Tienes mensajes de tu farmacéutico:\n\n" + alertas,
				   "Alerta del Farmacéutico",
				   MessageBoxButtons::OK,
				   MessageBoxIcon::Information
			   );
			   // Borrar alertas tras mostrarlas (opcional)
		   }
	   }
private: System::Void dgvMedicamentos_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}