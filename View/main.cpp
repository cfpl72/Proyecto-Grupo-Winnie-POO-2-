#include "pch.h"
#include "LoginForm.h" 

using namespace System;
using namespace System::Windows::Forms; // Necesario para interfaces gráficas
using namespace WinniePOOview; // El namespace donde vive tu vista

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    // Configuraciones visuales estándar de Windows
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // ¡El momento de la verdad! Arrancamos el programa mostrando tu LoginForm
    Application::Run(gcnew LoginForm());

    return 0;
}