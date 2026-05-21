#pragma once

namespace Appescuelaw
{
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class secretariaForm : public Form
	{
	public:
		secretariaForm(void)
		{
			InitializeComponent();
		}

	protected:
		~secretariaForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Label^ lblTitulo;
		Button^ btnMostrar;
		Button^ btnVolver;
		DataGridView^ dataGridView1;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblTitulo = gcnew Label();
			this->btnMostrar = gcnew Button();
			this->btnVolver = gcnew Button();
			this->dataGridView1 = gcnew DataGridView();

			this->SuspendLayout();

			this->Text = L"Secretaria";
			this->ClientSize = Drawing::Size(900, 500);
			this->StartPosition = FormStartPosition::CenterScreen;

			lblTitulo->Text = L"Matriculados";
			lblTitulo->Location = Point(30, 20);
			lblTitulo->Size = Drawing::Size(200, 30);

			btnMostrar->Text = L"Mostrar Matriculados";
			btnMostrar->Location = Point(30, 60);
			btnMostrar->Size = Drawing::Size(180, 40);
			btnMostrar->Click += gcnew EventHandler(this, &secretariaForm::btnMostrar_Click);

			btnVolver->Text = L"Volver";
			btnVolver->Location = Point(230, 60);
			btnVolver->Size = Drawing::Size(120, 40);
			btnVolver->Click += gcnew EventHandler(this, &secretariaForm::btnVolver_Click);

			dataGridView1->Location = Point(30, 120);
			dataGridView1->Size = Drawing::Size(820, 320);
			dataGridView1->AllowUserToAddRows = false;
			dataGridView1->ColumnCount = 6;

			dataGridView1->Columns[0]->Name = "Nombre";
			dataGridView1->Columns[1]->Name = "Edad";
			dataGridView1->Columns[2]->Name = "CI";
			dataGridView1->Columns[3]->Name = "Carrera";
			dataGridView1->Columns[4]->Name = "Periodo";
			dataGridView1->Columns[5]->Name = "Materias";

			this->Controls->Add(lblTitulo);
			this->Controls->Add(btnMostrar);
			this->Controls->Add(btnVolver);
			this->Controls->Add(dataGridView1);

			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion

	private:

		System::Void btnMostrar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			dataGridView1->Rows->Clear();

			if (!File::Exists("matriculas.txt"))
			{
				MessageBox::Show("No hay matriculas registradas");
				return;
			}

			StreamReader^ sr = gcnew StreamReader("matriculas.txt");

			while (!sr->EndOfStream)
			{
				String^ linea = sr->ReadLine();

				array<String^>^ datos = linea->Split(',');

				if (datos->Length == 6)
				{
					dataGridView1->Rows->Add(
						datos[0],
						datos[1],
						datos[2],
						datos[3],
						datos[4],
						datos[5]
					);
				}
			}

			sr->Close();
		}

		System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}
	};
}