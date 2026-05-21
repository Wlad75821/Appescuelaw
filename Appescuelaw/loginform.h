#pragma once

#include "adminForm.h"
#include "secretariaForm.h"
#include "matriculaForm.h"

namespace Appescuelaw
{
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class loginForm : public Form
	{
	public:
		loginForm(void)
		{
			InitializeComponent();
			corregirTextBox();
		}

	protected:
		~loginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Label^ lblUsuario;
		Label^ lblClave;
		TextBox^ txtUsuario;
		TextBox^ txtClave;
		Button^ btnIngresar;
		Button^ btnSalir;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblUsuario = gcnew Label();
			this->lblClave = gcnew Label();
			this->txtUsuario = gcnew TextBox();
			this->txtClave = gcnew TextBox();
			this->btnIngresar = gcnew Button();
			this->btnSalir = gcnew Button();

			this->SuspendLayout();

			this->Text = L"Login";
			this->ClientSize = Drawing::Size(750, 450);
			this->StartPosition = FormStartPosition::CenterScreen;

			lblUsuario->Text = L"Usuario";
			lblUsuario->Location = Point(250, 150);

			txtUsuario->Location = Point(340, 150);
			txtUsuario->Size = Drawing::Size(180, 28);

			lblClave->Text = L"Contrasena";
			lblClave->Location = Point(250, 200);

			txtClave->Location = Point(340, 200);
			txtClave->Size = Drawing::Size(180, 28);
			txtClave->UseSystemPasswordChar = true;

			btnIngresar->Text = L"Ingresar";
			btnIngresar->Location = Point(310, 270);
			btnIngresar->Size = Drawing::Size(120, 40);
			btnIngresar->Click += gcnew EventHandler(this, &loginForm::btnIngresar_Click);

			btnSalir->Text = L"Salir";
			btnSalir->Location = Point(450, 270);
			btnSalir->Size = Drawing::Size(120, 40);
			btnSalir->Click += gcnew EventHandler(this, &loginForm::btnSalir_Click);

			this->Controls->Add(lblUsuario);
			this->Controls->Add(txtUsuario);
			this->Controls->Add(lblClave);
			this->Controls->Add(txtClave);
			this->Controls->Add(btnIngresar);
			this->Controls->Add(btnSalir);

			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion

	private:

		void corregirTextBox()
		{
			for each (Control ^ c in this->Controls)
			{
				TextBox^ txt = dynamic_cast<TextBox^>(c);

				if (txt != nullptr)
				{
					txt->Multiline = false;
					txt->Font = gcnew Drawing::Font("Microsoft Sans Serif", 10);
					txt->Height = 28;
					txt->BorderStyle = BorderStyle::FixedSingle;
					txt->TextAlign = HorizontalAlignment::Left;
					txt->BackColor = Color::White;
					txt->ForeColor = Color::Black;
					txt->BringToFront();
				}
			}
		}

		System::Void btnIngresar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ usuario = txtUsuario->Text->Trim();
			String^ clave = txtClave->Text->Trim();

			if (usuario == "admin" && clave == "789")
			{
				adminForm^ form = gcnew adminForm();

				this->Hide();
				form->ShowDialog();
				this->Show();

				return;
			}

			if (!File::Exists("usuarios.txt"))
			{
				MessageBox::Show("No hay usuarios creados");
				return;
			}

			StreamReader^ sr = gcnew StreamReader("usuarios.txt");

			bool encontrado = false;
			String^ rol = "";

			while (!sr->EndOfStream)
			{
				String^ linea = sr->ReadLine();
				array<String^>^ datos = linea->Split(',');

				if (datos->Length == 3)
				{
					if (usuario == datos[0] && clave == datos[1])
					{
						encontrado = true;
						rol = datos[2];
						break;
					}
				}
			}

			sr->Close();

			if (!encontrado)
			{
				MessageBox::Show("Usuario o clave incorrectos");
				return;
			}

			if (rol == "admin")
			{
				adminForm^ form = gcnew adminForm();

				this->Hide();
				form->ShowDialog();
				this->Show();
			}
			else if (rol == "secretaria")
			{
				secretariaForm^ form = gcnew secretariaForm();

				this->Hide();
				form->ShowDialog();
				this->Show();
			}
			else if (rol == "estudiante")
			{
				matriculaForm^ form = gcnew matriculaForm();

				this->Hide();
				form->ShowDialog();
				this->Show();
			}
			else
			{
				MessageBox::Show("Rol no valido");
			}
		}

		System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}
	};
}