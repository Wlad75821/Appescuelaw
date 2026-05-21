#pragma once

#include "Usuario.h"

namespace Appescuelaw
{
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;

	public ref class adminForm : public Form
	{
	public:
		adminForm(void)
		{
			InitializeComponent();
			corregirTextBox();

			listaUsuarios = gcnew List<Usuario^>();

			cargarUsuarios();
		}

	protected:
		~adminForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		List<Usuario^>^ listaUsuarios;

		Label^ lblUsuario;
		Label^ lblClave;
		Label^ lblRol;

		TextBox^ txtUsuario;
		TextBox^ txtClave;
		TextBox^ txtRol;

		Button^ btnCrear;
		Button^ btnEditar;
		Button^ btnEliminar;
		Button^ btnVolver;

		DataGridView^ dataGridView1;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblUsuario = gcnew Label();
			this->lblClave = gcnew Label();
			this->lblRol = gcnew Label();

			this->txtUsuario = gcnew TextBox();
			this->txtClave = gcnew TextBox();
			this->txtRol = gcnew TextBox();

			this->btnCrear = gcnew Button();
			this->btnEditar = gcnew Button();
			this->btnEliminar = gcnew Button();
			this->btnVolver = gcnew Button();

			this->dataGridView1 = gcnew DataGridView();

			this->SuspendLayout();

			this->Text = L"adminForm";
			this->ClientSize = Drawing::Size(850, 500);
			this->StartPosition = FormStartPosition::CenterScreen;

			lblUsuario->Text = L"Usuario";
			lblUsuario->Location = Point(40, 40);

			txtUsuario->Location = Point(120, 40);
			txtUsuario->Size = Drawing::Size(180, 28);

			lblClave->Text = L"Clave";
			lblClave->Location = Point(40, 90);

			txtClave->Location = Point(120, 90);
			txtClave->Size = Drawing::Size(180, 28);

			lblRol->Text = L"Rol";
			lblRol->Location = Point(40, 140);

			txtRol->Location = Point(120, 140);
			txtRol->Size = Drawing::Size(180, 28);

			btnCrear->Text = L"Crear";
			btnCrear->Location = Point(40, 200);
			btnCrear->Size = Drawing::Size(100, 35);
			btnCrear->Click += gcnew EventHandler(this, &adminForm::btnCrear_Click);

			btnEditar->Text = L"Editar";
			btnEditar->Location = Point(150, 200);
			btnEditar->Size = Drawing::Size(100, 35);
			btnEditar->Click += gcnew EventHandler(this, &adminForm::btnEditar_Click);

			btnEliminar->Text = L"Eliminar";
			btnEliminar->Location = Point(260, 200);
			btnEliminar->Size = Drawing::Size(100, 35);
			btnEliminar->Click += gcnew EventHandler(this, &adminForm::btnEliminar_Click);

			btnVolver->Text = L"Volver";
			btnVolver->Location = Point(150, 260);
			btnVolver->Size = Drawing::Size(100, 35);
			btnVolver->Click += gcnew EventHandler(this, &adminForm::btnVolver_Click);

			dataGridView1->Location = Point(370, 40);
			dataGridView1->Size = Drawing::Size(430, 300);
			dataGridView1->AllowUserToAddRows = false;
			dataGridView1->ColumnCount = 3;
			dataGridView1->Columns[0]->Name = "Usuario";
			dataGridView1->Columns[1]->Name = "Clave";
			dataGridView1->Columns[2]->Name = "Rol";
			dataGridView1->SelectionChanged += gcnew EventHandler(this, &adminForm::dataGridView1_SelectionChanged);

			this->Controls->Add(lblUsuario);
			this->Controls->Add(txtUsuario);
			this->Controls->Add(lblClave);
			this->Controls->Add(txtClave);
			this->Controls->Add(lblRol);
			this->Controls->Add(txtRol);

			this->Controls->Add(btnCrear);
			this->Controls->Add(btnEditar);
			this->Controls->Add(btnEliminar);
			this->Controls->Add(btnVolver);

			this->Controls->Add(dataGridView1);

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

		void guardarUsuarios()
		{
			StreamWriter^ sw = gcnew StreamWriter("usuarios.txt");

			for each (Usuario ^ u in listaUsuarios)
			{
				sw->WriteLine(u->usuario + "," + u->clave + "," + u->rol);
			}

			sw->Close();
		}

		void cargarUsuarios()
		{
			dataGridView1->Rows->Clear();

			if (!File::Exists("usuarios.txt"))
			{
				return;
			}

			StreamReader^ sr = gcnew StreamReader("usuarios.txt");

			while (!sr->EndOfStream)
			{
				String^ linea = sr->ReadLine();
				array<String^>^ datos = linea->Split(',');

				if (datos->Length == 3)
				{
					Usuario^ u = gcnew Usuario(datos[0], datos[1], datos[2]);

					listaUsuarios->Add(u);

					dataGridView1->Rows->Add(u->usuario, u->clave, u->rol);
				}
			}

			sr->Close();
		}

		System::Void btnCrear_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (txtUsuario->Text == "" || txtClave->Text == "" || txtRol->Text == "")
			{
				MessageBox::Show("Llene todos los campos");
				return;
			}

			if (txtRol->Text != "admin" &&
				txtRol->Text != "secretaria" &&
				txtRol->Text != "estudiante")
			{
				MessageBox::Show("Rol debe ser: admin, secretaria o estudiante");
				return;
			}

			Usuario^ u = gcnew Usuario(txtUsuario->Text, txtClave->Text, txtRol->Text);

			listaUsuarios->Add(u);
			dataGridView1->Rows->Add(u->usuario, u->clave, u->rol);

			guardarUsuarios();

			MessageBox::Show("Usuario creado");
		}

		System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (dataGridView1->CurrentRow == nullptr)
			{
				MessageBox::Show("Seleccione una fila");
				return;
			}

			int i = dataGridView1->CurrentRow->Index;

			if (i >= 0 && i < listaUsuarios->Count)
			{
				listaUsuarios[i]->usuario = txtUsuario->Text;
				listaUsuarios[i]->clave = txtClave->Text;
				listaUsuarios[i]->rol = txtRol->Text;

				dataGridView1->Rows[i]->Cells[0]->Value = txtUsuario->Text;
				dataGridView1->Rows[i]->Cells[1]->Value = txtClave->Text;
				dataGridView1->Rows[i]->Cells[2]->Value = txtRol->Text;

				guardarUsuarios();

				MessageBox::Show("Usuario editado");
			}
		}

		System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (dataGridView1->CurrentRow == nullptr)
			{
				MessageBox::Show("Seleccione una fila");
				return;
			}

			int i = dataGridView1->CurrentRow->Index;

			if (i >= 0 && i < listaUsuarios->Count)
			{
				listaUsuarios->RemoveAt(i);
				dataGridView1->Rows->RemoveAt(i);

				guardarUsuarios();

				MessageBox::Show("Usuario eliminado");
			}
		}

		System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		System::Void dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (dataGridView1->CurrentRow != nullptr)
			{
				txtUsuario->Text = Convert::ToString(dataGridView1->CurrentRow->Cells[0]->Value);
				txtClave->Text = Convert::ToString(dataGridView1->CurrentRow->Cells[1]->Value);
				txtRol->Text = Convert::ToString(dataGridView1->CurrentRow->Cells[2]->Value);
			}
		}
	};
}