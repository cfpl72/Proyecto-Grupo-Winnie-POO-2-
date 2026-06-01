#pragma once
#include "OperadorVentas.h"


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
			   this->lblBienvenida->Click += gcnew System::EventHandler(this, &LoginForm::lblBienvenida_Click);
			   // 
			   // lblRol
			   // 
			   this->lblSubtitulo->AutoSize = true;
			   this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblSubtitulo->ForeColor = System::Drawing::Color::CadetBlue;
			   this->lblSubtitulo->Location = System::Drawing::Point(55, 80);
			   this->lblSubtitulo->Name = L"lblSubtitulo";
			   this->lblSubtitulo->Size = System::Drawing::Size(284, 20);
			   this->lblSubtitulo->TabIndex = 1;
			   this->lblSubtitulo->Text = L"Sistema de Gestión Farmacéutica";
			   // 
			   // cmbRol
			   // 
			   this->grpLogin->Controls->Add(this->txtContrasenia);
			   this->grpLogin->Controls->Add(this->lblContrasenia);
			   this->grpLogin->Controls->Add(this->txtUsuario);
			   this->grpLogin->Controls->Add(this->lblUsuario);
			   this->grpLogin->Controls->Add(this->cmbRol);
			   this->grpLogin->Controls->Add(this->lblRol);
			   this->grpLogin->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			   // lblUsuario
			   // 
			   this->txtContrasenia->Location = System::Drawing::Point(29, 206);
			   this->txtContrasenia->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->txtContrasenia->Name = L"txtContrasenia";
			   this->txtContrasenia->PasswordChar = '*';
			   this->txtContrasenia->Size = System::Drawing::Size(249, 27);
			   this->txtContrasenia->TabIndex = 5;
			   // 
			   // lblContrasenia
			   // 
			   this->lblContrasenia->AutoSize = true;
			   this->lblContrasenia->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblContrasenia->Location = System::Drawing::Point(25, 180);
			   this->lblContrasenia->Name = L"lblContrasenia";
			   this->lblContrasenia->Size = System::Drawing::Size(98, 17);
			   this->lblContrasenia->TabIndex = 4;
			   this->lblContrasenia->Text = L"Contraseña:";
			   // 
			   // txtUsuario
			   // 
			   this->txtUsuario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->txtUsuario->Location = System::Drawing::Point(67, 363);
			   this->txtUsuario->Margin = System::Windows::Forms::Padding(4);
			   this->txtUsuario->Name = L"txtUsuario";
			   this->txtUsuario->Size = System::Drawing::Size(249, 27);
			   this->txtUsuario->TabIndex = 3;
			   // 
			   // lblPassword
			   // 
			   this->lblUsuario->AutoSize = true;
			   this->lblUsuario->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblUsuario->Location = System::Drawing::Point(25, 110);
			   this->lblUsuario->Name = L"lblUsuario";
			   this->lblUsuario->Size = System::Drawing::Size(112, 17);
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
			   this->cmbRol->Size = System::Drawing::Size(249, 28);
			   this->cmbRol->TabIndex = 1;
			   // 
			   // txtPassword
			   // 
			   this->lblRol->AutoSize = true;
			   this->lblRol->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblRol->Location = System::Drawing::Point(25, 39);
			   this->lblRol->Name = L"lblRol";
			   this->lblRol->Size = System::Drawing::Size(143, 17);
			   this->lblRol->TabIndex = 0;
			   this->lblRol->Text = L"Seleccione su Rol:";
			   // 
			   // btnIngresar
			   // 
			   this->btnIngresar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->btnIngresar->FlatAppearance->BorderSize = 0;
			   this->btnIngresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnIngresar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnIngresar->ForeColor = System::Drawing::Color::White;
			   this->btnIngresar->Location = System::Drawing::Point(67, 535);
			   this->btnIngresar->Margin = System::Windows::Forms::Padding(4);
			   this->btnIngresar->Name = L"btnIngresar";
			   this->btnIngresar->Size = System::Drawing::Size(398, 51);
			   this->btnIngresar->TabIndex = 9;
			   this->btnIngresar->Text = L"Ingresar";
			   this->btnIngresar->UseVisualStyleBackColor = false;
			   this->btnIngresar->Click += gcnew System::EventHandler(this, &LoginForm::btnIngresar_Click);
			   // 
			   // lnkCrearCuenta
			   // 
			   this->btnSalir->BackColor = System::Drawing::Color::IndianRed;
			   this->btnSalir->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnSalir->FlatAppearance->BorderSize = 0;
			   this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnSalir->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F));
			   this->btnSalir->ForeColor = System::Drawing::Color::White;
			   this->btnSalir->Location = System::Drawing::Point(35, 455);
			   this->btnSalir->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->btnSalir->Name = L"btnSalir";
			   this->btnSalir->Size = System::Drawing::Size(315, 43);
			   this->btnSalir->TabIndex = 4;
			   this->btnSalir->Text = L"Salir";
			   this->btnSalir->UseVisualStyleBackColor = false;
			   this->btnSalir->Click += gcnew System::EventHandler(this, &LoginForm::btnSalir_Click);
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

	private: System::Void btnIngresar_Click(System::Object^ sender, System::EventArgs^ e) {

		if (cmbRol->SelectedItem == nullptr) {
			MessageBox::Show("¡WinniePOO necesita saber tu rol para dejarte entrar!", "Falta información", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		String^ rol = cmbRol->SelectedItem->ToString();
		String^ usuario = txtUsuario->Text;
		String^ password = txtPassword->Text;

		if (usuario == "" || password == "") {
			MessageBox::Show("Por favor, ingresa tu DNI y contraseña.", "Campos vacíos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Mensaje amigable simulando el ingreso
		MessageBox::Show("¡Hola " + usuario + "!\nIngresando al sistema como: " + rol, "¡Bienvenido a WinniePOO!", MessageBoxButtons::OK, MessageBoxIcon::Information);


			// Cuando se cierre la ventana de Operador (Cerrar Sesión), volvemos a mostrar el Login
			this->Show();
		}
		else {
			// Mensaje temporal para los otros roles que aún no tienen interfaz lista
			MessageBox::Show("La interfaz para " + rolSeleccionado + " todavía está en desarrollo.", "Próximamente");
		}


	private: System::Void lnkCrearCuenta_Click(System::Object^ sender, System::EventArgs^ e) {
		RegisterForm^ ventanaRegistro = gcnew RegisterForm();
		ventanaRegistro->ShowDialog();
	}

	private: System::Void lblBienvenida_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}