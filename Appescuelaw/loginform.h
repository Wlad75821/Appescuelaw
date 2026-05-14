// ===== loginForm.h =====

#pragma once

#include "matriculaForm.h"
#include "secretariaForm.h"
#include "adminForm.h"
#include "claseDatos.h"

namespace Appescuelaw {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class loginForm : public System::Windows::Forms::Form
	{
	public:
		loginForm(void)
		{
			InitializeComponent();
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
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());

			this->SuspendLayout();

			// textBox1
			this->textBox1->Location = System::Drawing::Point(321, 142);
			this->textBox1->Size = System::Drawing::Size(151, 20);

			// textBox2
			this->textBox2->Location = System::Drawing::Point(321, 193);
			this->textBox2->Size = System::Drawing::Size(151, 20);
			this->textBox2->UseSystemPasswordChar = true;

			// button1
			this->button1->Location = System::Drawing::Point(303, 246);
			this->button1->Size = System::Drawing::Size(112, 41);
			this->button1->Text = L"Ingresar";
			this->button1->Click +=
				gcnew System::EventHandler(this, &loginForm::button1_Click);

			// label1
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(266, 145);
			this->label1->Text = L"Usuario";

			// label2
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(248, 196);
			this->label2->Text = L"Contraseña";

			// loginForm
			this->ClientSize = System::Drawing::Size(737, 444);

			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);

			this->Text = L"Login";

			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion

	private:

		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ usuario = textBox1->Text->Trim();
			String^ password = textBox2->Text->Trim();

			// ADMIN
			if (usuario == "admin" && password == "789")
			{
				adminForm^ form = gcnew adminForm();
				form->Show();

				this->Hide();
				return;
			}

			// SECRETARIA
			if (usuario == "secretaria" && password == "456")
			{
				secretariaForm^ form = gcnew secretariaForm();
				form->Show();

				this->Hide();
				return;
			}

			// ESTUDIANTES
			for each (Estudiante ^ e in DatosSistema::estudiantes)
			{
				if (e->usuario == usuario &&
					e->password == password)
				{
					matriculaForm^ form =
						gcnew matriculaForm();

					form->Show();

					this->Hide();
					return;
				}
			}

			MessageBox::Show("Usuario o contraseña incorrectos");
		}
	};
}