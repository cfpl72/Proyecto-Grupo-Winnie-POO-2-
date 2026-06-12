// ============================================================
//  PacienteView.h  —  CORREGIDO (diseño original intacto)
//  Cambios aplicados:
//    1. Constructor acepta (int ID, Form^ loginRef)
//    2. MyForm_Load ahora es PacienteForm_Load (evento Load)
//       → carga alertas del farmacéutico al abrir
//    3. btnComprar_Click llama a ServicioVentas::RegistrarVenta
//       con datos reales de la fila seleccionada del dgvMedicamentos
//    4. btnEvaluar_Click: tras la IA, recarga dgvMedicamentos
//       con el inventario REAL desde ServicioMedicamentos
//    5. Añadidos: btnVolver y btnCerrarSesion en panelSuperior
//    6. FormClosing muestra el Login si se cierra con la X
// ============================================================
#pragma once

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
	private:
		int   idPaciente;
		Form^ loginRef;   // referencia al Login para Volver / Cerrar Sesión

	public:
		PacienteForm(int ID, Form^ loginForm)
		{
			InitializeComponent();
			idPaciente = ID;
			loginRef = loginForm;
		}

	protected:
		~PacienteForm()
		{
			if (components) delete components;
		}

		// ── Controles originales ──────────────────────────────
	private: System::Windows::Forms::Panel^ panelSuperior;
	private: System::Windows::Forms::Label^ lblTituloPpal;
	private: System::Windows::Forms::Label^ lblBienvenida;
	private: System::Windows::Forms::Label^ label1;

		   // ── Botones nuevos (en panelSuperior) ─────────────────
	private: System::Windows::Forms::Button^ btnVolver;
	private: System::Windows::Forms::Button^ btnCerrarSesion;

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

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   this->panelSuperior = (gcnew System::Windows::Forms::Panel());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			   this->lblTituloPpal = (gcnew System::Windows::Forms::Label());
			   this->btnVolver = (gcnew System::Windows::Forms::Button());
			   this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
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

			   // ── panelSuperior (original) ─────────────────────
			   this->panelSuperior->BackColor = System::Drawing::Color::CadetBlue;
			   this->panelSuperior->Controls->Add(this->label1);
			   this->panelSuperior->Controls->Add(this->lblBienvenida);
			   this->panelSuperior->Controls->Add(this->lblTituloPpal);
			   this->panelSuperior->Controls->Add(this->btnVolver);       // NUEVO
			   this->panelSuperior->Controls->Add(this->btnCerrarSesion); // NUEVO
			   this->panelSuperior->Location = System::Drawing::Point(0, 0);
			   this->panelSuperior->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->panelSuperior->Name = L"panelSuperior";
			   this->panelSuperior->Size = System::Drawing::Size(952, 62);
			   this->panelSuperior->TabIndex = 0;
			   this->panelSuperior->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PacienteForm::panelSuperior_Paint);

			   // label1 (original)
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::Transparent;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Heavy", 13.8F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::Color::Cornsilk;
			   this->label1->Location = System::Drawing::Point(12, 23);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(117, 29);
			   this->label1->TabIndex = 7;
			   this->label1->Text = L"PACIENTE";

			   // lblBienvenida (original - emoji oso)
			   this->lblBienvenida->AutoSize = true;
			   this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->lblBienvenida->ForeColor = System::Drawing::SystemColors::Control;
			   this->lblBienvenida->Location = System::Drawing::Point(884, 10);
			   this->lblBienvenida->Name = L"lblBienvenida";
			   this->lblBienvenida->Size = System::Drawing::Size(56, 38);
			   this->lblBienvenida->TabIndex = 6;
			   this->lblBienvenida->Text = L"🐻";
			   this->lblBienvenida->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			   // lblTituloPpal (original)
			   this->lblTituloPpal->AutoSize = true;
			   this->lblTituloPpal->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->lblTituloPpal->ForeColor = System::Drawing::Color::Teal;
			   this->lblTituloPpal->Location = System::Drawing::Point(13, 10);
			   this->lblTituloPpal->Name = L"lblTituloPpal";
			   this->lblTituloPpal->Size = System::Drawing::Size(151, 16);
			   this->lblTituloPpal->TabIndex = 1;
			   this->lblTituloPpal->Text = L"Portal de Autoconsulta";

			   // ── NUEVO: btnVolver ─────────────────────────────
			   this->btnVolver->Text = L"◀ Volver";
			   this->btnVolver->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->btnVolver->BackColor = System::Drawing::Color::FromArgb(95, 158, 160); // CadetBlue más oscuro
			   this->btnVolver->ForeColor = System::Drawing::Color::White;
			   this->btnVolver->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnVolver->FlatAppearance->BorderSize = 0;
			   this->btnVolver->Location = System::Drawing::Point(640, 14);
			   this->btnVolver->Size = System::Drawing::Size(100, 32);
			   this->btnVolver->TabIndex = 8;
			   this->btnVolver->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnVolver->Click += gcnew System::EventHandler(this, &PacienteForm::btnVolver_Click);

			   // ── NUEVO: btnCerrarSesion ────────────────────────
			   this->btnCerrarSesion->Text = L"Cerrar Sesión";
			   this->btnCerrarSesion->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->btnCerrarSesion->BackColor = System::Drawing::Color::FromArgb(160, 60, 60);
			   this->btnCerrarSesion->ForeColor = System::Drawing::Color::White;
			   this->btnCerrarSesion->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnCerrarSesion->FlatAppearance->BorderSize = 0;
			   this->btnCerrarSesion->Location = System::Drawing::Point(750, 14);
			   this->btnCerrarSesion->Size = System::Drawing::Size(120, 32);
			   this->btnCerrarSesion->TabIndex = 9;
			   this->btnCerrarSesion->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &PacienteForm::btnCerrarSesion_Click);

			   // ── panelDashboard (original) ────────────────────
			   this->panelDashboard->BackColor = System::Drawing::Color::FromArgb(
				   static_cast<System::Int32>(static_cast<System::Byte>(245)),
				   static_cast<System::Int32>(static_cast<System::Byte>(245)),
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

			   // btnComprar (original)
			   this->btnComprar->BackColor = System::Drawing::Color::SeaGreen;
			   this->btnComprar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnComprar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->btnComprar->ForeColor = System::Drawing::Color::White;
			   this->btnComprar->Location = System::Drawing::Point(749, 230);
			   this->btnComprar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->btnComprar->Name = L"btnComprar";
			   this->btnComprar->Size = System::Drawing::Size(149, 50);
			   this->btnComprar->TabIndex = 5;
			   this->btnComprar->Text = L"Realizar Compra";
			   this->btnComprar->UseVisualStyleBackColor = false;
			   this->btnComprar->Click += gcnew System::EventHandler(this, &PacienteForm::btnComprar_Click);

			   // dgvMedicamentos (original)
			   dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(
				   static_cast<System::Int32>(static_cast<System::Byte>(224)),
				   static_cast<System::Int32>(static_cast<System::Byte>(224)),
				   static_cast<System::Int32>(static_cast<System::Byte>(224)));
			   this->dgvMedicamentos->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			   this->dgvMedicamentos->BackgroundColor = System::Drawing::Color::White;
			   this->dgvMedicamentos->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   dataGridViewCellStyle2->BackColor = System::Drawing::Color::CadetBlue;
			   dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9,
				   System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			   this->dgvMedicamentos->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			   this->dgvMedicamentos->ColumnHeadersHeight = 30;
			   this->dgvMedicamentos->Columns->AddRange(gcnew cli::array<System::Windows::Forms::DataGridViewColumn^>(3) {
				   this->colNombre, this->colPrecio, this->colStock
			   });
			   this->dgvMedicamentos->Location = System::Drawing::Point(29, 175);
			   this->dgvMedicamentos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->dgvMedicamentos->Name = L"dgvMedicamentos";
			   this->dgvMedicamentos->ReadOnly = true;
			   this->dgvMedicamentos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->dgvMedicamentos->Size = System::Drawing::Size(700, 220);
			   this->dgvMedicamentos->TabIndex = 4;
			   this->dgvMedicamentos->AllowUserToAddRows = false;

			   // columnas (original)
			   this->colNombre->HeaderText = L"Medicamento";
			   this->colNombre->Name = L"colNombre";
			   this->colNombre->Width = 300;
			   this->colPrecio->HeaderText = L"Precio (S/.)";
			   this->colPrecio->Name = L"colPrecio";
			   this->colPrecio->Width = 150;
			   this->colStock->HeaderText = L"Stock Disponible";
			   this->colStock->Name = L"colStock";
			   this->colStock->Width = 180;

			   // lblRecomendaciones (original)
			   this->lblRecomendaciones->AutoSize = true;
			   this->lblRecomendaciones->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F,
				   System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->lblRecomendaciones->Location = System::Drawing::Point(29, 150);
			   this->lblRecomendaciones->Name = L"lblRecomendaciones";
			   this->lblRecomendaciones->Size = System::Drawing::Size(266, 20);
			   this->lblRecomendaciones->TabIndex = 3;
			   this->lblRecomendaciones->Text = L"Medicamentos Recomendados:";

			   // btnEvaluar (original)
			   this->btnEvaluar->BackColor = System::Drawing::Color::CadetBlue;
			   this->btnEvaluar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnEvaluar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9,
				   System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->btnEvaluar->ForeColor = System::Drawing::Color::White;
			   this->btnEvaluar->Location = System::Drawing::Point(749, 60);
			   this->btnEvaluar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->btnEvaluar->Name = L"btnEvaluar";
			   this->btnEvaluar->Size = System::Drawing::Size(149, 60);
			   this->btnEvaluar->TabIndex = 2;
			   this->btnEvaluar->Text = L"Evaluar Malestar";
			   this->btnEvaluar->UseVisualStyleBackColor = false;
			   this->btnEvaluar->Click += gcnew System::EventHandler(this, &PacienteForm::btnEvaluar_Click);

			   // txtSintomas (original)
			   this->txtSintomas->Location = System::Drawing::Point(35, 60);
			   this->txtSintomas->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->txtSintomas->Multiline = true;
			   this->txtSintomas->Name = L"txtSintomas";
			   this->txtSintomas->Size = System::Drawing::Size(700, 61);
			   this->txtSintomas->TabIndex = 1;

			   // lblSintomas (original)
			   this->lblSintomas->AutoSize = true;
			   this->lblSintomas->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F,
				   System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->lblSintomas->Location = System::Drawing::Point(29, 30);
			   this->lblSintomas->Name = L"lblSintomas";
			   this->lblSintomas->Size = System::Drawing::Size(347, 20);
			   this->lblSintomas->TabIndex = 0;
			   this->lblSintomas->Text = L"Describa sus sintomas y malestares aqui:";

			   // ── PacienteForm ──────────────────────────────────
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(952, 489);
			   this->Controls->Add(this->panelDashboard);
			   this->Controls->Add(this->panelSuperior);
			   this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->Name = L"PacienteForm";
			   this->Text = L"Sistema de Dispensacion - Paciente";
			   this->Load += gcnew System::EventHandler(this, &PacienteForm::PacienteForm_Load);
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PacienteForm::PacienteForm_FormClosing);

			   this->panelSuperior->ResumeLayout(false);
			   this->panelSuperior->PerformLayout();
			   this->panelDashboard->ResumeLayout(false);
			   this->panelDashboard->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvMedicamentos))->EndInit();
			   this->ResumeLayout(false);
		   }
#pragma endregion

		   // ─────────────────────────────────────────────────────────
		   //  CARGA INICIAL: alertas del farmacéutico
		   // ─────────────────────────────────────────────────────────
	private: System::Void PacienteForm_Load(System::Object^ sender, System::EventArgs^ e) {
		try {
			Controller::ServicioPacientes^ svc = gcnew Controller::ServicioPacientes();
			Paciente^ p = svc->ObtenerPorId(idPaciente);
			if (p == nullptr) return;

			// Nombre con guion bajo para coincidir con el archivo alertas_Nombre_Apellido.txt
			String^ nombreArchivo = p->nombre + "_" + p->apellido;
			String^ alertas = Controller::ServicioFarmaceutico::LeerAlertas(nombreArchivo);

			if (alertas != nullptr && alertas->Trim() != String::Empty) {
				MessageBox::Show(
					"Tienes mensajes de tu farmacéutico:\n\n" + alertas,
					"Alertas del Farmacéutico",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
			}
		}
		catch (...) {} // no interrumpir si el archivo no existe
	}

		   // ─────────────────────────────────────────────────────────
		   //  EVALUAR SÍNTOMAS CON IA → actualizar dgvMedicamentos
		   // ─────────────────────────────────────────────────────────
	private: System::Void btnEvaluar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(txtSintomas->Text)) {
			MessageBox::Show(L"Por favor, describa sus sintomas para poder evaluarlos.",
				L"Datos incompletos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		Controller::ServicioPacientes^ svcP = gcnew Controller::ServicioPacientes();
		Controller::ServicioMedicamentos^ svcM = gcnew Controller::ServicioMedicamentos();

		// Historial del paciente
		List<String^>^ histLista = svcP->ExaminarHistorialReceta(idPaciente);
		String^ historial = (histLista->Count > 0)
			? String::Join(" | ", histLista)
			: "Sin historial previo";

		// Stock disponible para la IA
		List<Medicamento^>^ inv = svcM->ObtenerInventarioCompleto();
		List<String^>^ textos = gcnew List<String^>();
		for each(Medicamento ^ m in inv) {
			if (m->stock > 0)
				textos->Add(m->nombre + " (" + m->principioActivo + ") S/." +
					m->precio.ToString("F2") + " stock:" + m->stock);
		}
		String^ stockStr = String::Join(", ", textos);

		// Llamada a la IA
		IA_CLASS::IA^ ia = gcnew IA_CLASS::IA();
		String^ respuesta = ia->GenerarRecomendacion(
			txtSintomas->Text, historial, stockStr);

		MessageBox::Show(L"Analizando sintomas...",
			L"Evaluacion en curso", MessageBoxButtons::OK, MessageBoxIcon::Information);
		MessageBox::Show(respuesta, L"Recomendación de la IA",
			MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Recargar tabla con inventario REAL
		dgvMedicamentos->Rows->Clear();
		for each(Medicamento ^ m in inv) {
			dgvMedicamentos->Rows->Add(m->nombre, m->precio.ToString("F2"), m->stock);
		}
	}

		   // ─────────────────────────────────────────────────────────
		   //  COMPRA REAL → ServicioVentas::RegistrarVenta
		   // ─────────────────────────────────────────────────────────
	private: System::Void btnComprar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dgvMedicamentos->CurrentRow == nullptr ||
			dgvMedicamentos->CurrentRow->IsNewRow) {
			MessageBox::Show(L"Seleccione un medicamento de la tabla para realizar la compra.",
				L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Obtener datos de la fila seleccionada
		String^ nombreMed = dgvMedicamentos->CurrentRow->Cells["colNombre"]->Value->ToString();
		int stock = Convert::ToInt32(dgvMedicamentos->CurrentRow->Cells["colStock"]->Value);

		if (stock <= 0) {
			MessageBox::Show(L"Este medicamento no tiene stock disponible.",
				L"Sin stock", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Buscar el ID del medicamento por nombre
		Controller::ServicioMedicamentos^ svcM = gcnew Controller::ServicioMedicamentos();
		Dictionary<int, Medicamento^>^ dicMed = svcM->ObtenerDiccionarioCompleto();
		int idMed = -1;
		for each(auto kv in dicMed) {
			if (kv.Value->nombre == nombreMed) { idMed = kv.Key; break; }
		}
		if (idMed == -1) {
			MessageBox::Show(L"No se encontró el medicamento en el inventario.",
				L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Confirmar compra
		System::Windows::Forms::DialogResult conf = MessageBox::Show(
			"¿Confirma la compra de 1 unidad de " + nombreMed + "?",
			L"Confirmar Compra", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		if (conf == System::Windows::Forms::DialogResult::Yes) {
			Controller::ServicioVentas^ svcV = gcnew Controller::ServicioVentas();
			int nuevoId = (int)(DateTime::Now.Ticks % 100000);
			bool ok = svcV->RegistrarVenta(nuevoId, idPaciente, idMed, 1);

			if (ok) {
				MessageBox::Show(
					L"Compra procesada con exito!\nPor favor, retire su medicamento del dispensador.",
					L"Operacion Exitosa", MessageBoxButtons::OK, MessageBoxIcon::Information);
				txtSintomas->Text = "";
				dgvMedicamentos->Rows->Clear();
			}
			else {
				MessageBox::Show(L"No se pudo registrar la compra. Verifique el stock.",
					L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

		   // ─────────────────────────────────────────────────────────
		   //  NAVEGACIÓN
		   // ─────────────────────────────────────────────────────────
	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		if (loginRef != nullptr) loginRef->Show();
		this->Close();
	}

	private: System::Void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
		auto r = MessageBox::Show(L"¿Desea cerrar sesión?", L"Cerrar Sesión",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (r == System::Windows::Forms::DialogResult::Yes) {
			if (loginRef != nullptr) loginRef->Show();
			this->Close();
		}
	}

		   // Si cierra con la X, mostrar el Login igualmente
	private: System::Void PacienteForm_FormClosing(System::Object^ sender,
		System::Windows::Forms::FormClosingEventArgs^ e) {
		if (loginRef != nullptr && !loginRef->Visible)
			loginRef->Show();
	}

		   // ── Eventos vacíos originales (no eliminar) ───────────────
	private: System::Void panelSuperior_Paint(System::Object^ sender,
		System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panelDashboard_Paint(System::Object^ sender,
		System::Windows::Forms::PaintEventArgs^ e) {
	}
	};
}