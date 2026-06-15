#include "pch.h"
#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace WinniePOOviews;



[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew LoginForm());
    return 0;
}
