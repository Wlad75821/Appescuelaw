#include "mainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Appescuelaw;

[STAThreadAttribute]

int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    mainForm form;
    Application::Run(% form);

    return 0;
}