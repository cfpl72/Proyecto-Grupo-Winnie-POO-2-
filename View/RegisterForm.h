#pragma once

namespace WinniePOOview {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void) { InitializeComponent(); }

	protected:
		~RegisterForm() { if (components) delete components; }


	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblDNI;
	private: System::Windows::Forms::Label^ lblNombres;
	private: System::Windows::Forms::Label^ lblApellidos;
	private: System::Windows::Forms::Label^ lblEdad;
		   // NUEVO
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::Label^ lblConfirmPassword;


	private: System::Windows::Forms::TextBox^ txtDNI;
	private: System::Windows::Forms::TextBox^ txtNombres;
	private: System::Windows::Forms::TextBox^ txtApellidos;
	private: System::Windows::Forms::TextBox^ txtEdad;
		   // NUEVO
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::TextBox^ txtConfirmPassword;
	private: System::Windows::Forms::Button^ btnRegistrar;
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->lblTitulo = (gcnew System::Windows::Forms::Label());
			   this->lblDNI = (gcnew System::Windows::Forms::Label());
			   this->txtDNI = (gcnew System::Windows::Forms::TextBox());
			   this->lblNombres = (gcnew System::Windows::Forms::Label());
			   this->txtNombres = (gcnew System::Windows::Forms::TextBox());
			   this->lblApellidos = (gcnew System::Windows::Forms::Label());
			   this->txtApellidos = (gcnew System::Windows::Forms::TextBox());
			   this->lblEdad = (gcnew System::Windows::Forms::Label());
			   this->txtEdad = (gcnew System::Windows::Forms::TextBox());
			   this->lblPassword = (gcnew System::Windows::Forms::Label());
			   this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			   this->lblConfirmPassword = (gcnew System::Windows::Forms::Label());
			   this->txtConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			   this->btnRegistrar = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // lblTitulo
			   // 
			   this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			   this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				   static_cast<System::Int32>(static_cast<System::Byte>(100)));
			   this->lblTitulo->Location = System::Drawing::Point(0, 47);
			   this->lblTitulo->Name = L"lblTitulo";
			   this->lblTitulo->Size = System::Drawing::Size(400, 36);
			   this->lblTitulo->TabIndex = 16;
			   this->lblTitulo->Text = L"Registro de Nuevo Paciente";
			   this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // lblDNI
			   // 
			   this->lblDNI->AutoSize = true;
			   this->lblDNI->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			   this->lblDNI->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->lblDNI->Location = System::Drawing::Point(50, 125);
			   this->lblDNI->Name = L"lblDNI";
			   this->lblDNI->Size = System::Drawing::Size(111, 20);
			   this->lblDNI->TabIndex = 15;
			   this->lblDNI->Text = L"DNI (Usuario):";
			   // 
			   // txtDNI
			   // 
			   this->txtDNI->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   this->txtDNI->Location = System::Drawing::Point(50, 145);
			   this->txtDNI->Name = L"txtDNI";
			   this->txtDNI->Size = System::Drawing::Size(300, 30);
			   this->txtDNI->TabIndex = 14;
			   // 
			   // lblNombres
			   // 
			   this->lblNombres->AutoSize = true;
			   this->lblNombres->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			   this->lblNombres->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->lblNombres->Location = System::Drawing::Point(50, 180);
			   this->lblNombres->Name = L"lblNombres";
			   this->lblNombres->Size = System::Drawing::Size(78, 20);
			   this->lblNombres->TabIndex = 13;
			   this->lblNombres->Text = L"Nombres:";
			   // 
			   // txtNombres
			   // 
			   this->txtNombres->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   this->txtNombres->Location = System::Drawing::Point(50, 200);
			   this->txtNombres->Name = L"txtNombres";
			   this->txtNombres->Size = System::Drawing::Size(300, 30);
			   this->txtNombres->TabIndex = 12;
			   // 
			   // lblApellidos
			   // 
			   this->lblApellidos->AutoSize = true;
			   this->lblApellidos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			   this->lblApellidos->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->lblApellidos->Location = System::Drawing::Point(50, 235);
			   this->lblApellidos->Name = L"lblApellidos";
			   this->lblApellidos->Size = System::Drawing::Size(78, 20);
			   this->lblApellidos->TabIndex = 11;
			   this->lblApellidos->Text = L"Apellidos:";
			   // 
			   // txtApellidos
			   // 
			   this->txtApellidos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   this->txtApellidos->Location = System::Drawing::Point(50, 255);
			   this->txtApellidos->Name = L"txtApellidos";
			   this->txtApellidos->Size = System::Drawing::Size(300, 30);
			   this->txtApellidos->TabIndex = 10;
			   // 
			   // lblEdad
			   // 
			   this->lblEdad->AutoSize = true;
			   this->lblEdad->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			   this->lblEdad->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->lblEdad->Location = System::Drawing::Point(50, 290);
			   this->lblEdad->Name = L"lblEdad";
			   this->lblEdad->Size = System::Drawing::Size(47, 20);
			   this->lblEdad->TabIndex = 9;
			   this->lblEdad->Text = L"Edad:";
			   // 
			   // txtEdad
			   // 
			   this->txtEdad->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   this->txtEdad->Location = System::Drawing::Point(50, 310);
			   this->txtEdad->Name = L"txtEdad";
			   this->txtEdad->Size = System::Drawing::Size(300, 30);
			   this->txtEdad->TabIndex = 8;
			   // 
			   // lblPassword
			   // 
			   this->lblPassword->AutoSize = true;
			   this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			   this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->lblPassword->Location = System::Drawing::Point(46, 343);
			   this->lblPassword->Name = L"lblPassword";
			   this->lblPassword->Size = System::Drawing::Size(92, 20);
			   this->lblPassword->TabIndex = 5;
			   this->lblPassword->Text = L"Contraseña:";
			   // 
			   // txtPassword
			   // 
			   this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   this->txtPassword->Location = System::Drawing::Point(50, 366);
			   this->txtPassword->Name = L"txtPassword";
			   this->txtPassword->Size = System::Drawing::Size(300, 30);
			   this->txtPassword->TabIndex = 4;
			   this->txtPassword->UseSystemPasswordChar = true;
			   // 
			   // lblConfirmPassword
			   // 
			   this->lblConfirmPassword->AutoSize = true;
			   this->lblConfirmPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			   this->lblConfirmPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)),
				   static_cast<System::Int32>(static_cast<System::Byte>(166)), static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->lblConfirmPassword->Location = System::Drawing::Point(46, 399);
			   this->lblConfirmPassword->Name = L"lblConfirmPassword";
			   this->lblConfirmPassword->Size = System::Drawing::Size(167, 20);
			   this->lblConfirmPassword->TabIndex = 3;
			   this->lblConfirmPassword->Text = L"Confirmar Contraseña:";
			   // 
			   // txtConfirmPassword
			   // 
			   this->txtConfirmPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   this->txtConfirmPassword->Location = System::Drawing::Point(50, 422);
			   this->txtConfirmPassword->Name = L"txtConfirmPassword";
			   this->txtConfirmPassword->Size = System::Drawing::Size(300, 30);
			   this->txtConfirmPassword->TabIndex = 2;
			   this->txtConfirmPassword->UseSystemPasswordChar = true;
			   this->txtConfirmPassword->TextChanged += gcnew System::EventHandler(this, &RegisterForm::txtConfirmPassword_TextChanged);
			   // 
			   // btnRegistrar
			   // 
			   this->btnRegistrar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->btnRegistrar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnRegistrar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			   this->btnRegistrar->ForeColor = System::Drawing::Color::White;
			   this->btnRegistrar->Location = System::Drawing::Point(50, 508);
			   this->btnRegistrar->Name = L"btnRegistrar";
			   this->btnRegistrar->Size = System::Drawing::Size(300, 40);
			   this->btnRegistrar->TabIndex = 0;
			   this->btnRegistrar->Text = L"Registrarme";
			   this->btnRegistrar->UseVisualStyleBackColor = false;
			   this->btnRegistrar->Click += gcnew System::EventHandler(this, &RegisterForm::btnRegistrar_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(50, 459);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(132, 16);
			   this->label1->TabIndex = 17;
			   this->label1->Text = L"*Mínimo 8 caracteres";
			   // 
			   // RegisterForm
			   // 
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(250)));
			   this->ClientSize = System::Drawing::Size(400, 572);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->btnRegistrar);
			   this->Controls->Add(this->txtConfirmPassword);
			   this->Controls->Add(this->lblConfirmPassword);
			   this->Controls->Add(this->txtPassword);
			   this->Controls->Add(this->lblPassword);
			   this->Controls->Add(this->txtEdad);
			   this->Controls->Add(this->lblEdad);
			   this->Controls->Add(this->txtApellidos);
			   this->Controls->Add(this->lblApellidos);
			   this->Controls->Add(this->txtNombres);
			   this->Controls->Add(this->lblNombres);
			   this->Controls->Add(this->txtDNI);
			   this->Controls->Add(this->lblDNI);
			   this->Controls->Add(this->lblTitulo);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->Name = L"RegisterForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"WinniePOO - Registro de Paciente";
			   this->Load += gcnew System::EventHandler(this, &RegisterForm::RegisterForm_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void btnRegistrar_Click(System::Object^ sender, System::EventArgs^ e) {

		// 1. Validar campos vacíos 
		if (txtDNI->Text == "" || txtNombres->Text == "" || txtApellidos->Text == "" ||
			txtEdad->Text == "" || txtPassword->Text == "" || txtConfirmPassword->Text == "") {
			MessageBox::Show("Por favor, completa todos los campos antes de continuar.", "Campos incompletos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// 2. Validar que las contraseñas coincidan
		if (txtPassword->Text != txtConfirmPassword->Text) {
			MessageBox::Show("¡Las contraseñas no coinciden!", "Error de Validación", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// 3. Validar seguridad mínima de la contraseña (¡Excelente detalle tuyo!)
		if (txtPassword->Text->Length < 8) {
			MessageBox::Show("La contraseña debe tener al menos 8 caracteres.", "Seguridad", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		
		MessageBox::Show("¡Bienvenido a WinniePOO, " + txtNombres->Text + "!\nTu cuenta ha sido creada exitosamente.", "Registro Completado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close(); // Cierra el formulario de registro y probablemente regrese al Login
	}

	private: System::Void RegisterForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void txtConfirmPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};

}
