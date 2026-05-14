#pragma once

#include "claseDatos.h"

namespace Appescuelaw {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class secretariaForm : public System::Windows::Forms::Form
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

		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::Button^ button1;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->dataGridView1 =
				(gcnew System::Windows::Forms::DataGridView());

			this->button1 =
				(gcnew System::Windows::Forms::Button());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(
				this->dataGridView1))->BeginInit();

			this->SuspendLayout();

			// dataGridView1
			this->dataGridView1->ColumnHeadersHeightSizeMode =
				System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;

			this->dataGridView1->Location =
				System::Drawing::Point(20, 80);

			this->dataGridView1->Name = L"dataGridView1";

			this->dataGridView1->Size =
				System::Drawing::Size(700, 250);

			// button1
			this->button1->Location =
				System::Drawing::Point(20, 20);

			this->button1->Name = L"button1";

			this->button1->Size =
				System::Drawing::Size(220, 40);

			this->button1->Text = L"Mostrar Matriculados";

			this->button1->UseVisualStyleBackColor = true;

			this->button1->Click +=
				gcnew System::EventHandler(
					this,
					&secretariaForm::button1_Click);

			// secretariaForm
			this->AutoScaleDimensions =
				System::Drawing::SizeF(6, 13);

			this->AutoScaleMode =
				System::Windows::Forms::AutoScaleMode::Font;

			this->ClientSize =
				System::Drawing::Size(760, 400);

			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);

			this->Name = L"secretariaForm";

			this->Text = L"Secretaria";

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(
				this->dataGridView1))->EndInit();

			this->ResumeLayout(false);
		}

#pragma endregion

	private:

		System::Void button1_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			dataGridView1->Rows->Clear();
			dataGridView1->Columns->Clear();

			dataGridView1->ColumnCount = 4;

			dataGridView1->Columns[0]->Name = "Usuario";
			dataGridView1->Columns[1]->Name = "Carrera";
			dataGridView1->Columns[2]->Name = "Semestre";
			dataGridView1->Columns[3]->Name = "Materia";

			for each(Estudiante ^ e in DatosSistema::estudiantes)
			{
				array<String^>^ fila =
				{
					e->usuario,
					e->carrera,
					e->semestre,
					e->materia
				};

				dataGridView1->Rows->Add(fila);
			}
		}
	};
}