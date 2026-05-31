#pragma once

namespace WinniePOOview {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class RecoverPasswordForm : public System::Windows::Forms::Form
	{
	public:
		RecoverPasswordForm(void) { InitializeComponent(); }

	protected:
		~RecoverPasswordForm() { if (components) delete components; }


	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblInstrucciones;
	private: System::Windows::Forms::Label^ lblCorreo;
	private: System::Windows::Forms::TextBox^ txtCorreo;
	private: System::Windows::Forms::Button^ btnEnviar;
	private: System::Windows::Forms::PictureBox^ pictureBoxOso;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RecoverPasswordForm::typeid));
			   this->lblTitulo = (gcnew System::Windows::Forms::Label());
			   this->lblInstrucciones = (gcnew System::Windows::Forms::Label());
			   this->lblCorreo = (gcnew System::Windows::Forms::Label());
			   this->txtCorreo = (gcnew System::Windows::Forms::TextBox());
			   this->btnEnviar = (gcnew System::Windows::Forms::Button());
			   this->pictureBoxOso = (gcnew System::Windows::Forms::PictureBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOso))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // lblTitulo
			   // 
			   this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			   this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				   static_cast<System::Int32>(static_cast<System::Byte>(100)));
			   this->lblTitulo->Location = System::Drawing::Point(188, 40);
			   this->lblTitulo->Name = L"lblTitulo";
			   this->lblTitulo->Size = System::Drawing::Size(162, 63);
			   this->lblTitulo->TabIndex = 4;
			   this->lblTitulo->Text = L"Recuperar Contraseña";
			   this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // lblInstrucciones
			   // 
			   this->lblInstrucciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			   this->lblInstrucciones->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->lblInstrucciones->Location = System::Drawing::Point(46, 137);
			   this->lblInstrucciones->Name = L"lblInstrucciones";
			   this->lblInstrucciones->Size = System::Drawing::Size(320, 66);
			   this->lblInstrucciones->TabIndex = 3;
			   this->lblInstrucciones->Text = L"Ingresa el correo asociado a tu cuenta. Te enviaremos un enlace para restablecer "
				   L"tu contraseña.";
			   this->lblInstrucciones->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // lblCorreo
			   // 
			   this->lblCorreo->AutoSize = true;
			   this->lblCorreo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			   this->lblCorreo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->lblCorreo->Location = System::Drawing::Point(46, 203);
			   this->lblCorreo->Name = L"lblCorreo";
			   this->lblCorreo->Size = System::Drawing::Size(141, 20);
			   this->lblCorreo->TabIndex = 2;
			   this->lblCorreo->Text = L"Correo Electrónico:";
			   // 
			   // txtCorreo
			   // 
			   this->txtCorreo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   this->txtCorreo->Location = System::Drawing::Point(50, 226);
			   this->txtCorreo->Name = L"txtCorreo";
			   this->txtCorreo->Size = System::Drawing::Size(300, 30);
			   this->txtCorreo->TabIndex = 1;
			   // 
			   // btnEnviar
			   // 
			   this->btnEnviar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(166)),
				   static_cast<System::Int32>(static_cast<System::Byte>(160)));
			   this->btnEnviar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnEnviar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			   this->btnEnviar->ForeColor = System::Drawing::Color::White;
			   this->btnEnviar->Location = System::Drawing::Point(50, 276);
			   this->btnEnviar->Name = L"btnEnviar";
			   this->btnEnviar->Size = System::Drawing::Size(300, 40);
			   this->btnEnviar->TabIndex = 0;
			   this->btnEnviar->Text = L"Enviar Instrucciones";
			   this->btnEnviar->UseVisualStyleBackColor = false;
			   this->btnEnviar->Click += gcnew System::EventHandler(this, &RecoverPasswordForm::btnEnviar_Click);
			   // 
			   // pictureBoxOso
			   // 
			   this->pictureBoxOso->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxOso.Image")));
			   this->pictureBoxOso->Location = System::Drawing::Point(50, 12);
			   this->pictureBoxOso->Name = L"pictureBoxOso";
			   this->pictureBoxOso->Size = System::Drawing::Size(132, 122);
			   this->pictureBoxOso->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBoxOso->TabIndex = 5;
			   this->pictureBoxOso->TabStop = false;
			   // 
			   // RecoverPasswordForm
			   // 
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(250)));
			   this->ClientSize = System::Drawing::Size(400, 340);
			   this->Controls->Add(this->btnEnviar);
			   this->Controls->Add(this->txtCorreo);
			   this->Controls->Add(this->lblCorreo);
			   this->Controls->Add(this->lblInstrucciones);
			   this->Controls->Add(this->lblTitulo);
			   this->Controls->Add(this->pictureBoxOso);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->Name = L"RecoverPasswordForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"WinniePOO - Recuperación";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOso))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void btnEnviar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtCorreo->Text == "" || !txtCorreo->Text->Contains("@")) {
			MessageBox::Show("Por favor, ingresa un correo válido.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		MessageBox::Show("Si el correo está registrado en nuestro sistema, en breve recibirás las instrucciones para restablecer tu contraseña.", "Correo Enviado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
	}
	};
}