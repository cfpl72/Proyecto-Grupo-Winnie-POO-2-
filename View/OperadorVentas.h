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
	using namespace WinniePOO_Modelos;

	/// <summary>
	/// Resumen de OperadorVentas
	/// </summary>
	public ref class OperadorVentas : public System::Windows::Forms::Form
	{
	public:
		OperadorVentas(void)
		{
			InitializeComponent();
		}

	protected:
		~OperadorVentas()
		{
			if (components)
			{
				delete components;
			}
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
	private: System::Windows::Forms::Label^ lblBienvenida;





	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->tabControlPrincipal = (gcnew System::Windows::Forms::TabControl());
			this->tabInventario = (gcnew System::Windows::Forms::TabPage());
			this->groupBoxEdicion = (gcnew System::Windows::Forms::GroupBox());
			this->btnActualizarMed = (gcnew System::Windows::Forms::Button());
			this->txtNuevoStock = (gcnew System::Windows::Forms::TextBox());
			this->txtNuevoPrecio = (gcnew System::Windows::Forms::TextBox());
			this->txtIdMed = (gcnew System::Windows::Forms::TextBox());
			this->lblNuevoStock = (gcnew System::Windows::Forms::Label());
			this->lblNuevoPrecio = (gcnew System::Windows::Forms::Label());
			this->lblIdMed = (gcnew System::Windows::Forms::Label());
			this->tablaInventario = (gcnew System::Windows::Forms::DataGridView());
			this->tabVentas = (gcnew System::Windows::Forms::TabPage());
			this->btnGestionarVentas = (gcnew System::Windows::Forms::Button());
			this->tablaVentas = (gcnew System::Windows::Forms::DataGridView());
			this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControlPrincipal->SuspendLayout();
			this->tabInventario->SuspendLayout();
			this->groupBoxEdicion->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaInventario))->BeginInit();
			this->tabVentas->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaVentas))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControlPrincipal
			// 
			this->tabControlPrincipal->Controls->Add(this->tabInventario);
			this->tabControlPrincipal->Controls->Add(this->tabVentas);
			this->tabControlPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControlPrincipal->Location = System::Drawing::Point(25, 83);
			this->tabControlPrincipal->Name = L"tabControlPrincipal";
			this->tabControlPrincipal->SelectedIndex = 0;
			this->tabControlPrincipal->Size = System::Drawing::Size(550, 420);
			this->tabControlPrincipal->TabIndex = 1;
			// 
			// tabInventario
			// 
			this->tabInventario->BackColor = System::Drawing::Color::White;
			this->tabInventario->Controls->Add(this->groupBoxEdicion);
			this->tabInventario->Controls->Add(this->tablaInventario);
			this->tabInventario->Location = System::Drawing::Point(4, 27);
			this->tabInventario->Name = L"tabInventario";
			this->tabInventario->Padding = System::Windows::Forms::Padding(3);
			this->tabInventario->Size = System::Drawing::Size(542, 389);
			this->tabInventario->TabIndex = 0;
			this->tabInventario->Text = L"📦 Gestión de Inventario";
			// 
			// groupBoxEdicion
			// 
			this->groupBoxEdicion->Controls->Add(this->btnActualizarMed);
			this->groupBoxEdicion->Controls->Add(this->txtNuevoStock);
			this->groupBoxEdicion->Controls->Add(this->txtNuevoPrecio);
			this->groupBoxEdicion->Controls->Add(this->txtIdMed);
			this->groupBoxEdicion->Controls->Add(this->lblNuevoStock);
			this->groupBoxEdicion->Controls->Add(this->lblNuevoPrecio);
			this->groupBoxEdicion->Controls->Add(this->lblIdMed);
			this->groupBoxEdicion->Location = System::Drawing::Point(15, 225);
			this->groupBoxEdicion->Name = L"groupBoxEdicion";
			this->groupBoxEdicion->Size = System::Drawing::Size(510, 145);
			this->groupBoxEdicion->TabIndex = 1;
			this->groupBoxEdicion->TabStop = false;
			this->groupBoxEdicion->Text = L"Modificar Precio y Stock";
			// 
			// btnActualizarMed
			// 
			this->btnActualizarMed->BackColor = System::Drawing::Color::Teal;
			this->btnActualizarMed->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnActualizarMed->FlatAppearance->BorderSize = 0;
			this->btnActualizarMed->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActualizarMed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnActualizarMed->ForeColor = System::Drawing::Color::White;
			this->btnActualizarMed->Location = System::Drawing::Point(291, 90);
			this->btnActualizarMed->Name = L"btnActualizarMed";
			this->btnActualizarMed->Size = System::Drawing::Size(204, 40);
			this->btnActualizarMed->TabIndex = 6;
			this->btnActualizarMed->Text = L"Actualizar Medicamento";
			this->btnActualizarMed->UseVisualStyleBackColor = false;
			this->btnActualizarMed->Click += gcnew System::EventHandler(this, &OperadorVentas::btnActualizarMed_Click);
			// 
			// txtNuevoStock
			// 
			this->txtNuevoStock->Location = System::Drawing::Point(165, 105);
			this->txtNuevoStock->Name = L"txtNuevoStock";
			this->txtNuevoStock->Size = System::Drawing::Size(100, 24);
			this->txtNuevoStock->TabIndex = 5;
			// 
			// txtNuevoPrecio
			// 
			this->txtNuevoPrecio->Location = System::Drawing::Point(165, 70);
			this->txtNuevoPrecio->Name = L"txtNuevoPrecio";
			this->txtNuevoPrecio->Size = System::Drawing::Size(100, 24);
			this->txtNuevoPrecio->TabIndex = 4;
			// 
			// txtIdMed
			// 
			this->txtIdMed->Location = System::Drawing::Point(165, 35);
			this->txtIdMed->Name = L"txtIdMed";
			this->txtIdMed->Size = System::Drawing::Size(100, 24);
			this->txtIdMed->TabIndex = 3;
			// 
			// lblNuevoStock
			// 
			this->lblNuevoStock->AutoSize = true;
			this->lblNuevoStock->Location = System::Drawing::Point(20, 108);
			this->lblNuevoStock->Name = L"lblNuevoStock";
			this->lblNuevoStock->Size = System::Drawing::Size(98, 18);
			this->lblNuevoStock->TabIndex = 2;
			this->lblNuevoStock->Text = L"Nuevo Stock:";
			// 
			// lblNuevoPrecio
			// 
			this->lblNuevoPrecio->AutoSize = true;
			this->lblNuevoPrecio->Location = System::Drawing::Point(20, 73);
			this->lblNuevoPrecio->Name = L"lblNuevoPrecio";
			this->lblNuevoPrecio->Size = System::Drawing::Size(130, 18);
			this->lblNuevoPrecio->TabIndex = 1;
			this->lblNuevoPrecio->Text = L"Nuevo Precio (S/):";
			// 
			// lblIdMed
			// 
			this->lblIdMed->AutoSize = true;
			this->lblIdMed->Location = System::Drawing::Point(20, 38);
			this->lblIdMed->Name = L"lblIdMed";
			this->lblIdMed->Size = System::Drawing::Size(120, 18);
			this->lblIdMed->TabIndex = 0;
			this->lblIdMed->Text = L"ID Medicamento:";
			// 
			// tablaInventario
			// 
			this->tablaInventario->AllowUserToAddRows = false;
			this->tablaInventario->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->tablaInventario->BackgroundColor = System::Drawing::Color::Azure;
			this->tablaInventario->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tablaInventario->Location = System::Drawing::Point(15, 15);
			this->tablaInventario->Name = L"tablaInventario";
			this->tablaInventario->RowHeadersWidth = 51;
			this->tablaInventario->RowTemplate->Height = 24;
			this->tablaInventario->Size = System::Drawing::Size(510, 195);
			this->tablaInventario->TabIndex = 0;
			// 
			// tabVentas
			// 
			this->tabVentas->BackColor = System::Drawing::Color::White;
			this->tabVentas->Controls->Add(this->btnGestionarVentas);
			this->tabVentas->Controls->Add(this->tablaVentas);
			this->tabVentas->Location = System::Drawing::Point(4, 27);
			this->tabVentas->Name = L"tabVentas";
			this->tabVentas->Padding = System::Windows::Forms::Padding(3);
			this->tabVentas->Size = System::Drawing::Size(542, 389);
			this->tabVentas->TabIndex = 1;
			this->tabVentas->Text = L"📊 Historial de Ventas";
			// 
			// btnGestionarVentas
			// 
			this->btnGestionarVentas->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnGestionarVentas->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnGestionarVentas->FlatAppearance->BorderSize = 0;
			this->btnGestionarVentas->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGestionarVentas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGestionarVentas->ForeColor = System::Drawing::Color::White;
			this->btnGestionarVentas->Location = System::Drawing::Point(15, 330);
			this->btnGestionarVentas->Name = L"btnGestionarVentas";
			this->btnGestionarVentas->Size = System::Drawing::Size(510, 40);
			this->btnGestionarVentas->TabIndex = 1;
			this->btnGestionarVentas->Text = L"Gestionar Ventas Seleccionadas";
			this->btnGestionarVentas->UseVisualStyleBackColor = false;
			// 
			// tablaVentas
			// 
			this->tablaVentas->AllowUserToAddRows = false;
			this->tablaVentas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->tablaVentas->BackgroundColor = System::Drawing::Color::Azure;
			this->tablaVentas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tablaVentas->Location = System::Drawing::Point(15, 15);
			this->tablaVentas->Name = L"tablaVentas";
			this->tablaVentas->RowHeadersWidth = 51;
			this->tablaVentas->RowTemplate->Height = 24;
			this->tablaVentas->Size = System::Drawing::Size(510, 300);
			this->tablaVentas->TabIndex = 0;
			// 
			// btnCerrarSesion
			// 
			this->btnCerrarSesion->BackColor = System::Drawing::Color::IndianRed;
			this->btnCerrarSesion->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnCerrarSesion->FlatAppearance->BorderSize = 0;
			this->btnCerrarSesion->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCerrarSesion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCerrarSesion->ForeColor = System::Drawing::Color::White;
			this->btnCerrarSesion->Location = System::Drawing::Point(417, 519);
			this->btnCerrarSesion->Name = L"btnCerrarSesion";
			this->btnCerrarSesion->Size = System::Drawing::Size(158, 40);
			this->btnCerrarSesion->TabIndex = 2;
			this->btnCerrarSesion->Text = L"Cerrar Sesión";
			this->btnCerrarSesion->UseVisualStyleBackColor = false;
			this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &OperadorVentas::btnCerrarSesion_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::CadetBlue;
			this->panel1->Controls->Add(this->lblBienvenida);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(1, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(600, 64);
			this->panel1->TabIndex = 3;
			// 
			// lblBienvenida
			// 
			this->lblBienvenida->AutoSize = true;
			this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBienvenida->ForeColor = System::Drawing::SystemColors::Control;
			this->lblBienvenida->Location = System::Drawing::Point(541, 10);
			this->lblBienvenida->Name = L"lblBienvenida";
			this->lblBienvenida->Size = System::Drawing::Size(56, 38);
			this->lblBienvenida->TabIndex = 9;
			this->lblBienvenida->Text = L"🐻";
			this->lblBienvenida->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Cornsilk;
			this->label3->Location = System::Drawing::Point(10, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(290, 29);
			this->label3->TabIndex = 8;
			this->label3->Text = L"OPERADOR DE VENTAS";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
			this->label1->ForeColor = System::Drawing::Color::Teal;
			this->label1->Location = System::Drawing::Point(13, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Panel Operador de Ventas";
			this->label1->Click += gcnew System::EventHandler(this, &OperadorVentas::label1_Click);
			// 
			// OperadorVentas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MintCream;
			this->ClientSize = System::Drawing::Size(600, 584);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnCerrarSesion);
			this->Controls->Add(this->tabControlPrincipal);
			this->Name = L"OperadorVentas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Operador de Ventas - WinniePOO";
			this->Load += gcnew System::EventHandler(this, &OperadorVentas::OperadorVentas_Load);
			this->tabControlPrincipal->ResumeLayout(false);
			this->tabInventario->ResumeLayout(false);
			this->groupBoxEdicion->ResumeLayout(false);
			this->groupBoxEdicion->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaInventario))->EndInit();
			this->tabVentas->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaVentas))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
		// Aquí irá la lógica para volver al Login
		this->Close();
	}

	private: System::Void OperadorVentas_Load(System::Object^ sender, System::EventArgs^ e) {

		Console::WriteLine("=== CARGANDO OPERADOR VENTAS ===");

		// =========================
		// 📦 INVENTARIO REAL
		// =========================
		tablaInventario->Columns->Clear();
		tablaInventario->Rows->Clear();

		tablaInventario->Columns->Add("ColID", "ID Med.");
		tablaInventario->Columns->Add("ColNombre", "Nombre");
		tablaInventario->Columns->Add("ColPrincipio", "Principio Activo");
		tablaInventario->Columns->Add("ColPrecio", "Precio");
		tablaInventario->Columns->Add("ColStock", "Stock");

		Controller::ServicioMedicamentos^ servMedicamentos = gcnew Controller::ServicioMedicamentos();

		List<Medicamento^>^ lista = servMedicamentos->ObtenerInventarioCompleto();

		Console::WriteLine("\n--- INVENTARIO CARGADO ---");

		for each (Medicamento ^ med in lista) {

			Console::WriteLine("ID: " + med->id +
				" | Nombre: " + med->nombre +
				" | Precio: " + med->precio.ToString() +
				" | Stock: " + med->stock.ToString());

			tablaInventario->Rows->Add(
				med->id.ToString(),
				med->nombre,
				med->principioActivo,
				med->precio.ToString("F2"),
				med->stock.ToString()
			);
		}

		// =========================
		// 💰 VENTAS (opcional real)
		// =========================
		tablaVentas->Columns->Clear();
		tablaVentas->Rows->Clear();

		tablaVentas->Columns->Add("ColIdVenta", "ID Venta");
		tablaVentas->Columns->Add("ColCant", "Cant. Vendida");
		tablaVentas->Columns->Add("ColFecha", "Fecha de Venta");

		Controller::ServicioVentas^ servVentas = gcnew Controller::ServicioVentas();
		List<Venta^>^ ventas = servVentas->ObtenerTodasLasVentas();

		Console::WriteLine("\n--- VENTAS CARGADAS ---");

		for each (Venta ^ v in ventas) {

			Console::WriteLine("Venta ID: " + v->id +
				" | Cantidad: " + v->cantidadVendida);

			tablaVentas->Rows->Add(
				v->id.ToString(),
				v->cantidadVendida.ToString(),
				DateTime::Now.ToString("dd/MM/yyyy HH:mm") // (tu modelo no guarda fecha aún)
			);
		}

		Console::WriteLine("=== FIN CARGA ===");
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnActualizarMed_Click(System::Object^ sender, System::EventArgs^ e) {

	Console::WriteLine("\n=== INICIO btnActualizarMed_Click ===");

	// =========================
	// 🔍 VALIDACIONES
	// =========================
	if (String::IsNullOrWhiteSpace(txtIdMed->Text) ||
		String::IsNullOrWhiteSpace(txtNuevoPrecio->Text) ||
		String::IsNullOrWhiteSpace(txtNuevoStock->Text)) {

		Console::WriteLine("❌ Campos incompletos");

		MessageBox::Show("Complete todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	int id;
	double nuevoPrecio;
	int nuevoStock;

	try {
		id = Convert::ToInt32(txtIdMed->Text);
		nuevoPrecio = Convert::ToDouble(txtNuevoPrecio->Text);
		nuevoStock = Convert::ToInt32(txtNuevoStock->Text);
	}
	catch (Exception^) {
		Console::WriteLine("❌ Error de conversión");

		MessageBox::Show("Ingrese valores numéricos válidos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	Console::WriteLine("✔ Datos recibidos:");
	Console::WriteLine("ID: " + id);
	Console::WriteLine("Nuevo Precio: " + nuevoPrecio);
	Console::WriteLine("Nuevo Stock: " + nuevoStock);

	// =========================
	// 💊 ACTUALIZAR MEDICAMENTO
	// =========================
	Controller::ServicioMedicamentos^ servMedicamentos = gcnew Controller::ServicioMedicamentos();

	bool resultado = servMedicamentos->ActualizarMedicamento(id, nuevoPrecio, nuevoStock);

	if (resultado) {
		Console::WriteLine("✔ Medicamento actualizado correctamente");

		MessageBox::Show("Medicamento actualizado con éxito.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// =========================
		// 🔄 REFRESCAR TABLA
		// =========================
		tablaInventario->Rows->Clear();

		List<Medicamento^>^ lista = servMedicamentos->ObtenerInventarioCompleto();

		for each (Medicamento ^ med in lista) {
			tablaInventario->Rows->Add(
				med->id.ToString(),
				med->nombre,
				med->principioActivo,
				med->precio.ToString("F2"),
				med->stock.ToString()
			);
		}

		Console::WriteLine("✔ Tabla refrescada");
	}
	else {
		Console::WriteLine("❌ Medicamento no encontrado");

		MessageBox::Show("No se encontró el medicamento con ese ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	Console::WriteLine("=== FIN btnActualizarMed_Click ===");
}
};
}