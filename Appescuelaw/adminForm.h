// ===== adminForm.h =====

#pragma once

#include "claseDatos.h"

namespace Appescuelaw {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class adminForm : public Form
	{
	public:
		adminForm(void)
		{
			InitializeComponent();
		}

	private:

		TextBox^ textBox1;
		TextBox^ textBox2;

		Button^ button1;
		Button^ button2;
		Button^ button3;

		void InitializeComponent(void)
		{
			this->textBox1 = gcnew TextBox();
			this->textBox2 = gcnew TextBox();

			this->button1 = gcnew Button();
			this->button2 = gcnew Button();
			this->button3 = gcnew Button();

			this->SuspendLayout();

			// textBox1
			this->textBox1->Location = Point(40, 40);
			this->textBox1->Text = "";

			// textBox2
			this->textBox2->Location = Point(40, 90);
			this->textBox2->Text = "";

			// button1
			this->button1->Location = Point(40, 150);
			this->button1->Text = "Crear";
			this->button1->Click +=
				gcnew EventHandler(this, &adminForm::button1_Click);

			// button2
			this->button2->Location = Point(140, 150);
			this->button2->Text = "Eliminar";
			this->button2->Click +=
				gcnew EventHandler(this, &adminForm::button2_Click);

			// button3
			this->button3->Location = Point(260, 150);
			this->button3->Text = "Editar";
			this->button3->Click +=
				gcnew EventHandler(this, &adminForm::button3_Click);

			// form
			this->ClientSize = Drawing::Size(500, 300);

			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox2);

			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);

			this->Text = L"Administrador";

			this->ResumeLayout(false);
		}

	private:

		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Estudiante^ nuevo = gcnew Estudiante();

			nuevo->usuario = textBox1->Text;
			nuevo->password = textBox2->Text;

			DatosSistema::estudiantes->Add(nuevo);

			MessageBox::Show("Usuario creado");
		}

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ usuario = textBox1->Text;

			for (int i = 0; i < DatosSistema::estudiantes->Count; i++)
			{
				if (DatosSistema::estudiantes[i]->usuario == usuario)
				{
					DatosSistema::estudiantes->RemoveAt(i);

					MessageBox::Show("Usuario eliminado");
					return;
				}
			}

			MessageBox::Show("Usuario no encontrado");
		}

		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ usuario = textBox1->Text;

			for each (Estudiante ^ e in DatosSistema::estudiantes)
			{
				if (e->usuario == usuario)
				{
					e->password = textBox2->Text;

					MessageBox::Show("Usuario editado");
					return;
				}
			}

			MessageBox::Show("Usuario no encontrado");
		}
	};
}