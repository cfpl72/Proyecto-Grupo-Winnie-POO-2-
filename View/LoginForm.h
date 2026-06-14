//    1. btnIngresar_Click:
//       - Operador de Ventas: DNI=12345678 / pass=operador  
//       - Farmacéutico      : DNI=87654321 / pass=farmaceutico 
//       - Paciente          : validado por ServicioAutenticacion
//    2. Cada form hijo recibe "this" como loginRef para poder volver
//    3. Se pasa el ID del paciente al PacienteForm
//    4. El constructor vacío de OperadorVentas/Farmaceutico se reemplaza
//       por uno que acepta Form^ loginRef

#pragma once
#include "RegisterForm.h"
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
	using namespace WinniePOO_Modelos;
	using namespace Controller;

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

	private: System::Windows::Forms::PictureBox^ pictureBoxOso;
	private: System::Windows::Forms::Label^ lblBienvenida;
	private: System::Windows::Forms::Label^ lblRol;
	private: System::Windows::Forms::ComboBox^ cmbRol;
	private: System::Windows::Forms::Label^ lblUsuario;
	private: System::Windows::Forms::TextBox^ txtUsuario;
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Button^ btnIngresar;
	private: System::Windows::Forms::LinkLabel^ lnkCrearCuenta;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			   this->pictureBoxOso = (gcnew System::Windows::Forms::PictureBox());
			   this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			   this->lblRol = (gcnew System::Windows::Forms::Label());
			   this->cmbRol = (gcnew System::Windows::Forms::ComboBox());
			   this->lblUsuario = (gcnew System::Windows::Forms::Label());
			   this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			   this->lblPassword = (gcnew System::Windows::Forms::Label());
			   this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			   this->btnIngresar = (gcnew System::Windows::Forms::Button());
			   this->lnkCrearCuenta = (gcnew System::Windows::Forms::LinkLabel());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOso))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // pictureBoxOso
			   // 
			   this->pictureBoxOso->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxOso.Image")));
			   this->pictureBoxOso->Location = System::Drawing::Point(205, 24);
			   this->pictureBoxOso->Margin = System::Windows::Forms::Padding(4);
			   this->pictureBoxOso->Name = L"pictureBoxOso";
			   this->pictureBoxOso->Size = System::Drawing::Size(138, 135);
			   this->pictureBoxOso->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBoxOso->TabIndex = 0;
			   this->pictureBoxOso->TabStop = false;
			   // 
			   // lblBienvenida
			   // 
			   this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblBienvenida->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				   static_cast<System::Int32>(static_cast<System::Byte>(100)));
			   this->lblBienvenida->Location = System::Drawing::Point(27, 172);
			   this->lblBienvenida->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lblBienvenida->Name = L"lblBienvenida";
			   this->lblBienvenida->Size = System::Drawing::Size(480, 62);
			   this->lblBienvenida->TabIndex = 1;
			   this->lblBienvenida->Text = L"¡Bienvenidos a Winnie POO!\r\nTu oso farmacéutico favorito ✨";
			   this->lblBienvenida->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // lblRol
			   // 
			   this->lblRol->AutoSize = true;
			   this->lblRol->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblRol->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->lblRol->Location = System::Drawing::Point(67, 258);
			   this->lblRol->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lblRol->Name = L"lblRol";
			   this->lblRol->Size = System::Drawing::Size(151, 23);
			   this->lblRol->TabIndex = 2;
			   this->lblRol->Text = L"Seleccione su Rol:";
			   // 
			   // cmbRol
			   // 
			   this->cmbRol->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cmbRol->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->cmbRol->FormattingEnabled = true;
			   this->cmbRol->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Paciente", L"Operador de Ventas", L"Farmacéutico" });
			   this->cmbRol->Location = System::Drawing::Point(67, 283);
			   this->cmbRol->Margin = System::Windows::Forms::Padding(4);
			   this->cmbRol->Name = L"cmbRol";
			   this->cmbRol->Size = System::Drawing::Size(399, 33);
			   this->cmbRol->TabIndex = 3;
			   // 
			   // lblUsuario
			   // 
			   this->lblUsuario->AutoSize = true;
			   this->lblUsuario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			   this->lblUsuario->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->lblUsuario->Location = System::Drawing::Point(67, 338);
			   this->lblUsuario->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lblUsuario->Name = L"lblUsuario";
			   this->lblUsuario->Size = System::Drawing::Size(123, 23);
			   this->lblUsuario->TabIndex = 4;
			   this->lblUsuario->Text = L"Usuario (DNI):";
			   // 
			   // txtUsuario
			   // 
			   this->txtUsuario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->txtUsuario->Location = System::Drawing::Point(67, 363);
			   this->txtUsuario->Margin = System::Windows::Forms::Padding(4);
			   this->txtUsuario->Name = L"txtUsuario";
			   this->txtUsuario->Size = System::Drawing::Size(399, 32);
			   this->txtUsuario->TabIndex = 5;
			   // 
			   // lblPassword
			   // 
			   this->lblPassword->AutoSize = true;
			   this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold));
			   this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->lblPassword->Location = System::Drawing::Point(67, 412);
			   this->lblPassword->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lblPassword->Name = L"lblPassword";
			   this->lblPassword->Size = System::Drawing::Size(104, 23);
			   this->lblPassword->TabIndex = 6;
			   this->lblPassword->Text = L"Contraseña:";
			   // 
			   // txtPassword
			   // 
			   this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->txtPassword->Location = System::Drawing::Point(67, 437);
			   this->txtPassword->Margin = System::Windows::Forms::Padding(4);
			   this->txtPassword->Name = L"txtPassword";
			   this->txtPassword->Size = System::Drawing::Size(399, 32);
			   this->txtPassword->TabIndex = 7;
			   this->txtPassword->UseSystemPasswordChar = true;
			   // 
			   // btnIngresar
			   // 
			   this->btnIngresar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->btnIngresar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnIngresar->ForeColor = System::Drawing::Color::White;
			   this->btnIngresar->Location = System::Drawing::Point(67, 535);
			   this->btnIngresar->Margin = System::Windows::Forms::Padding(4);
			   this->btnIngresar->Name = L"btnIngresar";
			   this->btnIngresar->Size = System::Drawing::Size(398, 51);
			   this->btnIngresar->TabIndex = 9;
			   this->btnIngresar->Text = L"INGRESAR";
			   this->btnIngresar->UseVisualStyleBackColor = false;
			   this->btnIngresar->Click += gcnew System::EventHandler(this, &LoginForm::btnIngresar_Click);
			   // 
			   // lnkCrearCuenta
			   // 
			   this->lnkCrearCuenta->AutoSize = true;
			   this->lnkCrearCuenta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			   this->lnkCrearCuenta->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			   this->lnkCrearCuenta->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				   static_cast<System::Int32>(static_cast<System::Byte>(100)));
			   this->lnkCrearCuenta->Location = System::Drawing::Point(180, 609);
			   this->lnkCrearCuenta->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lnkCrearCuenta->Name = L"lnkCrearCuenta";
			   this->lnkCrearCuenta->Size = System::Drawing::Size(163, 23);
			   this->lnkCrearCuenta->TabIndex = 10;
			   this->lnkCrearCuenta->TabStop = true;
			   this->lnkCrearCuenta->Text = L"Crear cuenta nueva";
			   this->lnkCrearCuenta->Click += gcnew System::EventHandler(this, &LoginForm::lnkCrearCuenta_Click);
			   // 
			   // LoginForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(250)));
			   this->ClientSize = System::Drawing::Size(543, 685);
			   this->Controls->Add(this->lnkCrearCuenta);
			   this->Controls->Add(this->btnIngresar);
			   this->Controls->Add(this->txtPassword);
			   this->Controls->Add(this->lblPassword);
			   this->Controls->Add(this->txtUsuario);
			   this->Controls->Add(this->lblUsuario);
			   this->Controls->Add(this->cmbRol);
			   this->Controls->Add(this->lblRol);
			   this->Controls->Add(this->lblBienvenida);
			   this->Controls->Add(this->pictureBoxOso);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->MaximizeBox = false;
			   this->Name = L"LoginForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"WinniePOO - Login";
			   this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOso))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   // ─────────────────────────────────────────────────────────
		   //  LÓGICA DE INGRESO 
		   // ─────────────────────────────────────────────────────────
	private: System::Void btnIngresar_Click(System::Object^ sender, System::EventArgs^ e) {

		if (cmbRol->SelectedItem == nullptr) {
			MessageBox::Show(L"¡WinniePOO necesita saber tu rol para dejarte entrar!",
				L"Falta información", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		String^ rol = cmbRol->SelectedItem->ToString();
		String^ usuario = txtUsuario->Text->Trim();
		String^ password = txtPassword->Text->Trim();

		if (usuario == "" || password == "") {
			MessageBox::Show(L"Por favor, ingresa tu DNI y contraseña.",
				L"Campos vacíos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// ── Roles fijos (sin archivo) ───────────────────────
		if (rol == "Operador de Ventas") {
			if (usuario == "12345678" && password == "operador") {
				this->Hide();
				WinniePOOview::OperadorVentas^ formOV = gcnew WinniePOOview::OperadorVentas(this);
				formOV->Show();
			}
			else {
				MessageBox::Show(L"Credenciales incorrectas para Operador de Ventas.",
					L"Acceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			return;
		}

		if (rol == "Farmacéutico") {
			if (usuario == "87654321" && password == "farmaceutico") {
				this->Hide();
				ViewFarmaceutico::Farmaceutico^ formFarma =
					gcnew ViewFarmaceutico::Farmaceutico(this);
				formFarma->Show();
			}
			else {
				MessageBox::Show(L"Credenciales incorrectas para Farmacéutico.",
					L"Acceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			return;
		}

		// ── Paciente: validar contra Pacientes.txt ──────────
		if (rol == "Paciente") {
			Controller::ServicioAutenticacion^ authSvc =
				gcnew Controller::ServicioAutenticacion();
			bool ok = authSvc->ValidarAcceso(rol, usuario, password);

			if (ok) {
				Controller::ServicioPacientes^ pacSvc =
					gcnew Controller::ServicioPacientes();
				int dni = Convert::ToInt32(usuario);
				Paciente^ p = pacSvc->ObtenerPorId(dni);

				if (p != nullptr) {
					this->Hide();
					ViewPaciente::PacienteForm^ formPac =
						gcnew ViewPaciente::PacienteForm(p->id, this);
					formPac->Show();
				}
				else {
					MessageBox::Show(L"Paciente no encontrado en el sistema.",
						L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else {
				MessageBox::Show(L"DNI o contraseña incorrectos.",
					L"Acceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			return;
		}
	}

	private: System::Void lnkCrearCuenta_Click(System::Object^ sender, System::EventArgs^ e) {
		RegisterForm^ ventanaRegistro = gcnew RegisterForm();
		ventanaRegistro->ShowDialog();
	}

	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->AcceptButton = this->btnIngresar; // Cambia 'btnIngresar' por el nombre real de tu botón
		
	}
	};
}