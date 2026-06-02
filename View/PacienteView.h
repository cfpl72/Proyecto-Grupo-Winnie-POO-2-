#pragma once
#include "PacienteView.h"
#include "stdlib.h"

namespace ViewPaciente {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace IA_CLASS;

	public ref class PacienteForm : public System::Windows::Forms::Form
	{
	private: int idPaciente; //Cambio de nombre a id para evitar confusión con el nombre del paciente
		   Controller::ServicioPacientes^ pacienteService = gcnew Controller::ServicioPacientes();
		   Controller::ServicioMedicamentos^ medicamentoService = gcnew Controller::ServicioMedicamentos();
		   Controller::ServicioVentas^ ventasService = gcnew Controller::ServicioVentas();

		   IA_CLASS::IA^ ia = gcnew IA();

	public:
		// Constructor que recibe el nombre
		PacienteForm(int idBus)
		{
			InitializeComponent();
			idPaciente = idBus;
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colPrecio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colStock;
	private: System::Windows::Forms::Button^ btnComprar;

	private: System::Windows::Forms::Label^ lblBienvenida;
	private: System::Windows::Forms::Label^ label1;

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
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPrecio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colStock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lblRecomendaciones = (gcnew System::Windows::Forms::Label());
			this->btnEvaluar = (gcnew System::Windows::Forms::Button());
			this->txtSintomas = (gcnew System::Windows::Forms::TextBox());
			this->lblSintomas = (gcnew System::Windows::Forms::Label());
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
			this->panelSuperior->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelSuperior->Name = L"panelSuperior";
			this->panelSuperior->Size = System::Drawing::Size(714, 50);
			this->panelSuperior->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Heavy", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Cornsilk;
			this->label1->Location = System::Drawing::Point(9, 19);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 24);
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
			this->lblBienvenida->Location = System::Drawing::Point(663, 8);
			this->lblBienvenida->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblBienvenida->Name = L"lblBienvenida";
			this->lblBienvenida->Size = System::Drawing::Size(44, 30);
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
			this->lblTituloPpal->Location = System::Drawing::Point(10, 8);
			this->lblTituloPpal->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblTituloPpal->Name = L"lblTituloPpal";
			this->lblTituloPpal->Size = System::Drawing::Size(132, 14);
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
			this->panelDashboard->Location = System::Drawing::Point(0, 50);
			this->panelDashboard->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelDashboard->Name = L"panelDashboard";
			this->panelDashboard->Size = System::Drawing::Size(714, 349);
			this->panelDashboard->TabIndex = 2;
			this->panelDashboard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PacienteForm::panelDashboard_Paint);
			// 
			// btnComprar
			// 
			this->btnComprar->BackColor = System::Drawing::Color::SeaGreen;
			this->btnComprar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnComprar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnComprar->ForeColor = System::Drawing::Color::White;
			this->btnComprar->Location = System::Drawing::Point(562, 187);
			this->btnComprar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnComprar->Name = L"btnComprar";
			this->btnComprar->Size = System::Drawing::Size(112, 41);
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
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::DimGray;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::DimGray;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::DimGray;
			this->dgvMedicamentos->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvMedicamentos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvMedicamentos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->colNombre,
					this->colPrecio, this->colStock
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Gray;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::CadetBlue;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvMedicamentos->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvMedicamentos->Location = System::Drawing::Point(26, 146);
			this->dgvMedicamentos->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dgvMedicamentos->Name = L"dgvMedicamentos";
			this->dgvMedicamentos->RowHeadersVisible = false;
			this->dgvMedicamentos->RowHeadersWidth = 51;
			this->dgvMedicamentos->RowTemplate->Height = 24;
			this->dgvMedicamentos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvMedicamentos->Size = System::Drawing::Size(525, 122);
			this->dgvMedicamentos->TabIndex = 4;
			// 
			// colNombre
			// 
			this->colNombre->HeaderText = L"Medicamento";
			this->colNombre->MinimumWidth = 6;
			this->colNombre->Name = L"colNombre";
			this->colNombre->Width = 350;
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
			this->colStock->HeaderText = L"Stock Disponible";
			this->colStock->MinimumWidth = 6;
			this->colStock->Name = L"colStock";
			this->colStock->Width = 180;
			// 
			// lblRecomendaciones
			// 
			this->lblRecomendaciones->AutoSize = true;
			this->lblRecomendaciones->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblRecomendaciones->Location = System::Drawing::Point(22, 122);
			this->lblRecomendaciones->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblRecomendaciones->Name = L"lblRecomendaciones";
			this->lblRecomendaciones->Size = System::Drawing::Size(217, 16);
			this->lblRecomendaciones->TabIndex = 3;
			this->lblRecomendaciones->Text = L"Medicamentos Recomendados:";
			// 
			// btnEvaluar
			// 
			this->btnEvaluar->BackColor = System::Drawing::Color::CadetBlue;
			this->btnEvaluar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEvaluar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEvaluar->ForeColor = System::Drawing::Color::White;
			this->btnEvaluar->Location = System::Drawing::Point(562, 49);
			this->btnEvaluar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnEvaluar->Name = L"btnEvaluar";
			this->btnEvaluar->Size = System::Drawing::Size(112, 49);
			this->btnEvaluar->TabIndex = 2;
			this->btnEvaluar->Text = L"Evaluar Malestar";
			this->btnEvaluar->UseVisualStyleBackColor = false;
			this->btnEvaluar->Click += gcnew System::EventHandler(this, &PacienteForm::btnEvaluar_Click);
			// 
			// txtSintomas
			// 
			this->txtSintomas->Location = System::Drawing::Point(26, 49);
			this->txtSintomas->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtSintomas->Multiline = true;
			this->txtSintomas->Name = L"txtSintomas";
			this->txtSintomas->Size = System::Drawing::Size(526, 50);
			this->txtSintomas->TabIndex = 1;
			// 
			// lblSintomas
			// 
			this->lblSintomas->AutoSize = true;
			this->lblSintomas->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSintomas->Location = System::Drawing::Point(22, 24);
			this->lblSintomas->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblSintomas->Name = L"lblSintomas";
			this->lblSintomas->Size = System::Drawing::Size(289, 16);
			this->lblSintomas->TabIndex = 0;
			this->lblSintomas->Text = L"Describa sus sintomas y malestares aqui:";
			// 
			// PacienteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 397);
			this->Controls->Add(this->panelDashboard);
			this->Controls->Add(this->panelSuperior);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
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
			MessageBox::Show("Por favor, describa sus sintomas para poder evaluarlos.",
				"Datos incompletos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		MessageBox::Show("Analizando sintomas...",
			"Evaluacion en curso", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// =========================
		// 1. Datos de entrada
		// =========================

		String^ sintomas = txtSintomas->Text;
		int idPaciente = 1; // ⚠️ luego esto debería venir de la UI

		// =========================
		// 2. Historial desde servicio
		// =========================

		List<String^>^ historialLista = pacienteService->ExaminarHistorialReceta(idPaciente);

		String^ historial = "";
		if (historialLista != nullptr) {
			for each (String ^ item in historialLista) {
				historial += item + ", ";
			}
		}

		// =========================
		// 3. Lista de medicamentos
		// =========================

		// (por ahora mock, luego lo sacamos del servicio)
		String^ listaMedicamentos = "Paracetamol, Ibuprofeno, Jarabe Antitusivo";

		// =========================
		// 4. Llamada a la IA
		// =========================

		String^ recomendacion = ia->GenerarRecomendacion(sintomas, historial, listaMedicamentos);

		// =========================
		// 5. Mostrar recomendación
		// =========================

		MessageBox::Show(recomendacion,
			"Recomendación IA", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// =========================
		// 6. Tabla (se mantiene igual)
		// =========================

		dgvMedicamentos->Rows->Clear();

		dgvMedicamentos->Rows->Add("Paracetamol 500mg", "1.50", "50");
		dgvMedicamentos->Rows->Add("Ibuprofeno 400mg", "2.00", "30");
		dgvMedicamentos->Rows->Add("Jarabe Antitusivo", "15.00", "12");
	}



		   // HU04 (Extension): Compra del medicamento
	private: System::Void btnComprar_Click(System::Object^ sender, System::EventArgs^ e) {

		if (dgvMedicamentos->SelectedRows->Count > 0) {

			// =========================
			// 1. Obtener fila seleccionada
			// =========================
			DataGridViewRow^ fila = dgvMedicamentos->SelectedRows[0];

			String^ nombreMed = fila->Cells[0]->Value->ToString();
			double precio = Convert::ToDouble(fila->Cells[1]->Value);
			int stock = Convert::ToInt32(fila->Cells[2]->Value);

			// =========================
			// 2. Datos simulados (por ahora)
			// =========================
			int idVenta = rand() % 10000 + 1000;   // ID simple
			int idPaciente = 1;                   // luego vendrá de sesión
			int idMedicamento = dgvMedicamentos->SelectedRows[0]->Index + 101; // mock
			int cantidad = 1;

			// =========================
			// 3. Registrar venta
			// =========================
			bool ok = ventasService->RegistrarVenta(idVenta, idPaciente, idMedicamento, cantidad);

			// =========================
			// 4. Resultado
			// =========================
			if (ok) {

				MessageBox::Show(
					"Compra procesada con éxito!\nPor favor, retire su medicamento del dispensador.",
					"Operación Exitosa",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information
				);

				// limpiar UI
				txtSintomas->Text = "";
				dgvMedicamentos->Rows->Clear();
			}
			else {
				MessageBox::Show(
					"No se pudo registrar la venta.",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
			}

		}
		else {
			MessageBox::Show(
				"Seleccione un medicamento de la tabla para realizar la compra.",
				"Aviso",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);
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

		   // ── Verificar alertas pendientes del farmacéutico ─────────────────────
			String^ _nombrePaciente = "A"; // Obtener nombre usando el ID
		   String^ alertas = Controller::ServicioFarmaceutico::LeerAlertas(_nombrePaciente);

		   if (alertas != nullptr && alertas->Trim() != String::Empty) {
			   MessageBox::Show(
				   "📢 Tienes mensajes de tu farmacéutico:\n\n" + alertas,
				   "Alerta del Farmacéutico",
				   MessageBoxButtons::OK,
				   MessageBoxIcon::Information
			   );
			   // Borrar alertas tras mostrarlas (opcional)
		   }
	   }
};
}