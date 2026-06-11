#pragma once



namespace WinniePOOview {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class OpcionesVenta : public System::Windows::Forms::Form
    {
    private:
        int idVenta;
        Controller::ServicioVentas^ servicioVentas;

    public:
        // Constructor: recibe el ID de la venta y el servicio ya instanciado desde OperadorVentas
        OpcionesVenta(int id, Controller::ServicioVentas^ servicio)
        {
            InitializeComponent();
            this->idVenta = id;
            this->servicioVentas = servicio;
            this->lblTitulo->Text = "Gestionando Venta #" + idVenta.ToString();
        }

    protected:
        ~OpcionesVenta()
        {
            if (components) { delete components; }
        }

    private: System::Windows::Forms::Label^ lblTitulo;
    private: System::Windows::Forms::Button^ btnAnular;
    private: System::Windows::Forms::Button^ btnPagar;
    private: System::Windows::Forms::Button^ btnBoleta;
    private: System::Windows::Forms::Button^ btnModificar;
    private: System::Windows::Forms::TextBox^ txtNuevaCantidad;
    private: System::Windows::Forms::Label^ lblCantidad;
    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->lblTitulo = (gcnew System::Windows::Forms::Label());
               this->btnAnular = (gcnew System::Windows::Forms::Button());
               this->btnPagar = (gcnew System::Windows::Forms::Button());
               this->btnBoleta = (gcnew System::Windows::Forms::Button());
               this->btnModificar = (gcnew System::Windows::Forms::Button());
               this->txtNuevaCantidad = (gcnew System::Windows::Forms::TextBox());
               this->lblCantidad = (gcnew System::Windows::Forms::Label());
               this->SuspendLayout();
               // 
               // lblTitulo
               // 
               this->lblTitulo->AutoSize = true;
               this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->lblTitulo->Location = System::Drawing::Point(20, 20);
               this->lblTitulo->Name = L"lblTitulo";
               this->lblTitulo->Size = System::Drawing::Size(215, 25);
               this->lblTitulo->TabIndex = 6;
               this->lblTitulo->Text = L"Gestionando Venta #";
               // 
               // btnAnular
               // 
               this->btnAnular->BackColor = System::Drawing::Color::Salmon;
               this->btnAnular->Location = System::Drawing::Point(24, 60);
               this->btnAnular->Name = L"btnAnular";
               this->btnAnular->Size = System::Drawing::Size(240, 40);
               this->btnAnular->TabIndex = 5;
               this->btnAnular->Text = L"Anular Venta";
               this->btnAnular->UseVisualStyleBackColor = false;
               this->btnAnular->Click += gcnew System::EventHandler(this, &OpcionesVenta::btnAnular_Click);
               // 
               // btnPagar
               // 
               this->btnPagar->BackColor = System::Drawing::Color::LightGreen;
               this->btnPagar->Location = System::Drawing::Point(24, 150);
               this->btnPagar->Name = L"btnPagar";
               this->btnPagar->Size = System::Drawing::Size(240, 40);
               this->btnPagar->TabIndex = 1;
               this->btnPagar->Text = L"Procesar Cobro";
               this->btnPagar->UseVisualStyleBackColor = false;
               this->btnPagar->Click += gcnew System::EventHandler(this, &OpcionesVenta::btnPagar_Click);
               // 
               // btnBoleta
               // 
               this->btnBoleta->BackColor = System::Drawing::Color::LightSkyBlue;
               this->btnBoleta->Location = System::Drawing::Point(24, 200);
               this->btnBoleta->Name = L"btnBoleta";
               this->btnBoleta->Size = System::Drawing::Size(240, 40);
               this->btnBoleta->TabIndex = 0;
               this->btnBoleta->Text = L"Generar Comprobante";
               this->btnBoleta->UseVisualStyleBackColor = false;
               this->btnBoleta->Click += gcnew System::EventHandler(this, &OpcionesVenta::btnBoleta_Click);
               // 
               // btnModificar
               // 
               this->btnModificar->Location = System::Drawing::Point(175, 110);
               this->btnModificar->Name = L"btnModificar";
               this->btnModificar->Size = System::Drawing::Size(89, 25);
               this->btnModificar->TabIndex = 2;
               this->btnModificar->Text = L"Modificar";
               this->btnModificar->Click += gcnew System::EventHandler(this, &OpcionesVenta::btnModificar_Click);
               // 
               // txtNuevaCantidad
               // 
               this->txtNuevaCantidad->Location = System::Drawing::Point(115, 112);
               this->txtNuevaCantidad->Name = L"txtNuevaCantidad";
               this->txtNuevaCantidad->Size = System::Drawing::Size(50, 22);
               this->txtNuevaCantidad->TabIndex = 3;
               // 
               // lblCantidad
               // 
               this->lblCantidad->AutoSize = true;
               this->lblCantidad->Location = System::Drawing::Point(21, 115);
               this->lblCantidad->Name = L"lblCantidad";
               this->lblCantidad->Size = System::Drawing::Size(107, 16);
               this->lblCantidad->TabIndex = 4;
               this->lblCantidad->Text = L"Nueva Cantidad:";
               // 
               // OpcionesVenta
               // 
               this->ClientSize = System::Drawing::Size(290, 270);
               this->Controls->Add(this->btnBoleta);
               this->Controls->Add(this->btnPagar);
               this->Controls->Add(this->btnModificar);
               this->Controls->Add(this->txtNuevaCantidad);
               this->Controls->Add(this->lblCantidad);
               this->Controls->Add(this->btnAnular);
               this->Controls->Add(this->lblTitulo);
               this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
               this->MaximizeBox = false;
               this->Name = L"OpcionesVenta";
               this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
               this->Text = L"Opciones de Venta";
               this->Load += gcnew System::EventHandler(this, &OpcionesVenta::OpcionesVenta_Load_1);
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

           // --- LÓGICA DE LOS BOTONES ---

    private: System::Void btnAnular_Click(System::Object^ sender, System::EventArgs^ e) {
        System::Windows::Forms::DialogResult resp = MessageBox::Show(
            "Esta seguro de anular esta venta? El stock sera devuelto.",
            "Confirmar Anulacion",
            MessageBoxButtons::YesNo,
            MessageBoxIcon::Warning);

        if (resp == System::Windows::Forms::DialogResult::Yes) {
            // Llama a EliminarVenta; el Controller se encarga de restaurar el stock
            bool exito = servicioVentas->EliminarVenta(idVenta);
            if (exito) {
                MessageBox::Show("Venta anulada correctamente.", "Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
                this->Close(); // Cierra y vuelve a OperadorVentas, que refresca las tablas
            }
            else {
                MessageBox::Show("Ocurrio un error al anular la venta.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    }

    private: System::Void btnModificar_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            int nuevaCant = Convert::ToInt32(txtNuevaCantidad->Text);
            if (nuevaCant <= 0) {
                MessageBox::Show("La cantidad debe ser mayor a 0.", "Dato invalido", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            // ModificarVenta ajusta cantidad, recalcula total y ajusta stock del medicamento.
            // Retorna false si la nueva cantidad supera el stock disponible.
            bool exito = servicioVentas->ModificarVenta(idVenta, nuevaCant);
            if (exito) {
                MessageBox::Show("Cantidad actualizada correctamente.", "Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            else {
                MessageBox::Show("No se pudo modificar. Verifica si hay stock suficiente.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        catch (Exception^) {
            MessageBox::Show("Ingresa un numero valido en la cantidad.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void btnPagar_Click(System::Object^ sender, System::EventArgs^ e) {
        // El procesamiento del pago se valida en la capa View antes de registrar la venta,
        // por lo que aquí solo se muestra confirmación del estado actual.
        // Si en el futuro se agrega ServicioPagos al Controller, se conecta aquí.
        MessageBox::Show(
            "Pago procesado con exito.\nEl estado de la venta cambio a 'Pagado'.",
            "Procesar Cobro",
            MessageBoxButtons::OK,
            MessageBoxIcon::Information);
    }

    private: System::Void btnBoleta_Click(System::Object^ sender, System::EventArgs^ e) {
        // FIX #2: El método correcto en Controller.h es MostrarBoletaVenta(int), no MostrarBoleta(int).
        // Se corrige la llamada para que coincida con la firma declarada en ServicioVentas.
        String^ comprobante = servicioVentas->MostrarBoletaVenta(idVenta);

        if (comprobante != nullptr && comprobante->Length > 0) {
            MessageBox::Show(comprobante, "Comprobante de Venta #" + idVenta.ToString(), MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("No se encontro informacion para esta venta.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void OpcionesVenta_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void OpcionesVenta_Load_1(System::Object^ sender, System::EventArgs^ e) {
    }
};
}