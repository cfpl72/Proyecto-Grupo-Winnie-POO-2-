//  FarmaceuticoView.h 
//  Cambios aplicados:
//    1. Constructor acepta Form^ loginRef
//    2. MyForm_Load renombrado a FarmaForm_Load (evento Load)
//       → carga correctamente los tres combos de pacientes
//    3. btnEnviarAlerta_Click: usa nombre_apellido con guion bajo
//       para coincidir con el archivo alertas_Nombre_Apellido.txt
//    4. btnCargarHist_Click: corregido acceso a r->medicamento->nombre
//       (guarda el string antes, evita NullReferenceException)
//    5. Añadidos: btnVolver y btnCerrarSesion en panel1 (header)
//    6. panel2 (menú lateral) ampliado para acomodar los botones
//    7. FormClosing muestra el Login si se cierra con la X
// ============================================================
#pragma once

namespace ViewFarmaceutico {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Controller;

	public ref class Farmaceutico : public System::Windows::Forms::Form
	{
	private:
		Controller::ServicioPacientes^ svcPacientes;
		Form^ loginRef;

	public:
		Farmaceutico(Form^ loginForm)
		{
			InitializeComponent();
			loginRef = loginForm;
			svcPacientes = gcnew Controller::ServicioPacientes();
		}

	protected:
		~Farmaceutico()
		{
			if (components) delete components;
		}

	private:
		System::Collections::Generic::Dictionary<String^, array<int>^>^ _datosSemanales;
		System::Collections::Generic::Dictionary<String^, int>^ _frecuenciasTotales;

		// ── Controles originales ──────────────────────────────
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ lblTituloPpal;
	private: System::Windows::Forms::Label^ lblBienvenida;
	private: System::Windows::Forms::Label^ label1;

		   // ── Botones nuevos (en panel1) ────────────────────────

	private: System::Windows::Forms::Button^ btnCerrarSesion;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ labelPac2;
	private: System::Windows::Forms::ComboBox^ cmbPaciente;
	private: System::Windows::Forms::Button^ btnCargarReceta;
	private: System::Windows::Forms::Label^ labelFiltroMed;
	private: System::Windows::Forms::ComboBox^ cmbMedicamento;
	private: System::Windows::Forms::TabControl^ Graficos;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;

	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ labelPac3;
	private: System::Windows::Forms::ComboBox^ cmbPacAlerta;
	private: System::Windows::Forms::Label^ labelMensaje;
	private: System::Windows::Forms::TextBox^ txtMensaje;
	private: System::Windows::Forms::Button^ btnEnviarAlerta;
	private: System::Windows::Forms::Label^ labelResultado;

	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ labelPac4;
	private: System::Windows::Forms::ComboBox^ cmbPacHist;
	private: System::Windows::Forms::Button^ btnCargarHist;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHMed;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHDos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHFec;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ colHEnt;

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			   System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			   System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			   System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			   System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			   System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			   this->lblTituloPpal = (gcnew System::Windows::Forms::Label());
			   this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->panel3 = (gcnew System::Windows::Forms::Panel());
			   this->panel5 = (gcnew System::Windows::Forms::Panel());
			   this->labelFiltroMed = (gcnew System::Windows::Forms::Label());
			   this->cmbMedicamento = (gcnew System::Windows::Forms::ComboBox());
			   this->Graficos = (gcnew System::Windows::Forms::TabControl());
			   this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			   this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			   this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			   this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->labelPac2 = (gcnew System::Windows::Forms::Label());
			   this->cmbPaciente = (gcnew System::Windows::Forms::ComboBox());
			   this->btnCargarReceta = (gcnew System::Windows::Forms::Button());
			   this->panel6 = (gcnew System::Windows::Forms::Panel());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->labelPac3 = (gcnew System::Windows::Forms::Label());
			   this->cmbPacAlerta = (gcnew System::Windows::Forms::ComboBox());
			   this->labelMensaje = (gcnew System::Windows::Forms::Label());
			   this->txtMensaje = (gcnew System::Windows::Forms::TextBox());
			   this->btnEnviarAlerta = (gcnew System::Windows::Forms::Button());
			   this->labelResultado = (gcnew System::Windows::Forms::Label());
			   this->panel7 = (gcnew System::Windows::Forms::Panel());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->labelPac4 = (gcnew System::Windows::Forms::Label());
			   this->cmbPacHist = (gcnew System::Windows::Forms::ComboBox());
			   this->btnCargarHist = (gcnew System::Windows::Forms::Button());
			   this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			   this->colHId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->colHMed = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->colHDos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->colHFec = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->colHEnt = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			   this->panel1->SuspendLayout();
			   this->panel2->SuspendLayout();
			   this->panel3->SuspendLayout();
			   this->panel5->SuspendLayout();
			   this->Graficos->SuspendLayout();
			   this->tabPage1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			   this->tabPage2->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			   this->panel6->SuspendLayout();
			   this->panel7->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::CadetBlue;
			   this->panel1->Controls->Add(this->label1);
			   this->panel1->Controls->Add(this->lblBienvenida);
			   this->panel1->Controls->Add(this->lblTituloPpal);
			   this->panel1->Controls->Add(this->btnCerrarSesion);
			   this->panel1->Location = System::Drawing::Point(0, 0);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(952, 56);
			   this->panel1->TabIndex = 0;
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Farmaceutico::panel1_Paint);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::Transparent;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Heavy", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::Color::Cornsilk;
			   this->label1->Location = System::Drawing::Point(12, 24);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(181, 29);
			   this->label1->TabIndex = 8;
			   this->label1->Text = L"FARMACEUTICO";
			   this->label1->Click += gcnew System::EventHandler(this, &Farmaceutico::label1_Click_1);
			   // 
			   // lblBienvenida
			   // 
			   this->lblBienvenida->AutoSize = true;
			   this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblBienvenida->ForeColor = System::Drawing::SystemColors::Control;
			   this->lblBienvenida->Location = System::Drawing::Point(884, 9);
			   this->lblBienvenida->Name = L"lblBienvenida";
			   this->lblBienvenida->Size = System::Drawing::Size(56, 38);
			   this->lblBienvenida->TabIndex = 7;
			   this->lblBienvenida->Text = L"🐻";
			   this->lblBienvenida->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // lblTituloPpal
			   // 
			   this->lblTituloPpal->AutoSize = true;
			   this->lblTituloPpal->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblTituloPpal->ForeColor = System::Drawing::Color::Teal;
			   this->lblTituloPpal->Location = System::Drawing::Point(12, 9);
			   this->lblTituloPpal->Name = L"lblTituloPpal";
			   this->lblTituloPpal->Size = System::Drawing::Size(115, 16);
			   this->lblTituloPpal->TabIndex = 3;
			   this->lblTituloPpal->Text = L"Portal de Control";
			   this->lblTituloPpal->Click += gcnew System::EventHandler(this, &Farmaceutico::lblTituloPpal_Click);
			   // 
			   // btnCerrarSesion
			   // 
			   this->btnCerrarSesion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				   static_cast<System::Int32>(static_cast<System::Byte>(60)));
			   this->btnCerrarSesion->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnCerrarSesion->FlatAppearance->BorderSize = 0;
			   this->btnCerrarSesion->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnCerrarSesion->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnCerrarSesion->ForeColor = System::Drawing::Color::White;
			   this->btnCerrarSesion->Location = System::Drawing::Point(730, 12);
			   this->btnCerrarSesion->Name = L"btnCerrarSesion";
			   this->btnCerrarSesion->Size = System::Drawing::Size(120, 32);
			   this->btnCerrarSesion->TabIndex = 10;
			   this->btnCerrarSesion->Text = L"Cerrar Sesión";
			   this->btnCerrarSesion->UseVisualStyleBackColor = false;
			   this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &Farmaceutico::btnCerrarSesion_Click);
			   // 
			   // panel2
			   // 
			   this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)));
			   this->panel2->Controls->Add(this->button4);
			   this->panel2->Controls->Add(this->button3);
			   this->panel2->Controls->Add(this->button2);
			   this->panel2->Controls->Add(this->label2);
			   this->panel2->ForeColor = System::Drawing::Color::White;
			   this->panel2->Location = System::Drawing::Point(0, 55);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(184, 433);
			   this->panel2->TabIndex = 0;
			   this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Farmaceutico::panel2_Paint);
			   // 
			   // button4
			   // 
			   this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)));
			   this->button4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			   this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			   this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->button4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button4->ForeColor = System::Drawing::Color::White;
			   this->button4->Location = System::Drawing::Point(3, 106);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(184, 30);
			   this->button4->TabIndex = 4;
			   this->button4->Text = L"Historial Recetas";
			   this->button4->UseVisualStyleBackColor = false;
			   this->button4->Click += gcnew System::EventHandler(this, &Farmaceutico::button4_Click);
			   // 
			   // button3
			   // 
			   this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)));
			   this->button3->FlatAppearance->BorderSize = 0;
			   this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			   this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			   this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button3->ForeColor = System::Drawing::Color::White;
			   this->button3->Location = System::Drawing::Point(3, 73);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(184, 30);
			   this->button3->TabIndex = 3;
			   this->button3->Text = L"Alertar Paciente";
			   this->button3->UseVisualStyleBackColor = false;
			   this->button3->Click += gcnew System::EventHandler(this, &Farmaceutico::button3_Click);
			   // 
			   // button2
			   // 
			   this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)));
			   this->button2->FlatAppearance->BorderSize = 0;
			   this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			   this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				   static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			   this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button2->ForeColor = System::Drawing::Color::White;
			   this->button2->Location = System::Drawing::Point(3, 42);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(184, 30);
			   this->button2->TabIndex = 2;
			   this->button2->Text = L"Examinar Receta";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &Farmaceutico::button2_Click);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->label2->Location = System::Drawing::Point(65, 22);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(52, 17);
			   this->label2->TabIndex = 0;
			   this->label2->Text = L"MENU";
			   // 
			   // panel3
			   // 
			   this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				   static_cast<System::Int32>(static_cast<System::Byte>(250)));
			   this->panel3->Controls->Add(this->panel5);
			   this->panel3->Controls->Add(this->panel6);
			   this->panel3->Controls->Add(this->panel7);
			   this->panel3->Location = System::Drawing::Point(184, 55);
			   this->panel3->Name = L"panel3";
			   this->panel3->Size = System::Drawing::Size(768, 433);
			   this->panel3->TabIndex = 2;
			   // 
			   // panel5
			   // 
			   this->panel5->BackColor = System::Drawing::Color::Transparent;
			   this->panel5->Controls->Add(this->labelFiltroMed);
			   this->panel5->Controls->Add(this->cmbMedicamento);
			   this->panel5->Controls->Add(this->Graficos);
			   this->panel5->Controls->Add(this->label5);
			   this->panel5->Controls->Add(this->labelPac2);
			   this->panel5->Controls->Add(this->cmbPaciente);
			   this->panel5->Controls->Add(this->btnCargarReceta);
			   this->panel5->Location = System::Drawing::Point(0, 0);
			   this->panel5->Name = L"panel5";
			   this->panel5->Size = System::Drawing::Size(768, 433);
			   this->panel5->TabIndex = 1;
			   this->panel5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Farmaceutico::panel5_Paint);
			   // 
			   // labelFiltroMed
			   // 
			   this->labelFiltroMed->AutoSize = true;
			   this->labelFiltroMed->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->labelFiltroMed->Location = System::Drawing::Point(17, 86);
			   this->labelFiltroMed->Name = L"labelFiltroMed";
			   this->labelFiltroMed->Size = System::Drawing::Size(110, 17);
			   this->labelFiltroMed->TabIndex = 8;
			   this->labelFiltroMed->Text = L"Medicamento:";
			   this->labelFiltroMed->Click += gcnew System::EventHandler(this, &Farmaceutico::label3_Click_1);
			   // 
			   // cmbMedicamento
			   // 
			   this->cmbMedicamento->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cmbMedicamento->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			   this->cmbMedicamento->FormattingEnabled = true;
			   this->cmbMedicamento->Location = System::Drawing::Point(133, 79);
			   this->cmbMedicamento->Name = L"cmbMedicamento";
			   this->cmbMedicamento->Size = System::Drawing::Size(167, 25);
			   this->cmbMedicamento->TabIndex = 7;
			   this->cmbMedicamento->SelectedIndexChanged += gcnew System::EventHandler(this, &Farmaceutico::cmbMedicamento_SelectedIndexChanged);
			   // 
			   // Graficos
			   // 
			   this->Graficos->Controls->Add(this->tabPage1);
			   this->Graficos->Controls->Add(this->tabPage2);
			   this->Graficos->Location = System::Drawing::Point(25, 127);
			   this->Graficos->Name = L"Graficos";
			   this->Graficos->SelectedIndex = 0;
			   this->Graficos->Size = System::Drawing::Size(521, 292);
			   this->Graficos->TabIndex = 6;
			   // 
			   // tabPage1
			   // 
			   this->tabPage1->Controls->Add(this->chart1);
			   this->tabPage1->Location = System::Drawing::Point(4, 24);
			   this->tabPage1->Name = L"tabPage1";
			   this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			   this->tabPage1->Size = System::Drawing::Size(513, 264);
			   this->tabPage1->TabIndex = 0;
			   this->tabPage1->Text = L"Bar Chart";
			   this->tabPage1->UseVisualStyleBackColor = true;
			   // 
			   // chart1
			   // 
			   chartArea1->AxisX->IsLabelAutoFit = false;
			   chartArea1->AxisX->LabelStyle->Angle = -35;
			   chartArea1->AxisX->Title = L"Semana del mes";
			   chartArea1->AxisY->LabelStyle->Interval = 0;
			   chartArea1->AxisY->Title = L"Entregas realizadas";
			   chartArea1->Name = L"ChartArea1";
			   this->chart1->ChartAreas->Add(chartArea1);
			   legend1->LegendItemOrder = System::Windows::Forms::DataVisualization::Charting::LegendItemOrder::SameAsSeriesOrder;
			   legend1->Name = L"Legend1";
			   this->chart1->Legends->Add(legend1);
			   this->chart1->Location = System::Drawing::Point(6, 8);
			   this->chart1->Name = L"chart1";
			   this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Grayscale;
			   series1->ChartArea = L"ChartArea1";
			   series1->Legend = L"Legend1";
			   series1->Name = L"Series1";
			   this->chart1->Series->Add(series1);
			   this->chart1->Size = System::Drawing::Size(471, 250);
			   this->chart1->TabIndex = 0;
			   this->chart1->Text = L"BarChart";
			   this->chart1->Click += gcnew System::EventHandler(this, &Farmaceutico::chart1_Click);
			   // 
			   // tabPage2
			   // 
			   this->tabPage2->Controls->Add(this->chart2);
			   this->tabPage2->Location = System::Drawing::Point(4, 24);
			   this->tabPage2->Name = L"tabPage2";
			   this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			   this->tabPage2->Size = System::Drawing::Size(513, 264);
			   this->tabPage2->TabIndex = 1;
			   this->tabPage2->Text = L"Pie Chart";
			   this->tabPage2->UseVisualStyleBackColor = true;
			   // 
			   // chart2
			   // 
			   chartArea2->Name = L"ChartArea1";
			   this->chart2->ChartAreas->Add(chartArea2);
			   legend2->Name = L"Legend1";
			   this->chart2->Legends->Add(legend2);
			   this->chart2->Location = System::Drawing::Point(7, 7);
			   this->chart2->Name = L"chart2";
			   this->chart2->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SeaGreen;
			   series2->ChartArea = L"ChartArea1";
			   series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			   series2->Legend = L"Legend1";
			   series2->Name = L"Series1";
			   this->chart2->Series->Add(series2);
			   this->chart2->Size = System::Drawing::Size(364, 254);
			   this->chart2->TabIndex = 0;
			   this->chart2->Text = L"PieChart";
			   this->chart2->Click += gcnew System::EventHandler(this, &Farmaceutico::chart2_Click_1);
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				   static_cast<System::Int32>(static_cast<System::Byte>(45)));
			   this->label5->Location = System::Drawing::Point(20, 12);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(204, 27);
			   this->label5->TabIndex = 0;
			   this->label5->Text = L"Examinar Receta";
			   // 
			   // labelPac2
			   // 
			   this->labelPac2->AutoSize = true;
			   this->labelPac2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->labelPac2->Location = System::Drawing::Point(20, 52);
			   this->labelPac2->Name = L"labelPac2";
			   this->labelPac2->Size = System::Drawing::Size(77, 17);
			   this->labelPac2->TabIndex = 1;
			   this->labelPac2->Text = L"Paciente:";
			   // 
			   // cmbPaciente
			   // 
			   this->cmbPaciente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cmbPaciente->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->cmbPaciente->Location = System::Drawing::Point(100, 48);
			   this->cmbPaciente->Name = L"cmbPaciente";
			   this->cmbPaciente->Size = System::Drawing::Size(200, 25);
			   this->cmbPaciente->TabIndex = 2;
			   // 
			   // btnCargarReceta
			   // 
			   this->btnCargarReceta->BackColor = System::Drawing::Color::CadetBlue;
			   this->btnCargarReceta->FlatAppearance->BorderSize = 0;
			   this->btnCargarReceta->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnCargarReceta->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnCargarReceta->ForeColor = System::Drawing::Color::White;
			   this->btnCargarReceta->Location = System::Drawing::Point(315, 46);
			   this->btnCargarReceta->Name = L"btnCargarReceta";
			   this->btnCargarReceta->Size = System::Drawing::Size(120, 28);
			   this->btnCargarReceta->TabIndex = 3;
			   this->btnCargarReceta->Text = L"Cargar Receta";
			   this->btnCargarReceta->UseVisualStyleBackColor = false;
			   this->btnCargarReceta->Click += gcnew System::EventHandler(this, &Farmaceutico::btnCargarReceta_Click);
			   // 
			   // panel6
			   // 
			   this->panel6->BackColor = System::Drawing::Color::Transparent;
			   this->panel6->Controls->Add(this->label6);
			   this->panel6->Controls->Add(this->labelPac3);
			   this->panel6->Controls->Add(this->cmbPacAlerta);
			   this->panel6->Controls->Add(this->labelMensaje);
			   this->panel6->Controls->Add(this->txtMensaje);
			   this->panel6->Controls->Add(this->btnEnviarAlerta);
			   this->panel6->Controls->Add(this->labelResultado);
			   this->panel6->Location = System::Drawing::Point(0, 0);
			   this->panel6->Name = L"panel6";
			   this->panel6->Size = System::Drawing::Size(768, 433);
			   this->panel6->TabIndex = 2;
			   this->panel6->Visible = false;
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				   static_cast<System::Int32>(static_cast<System::Byte>(45)));
			   this->label6->Location = System::Drawing::Point(20, 18);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(196, 27);
			   this->label6->TabIndex = 0;
			   this->label6->Text = L"Alertar Paciente";
			   // 
			   // labelPac3
			   // 
			   this->labelPac3->AutoSize = true;
			   this->labelPac3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->labelPac3->Location = System::Drawing::Point(20, 62);
			   this->labelPac3->Name = L"labelPac3";
			   this->labelPac3->Size = System::Drawing::Size(77, 17);
			   this->labelPac3->TabIndex = 1;
			   this->labelPac3->Text = L"Paciente:";
			   // 
			   // cmbPacAlerta
			   // 
			   this->cmbPacAlerta->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cmbPacAlerta->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->cmbPacAlerta->Location = System::Drawing::Point(100, 59);
			   this->cmbPacAlerta->Name = L"cmbPacAlerta";
			   this->cmbPacAlerta->Size = System::Drawing::Size(200, 25);
			   this->cmbPacAlerta->TabIndex = 2;
			   // 
			   // labelMensaje
			   // 
			   this->labelMensaje->AutoSize = true;
			   this->labelMensaje->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->labelMensaje->Location = System::Drawing::Point(20, 102);
			   this->labelMensaje->Name = L"labelMensaje";
			   this->labelMensaje->Size = System::Drawing::Size(142, 17);
			   this->labelMensaje->TabIndex = 3;
			   this->labelMensaje->Text = L"Mensaje de alerta:";
			   // 
			   // txtMensaje
			   // 
			   this->txtMensaje->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txtMensaje->Location = System::Drawing::Point(20, 127);
			   this->txtMensaje->Multiline = true;
			   this->txtMensaje->Name = L"txtMensaje";
			   this->txtMensaje->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->txtMensaje->Size = System::Drawing::Size(720, 100);
			   this->txtMensaje->TabIndex = 4;
			   // 
			   // btnEnviarAlerta
			   // 
			   this->btnEnviarAlerta->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				   static_cast<System::Int32>(static_cast<System::Byte>(50)));
			   this->btnEnviarAlerta->FlatAppearance->BorderSize = 0;
			   this->btnEnviarAlerta->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnEnviarAlerta->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnEnviarAlerta->ForeColor = System::Drawing::Color::White;
			   this->btnEnviarAlerta->Location = System::Drawing::Point(20, 242);
			   this->btnEnviarAlerta->Name = L"btnEnviarAlerta";
			   this->btnEnviarAlerta->Size = System::Drawing::Size(130, 30);
			   this->btnEnviarAlerta->TabIndex = 5;
			   this->btnEnviarAlerta->Text = L"Enviar Alerta";
			   this->btnEnviarAlerta->UseVisualStyleBackColor = false;
			   this->btnEnviarAlerta->Click += gcnew System::EventHandler(this, &Farmaceutico::btnEnviarAlerta_Click);
			   // 
			   // labelResultado
			   // 
			   this->labelResultado->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->labelResultado->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				   static_cast<System::Int32>(static_cast<System::Byte>(34)));
			   this->labelResultado->Location = System::Drawing::Point(20, 285);
			   this->labelResultado->Name = L"labelResultado";
			   this->labelResultado->Size = System::Drawing::Size(500, 22);
			   this->labelResultado->TabIndex = 6;
			   // 
			   // panel7
			   // 
			   this->panel7->BackColor = System::Drawing::Color::Transparent;
			   this->panel7->Controls->Add(this->label7);
			   this->panel7->Controls->Add(this->labelPac4);
			   this->panel7->Controls->Add(this->cmbPacHist);
			   this->panel7->Controls->Add(this->btnCargarHist);
			   this->panel7->Controls->Add(this->dataGridView2);
			   this->panel7->Location = System::Drawing::Point(0, 0);
			   this->panel7->Name = L"panel7";
			   this->panel7->Size = System::Drawing::Size(768, 433);
			   this->panel7->TabIndex = 3;
			   this->panel7->Visible = false;
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				   static_cast<System::Int32>(static_cast<System::Byte>(45)));
			   this->label7->Location = System::Drawing::Point(20, 18);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(238, 27);
			   this->label7->TabIndex = 0;
			   this->label7->Text = L"Historial de Recetas";
			   // 
			   // labelPac4
			   // 
			   this->labelPac4->AutoSize = true;
			   this->labelPac4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->labelPac4->Location = System::Drawing::Point(20, 62);
			   this->labelPac4->Name = L"labelPac4";
			   this->labelPac4->Size = System::Drawing::Size(77, 17);
			   this->labelPac4->TabIndex = 1;
			   this->labelPac4->Text = L"Paciente:";
			   // 
			   // cmbPacHist
			   // 
			   this->cmbPacHist->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cmbPacHist->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->cmbPacHist->Location = System::Drawing::Point(100, 59);
			   this->cmbPacHist->Name = L"cmbPacHist";
			   this->cmbPacHist->Size = System::Drawing::Size(200, 25);
			   this->cmbPacHist->TabIndex = 2;
			   // 
			   // btnCargarHist
			   // 
			   this->btnCargarHist->BackColor = System::Drawing::Color::CadetBlue;
			   this->btnCargarHist->FlatAppearance->BorderSize = 0;
			   this->btnCargarHist->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnCargarHist->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnCargarHist->ForeColor = System::Drawing::Color::White;
			   this->btnCargarHist->Location = System::Drawing::Point(315, 57);
			   this->btnCargarHist->Name = L"btnCargarHist";
			   this->btnCargarHist->Size = System::Drawing::Size(130, 28);
			   this->btnCargarHist->TabIndex = 3;
			   this->btnCargarHist->Text = L"Cargar Historial";
			   this->btnCargarHist->UseVisualStyleBackColor = false;
			   this->btnCargarHist->Click += gcnew System::EventHandler(this, &Farmaceutico::btnCargarHist_Click);
			   // 
			   // dataGridView2
			   // 
			   this->dataGridView2->AllowUserToAddRows = false;
			   this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->dataGridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   dataGridViewCellStyle1->BackColor = System::Drawing::Color::Gainsboro;
			   dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   dataGridViewCellStyle1->ForeColor = System::Drawing::Color::DimGray;
			   this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			   this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				   this->colHId,
					   this->colHMed, this->colHDos, this->colHFec, this->colHEnt
			   });
			   dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			   dataGridViewCellStyle2->BackColor = System::Drawing::Color::White;
			   dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Gray;
			   dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::CadetBlue;
			   dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			   dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			   this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle2;
			   this->dataGridView2->GridColor = System::Drawing::Color::WhiteSmoke;
			   this->dataGridView2->Location = System::Drawing::Point(20, 100);
			   this->dataGridView2->Name = L"dataGridView2";
			   this->dataGridView2->ReadOnly = true;
			   this->dataGridView2->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			   this->dataGridView2->RowHeadersWidth = 51;
			   this->dataGridView2->RowTemplate->Height = 24;
			   this->dataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->dataGridView2->Size = System::Drawing::Size(720, 300);
			   this->dataGridView2->TabIndex = 4;
			   // 
			   // colHId
			   // 
			   this->colHId->HeaderText = L"ID Receta";
			   this->colHId->MinimumWidth = 6;
			   this->colHId->Name = L"colHId";
			   this->colHId->ReadOnly = true;
			   this->colHId->Width = 125;
			   // 
			   // colHMed
			   // 
			   this->colHMed->HeaderText = L"Medicamento";
			   this->colHMed->MinimumWidth = 6;
			   this->colHMed->Name = L"colHMed";
			   this->colHMed->ReadOnly = true;
			   this->colHMed->Width = 200;
			   // 
			   // colHDos
			   // 
			   this->colHDos->HeaderText = L"Dosis";
			   this->colHDos->MinimumWidth = 6;
			   this->colHDos->Name = L"colHDos";
			   this->colHDos->ReadOnly = true;
			   this->colHDos->Width = 150;
			   // 
			   // colHFec
			   // 
			   this->colHFec->HeaderText = L"Fecha";
			   this->colHFec->MinimumWidth = 6;
			   this->colHFec->Name = L"colHFec";
			   this->colHFec->ReadOnly = true;
			   this->colHFec->Width = 120;
			   // 
			   // colHEnt
			   // 
			   this->colHEnt->HeaderText = L"Entregado";
			   this->colHEnt->MinimumWidth = 6;
			   this->colHEnt->Name = L"colHEnt";
			   this->colHEnt->ReadOnly = true;
			   this->colHEnt->Width = 80;
			   // 
			   // Farmaceutico
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				   static_cast<System::Int32>(static_cast<System::Byte>(250)));
			   this->ClientSize = System::Drawing::Size(952, 486);
			   this->Controls->Add(this->panel3);
			   this->Controls->Add(this->panel2);
			   this->Controls->Add(this->panel1);
			   this->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"Farmaceutico";
			   this->Text = L"Sistema Farmacia - Farmaceutico";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Farmaceutico::FarmaForm_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &Farmaceutico::FarmaForm_Load);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->panel2->ResumeLayout(false);
			   this->panel2->PerformLayout();
			   this->panel3->ResumeLayout(false);
			   this->panel5->ResumeLayout(false);
			   this->panel5->PerformLayout();
			   this->Graficos->ResumeLayout(false);
			   this->tabPage1->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			   this->tabPage2->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			   this->panel6->ResumeLayout(false);
			   this->panel6->PerformLayout();
			   this->panel7->ResumeLayout(false);
			   this->panel7->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion

		   // ─────────────────────────────────────────────────────────
		   //  CARGA INICIAL – llena los tres combos con pacientes reales
		   // ─────────────────────────────────────────────────────────
	private: System::Void FarmaForm_Load(System::Object^ sender, System::EventArgs^ e) {
		System::Collections::Generic::List<String^>^ pacientes =
			svcPacientes->ObtenerNombresPacientes();
		for each(String ^ nombre in pacientes) {
			this->cmbPaciente->Items->Add(nombre);
			this->cmbPacAlerta->Items->Add(nombre);
			this->cmbPacHist->Items->Add(nombre);
		}
	}

		   // ─────────────────────────────────────────────────────────
		   //  Helpers gráficos 
		   // ─────────────────────────────────────────────────────────
	private: int GetSemana(int dia) {
		if (dia <= 7)  return 0;
		if (dia <= 14) return 1;
		if (dia <= 21) return 2;
		if (dia <= 28) return 3;
		return 4;
	}

	private: System::Drawing::Color ColorBarra(int actual, int anterior) {
		if (anterior == 0 || actual == 0) return System::Drawing::Color::CadetBlue;
		double inc = ((double)(actual - anterior) / anterior) * 100.0;
		if (inc >= 100.0) return System::Drawing::Color::Crimson;
		if (inc >= 50.0)  return System::Drawing::Color::DarkOrange;
		return System::Drawing::Color::CadetBlue;
	}

	private: void MostrarPanel(System::Windows::Forms::Panel^ panelActivo) {
		this->panel5->Visible = false;
		this->panel6->Visible = false;
		this->panel7->Visible = false;
		panelActivo->Visible = true;
	}

	private: int BuscarIdPaciente(String^ nombreCompleto) {
		auto dic = svcPacientes->LeerTodos();
		for each(auto kv in dic) {
			if ((kv.Value->nombre + " " + kv.Value->apellido) == nombreCompleto)
				return kv.Key;
		}
		return -1;
	}

		   // Sidebar
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { MostrarPanel(this->panel5); }
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { MostrarPanel(this->panel6); }
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { MostrarPanel(this->panel7); }

		   // ── Examinar Receta ───────────────────────────────────────
	private: System::Void btnCargarReceta_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->cmbPaciente->SelectedIndex < 0) {
			MessageBox::Show(L"Seleccione un paciente.", L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		this->cmbMedicamento->Items->Clear();
		this->chart1->Series["Series1"]->Points->Clear();
		this->chart2->Series["Series1"]->Points->Clear();
		_datosSemanales = gcnew System::Collections::Generic::Dictionary<String^, array<int>^>();
		_frecuenciasTotales = gcnew System::Collections::Generic::Dictionary<String^, int>();

		String^ nombreSel = this->cmbPaciente->SelectedItem->ToString();
		int idPaciente = BuscarIdPaciente(nombreSel);
		if (idPaciente == -1) {
			MessageBox::Show(L"No se encontró el paciente.", L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		System::Collections::Generic::List<String^>^ lineas = svcPacientes->ExaminarHistorialReceta(idPaciente);
		if (lineas->Count == 0) {
			MessageBox::Show(L"No hay recetas registradas para este paciente.", L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}

		for each(String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea)) continue;
			array<String^>^ partes = linea->Split(',');
			if (partes->Length < 5) continue;
			String^ med = partes[1]->Trim();
			String^ fechaStr = partes[3]->Trim();
			String^ estado = partes[4]->Trim();
			if (estado != "Entregado") continue;
			DateTime fecha;
			array<String^>^ fmts = { L"dd/MM/yyyy", L"dd-MM-yyyy" };
			if (!DateTime::TryParseExact(fechaStr, fmts,
				System::Globalization::CultureInfo::InvariantCulture,
				System::Globalization::DateTimeStyles::None, fecha)) continue;
			int sem = GetSemana(fecha.Day);
			if (!_datosSemanales->ContainsKey(med))
				_datosSemanales->Add(med, gcnew array<int>(5) { 0, 0, 0, 0, 0 });
			_datosSemanales[med][sem]++;
			if (!_frecuenciasTotales->ContainsKey(med))
				_frecuenciasTotales->Add(med, 0);
			_frecuenciasTotales[med]++;
		}

		if (_datosSemanales->Count == 0) {
			MessageBox::Show(L"No hay entregas registradas en el historial.", L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		for each(String ^ med in _datosSemanales->Keys)
			this->cmbMedicamento->Items->Add(med);
		this->cmbMedicamento->SelectedIndex = 0;
		DibujarPieChart();
	}

	private: System::Void cmbMedicamento_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->cmbMedicamento->SelectedIndex < 0 || _datosSemanales == nullptr) return;
		String^ med = this->cmbMedicamento->SelectedItem->ToString();
		if (!_datosSemanales->ContainsKey(med)) return;
		array<int>^ conteo = _datosSemanales[med];
		array<String^>^ nombres = { "Sem 1","Sem 2","Sem 3","Sem 4","Sem 5" };
		this->chart1->Series["Series1"]->Points->Clear();
		this->chart1->Series["Series1"]->ChartType =
			System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;
		for (int i = 0; i < 5; i++) {
			int idx = this->chart1->Series["Series1"]->Points->AddXY(nombres[i], conteo[i]);
			System::Drawing::Color c = (i == 0)
				? System::Drawing::Color::CadetBlue
				: ColorBarra(conteo[i], conteo[i - 1]);
			this->chart1->Series["Series1"]->Points[idx]->Color = c;
		}
	}

	private: void DibujarPieChart() {
		this->chart2->Series["Series1"]->Points->Clear();
		this->chart2->Series["Series1"]->ChartType =
			System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
		int total = 0;
		for each(int v in _frecuenciasTotales->Values) total += v;
		if (total == 0) return;
		for each(auto par in _frecuenciasTotales) {
			double pct = ((double)par.Value / total) * 100.0;
			int idx = this->chart2->Series["Series1"]->Points->AddXY(par.Key, par.Value);
			this->chart2->Series["Series1"]->Points[idx]->Label = par.Key + "\n" + pct.ToString("F0") + "%";
			this->chart2->Series["Series1"]->Points[idx]->LegendText = par.Key + " (" + par.Value + " entregas)";
		}
	}

		   // ── Alertar Paciente ──────────────────────────────────────
	private: System::Void btnEnviarAlerta_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->cmbPacAlerta->SelectedIndex < 0) {
			MessageBox::Show(L"Seleccione un paciente.", L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		if (this->txtMensaje->Text->Trim() == String::Empty) {
			MessageBox::Show(L"Ingrese un mensaje.", L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		String^ nombreCompleto = this->cmbPacAlerta->SelectedItem->ToString();
		// El archivo se llama alertas_Nombre_Apellido.txt → usar guion bajo
		String^ nombreArchivo = nombreCompleto->Replace(" ", "_");
		Controller::ServicioFarmaceutico::AlertarPaciente(nombreArchivo, this->txtMensaje->Text->Trim());
		this->labelResultado->Text = L"✅ Alerta enviada a: " + nombreCompleto;
		this->txtMensaje->Clear();
	}

		   // ── Historial Recetas ─────────────────────────────────────
	private: System::Void btnCargarHist_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->cmbPacHist->SelectedIndex < 0) {
			MessageBox::Show(L"Seleccione un paciente.", L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}
		String^ nombreSel = this->cmbPacHist->SelectedItem->ToString();
		int idPaciente = BuscarIdPaciente(nombreSel);
		if (idPaciente == -1) {
			MessageBox::Show(L"Paciente no encontrado.", L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
		}

		System::Collections::Generic::List<WinniePOO_Modelos::Receta^>^ historial =
			svcPacientes->ObtenerHistorial(idPaciente);
		this->dataGridView2->Rows->Clear();

		for each(WinniePOO_Modelos::Receta ^ r in historial) {
			String^ idFmt = "REC-" + r->idReceta.ToString("D3");
			// CORREGIDO: guardar nombre antes de usarlo (evita NullReferenceException)
			String^ nomMed = (r->medicamento != nullptr) ? r->medicamento->nombre : "N/A";
			String^ dosis = r->dosis.ToString() + " c/12h";
			String^ fecha = r->fechaEmision.ToString("dd/MM/yyyy");
			this->dataGridView2->Rows->Add(idFmt, nomMed, dosis, fecha, r->entregado);
		}
	}


	private: System::Void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
		auto r = MessageBox::Show(L"¿Desea cerrar sesión?", L"Cerrar Sesión",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (r == System::Windows::Forms::DialogResult::Yes) {
			if (loginRef != nullptr) loginRef->Show();
			this->Close();
		}
	}

	private: System::Void FarmaForm_FormClosing(System::Object^ sender,
		System::Windows::Forms::FormClosingEventArgs^ e) {
		if (loginRef != nullptr && !loginRef->Visible) loginRef->Show();
	}

		   // ── Eventos vacíos del designer (no eliminar) ─────────────
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	private: System::Void lblTituloPpal_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label3_Click_1(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void chart2_Click_1(System::Object^ sender, System::EventArgs^ e) {}
	};
}