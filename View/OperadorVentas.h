// ============================================================
//  OperadorVentas.h 
// ============================================================
#pragma once
#include "OpcionesVenta.h"

namespace WinniePOOview {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class OperadorVentas : public System::Windows::Forms::Form
	{
	private:
		Controller::ServicioMedicamentos^ servicioMedicamentos;
		Controller::ServicioVentas^ servicioVentas;
		Form^ loginRef;
		bool cerrandoSesion = false;


		System::Windows::Forms::DataVisualization::Charting::Chart^ chartStock;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartVentas;
		System::Windows::Forms::TabPage^ tabGraficos;
		System::Windows::Forms::TabControl^ tabSubGraficos;
		System::Windows::Forms::TabPage^ tabBarStock;
		System::Windows::Forms::TabPage^ tabBarVentas;

		// Configuración de gráficos fuera del Diseñador
		void ConfigurarGraficosAvanzados() {
			// Configuración de chartStock
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ area1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			area1->Name = L"AreaStock";
			this->chartStock->ChartAreas->Add(area1);

			System::Windows::Forms::DataVisualization::Charting::Series^ serie1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			serie1->Name = L"SerieStock";
			serie1->ChartArea = L"AreaStock";
			serie1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Bar;
			this->chartStock->Series->Add(serie1);

			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			title1->Text = L"Stock actual por medicamento";
			this->chartStock->Titles->Add(title1);

			// Configuración de chartVentas
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ area2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			area2->Name = L"AreaVentas";
			this->chartVentas->ChartAreas->Add(area2);

			System::Windows::Forms::DataVisualization::Charting::Series^ serie2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			serie2->Name = L"SerieVentas";
			serie2->ChartArea = L"AreaVentas";
			serie2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Bar;
			this->chartVentas->Series->Add(serie2);

			System::Windows::Forms::DataVisualization::Charting::Title^ title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			title2->Text = L"Ventas totales (S/.) por medicamento";
			this->chartVentas->Titles->Add(title2);
		}

		void ActualizarTablas() {
			tablaInventario->Rows->Clear();
			tablaVentas->Rows->Clear();

			// 1. Obtenemos el inventario completo del archivo/base de datos
			List<WinniePOO_Modelos::Medicamento^>^ inventarioCompleto =
				servicioMedicamentos->ObtenerInventarioCompleto();

			// 2. Creamos una nueva lista solo para los medicamentos "Activos" (Stock > 0)
			List<WinniePOO_Modelos::Medicamento^>^ inventarioFiltrado =
				gcnew List<WinniePOO_Modelos::Medicamento^>();

			// 3. Filtramos y llenamos la tabla de Inventario
			for each(WinniePOO_Modelos::Medicamento ^ med in inventarioCompleto) {
				if (med->stock > 0) { // ── AQUÍ ESTÁ LA MAGIA: Solo pasan los que tienen stock ──
					inventarioFiltrado->Add(med);
					tablaInventario->Rows->Add(
						med->id, med->nombre, med->principioActivo,
						med->precio.ToString("F2"), med->stock);
				}
			}

			// 4. Llenamos la tabla de Ventas (esto se queda igual)
			List<WinniePOO_Modelos::Venta^>^ ventas =
				servicioVentas->ObtenerTodasLasVentas();
			for each(WinniePOO_Modelos::Venta ^ v in ventas) {
				tablaVentas->Rows->Add(
					v->id, v->nombreMedicamento,
					v->cantidadVendida,
					v->totalVenta.ToString("F2"),
					v->fecha);
			}

			// 5. Pasamos la lista FILTRADA a los gráficos para que tampoco aparezcan ahí
			ActualizarGraficos(inventarioFiltrado, ventas);
		}

		void ActualizarGraficos(
			List<WinniePOO_Modelos::Medicamento^>^ inv,
			List<WinniePOO_Modelos::Venta^>^ ventas)
		{
			chartStock->Series["SerieStock"]->Points->Clear();
			chartStock->Series["SerieStock"]->ChartType = DataVisualization::Charting::SeriesChartType::Bar;

			for each (WinniePOO_Modelos::Medicamento ^ m in inv) {
				int idx = chartStock->Series["SerieStock"]->Points->AddXY(m->nombre, m->stock);
				System::Drawing::Color c;
				if (m->stock <= 5)       c = System::Drawing::Color::Crimson;
				else if (m->stock <= 15) c = System::Drawing::Color::DarkOrange;
				else                     c = System::Drawing::Color::CadetBlue;
				chartStock->Series["SerieStock"]->Points[idx]->Color = c;
			}

			chartVentas->Series["SerieVentas"]->Points->Clear();
			chartVentas->Series["SerieVentas"]->ChartType = DataVisualization::Charting::SeriesChartType::Bar;

			Dictionary<String^, double>^ acum = gcnew Dictionary<String^, double>();
			for each (WinniePOO_Modelos::Venta ^ v in ventas) {
				if (!acum->ContainsKey(v->nombreMedicamento))
					acum[v->nombreMedicamento] = 0.0;
				acum[v->nombreMedicamento] += v->totalVenta;
			}
			for each (auto par in acum) {
				int idx = chartVentas->Series["SerieVentas"]->Points->AddXY(par.Key, par.Value);
				chartVentas->Series["SerieVentas"]->Points[idx]->Color = System::Drawing::Color::SeaGreen;
				chartVentas->Series["SerieVentas"]->Points[idx]->Label = "S/." + par.Value.ToString("F2");
			}
		}

	public:
		OperadorVentas(void)
		{
			InitializeComponent();
		}

		OperadorVentas(Form^ loginForm)
		{
			InitializeComponent();
			loginRef = loginForm;
			servicioMedicamentos = gcnew Controller::ServicioMedicamentos();
			servicioVentas = gcnew Controller::ServicioVentas();
		}

	protected:
		~OperadorVentas()
		{
			if (components) delete components;
		}

	private: System::Windows::Forms::TabControl^ tabControlPrincipal;
	private: System::Windows::Forms::TabPage^ tabInventario;
	private: System::Windows::Forms::TabPage^ tabVentas;
	private: System::Windows::Forms::DataGridView^ tablaInventario;
	private: System::Windows::Forms::DataGridView^ tablaVentas;
	private: System::Windows::Forms::GroupBox^ groupBoxEdicion;
	private: System::Windows::Forms::Label^ lblIdMed;
	private: System::Windows::Forms::Label^ lblNuevoPrecio;
	private: System::Windows::Forms::Label^ lblNuevoStock;
	private: System::Windows::Forms::TextBox^ txtIdMed;
	private: System::Windows::Forms::TextBox^ txtNuevoPrecio;
	private: System::Windows::Forms::TextBox^ txtNuevoStock;
	private: System::Windows::Forms::Button^ btnActualizarMed;
	private: System::Windows::Forms::Button^ btnGestionarVentas;
	private: System::Windows::Forms::Button^ btnCerrarSesion;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->tabControlPrincipal = (gcnew System::Windows::Forms::TabControl());
			   this->tabInventario = (gcnew System::Windows::Forms::TabPage());
			   this->tablaInventario = (gcnew System::Windows::Forms::DataGridView());
			   this->groupBoxEdicion = (gcnew System::Windows::Forms::GroupBox());
			   this->lblIdMed = (gcnew System::Windows::Forms::Label());
			   this->txtIdMed = (gcnew System::Windows::Forms::TextBox());
			   this->lblNuevoPrecio = (gcnew System::Windows::Forms::Label());
			   this->txtNuevoPrecio = (gcnew System::Windows::Forms::TextBox());
			   this->lblNuevoStock = (gcnew System::Windows::Forms::Label());
			   this->txtNuevoStock = (gcnew System::Windows::Forms::TextBox());
			   this->btnActualizarMed = (gcnew System::Windows::Forms::Button());
			   this->tabVentas = (gcnew System::Windows::Forms::TabPage());
			   this->tablaVentas = (gcnew System::Windows::Forms::DataGridView());
			   this->btnGestionarVentas = (gcnew System::Windows::Forms::Button());
			   this->tabGraficos = (gcnew System::Windows::Forms::TabPage());
			   this->tabSubGraficos = (gcnew System::Windows::Forms::TabControl());
			   this->tabBarStock = (gcnew System::Windows::Forms::TabPage());
			   this->chartStock = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			   this->tabBarVentas = (gcnew System::Windows::Forms::TabPage());
			   this->chartVentas = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
			   this->tabControlPrincipal->SuspendLayout();
			   this->tabInventario->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaInventario))->BeginInit();
			   this->groupBoxEdicion->SuspendLayout();
			   this->tabVentas->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaVentas))->BeginInit();
			   this->tabGraficos->SuspendLayout();
			   this->tabSubGraficos->SuspendLayout();
			   this->tabBarStock->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartStock))->BeginInit();
			   this->tabBarVentas->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartVentas))->BeginInit();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // tabControlPrincipal
			   // 
			   this->tabControlPrincipal->Controls->Add(this->tabInventario);
			   this->tabControlPrincipal->Controls->Add(this->tabVentas);
			   this->tabControlPrincipal->Controls->Add(this->tabGraficos);
			   this->tabControlPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tabControlPrincipal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   this->tabControlPrincipal->Location = System::Drawing::Point(0, 60);
			   this->tabControlPrincipal->Name = L"tabControlPrincipal";
			   this->tabControlPrincipal->SelectedIndex = 0;
			   this->tabControlPrincipal->Size = System::Drawing::Size(962, 560);
			   this->tabControlPrincipal->TabIndex = 0;
			   // 
			   // tabInventario
			   // 
			   this->tabInventario->Controls->Add(this->tablaInventario);
			   this->tabInventario->Controls->Add(this->groupBoxEdicion);
			   this->tabInventario->Location = System::Drawing::Point(4, 32);
			   this->tabInventario->Name = L"tabInventario";
			   this->tabInventario->Padding = System::Windows::Forms::Padding(10);
			   this->tabInventario->Size = System::Drawing::Size(954, 524);
			   this->tabInventario->TabIndex = 0;
			   this->tabInventario->Text = L"Inventario";
			   this->tabInventario->UseVisualStyleBackColor = true;
			   // 
			   // tablaInventario
			   // 
			   this->tablaInventario->AllowUserToAddRows = false;
			   this->tablaInventario->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			   this->tablaInventario->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->tablaInventario->Dock = System::Windows::Forms::DockStyle::Top;
			   this->tablaInventario->Location = System::Drawing::Point(10, 10);
			   this->tablaInventario->Name = L"tablaInventario";
			   this->tablaInventario->ReadOnly = true;
			   this->tablaInventario->RowHeadersVisible = false;
			   this->tablaInventario->RowHeadersWidth = 51;
			   this->tablaInventario->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->tablaInventario->Size = System::Drawing::Size(934, 320);
			   this->tablaInventario->TabIndex = 0;
			   // 
			   // groupBoxEdicion
			   // 
			   this->groupBoxEdicion->Controls->Add(this->lblIdMed);
			   this->groupBoxEdicion->Controls->Add(this->txtIdMed);
			   this->groupBoxEdicion->Controls->Add(this->lblNuevoPrecio);
			   this->groupBoxEdicion->Controls->Add(this->txtNuevoPrecio);
			   this->groupBoxEdicion->Controls->Add(this->lblNuevoStock);
			   this->groupBoxEdicion->Controls->Add(this->txtNuevoStock);
			   this->groupBoxEdicion->Controls->Add(this->btnActualizarMed);
			   this->groupBoxEdicion->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->groupBoxEdicion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			   this->groupBoxEdicion->Location = System::Drawing::Point(10, 394);
			   this->groupBoxEdicion->Name = L"groupBoxEdicion";
			   this->groupBoxEdicion->Size = System::Drawing::Size(934, 120);
			   this->groupBoxEdicion->TabIndex = 1;
			   this->groupBoxEdicion->TabStop = false;
			   this->groupBoxEdicion->Text = L"Actualizar Medicamento";
			   // 
			   // lblIdMed
			   // 
			   this->lblIdMed->AutoSize = true;
			   this->lblIdMed->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			   this->lblIdMed->Location = System::Drawing::Point(20, 35);
			   this->lblIdMed->Name = L"lblIdMed";
			   this->lblIdMed->Size = System::Drawing::Size(123, 20);
			   this->lblIdMed->TabIndex = 0;
			   this->lblIdMed->Text = L"ID Medicamento:";
			   // 
			   // txtIdMed
			   // 
			   this->txtIdMed->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			   this->txtIdMed->Location = System::Drawing::Point(150, 32);
			   this->txtIdMed->Name = L"txtIdMed";
			   this->txtIdMed->Size = System::Drawing::Size(100, 27);
			   this->txtIdMed->TabIndex = 1;
			   // 
			   // lblNuevoPrecio
			   // 
			   this->lblNuevoPrecio->AutoSize = true;
			   this->lblNuevoPrecio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			   this->lblNuevoPrecio->Location = System::Drawing::Point(290, 35);
			   this->lblNuevoPrecio->Name = L"lblNuevoPrecio";
			   this->lblNuevoPrecio->Size = System::Drawing::Size(100, 20);
			   this->lblNuevoPrecio->TabIndex = 2;
			   this->lblNuevoPrecio->Text = L"Nuevo Precio:";
			   // 
			   // txtNuevoPrecio
			   // 
			   this->txtNuevoPrecio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			   this->txtNuevoPrecio->Location = System::Drawing::Point(400, 32);
			   this->txtNuevoPrecio->Name = L"txtNuevoPrecio";
			   this->txtNuevoPrecio->Size = System::Drawing::Size(100, 27);
			   this->txtNuevoPrecio->TabIndex = 3;
			   // 
			   // lblNuevoStock
			   // 
			   this->lblNuevoStock->AutoSize = true;
			   this->lblNuevoStock->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			   this->lblNuevoStock->Location = System::Drawing::Point(540, 35);
			   this->lblNuevoStock->Name = L"lblNuevoStock";
			   this->lblNuevoStock->Size = System::Drawing::Size(95, 20);
			   this->lblNuevoStock->TabIndex = 4;
			   this->lblNuevoStock->Text = L"Nuevo Stock:";
			   // 
			   // txtNuevoStock
			   // 
			   this->txtNuevoStock->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			   this->txtNuevoStock->Location = System::Drawing::Point(650, 32);
			   this->txtNuevoStock->Name = L"txtNuevoStock";
			   this->txtNuevoStock->Size = System::Drawing::Size(100, 27);
			   this->txtNuevoStock->TabIndex = 5;
			   // 
			   // btnActualizarMed
			   // 
			   this->btnActualizarMed->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->btnActualizarMed->ForeColor = System::Drawing::Color::White;
			   this->btnActualizarMed->Location = System::Drawing::Point(20, 75);
			   this->btnActualizarMed->Name = L"btnActualizarMed";
			   this->btnActualizarMed->Size = System::Drawing::Size(200, 35);
			   this->btnActualizarMed->TabIndex = 6;
			   this->btnActualizarMed->Text = L"Actualizar Medicamento";
			   this->btnActualizarMed->UseVisualStyleBackColor = false;
			   this->btnActualizarMed->Click += gcnew System::EventHandler(this, &OperadorVentas::btnActualizarMed_Click);
			   // 
			   // tabVentas
			   // 
			   this->tabVentas->Controls->Add(this->tablaVentas);
			   this->tabVentas->Controls->Add(this->btnGestionarVentas);
			   this->tabVentas->Location = System::Drawing::Point(4, 32);
			   this->tabVentas->Name = L"tabVentas";
			   this->tabVentas->Padding = System::Windows::Forms::Padding(10);
			   this->tabVentas->Size = System::Drawing::Size(954, 524);
			   this->tabVentas->TabIndex = 1;
			   this->tabVentas->Text = L"Historial de Ventas";
			   this->tabVentas->UseVisualStyleBackColor = true;
			   // 
			   // tablaVentas
			   // 
			   this->tablaVentas->AllowUserToAddRows = false;
			   this->tablaVentas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			   this->tablaVentas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->tablaVentas->Dock = System::Windows::Forms::DockStyle::Top;
			   this->tablaVentas->Location = System::Drawing::Point(10, 10);
			   this->tablaVentas->MultiSelect = false;
			   this->tablaVentas->Name = L"tablaVentas";
			   this->tablaVentas->ReadOnly = true;
			   this->tablaVentas->RowHeadersVisible = false;
			   this->tablaVentas->RowHeadersWidth = 51;
			   this->tablaVentas->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->tablaVentas->Size = System::Drawing::Size(934, 380);
			   this->tablaVentas->TabIndex = 0;
			   // 
			   // btnGestionarVentas
			   // 
			   this->btnGestionarVentas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)),
				   static_cast<System::Int32>(static_cast<System::Byte>(166)), static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->btnGestionarVentas->ForeColor = System::Drawing::Color::White;
			   this->btnGestionarVentas->Location = System::Drawing::Point(10, 400);
			   this->btnGestionarVentas->Name = L"btnGestionarVentas";
			   this->btnGestionarVentas->Size = System::Drawing::Size(250, 40);
			   this->btnGestionarVentas->TabIndex = 1;
			   this->btnGestionarVentas->Text = L"Gestionar Venta Seleccionada";
			   this->btnGestionarVentas->UseVisualStyleBackColor = false;
			   this->btnGestionarVentas->Click += gcnew System::EventHandler(this, &OperadorVentas::btnGestionarVentas_Click);
			   // 
			   // tabGraficos
			   // 
			   this->tabGraficos->Controls->Add(this->tabSubGraficos);
			   this->tabGraficos->Location = System::Drawing::Point(4, 32);
			   this->tabGraficos->Name = L"tabGraficos";
			   this->tabGraficos->Padding = System::Windows::Forms::Padding(10);
			   this->tabGraficos->Size = System::Drawing::Size(954, 524);
			   this->tabGraficos->TabIndex = 2;
			   this->tabGraficos->Text = L"Gráficos";
			   this->tabGraficos->UseVisualStyleBackColor = true;
			   // 
			   // tabSubGraficos
			   // 
			   this->tabSubGraficos->Controls->Add(this->tabBarStock);
			   this->tabSubGraficos->Controls->Add(this->tabBarVentas);
			   this->tabSubGraficos->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tabSubGraficos->Location = System::Drawing::Point(10, 10);
			   this->tabSubGraficos->Name = L"tabSubGraficos";
			   this->tabSubGraficos->SelectedIndex = 0;
			   this->tabSubGraficos->Size = System::Drawing::Size(934, 504);
			   this->tabSubGraficos->TabIndex = 0;
			   // 
			   // tabBarStock
			   // 
			   this->tabBarStock->Controls->Add(this->chartStock);
			   this->tabBarStock->Location = System::Drawing::Point(4, 32);
			   this->tabBarStock->Name = L"tabBarStock";
			   this->tabBarStock->Size = System::Drawing::Size(926, 468);
			   this->tabBarStock->TabIndex = 0;
			   this->tabBarStock->Text = L"Stock por Medicamento";
			   this->tabBarStock->UseVisualStyleBackColor = true;
			   // 
			   // chartStock
			   // 
			   this->chartStock->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->chartStock->Location = System::Drawing::Point(0, 0);
			   this->chartStock->Name = L"chartStock";
			   this->chartStock->Size = System::Drawing::Size(926, 468);
			   this->chartStock->TabIndex = 0;
			   // 
			   // tabBarVentas
			   // 
			   this->tabBarVentas->Controls->Add(this->chartVentas);
			   this->tabBarVentas->Location = System::Drawing::Point(4, 32);
			   this->tabBarVentas->Name = L"tabBarVentas";
			   this->tabBarVentas->Size = System::Drawing::Size(924, 468);
			   this->tabBarVentas->TabIndex = 1;
			   this->tabBarVentas->Text = L"Ventas Totales por Medicamento";
			   this->tabBarVentas->UseVisualStyleBackColor = true;
			   // 
			   // chartVentas
			   // 
			   this->chartVentas->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->chartVentas->Location = System::Drawing::Point(0, 0);
			   this->chartVentas->Name = L"chartVentas";
			   this->chartVentas->Size = System::Drawing::Size(924, 468);
			   this->chartVentas->TabIndex = 0;
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->panel1->Controls->Add(this->label1);
			   this->panel1->Controls->Add(this->label3);
			   this->panel1->Controls->Add(this->btnCerrarSesion);
			   this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			   this->panel1->Location = System::Drawing::Point(0, 0);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(962, 60);
			   this->panel1->TabIndex = 1;
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &OperadorVentas::panel1_Paint);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			   this->label1->ForeColor = System::Drawing::Color::White;
			   this->label1->Location = System::Drawing::Point(12, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(351, 32);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Panel del Operador de Ventas";
			   this->label1->Click += gcnew System::EventHandler(this, &OperadorVentas::label1_Click);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			   this->label3->ForeColor = System::Drawing::Color::White;
			   this->label3->Location = System::Drawing::Point(17, 37);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(298, 20);
			   this->label3->TabIndex = 1;
			   this->label3->Text = L"WinniePOO - Gestión de Inventario y Ventas";
			   // 
			   // btnCerrarSesion
			   // 
			   this->btnCerrarSesion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->btnCerrarSesion->BackColor = System::Drawing::Color::IndianRed;
			   this->btnCerrarSesion->ForeColor = System::Drawing::Color::White;
			   this->btnCerrarSesion->Location = System::Drawing::Point(792, 13);
			   this->btnCerrarSesion->Name = L"btnCerrarSesion";
			   this->btnCerrarSesion->Size = System::Drawing::Size(120, 35);
			   this->btnCerrarSesion->TabIndex = 3;
			   this->btnCerrarSesion->Text = L"Cerrar Sesión";
			   this->btnCerrarSesion->UseVisualStyleBackColor = false;
			   this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &OperadorVentas::btnCerrarSesion_Click);
			   // 
			   // OperadorVentas
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(962, 620);
			   this->Controls->Add(this->tabControlPrincipal);
			   this->Controls->Add(this->panel1);
			   this->MinimumSize = System::Drawing::Size(980, 660);
			   this->Name = L"OperadorVentas";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"WinniePOO - Operador de Ventas";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &OperadorVentas::OV_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &OperadorVentas::OperadorVentas_Load);
			   this->tabControlPrincipal->ResumeLayout(false);
			   this->tabInventario->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaInventario))->EndInit();
			   this->groupBoxEdicion->ResumeLayout(false);
			   this->groupBoxEdicion->PerformLayout();
			   this->tabVentas->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaVentas))->EndInit();
			   this->tabGraficos->ResumeLayout(false);
			   this->tabSubGraficos->ResumeLayout(false);
			   this->tabBarStock->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartStock))->EndInit();
			   this->tabBarVentas->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartVentas))->EndInit();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: System::Void OperadorVentas_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CancelButton = this->btnCerrarSesion;

		// Llama a la configuración avanzada aquí, donde es completamente seguro
		ConfigurarGraficosAvanzados();

		tablaInventario->Columns->Add("ColID", "ID Med.");
		tablaInventario->Columns->Add("ColNombre", "Nombre");
		tablaInventario->Columns->Add("ColPrincipio", "Principio Activo");
		tablaInventario->Columns->Add("ColPrecio", "Precio (S/.)");
		tablaInventario->Columns->Add("ColStock", "Stock");

		tablaVentas->Columns->Add("ColIdVenta", "ID Venta");
		tablaVentas->Columns->Add("ColMed", "Medicamento");
		tablaVentas->Columns->Add("ColCant", "Cantidad");
		tablaVentas->Columns->Add("ColTotal", "Total (S/.)");
		tablaVentas->Columns->Add("ColFecha", "Fecha");

		//servicioMedicamentos->SeedMedicamentosDemo();
		//servicioVentas->SeedVentasDemo();
		ActualizarTablas();
	}

	private: System::Void btnActualizarMed_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			int    id = Convert::ToInt32(txtIdMed->Text);
			double prec = Convert::ToDouble(txtNuevoPrecio->Text);
			int    stock = Convert::ToInt32(txtNuevoStock->Text);
			bool   ok = servicioMedicamentos->ActualizarMedicamento(id, prec, stock);
			if (ok) {
				MessageBox::Show(L"Medicamento actualizado correctamente.",
					L"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				ActualizarTablas();
			}
			else {
				MessageBox::Show(L"No se pudo actualizar. Verifica que el ID exista.",
					L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^) {
			MessageBox::Show(L"Por favor, ingresa numeros validos.",
				L"Error de formato", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	private: System::Void btnGestionarVentas_Click(System::Object^ sender, System::EventArgs^ e) {
		if (tablaVentas->SelectedRows->Count > 0) {
			int id = Convert::ToInt32(tablaVentas->SelectedRows[0]->Cells[0]->Value);
			WinniePOOview::OpcionesVenta^ ventanaOpciones =
				gcnew WinniePOOview::OpcionesVenta(id, servicioVentas);
			ventanaOpciones->ShowDialog();
			ActualizarTablas();
		}
		else {
			MessageBox::Show(L"Por favor, selecciona una fila del historial de ventas.",
				L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	private: System::Void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
		auto r = MessageBox::Show(L"¿Desea cerrar sesión?", L"Cerrar Sesión",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (r == System::Windows::Forms::DialogResult::Yes) {
			cerrandoSesion = true; // ── Avisamos que es un cierre de sesión
			if (loginRef != nullptr) loginRef->Show();
			this->Close();
		}
	}


	private: System::Void OV_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (!cerrandoSesion) {
			// Si la bandera es falsa, apretaron la "X". Apagamos todo el sistema.
			Application::Exit();
		}
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	};
}