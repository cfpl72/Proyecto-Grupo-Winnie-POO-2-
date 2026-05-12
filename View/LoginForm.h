#pragma once
#include "OperadorVentas.h"
#include "FarmaceuticoView.h"
#include "PacienteView.h"


namespace WinniePOOview {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ViewFarmaceutico;
	using namespace ViewPaciente;

	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
		}

	protected:
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblBienvenida;
	private: System::Windows::Forms::Label^ lblSubtitulo;
	private: System::Windows::Forms::GroupBox^ grpLogin;
	private: System::Windows::Forms::Label^ lblRol;
	private: System::Windows::Forms::ComboBox^ cmbRol;
	private: System::Windows::Forms::Label^ lblUsuario;
	private: System::Windows::Forms::TextBox^ txtUsuario;
	private: System::Windows::Forms::Label^ lblContrasenia;
	private: System::Windows::Forms::TextBox^ txtContrasenia;
	private: System::Windows::Forms::Button^ btnIngresar;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			   this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			   this->grpLogin = (gcnew System::Windows::Forms::GroupBox());
			   this->txtContrasenia = (gcnew System::Windows::Forms::TextBox());
			   this->lblContrasenia = (gcnew System::Windows::Forms::Label());
			   this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			   this->lblUsuario = (gcnew System::Windows::Forms::Label());
			   this->cmbRol = (gcnew System::Windows::Forms::ComboBox());
			   this->lblRol = (gcnew System::Windows::Forms::Label());
			   this->btnIngresar = (gcnew System::Windows::Forms::Button());
			   this->btnSalir = (gcnew System::Windows::Forms::Button());
			   this->grpLogin->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // lblBienvenida
			   // 
			   this->lblBienvenida->AutoSize = true;
			   this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblBienvenida->ForeColor = System::Drawing::Color::Teal;
			   this->lblBienvenida->Location = System::Drawing::Point(65, 30);
			   this->lblBienvenida->Name = L"lblBienvenida";
			   this->lblBienvenida->Size = System::Drawing::Size(254, 45);
			   this->lblBienvenida->TabIndex = 0;
			   this->lblBienvenida->Text = L"WinniePOO 🐻";
			   this->lblBienvenida->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->lblBienvenida->Click += gcnew System::EventHandler(this, &LoginForm::lblBienvenida_Click);
			   // 
			   // lblSubtitulo
			   // 
			   this->lblSubtitulo->AutoSize = true;
			   this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblSubtitulo->ForeColor = System::Drawing::Color::CadetBlue;
			   this->lblSubtitulo->Location = System::Drawing::Point(55, 80);
			   this->lblSubtitulo->Name = L"lblSubtitulo";
			   this->lblSubtitulo->Size = System::Drawing::Size(261, 23);
			   this->lblSubtitulo->TabIndex = 1;
			   this->lblSubtitulo->Text = L"Sistema de Gestión Farmacéutica";
			   this->lblSubtitulo->Click += gcnew System::EventHandler(this, &LoginForm::lblSubtitulo_Click);
			   // 
			   // grpLogin
			   // 
			   this->grpLogin->Controls->Add(this->txtContrasenia);
			   this->grpLogin->Controls->Add(this->lblContrasenia);
			   this->grpLogin->Controls->Add(this->txtUsuario);
			   this->grpLogin->Controls->Add(this->lblUsuario);
			   this->grpLogin->Controls->Add(this->cmbRol);
			   this->grpLogin->Controls->Add(this->lblRol);
			   this->grpLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->grpLogin->ForeColor = System::Drawing::Color::DarkSlateGray;
			   this->grpLogin->Location = System::Drawing::Point(35, 121);
			   this->grpLogin->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->grpLogin->Name = L"grpLogin";
			   this->grpLogin->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->grpLogin->Size = System::Drawing::Size(315, 260);
			   this->grpLogin->TabIndex = 2;
			   this->grpLogin->TabStop = false;
			   this->grpLogin->Text = L"Inicio de Sesión";
			   // 
			   // txtContrasenia
			   // 
			   this->txtContrasenia->Location = System::Drawing::Point(29, 206);
			   this->txtContrasenia->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->txtContrasenia->Name = L"txtContrasenia";
			   this->txtContrasenia->PasswordChar = '*';
			   this->txtContrasenia->Size = System::Drawing::Size(249, 30);
			   this->txtContrasenia->TabIndex = 5;
			   // 
			   // lblContrasenia
			   // 
			   this->lblContrasenia->AutoSize = true;
			   this->lblContrasenia->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblContrasenia->Location = System::Drawing::Point(25, 180);
			   this->lblContrasenia->Name = L"lblContrasenia";
			   this->lblContrasenia->Size = System::Drawing::Size(90, 20);
			   this->lblContrasenia->TabIndex = 4;
			   this->lblContrasenia->Text = L"Contraseña:";
			   // 
			   // txtUsuario
			   // 
			   this->txtUsuario->Location = System::Drawing::Point(29, 135);
			   this->txtUsuario->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->txtUsuario->Name = L"txtUsuario";
			   this->txtUsuario->Size = System::Drawing::Size(249, 30);
			   this->txtUsuario->TabIndex = 3;
			   // 
			   // lblUsuario
			   // 
			   this->lblUsuario->AutoSize = true;
			   this->lblUsuario->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblUsuario->Location = System::Drawing::Point(25, 110);
			   this->lblUsuario->Name = L"lblUsuario";
			   this->lblUsuario->Size = System::Drawing::Size(106, 20);
			   this->lblUsuario->TabIndex = 2;
			   this->lblUsuario->Text = L"ID de Usuario:";
			   // 
			   // cmbRol
			   // 
			   this->cmbRol->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cmbRol->FormattingEnabled = true;
			   this->cmbRol->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Paciente", L"Farmacéutico", L"Operador de Ventas" });
			   this->cmbRol->Location = System::Drawing::Point(29, 65);
			   this->cmbRol->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->cmbRol->Name = L"cmbRol";
			   this->cmbRol->Size = System::Drawing::Size(249, 31);
			   this->cmbRol->TabIndex = 1;
			   // 
			   // lblRol
			   // 
			   this->lblRol->AutoSize = true;
			   this->lblRol->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblRol->Location = System::Drawing::Point(25, 39);
			   this->lblRol->Name = L"lblRol";
			   this->lblRol->Size = System::Drawing::Size(130, 20);
			   this->lblRol->TabIndex = 0;
			   this->lblRol->Text = L"Seleccione su Rol:";
			   // 
			   // btnIngresar
			   // 
			   this->btnIngresar->BackColor = System::Drawing::Color::LightSeaGreen;
			   this->btnIngresar->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnIngresar->FlatAppearance->BorderSize = 0;
			   this->btnIngresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnIngresar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnIngresar->ForeColor = System::Drawing::Color::White;
			   this->btnIngresar->Location = System::Drawing::Point(35, 400);
			   this->btnIngresar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->btnIngresar->Name = L"btnIngresar";
			   this->btnIngresar->Size = System::Drawing::Size(315, 46);
			   this->btnIngresar->TabIndex = 3;
			   this->btnIngresar->Text = L"Ingresar";
			   this->btnIngresar->UseVisualStyleBackColor = false;
			   this->btnIngresar->Click += gcnew System::EventHandler(this, &LoginForm::btnIngresar_Click);
			   // 
			   // btnSalir
			   // 
			   this->btnSalir->BackColor = System::Drawing::Color::CadetBlue;
			   this->btnSalir->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnSalir->FlatAppearance->BorderSize = 0;
			   this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnSalir->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnSalir->ForeColor = System::Drawing::Color::White;
			   this->btnSalir->Location = System::Drawing::Point(35, 455);
			   this->btnSalir->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->btnSalir->Name = L"btnSalir";
			   this->btnSalir->Size = System::Drawing::Size(315, 34);
			   this->btnSalir->TabIndex = 4;
			   this->btnSalir->Text = L"Salir";
			   this->btnSalir->UseVisualStyleBackColor = false;
			   this->btnSalir->Click += gcnew System::EventHandler(this, &LoginForm::btnSalir_Click);
			   // 
			   // LoginForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::MintCream;
			   this->ClientSize = System::Drawing::Size(381, 523);
			   this->Controls->Add(this->btnSalir);
			   this->Controls->Add(this->btnIngresar);
			   this->Controls->Add(this->grpLogin);
			   this->Controls->Add(this->lblSubtitulo);
			   this->Controls->Add(this->lblBienvenida);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->MaximizeBox = false;
			   this->Name = L"LoginForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"WinniePOO - Login";
			   this->grpLogin->ResumeLayout(false);
			   this->grpLogin->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void btnIngresar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Aquí irá tu lógica para abrir la ventana según el rol seleccionado

		// 1. Verificamos si seleccionó algo en el ComboBox
		if (cmbRol->SelectedItem == nullptr) {
			MessageBox::Show("Por favor, seleccione un rol para ingresar.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		String^ rolSeleccionado = cmbRol->SelectedItem->ToString();

		// 2. Si eligió Operador de Ventas, abrimos su interfaz
		if (rolSeleccionado == "Operador de Ventas") {
			// Creamos la instancia de la ventana Operador
			OperadorVentas^ ventanaOperador = gcnew OperadorVentas();

			// Ocultamos el login para que no estorbe
			this->Hide();

			// Mostramos la ventana de Operador
			ventanaOperador->ShowDialog();

			// Cuando se cierre la ventana de Operador (Cerrar Sesión), volvemos a mostrar el Login
			this->Show();
		}
		else if (rolSeleccionado == "Farmacéutico") {
			Farmaceutico^ ventanaFarmaceutico = gcnew Farmaceutico();

			this->Hide();

			ventanaFarmaceutico->ShowDialog();

			this->Show();
		}
		else if (rolSeleccionado == "Paciente") {
			PacienteForm^ ventanaPaciente = gcnew PacienteForm();

			this->Hide();

			ventanaPaciente->ShowDialog();

			this->Show();
		}
		else {
			// Mensaje temporal para los otros roles que aún no tienen interfaz lista
			MessageBox::Show("La interfaz para " + rolSeleccionado + " todavía está en desarrollo.", "Próximamente");
		}

	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void lblBienvenida_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lblSubtitulo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}