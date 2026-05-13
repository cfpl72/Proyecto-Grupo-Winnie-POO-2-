#pragma once

namespace ViewFarmaceutico {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Farmaceutico : public System::Windows::Forms::Form
	{
	public:
		Farmaceutico(void)
		{
			InitializeComponent();
		}

	protected:
		~Farmaceutico()
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
		   // Ver Pacientes
	private: System::Windows::Forms::Button^ button2; // Examinar Receta
	private: System::Windows::Forms::Button^ button3; // Alertar Paciente
	private: System::Windows::Forms::Button^ button4; // Historial Recetas

		   // CONTROLES - Panel principal	  
	private: System::Windows::Forms::Panel^ panel3;

		   // Vista 2: Examinar Receta (panel5)
		   // ---------------agregando la declaracion de la libreria
	//private: System::Collections::Generic::Dictionary<String^, int>^ _frecuencias;
		   //agregar un arreglo de 5 espacios(semanas) de cada medicamento para graficar
	private: System::Collections::Generic::Dictionary<String^, array<int>^>^ _datosSemanales;
	//diccionario que guardara el total de entregas sumados de la semana
	private: System::Collections::Generic::Dictionary<String^, int>^ _frecuenciasTotales;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label5;      // titulo "Examinar Receta"
	private: System::Windows::Forms::Label^ labelPac2;
	private: System::Windows::Forms::ComboBox^ cmbPaciente;
	private: System::Windows::Forms::Button^ btnCargarReceta;


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
	private: System::Windows::Forms::TabControl^ Graficos;


	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::Label^ labelFiltroMed;

	private: System::Windows::Forms::ComboBox^ cmbMedicamento;


	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			this->lblTituloPpal = (gcnew System::Windows::Forms::Label());
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
			chartArea3->AxisX->IsLabelAutoFit = false;
			chartArea3->AxisX->LabelStyle->Angle = -35;
			chartArea3->AxisX->Title = L"Semana del mes";
			chartArea3->AxisY->LabelStyle->Interval = 0;
			chartArea3->AxisY->Title = L"Entregas realizadas";
			chartArea3->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea3);
			legend3->LegendItemOrder = System::Windows::Forms::DataVisualization::Charting::LegendItemOrder::SameAsSeriesOrder;
			legend3->Name = L"Legend1";
			this->chart1->Legends->Add(legend3);
			this->chart1->Location = System::Drawing::Point(6, 8);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Grayscale;
			series3->ChartArea = L"ChartArea1";
			series3->Legend = L"Legend1";
			series3->Name = L"Series1";
			this->chart1->Series->Add(series3);
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
			chartArea4->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea4);
			legend4->Name = L"Legend1";
			this->chart2->Legends->Add(legend4);
			this->chart2->Location = System::Drawing::Point(7, 7);
			this->chart2->Name = L"chart2";
			this->chart2->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SeaGreen;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series4->Legend = L"Legend1";
			series4->Name = L"Series1";
			this->chart2->Series->Add(series4);
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
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::DimGray;
			this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colHId,
					this->colHMed, this->colHDos, this->colHFec, this->colHEnt
			});
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Gray;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::CadetBlue;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle4;
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
			this->Load += gcnew System::EventHandler(this, &Farmaceutico::MyForm_Load);
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
		//METODOS PARA LAS GRAFICAS!!!!!!
		
		//=========METODOS PARA EL GRAFICO DE BARRAS==================== 
		//METODO QUE CONVIERTE LOS DIAS EN SEMANAS DEL OBJETO DATETIME
		private: int GetSemana(int dia) {
			if (dia <= 7) return 0;   // Semana 1: días  1– 7
			if (dia <= 14) return 1;   // Semana 2: días  8–14
			if (dia <= 21) return 2;   // Semana 3: días 15–21
			if (dia <= 28) return 3;   // Semana 4: días 22–28
			return 4;                  // Semana 5: días 29–31
		}
		//METODO PARA COLOEAR LA BARRA QUE INDICA EL SOBRECONSUMO
		private: System::Drawing::Color ColorBarra(int actual, int anterior) {
			// Sin datos anteriores para comparar → color neutro
			if (anterior == 0 || actual == 0)
				return System::Drawing::Color::CadetBlue;

			double incremento = ((double)(actual - anterior) / anterior) * 100.0;

			if (incremento >= 100.0)
				return System::Drawing::Color::Crimson;    // Sobreconsumo
			if (incremento >= 50.0)
				return System::Drawing::Color::DarkOrange; // Advertencia

			return System::Drawing::Color::CadetBlue;      // Normal
		}
		
		// Oculta todos los paneles y muestra solo el pedido
	private: void MostrarPanel(System::Windows::Forms::Panel^ panelActivo) {
		this->panel5->Visible = false;
		this->panel6->Visible = false;
		this->panel7->Visible = false;
		panelActivo->Visible = true;
	}

		   // Filtra filas del dataGridView1 por nombre o apellido
	private: void FiltrarPacientes(String^ texto) {
		String^ busqueda = texto->ToLower()->Trim();
		
	}
		   // MyForm_Load - datos de prueba
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// TODO: reemplazar con datos reales del Controller/ServicioUsuarios
		
		array<String^>^ pacientes = { L"Jenna Quezada", L"Luis Lopez", L"Carlos Ramos" };
		this->cmbPaciente->Items->AddRange(pacientes);
		this->cmbPacAlerta->Items->AddRange(pacientes);
		this->cmbPacHist->Items->AddRange(pacientes);
	}

		   // Sidebar - navegacion entre paneles
	
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MostrarPanel(this->panel5);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		MostrarPanel(this->panel6);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		MostrarPanel(this->panel7);
	}

		   // Vista 2: Examinar Receta
		   //=========================================
	private: System::Void btnCargarReceta_Click(System::Object^ sender, System::EventArgs^ e) {
		//PARA VER LA UBIACCION DE DONDE VA A LEER EL ARCHIVO HISTORIAL DEL PACIENTE
		//MessageBox::Show(System::IO::Directory::GetCurrentDirectory(), L"Ruta actual");

		if (this->cmbPaciente->SelectedIndex < 0) {
			MessageBox::Show(L"Seleccione un paciente.", L"Aviso",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// 1. Limpiar estado anterior
		this->cmbMedicamento->Items->Clear();
		this->chart1->Series["Series1"]->Points->Clear();
		this->chart2->Series["Series1"]->Points->Clear();
		//_frecuencias = gcnew System::Collections::Generic::Dictionary<String^, int>();
		_datosSemanales = gcnew System::Collections::Generic::Dictionary<String^, array<int>^>();
		_frecuenciasTotales = gcnew System::Collections::Generic::Dictionary<String^, int>();
		// 2. Construir nombre del archivo
		String^ paciente = this->cmbPaciente->SelectedItem->ToString();
		String^ nombreArchivo = L"historialReceta_" + paciente->Replace(L" ", L"_") + L".txt";
		String^ ruta = System::IO::Path::Combine(
			System::IO::Directory::GetCurrentDirectory(),
			nombreArchivo);
		//===============================================================verifica si el arhivo existe
		if (!System::IO::File::Exists(ruta)) {
			MessageBox::Show(L"No se encontró el archivo:\n" + ruta,
				L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		//=============================================================== LEE LAS LINEAS DEL ARCHIVO Y CUENTA LAS FRECUENCIAS DE CADA MEDICAMENTO
		// 4. Leer líneas y contar frecuencias por medicamento (columna [1])
		array<String^>^ lineas = System::IO::File::ReadAllLines(ruta);

		for each (String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea) || linea->StartsWith(L"#"))
				continue;

			array<String^>^ partes = linea->Split(L',');
			if (partes->Length < 5) continue;

			String^ med = partes[1]->Trim(); // columna [1] = Medicamento
			String^ fechaStr = partes[3]->Trim(); // columna [3] = Fecha
			String^ entregado = partes[4]->Trim(); // columna [4] = Entregado
			// Solo contar si fue entregado
			if (entregado != "1" && entregado != "true") continue;

			// ── Extraer el día usando DateTime::TryParseExact ─────────────────
			DateTime fecha;
			array<String^>^ formatos = { L"dd/MM/yyyy", L"dd-MM-yyyy" };

			if (!DateTime::TryParseExact(
				fechaStr,
				formatos,
				System::Globalization::CultureInfo::InvariantCulture,
				System::Globalization::DateTimeStyles::None,fecha))
				continue;

			int dia = fecha.Day;
			// ── Determinar semana e incrementar contador ───────────────────────
			int semana = GetSemana(dia);  // 0-4

			if (!_datosSemanales->ContainsKey(med))
				_datosSemanales->Add(med, gcnew array<int>(5) { 0, 0, 0, 0, 0 });

			array<int>^ conteo = _datosSemanales[med];  // extraer referencia al array
			conteo[semana]++;                           // modificar a través de la referencia


/*

			if (!_frecuencias->ContainsKey(med))
				_frecuencias->Add(med, 0);
				_frecuencias[med]++;
*/
			// Sumar al total por medicamento
			if (!_frecuenciasTotales->ContainsKey(med))
				_frecuenciasTotales->Add(med, 0);
			_frecuenciasTotales[med]++;   
		}

		// ── Validar que haya datos ────────────────────────────────────────────
		if (_datosSemanales->Count == 0) {
			MessageBox::Show(L"No hay entregas registradas en el historial.",
				L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}

		// ── Poblar combo con los medicamentos encontrados ─────────────────────
		for each (String ^ med in _datosSemanales->Keys)
			this->cmbMedicamento->Items->Add(med);

		// Seleccionar el primero → dispara automáticamente el evento del combo
		this->cmbMedicamento->SelectedIndex = 0;
		DibujarPieChart();
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
		   //===================METODO CARGAR HISTORIAL==========================
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
		   //=============================================================
		  
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	
	private: System::Void lblTituloPpal_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void chart2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chart2_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cmbMedicamento_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	
	if (this->cmbMedicamento->SelectedIndex < 0 || _datosSemanales == nullptr)
		return;

	String^ med = this->cmbMedicamento->SelectedItem->ToString();
	if (!_datosSemanales->ContainsKey(med)) return;

	array<int>^ conteo = _datosSemanales[med];

	// Nombres de cada semana para el eje X
	array<String^>^ nombres = { "Sem 1", "Sem 2", "Sem 3", "Sem 4", "Sem 5" };

	// Limpiar barras anteriores
	this->chart1->Series["Series1"]->Points->Clear();

	this->chart1->Series["Series1"]->ChartType =
		System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;

	// Dibujar una barra por semana
	for (int i = 0; i < 5; i++) {

		int idx = this->chart1->Series["Series1"]->Points->AddXY(nombres[i], conteo[i]);

		// Color según incremento respecto a la semana anterior
		if (i == 0) {
			// Primera semana no tiene con qué comparar
			this->chart1->Series["Series1"]->Points[idx]->Color =
				System::Drawing::Color::CadetBlue;
		}
		else {
			int anterior = conteo[i - 1];
			int actual = conteo[i];

			if (anterior == 0) {
				// No hay dato anterior para comparar
				this->chart1->Series["Series1"]->Points[idx]->Color =
					System::Drawing::Color::CadetBlue;
			}
			else {
				//logicca para detectar el incremento porcentual de una pastilla
				double incremento = ((double)(actual - anterior) / anterior) * 100.0;

				if (incremento >= 100.0)
					this->chart1->Series["Series1"]->Points[idx]->Color =
					System::Drawing::Color::Red;      // Sobreconsumo
				else if (incremento >= 50.0)
					this->chart1->Series["Series1"]->Points[idx]->Color =
					System::Drawing::Color::DarkOrange;   // Advertencia
				else
					this->chart1->Series["Series1"]->Points[idx]->Color =
					System::Drawing::Color::CadetBlue;    // Normal
			}
		}
	}


}
private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
	   private: void DibujarPieChart() {

		   this->chart2->Series["Series1"]->Points->Clear();
		   this->chart2->Series["Series1"]->ChartType =
			   System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;

		   // Calcular total general de entregas del mes
		   int totalGeneral = 0;
		   for each (int cantidad in _frecuenciasTotales->Values)
			   totalGeneral += cantidad;

		   if (totalGeneral == 0) return;

		   // Agregar cada medicamento como sección del pie
		   for each (System::Collections::Generic::KeyValuePair<String^, int> par in _frecuenciasTotales) {

			   String^ med = par.Key;
			   int      cantidad = par.Value;

			   double porcentaje = ((double)cantidad / totalGeneral) * 100.0;

			   int idx = this->chart2->Series["Series1"]->Points->AddXY(med, cantidad);

			   // Etiqueta dentro de cada sección: nombre + porcentaje
			   this->chart2->Series["Series1"]->Points[idx]->Label =
				   med + "\n" + porcentaje.ToString("F0") + "%";

			   this->chart2->Series["Series1"]->Points[idx]->LegendText =
				   med + " (" + cantidad.ToString() + " entregas)";
		   }


		   for each (System::Collections::Generic::KeyValuePair<String^, int> par in _frecuenciasTotales) {

			   double porcentaje = ((double)par.Value / totalGeneral) * 100.0;

			  
		   }
	   }
};
}