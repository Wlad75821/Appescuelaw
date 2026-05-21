#pragma once

namespace Appescuelaw
{
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;

	public ref class matriculaForm : public Form
	{
	public:
		matriculaForm(void)
		{
			InitializeComponent();
			corregirTextBox();

			cbCarrera->Items->Add("Computacion");
			cbCarrera->Items->Add("Ing Civil");
			cbCarrera->Items->Add("Enfermeria");

			cbPeriodo->Items->Add("1er Semestre");
			cbPeriodo->Items->Add("2do Semestre");
			cbPeriodo->Items->Add("3er Semestre");

			clbMaterias->Items->Add("Programacion");
			clbMaterias->Items->Add("Calculo");
			clbMaterias->Items->Add("Ingles");
		}

	protected:
		~matriculaForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Label^ lblNombre;
		Label^ lblEdad;
		Label^ lblCI;
		Label^ lblCarrera;
		Label^ lblPeriodo;
		Label^ lblMaterias;

		TextBox^ txtNombre;
		TextBox^ txtEdad;
		TextBox^ txtCI;

		ComboBox^ cbCarrera;
		ComboBox^ cbPeriodo;

		CheckedListBox^ clbMaterias;

		Button^ btnMatricular;
		Button^ btnVolver;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblNombre = gcnew Label();
			this->lblEdad = gcnew Label();
			this->lblCI = gcnew Label();
			this->lblCarrera = gcnew Label();
			this->lblPeriodo = gcnew Label();
			this->lblMaterias = gcnew Label();

			this->txtNombre = gcnew TextBox();
			this->txtEdad = gcnew TextBox();
			this->txtCI = gcnew TextBox();

			this->cbCarrera = gcnew ComboBox();
			this->cbPeriodo = gcnew ComboBox();

			this->clbMaterias = gcnew CheckedListBox();

			this->btnMatricular = gcnew Button();
			this->btnVolver = gcnew Button();

			this->SuspendLayout();

			this->Text = L"Matricula";
			this->ClientSize = Drawing::Size(700, 500);
			this->StartPosition = FormStartPosition::CenterScreen;

			lblNombre->Text = L"Nombres";
			lblNombre->Location = Point(180, 50);

			txtNombre->Location = Point(270, 50);
			txtNombre->Size = Drawing::Size(180, 28);

			lblEdad->Text = L"Edad";
			lblEdad->Location = Point(180, 90);

			txtEdad->Location = Point(270, 90);
			txtEdad->Size = Drawing::Size(180, 28);

			lblCI->Text = L"CI";
			lblCI->Location = Point(180, 130);

			txtCI->Location = Point(270, 130);
			txtCI->Size = Drawing::Size(180, 28);

			lblCarrera->Text = L"Carrera";
			lblCarrera->Location = Point(180, 170);

			cbCarrera->Location = Point(270, 170);
			cbCarrera->Size = Drawing::Size(180, 28);

			lblPeriodo->Text = L"Periodo";
			lblPeriodo->Location = Point(180, 210);

			cbPeriodo->Location = Point(270, 210);
			cbPeriodo->Size = Drawing::Size(180, 28);

			lblMaterias->Text = L"Materias";
			lblMaterias->Location = Point(180, 250);

			clbMaterias->Location = Point(270, 250);
			clbMaterias->Size = Drawing::Size(180, 90);

			btnMatricular->Text = L"Matricular";
			btnMatricular->Location = Point(500, 380);
			btnMatricular->Size = Drawing::Size(120, 40);
			btnMatricular->Click += gcnew EventHandler(this, &matriculaForm::btnMatricular_Click);

			btnVolver->Text = L"Volver";
			btnVolver->Location = Point(360, 380);
			btnVolver->Size = Drawing::Size(120, 40);
			btnVolver->Click += gcnew EventHandler(this, &matriculaForm::btnVolver_Click);

			this->Controls->Add(lblNombre);
			this->Controls->Add(txtNombre);
			this->Controls->Add(lblEdad);
			this->Controls->Add(txtEdad);
			this->Controls->Add(lblCI);
			this->Controls->Add(txtCI);
			this->Controls->Add(lblCarrera);
			this->Controls->Add(cbCarrera);
			this->Controls->Add(lblPeriodo);
			this->Controls->Add(cbPeriodo);
			this->Controls->Add(lblMaterias);
			this->Controls->Add(clbMaterias);
			this->Controls->Add(btnMatricular);
			this->Controls->Add(btnVolver);

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

		System::Void btnMatricular_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (txtNombre->Text == "" ||
				txtEdad->Text == "" ||
				txtCI->Text == "" ||
				cbCarrera->Text == "" ||
				cbPeriodo->Text == "")
			{
				MessageBox::Show("Llene todos los campos");
				return;
			}

			StringBuilder^ materias = gcnew StringBuilder();

			for each (String ^ item in clbMaterias->CheckedItems)
			{
				materias->Append(item + " | ");
			}

			if (materias->ToString() == "")
			{
				MessageBox::Show("Seleccione materias");
				return;
			}

			StreamWriter^ sw = gcnew StreamWriter("matriculas.txt", true);

			sw->WriteLine(
				txtNombre->Text + "," +
				txtEdad->Text + "," +
				txtCI->Text + "," +
				cbCarrera->Text + "," +
				cbPeriodo->Text + "," +
				materias->ToString()
			);

			sw->Close();

			MessageBox::Show("Matricula guardada correctamente");

			txtNombre->Clear();
			txtEdad->Clear();
			txtCI->Clear();
			cbCarrera->SelectedIndex = -1;
			cbPeriodo->SelectedIndex = -1;

			for (int i = 0; i < clbMaterias->Items->Count; i++)
			{
				clbMaterias->SetItemChecked(i, false);
			}
		}

		System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}
	};
}