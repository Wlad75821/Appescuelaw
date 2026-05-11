#include "mainForm.h" 

using namespace System;
using namespace System::Windows::Forms;

// Esta línea asegura que se use el punto de entrada 
main en lugar de WinMain
[STAThread]
void main(array<String^>^ arg)
{
    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);

    // Crea una instancia de tu formulario principal y 
    lo ejecuta
        AppEscuela::mainForm form;