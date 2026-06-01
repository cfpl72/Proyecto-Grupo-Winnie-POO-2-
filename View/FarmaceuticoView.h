#pragma once

namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


		// CONTROLES - Panel superior 
	private: System::Windows::Forms::Panel^ panel1;
		   // Panel de Control - Farmaceutico
		   // Usuario: Farmaceutico


		   // CONTROLES - Panel lateral 	   
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label2;  // MENU
	private: System::Windows::Forms::Button^ button1; // Ver Pacientes
	private: System::Windows::Forms::Button^ button2; // Examinar Receta
	private: System::Windows::Forms::Button^ button3; // Alertar Paciente
	private: System::Windows::Forms::Button^ button4; // Historial Recetas

		   // CONTROLES - Panel principal	  
	private: System::Windows::Forms::Panel^ panel3;


		   // Vista 1: Ver Pacientes (panel4)	  
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label4;   // titulo "Pacientes"
	private: System::Windows::Forms::Label^ labelBuscar;
	private: System::Windows::Forms::TextBox^ txtBuscar;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colApellido;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEdad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colAlergias;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colSintomas;

		   // Vista 2: Examinar Receta (panel5)   
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label5;      // titulo "Examinar Receta"
	private: System::Windows::Forms::Label^ labelPac2;
	private: System::Windows::Forms::ComboBox^ cmbPaciente;
	private: System::Windows::Forms::Button^ btnCargarReceta;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ lblIdL;   private: System::Windows::Forms::Label^ lblIdV;
	private: System::Windows::Forms::Label^ lblMedL;  private: System::Windows::Forms::Label^ lblMedV;
	private: System::Windows::Forms::Label^ lblDosL;  private: System::Windows::Forms::Label^ lblDosV;
	private: System::Windows::Forms::Label^ lblFecL;  private: System::Windows::Forms::Label^ lblFecV;
	private: System::Windows::Forms::Label^ lblEntL;  private: System::Windows::Forms::Label^ lblEntV;
	private: System::Windows::Forms::Button^ btnConfirmar;
	private: System::Windows::Forms::Button^ btnReporte;

		   // Vista 3: Alertar Paciente (panel6)
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ label6;      // titulo "Alertar Paciente"
	private: System::Windows::Forms::Label^ labelPac3;
	private: System::Windows::Forms::ComboBox^ cmbPacAlerta;
	private: System::Windows::Forms::Label^ labelMensaje;
	private: System::Windows::Forms::TextBox^ txtMensaje;
	private: System::Windows::Forms::Button^ btnEnviarAlerta;
	private: System::Windows::Forms::Label^ labelResultado;

		   // Vista 4: Historial Recetas (panel7)
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label7;      // titulo "Historial de Recetas"
	private: System::Windows::Forms::Label^ labelPac4;
	private: System::Windows::Forms::ComboBox^ cmbPacHist;
	private: System::Windows::Forms::Button^ btnCargarHist;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHMed;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHDos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHFec;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ colHEnt;

	private: System::Windows::Forms::Label^ lblTituloPpal;
	private: System::Windows::Forms::Label^ lblBienvenida;
	private: System::Windows::Forms::Label^ label1;

	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			this->lblTituloPpal = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->labelBuscar = (gcnew System::Windows::Forms::Label());
			this->txtBuscar = (gcnew System::Windows::Forms::TextBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ColNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colApellido = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEdad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colAlergias = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colSintomas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->labelPac2 = (gcnew System::Windows::Forms::Label());
			this->cmbPaciente = (gcnew System::Windows::Forms::ComboBox());
			this->btnCargarReceta = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lblIdL = (gcnew System::Windows::Forms::Label());
			this->lblIdV = (gcnew System::Windows::Forms::Label());
			this->lblMedL = (gcnew System::Windows::Forms::Label());
			this->lblMedV = (gcnew System::Windows::Forms::Label());
			this->lblDosL = (gcnew System::Windows::Forms::Label());
			this->lblDosV = (gcnew System::Windows::Forms::Label());
			this->lblFecL = (gcnew System::Windows::Forms::Label());
			this->lblFecV = (gcnew System::Windows::Forms::Label());
			this->lblEntL = (gcnew System::Windows::Forms::Label());
			this->lblEntV = (gcnew System::Windows::Forms::Label());
			this->btnConfirmar = (gcnew System::Windows::Forms::Button());
			this->btnReporte = (gcnew System::Windows::Forms::Button());
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
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel5->SuspendLayout();
			this->groupBox1->SuspendLayout();
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
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(952, 56);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
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
			this->label1->Size = System::Drawing::Size(148, 24);
			this->label1->TabIndex = 8;
			this->label1->Text = L"FARMACEUTICO";
			// 
			// lblBienvenida
			// 
			this->lblBienvenida->AutoSize = true;
			this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBienvenida->ForeColor = System::Drawing::SystemColors::Control;
			this->lblBienvenida->Location = System::Drawing::Point(884, 9);
			this->lblBienvenida->Name = L"lblBienvenida";
			this->lblBienvenida->Size = System::Drawing::Size(44, 30);
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
			this->lblTituloPpal->Size = System::Drawing::Size(100, 14);
			this->lblTituloPpal->TabIndex = 3;
			this->lblTituloPpal->Text = L"Portal de Control";
			this->lblTituloPpal->Click += gcnew System::EventHandler(this, &MyForm::lblTituloPpal_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->label2);
			this->panel2->ForeColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(0, 55);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(184, 433);
			this->panel2->TabIndex = 0;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel2_Paint);
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
			this->button4->Location = System::Drawing::Point(0, 147);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(184, 30);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Historial Recetas";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
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
			this->button3->Location = System::Drawing::Point(0, 111);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(184, 30);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Alertar Paciente";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
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
			this->button2->Location = System::Drawing::Point(0, 76);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(184, 30);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Examinar Receta";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(0, 40);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 30);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Ver Pacientes";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(62, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 14);
			this->label2->TabIndex = 0;
			this->label2->Text = L"MENU";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Controls->Add(this->panel5);
			this->panel3->Controls->Add(this->panel6);
			this->panel3->Controls->Add(this->panel7);
			this->panel3->Location = System::Drawing::Point(184, 55);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(768, 433);
			this->panel3->TabIndex = 2;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->Controls->Add(this->label4);
			this->panel4->Controls->Add(this->labelBuscar);
			this->panel4->Controls->Add(this->txtBuscar);
			this->panel4->Controls->Add(this->btnBuscar);
			this->panel4->Controls->Add(this->dataGridView1);
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(768, 433);
			this->panel4->TabIndex = 0;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel4_Paint);
			// 
			// label4
			// 
			this->label4->AllowDrop = true;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label4->Location = System::Drawing::Point(20, 18);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 22);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Pacientes";
			// 
			// labelBuscar
			// 
			this->labelBuscar->AutoSize = true;
			this->labelBuscar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelBuscar->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->labelBuscar->Location = System::Drawing::Point(20, 62);
			this->labelBuscar->Name = L"labelBuscar";
			this->labelBuscar->Size = System::Drawing::Size(106, 14);
			this->labelBuscar->TabIndex = 1;
			this->labelBuscar->Text = L"Buscar paciente:";
			// 
			// txtBuscar
			// 
			this->txtBuscar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBuscar->Location = System::Drawing::Point(155, 58);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(200, 21);
			this->txtBuscar->TabIndex = 2;
			this->txtBuscar->TextChanged += gcnew System::EventHandler(this, &MyForm::txtBuscar_TextChanged);
			// 
			// btnBuscar
			// 
			this->btnBuscar->BackColor = System::Drawing::Color::CadetBlue;
			this->btnBuscar->FlatAppearance->BorderSize = 0;
			this->btnBuscar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->ForeColor = System::Drawing::Color::White;
			this->btnBuscar->Location = System::Drawing::Point(365, 56);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(80, 28);
			this->btnBuscar->TabIndex = 3;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &MyForm::btnBuscar_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::DimGray;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::DimGray;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::DimGray;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->ColNombre,
					this->colApellido, this->colEdad, this->colAlergias, this->colSintomas
			});
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Gray;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::CadetBlue;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->GridColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->Location = System::Drawing::Point(14, 89);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->ShowCellErrors = false;
			this->dataGridView1->Size = System::Drawing::Size(726, 99);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// ColNombre
			// 
			this->ColNombre->HeaderText = L"Nombre";
			this->ColNombre->MinimumWidth = 6;
			this->ColNombre->Name = L"ColNombre";
			this->ColNombre->Width = 130;
			// 
			// colApellido
			// 
			this->colApellido->HeaderText = L"Apellido";
			this->colApellido->MinimumWidth = 6;
			this->colApellido->Name = L"colApellido";
			this->colApellido->Width = 130;
			// 
			// colEdad
			// 
			this->colEdad->HeaderText = L"Edad";
			this->colEdad->MinimumWidth = 6;
			this->colEdad->Name = L"colEdad";
			this->colEdad->Width = 60;
			// 
			// colAlergias
			// 
			this->colAlergias->HeaderText = L"Alergias";
			this->colAlergias->MinimumWidth = 6;
			this->colAlergias->Name = L"colAlergias";
			this->colAlergias->Width = 150;
			// 
			// colSintomas
			// 
			this->colSintomas->HeaderText = L"Sintomas";
			this->colSintomas->MinimumWidth = 6;
			this->colSintomas->Name = L"colSintomas";
			this->colSintomas->Width = 200;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Transparent;
			this->panel5->Controls->Add(this->label5);
			this->panel5->Controls->Add(this->labelPac2);
			this->panel5->Controls->Add(this->cmbPaciente);
			this->panel5->Controls->Add(this->btnCargarReceta);
			this->panel5->Controls->Add(this->groupBox1);
			this->panel5->Controls->Add(this->btnConfirmar);
			this->panel5->Controls->Add(this->btnReporte);
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(768, 433);
			this->panel5->TabIndex = 1;
			this->panel5->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label5->Location = System::Drawing::Point(20, 18);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(166, 22);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Examinar Receta";
			// 
			// labelPac2
			// 
			this->labelPac2->AutoSize = true;
			this->labelPac2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPac2->Location = System::Drawing::Point(20, 62);
			this->labelPac2->Name = L"labelPac2";
			this->labelPac2->Size = System::Drawing::Size(61, 14);
			this->labelPac2->TabIndex = 1;
			this->labelPac2->Text = L"Paciente:";
			// 
			// cmbPaciente
			// 
			this->cmbPaciente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbPaciente->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbPaciente->Location = System::Drawing::Point(100, 59);
			this->cmbPaciente->Name = L"cmbPaciente";
			this->cmbPaciente->Size = System::Drawing::Size(200, 22);
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
			this->btnCargarReceta->Location = System::Drawing::Point(315, 57);
			this->btnCargarReceta->Name = L"btnCargarReceta";
			this->btnCargarReceta->Size = System::Drawing::Size(120, 28);
			this->btnCargarReceta->TabIndex = 3;
			this->btnCargarReceta->Text = L"Cargar Receta";
			this->btnCargarReceta->UseVisualStyleBackColor = false;
			this->btnCargarReceta->Click += gcnew System::EventHandler(this, &MyForm::btnCargarReceta_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lblIdL);
			this->groupBox1->Controls->Add(this->lblIdV);
			this->groupBox1->Controls->Add(this->lblMedL);
			this->groupBox1->Controls->Add(this->lblMedV);
			this->groupBox1->Controls->Add(this->lblDosL);
			this->groupBox1->Controls->Add(this->lblDosV);
			this->groupBox1->Controls->Add(this->lblFecL);
			this->groupBox1->Controls->Add(this->lblFecV);
			this->groupBox1->Controls->Add(this->lblEntL);
			this->groupBox1->Controls->Add(this->lblEntV);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(20, 100);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(720, 210);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos de la Receta";
			// 
			// lblIdL
			// 
			this->lblIdL->AutoSize = true;
			this->lblIdL->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIdL->Location = System::Drawing::Point(15, 32);
			this->lblIdL->Name = L"lblIdL";
			this->lblIdL->Size = System::Drawing::Size(68, 14);
			this->lblIdL->TabIndex = 0;
			this->lblIdL->Text = L"ID Receta:";
			// 
			// lblIdV
			// 
			this->lblIdV->AutoSize = true;
			this->lblIdV->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIdV->ForeColor = System::Drawing::Color::DimGray;
			this->lblIdV->Location = System::Drawing::Point(130, 32);
			this->lblIdV->Name = L"lblIdV";
			this->lblIdV->Size = System::Drawing::Size(11, 14);
			this->lblIdV->TabIndex = 1;
			this->lblIdV->Text = L"-";
			// 
			// lblMedL
			// 
			this->lblMedL->AutoSize = true;
			this->lblMedL->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMedL->Location = System::Drawing::Point(15, 67);
			this->lblMedL->Name = L"lblMedL";
			this->lblMedL->Size = System::Drawing::Size(89, 14);
			this->lblMedL->TabIndex = 2;
			this->lblMedL->Text = L"Medicamento:";
			// 
			// lblMedV
			// 
			this->lblMedV->AutoSize = true;
			this->lblMedV->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMedV->ForeColor = System::Drawing::Color::DimGray;
			this->lblMedV->Location = System::Drawing::Point(130, 67);
			this->lblMedV->Name = L"lblMedV";
			this->lblMedV->Size = System::Drawing::Size(11, 14);
			this->lblMedV->TabIndex = 3;
			this->lblMedV->Text = L"-";
			// 
			// lblDosL
			// 
			this->lblDosL->AutoSize = true;
			this->lblDosL->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDosL->Location = System::Drawing::Point(15, 102);
			this->lblDosL->Name = L"lblDosL";
			this->lblDosL->Size = System::Drawing::Size(44, 14);
			this->lblDosL->TabIndex = 4;
			this->lblDosL->Text = L"Dosis:";
			// 
			// lblDosV
			// 
			this->lblDosV->AutoSize = true;
			this->lblDosV->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDosV->ForeColor = System::Drawing::Color::DimGray;
			this->lblDosV->Location = System::Drawing::Point(130, 102);
			this->lblDosV->Name = L"lblDosV";
			this->lblDosV->Size = System::Drawing::Size(11, 14);
			this->lblDosV->TabIndex = 5;
			this->lblDosV->Text = L"-";
			// 
			// lblFecL
			// 
			this->lblFecL->AutoSize = true;
			this->lblFecL->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFecL->Location = System::Drawing::Point(15, 137);
			this->lblFecL->Name = L"lblFecL";
			this->lblFecL->Size = System::Drawing::Size(95, 14);
			this->lblFecL->TabIndex = 6;
			this->lblFecL->Text = L"Fecha Emision:";
			// 
			// lblFecV
			// 
			this->lblFecV->AutoSize = true;
			this->lblFecV->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFecV->ForeColor = System::Drawing::Color::DimGray;
			this->lblFecV->Location = System::Drawing::Point(130, 137);
			this->lblFecV->Name = L"lblFecV";
			this->lblFecV->Size = System::Drawing::Size(11, 14);
			this->lblFecV->TabIndex = 7;
			this->lblFecV->Text = L"-";
			// 
			// lblEntL
			// 
			this->lblEntL->AutoSize = true;
			this->lblEntL->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEntL->Location = System::Drawing::Point(15, 172);
			this->lblEntL->Name = L"lblEntL";
			this->lblEntL->Size = System::Drawing::Size(72, 14);
			this->lblEntL->TabIndex = 8;
			this->lblEntL->Text = L"Entregado:";
			// 
			// lblEntV
			// 
			this->lblEntV->AutoSize = true;
			this->lblEntV->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEntV->ForeColor = System::Drawing::Color::Red;
			this->lblEntV->Location = System::Drawing::Point(130, 172);
			this->lblEntV->Name = L"lblEntV";
			this->lblEntV->Size = System::Drawing::Size(11, 14);
			this->lblEntV->TabIndex = 9;
			this->lblEntV->Text = L"-";
			// 
			// btnConfirmar
			// 
			this->btnConfirmar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->btnConfirmar->FlatAppearance->BorderSize = 0;
			this->btnConfirmar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnConfirmar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnConfirmar->ForeColor = System::Drawing::Color::White;
			this->btnConfirmar->Location = System::Drawing::Point(20, 325);
			this->btnConfirmar->Name = L"btnConfirmar";
			this->btnConfirmar->Size = System::Drawing::Size(150, 30);
			this->btnConfirmar->TabIndex = 5;
			this->btnConfirmar->Text = L"Confirmar Entrega";
			this->btnConfirmar->UseVisualStyleBackColor = false;
			this->btnConfirmar->Click += gcnew System::EventHandler(this, &MyForm::btnConfirmar_Click);
			// 
			// btnReporte
			// 
			this->btnReporte->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnReporte->FlatAppearance->BorderSize = 0;
			this->btnReporte->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReporte->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReporte->ForeColor = System::Drawing::Color::White;
			this->btnReporte->Location = System::Drawing::Point(185, 325);
			this->btnReporte->Name = L"btnReporte";
			this->btnReporte->Size = System::Drawing::Size(130, 30);
			this->btnReporte->TabIndex = 6;
			this->btnReporte->Text = L"Emitir Reporte";
			this->btnReporte->UseVisualStyleBackColor = false;
			this->btnReporte->Click += gcnew System::EventHandler(this, &MyForm::btnReporte_Click);
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
			this->label6->Size = System::Drawing::Size(159, 22);
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
			this->labelPac3->Size = System::Drawing::Size(61, 14);
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
			this->cmbPacAlerta->Size = System::Drawing::Size(200, 22);
			this->cmbPacAlerta->TabIndex = 2;
			// 
			// labelMensaje
			// 
			this->labelMensaje->AutoSize = true;
			this->labelMensaje->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelMensaje->Location = System::Drawing::Point(20, 102);
			this->labelMensaje->Name = L"labelMensaje";
			this->labelMensaje->Size = System::Drawing::Size(113, 14);
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
			this->btnEnviarAlerta->Click += gcnew System::EventHandler(this, &MyForm::btnEnviarAlerta_Click);
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
			this->label7->Size = System::Drawing::Size(194, 22);
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
			this->labelPac4->Size = System::Drawing::Size(61, 14);
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
			this->cmbPacHist->Size = System::Drawing::Size(200, 22);
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
			this->btnCargarHist->Click += gcnew System::EventHandler(this, &MyForm::btnCargarHist_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::DimGray;
			this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colHId,
					this->colHMed, this->colHDos, this->colHFec, this->colHEnt
			});
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::Color::Gray;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::CadetBlue;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle5;
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 11);
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
			this->Name = L"MyForm";
			this->Text = L"Sistema Farmacia - Farmaceutico";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		// Oculta todos los paneles y muestra solo el pedido
	private: void MostrarPanel(System::Windows::Forms::Panel^ panelActivo) {
		this->panel4->Visible = false;
		this->panel5->Visible = false;
		this->panel6->Visible = false;
		this->panel7->Visible = false;
		panelActivo->Visible = true;
	}

		   // Filtra filas del dataGridView1 por nombre o apellido
	private: void FiltrarPacientes(String^ texto) {
		String^ busqueda = texto->ToLower()->Trim();
		for each (System::Windows::Forms::DataGridViewRow ^ fila in this->dataGridView1->Rows)
		{
			if (fila->IsNewRow) continue;
			String^ nombre = fila->Cells[L"ColNombre"]->Value != nullptr ? fila->Cells[L"ColNombre"]->Value->ToString()->ToLower() : L"";
			String^ apellido = fila->Cells[L"colApellido"]->Value != nullptr ? fila->Cells[L"colApellido"]->Value->ToString()->ToLower() : L"";
			if (busqueda == String::Empty) {
				fila->Visible = true;
			}
			else {
				fila->Visible = nombre->Contains(busqueda) || apellido->Contains(busqueda);
			}
		}
	}
		   // MyForm_Load - datos de prueba
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// TODO: reemplazar con datos reales del Controller/ServicioUsuarios
		this->dataGridView1->Rows->Add(L"Jenna", L"Quezada", L"21", L"Penicilina", L"Fiebre, tos");
		this->dataGridView1->Rows->Add(L"Luis", L"Lopez", L"28", L"Ninguna", L"Dolor de cabeza");
		this->dataGridView1->Rows->Add(L"Carlos", L"Ramos", L"52", L"Ibuprofeno", L"Dolor articular");
		array<String^>^ pacientes = { L"Jenna Quezada", L"Luis Lopez", L"Carlos Ramos" };
		this->cmbPaciente->Items->AddRange(pacientes);
		this->cmbPacAlerta->Items->AddRange(pacientes);
		this->cmbPacHist->Items->AddRange(pacientes);
	}

		   // Sidebar - navegacion entre paneles
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MostrarPanel(this->panel4);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MostrarPanel(this->panel5);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		MostrarPanel(this->panel6);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		MostrarPanel(this->panel7);
	}

		   // Vista 1: Buscar paciente
	private: System::Void txtBuscar_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		FiltrarPacientes(this->txtBuscar->Text);
	}
	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		FiltrarPacientes(this->txtBuscar->Text);
	}

		   // Vista 2: Examinar Receta
	private: System::Void btnCargarReceta_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->cmbPaciente->SelectedIndex < 0) {
			MessageBox::Show(L"Seleccione un paciente.", L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		// TODO: obtener receta real via Controller -> Farmaceutico::ExaminarReceta(paciente)
		this->lblIdV->Text = L"REC-001";
		this->lblMedV->Text = L"Aspirina 500mg";
		this->lblDosV->Text = L"2 comprimidos cada 8 horas";
		this->lblFecV->Text = DateTime::Today.ToShortDateString();
		this->lblEntV->Text = L"No";
		this->lblEntV->ForeColor = System::Drawing::Color::Red;
	}
	private: System::Void btnConfirmar_Click(System::Object^ sender, System::EventArgs^ e) {
		// TODO: Receta::entregado = true via Controller
		this->lblEntV->Text = L"Si";
		this->lblEntV->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
			static_cast<System::Int32>(static_cast<System::Byte>(139)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
		MessageBox::Show(L"Entrega confirmada.", L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void btnReporte_Click(System::Object^ sender, System::EventArgs^ e) {
		// TODO: Receta::EmitirReporte() via Controller
		MessageBox::Show(L"Reporte emitido.", L"Reporte", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

		   // Vista 3: Alertar Paciente
	private: System::Void btnEnviarAlerta_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->cmbPacAlerta->SelectedIndex < 0) {
			MessageBox::Show(L"Seleccione un paciente.", L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (this->txtMensaje->Text->Trim() == String::Empty) {
			MessageBox::Show(L"Ingrese un mensaje.", L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		// TODO: Farmaceutico::AlertarPaciente() via Controller
		this->labelResultado->Text = L"Alerta enviada a: " + this->cmbPacAlerta->SelectedItem->ToString();
	}

		   // Vista 4: Historial Recetas
	private: System::Void btnCargarHist_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->cmbPacHist->SelectedIndex < 0) {
			MessageBox::Show(L"Seleccione un paciente.", L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		// TODO: ServicioVenta::VerHistorialPaciente(id) via Controller
		this->dataGridView2->Rows->Clear();
		this->dataGridView2->Rows->Add(L"REC-001", L"Aspirina 500mg", L"2 c/8h", L"01/04/2026", false);
		this->dataGridView2->Rows->Add(L"REC-002", L"Ibuprofeno 400mg", L"1 c/12h", L"15/04/2026", true);
	}

		   // Eventos vacios requeridos por el diseñador
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void lblTituloPpal_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}