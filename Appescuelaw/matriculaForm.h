#pragma once

namespace Appescuelaw {

    using namespace System;
    using namespace System::Text;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class matriculaForm : public System::Windows::Forms::Form
    {
    public:
        matriculaForm(void)
        {
            InitializeComponent();

            comboBox1->Items->Add("Computacion");
            comboBox1->Items->Add("Ing Civil");
            comboBox1->Items->Add("Enfermeria");

            comboBox2->Items->Add("1er Semestre");
            comboBox2->Items->Add("2do Semestre");
            comboBox2->Items->Add("3er Semestre");

            checkedListBox1->Items->Add("Programacion");
            checkedListBox1->Items->Add("Calculo Integral");
            checkedListBox1->Items->Add("Ingles");
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
        System::Windows::Forms::TextBox^ textBox1;
        System::Windows::Forms::TextBox^ textBox2;
        System::Windows::Forms::TextBox^ textBox3;
        System::Windows::Forms::ComboBox^ comboBox1;
        System::Windows::Forms::ComboBox^ comboBox2;
        System::Windows::Forms::CheckedListBox^ checkedListBox1;
        System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(matriculaForm::typeid));
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
            this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(297, 49);
            this->textBox1->Margin = System::Windows::Forms::Padding(2);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(151, 20);
            this->textBox1->TabIndex = 6;
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(297, 83);
            this->textBox2->Margin = System::Windows::Forms::Padding(2);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(151, 20);
            this->textBox2->TabIndex = 5;
            // 
            // textBox3
            // 
            this->textBox3->Location = System::Drawing::Point(297, 116);
            this->textBox3->Margin = System::Windows::Forms::Padding(2);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(151, 20);
            this->textBox3->TabIndex = 4;
            // 
            // comboBox1
            // 
            this->comboBox1->Location = System::Drawing::Point(297, 154);
            this->comboBox1->Margin = System::Windows::Forms::Padding(2);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(151, 21);
            this->comboBox1->TabIndex = 3;
            // 
            // comboBox2
            // 
            this->comboBox2->Location = System::Drawing::Point(297, 197);
            this->comboBox2->Margin = System::Windows::Forms::Padding(2);
            this->comboBox2->Name = L"comboBox2";
            this->comboBox2->Size = System::Drawing::Size(151, 21);
            this->comboBox2->TabIndex = 2;
            // 
            // checkedListBox1
            // 
            this->checkedListBox1->Location = System::Drawing::Point(297, 251);
            this->checkedListBox1->Margin = System::Windows::Forms::Padding(2);
            this->checkedListBox1->Name = L"checkedListBox1";
            this->checkedListBox1->Size = System::Drawing::Size(151, 49);
            this->checkedListBox1->TabIndex = 1;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(549, 372);
            this->button1->Margin = System::Windows::Forms::Padding(2);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(112, 41);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Matricular";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &matriculaForm::button1_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
            this->pictureBox1->Location = System::Drawing::Point(28, 49);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(158, 199);
            this->pictureBox1->TabIndex = 7;
            this->pictureBox1->TabStop = false;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::AliceBlue;
            this->label1->Location = System::Drawing::Point(243, 52);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(49, 13);
            this->label1->TabIndex = 8;
            this->label1->Text = L"Nombres";
            this->label1->Click += gcnew System::EventHandler(this, &matriculaForm::label1_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::AliceBlue;
            this->label2->Location = System::Drawing::Point(260, 86);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(32, 13);
            this->label2->TabIndex = 9;
            this->label2->Text = L"Edad";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::Color::AliceBlue;
            this->label3->Location = System::Drawing::Point(275, 119);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(17, 13);
            this->label3->TabIndex = 10;
            this->label3->Text = L"CI";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::Color::AliceBlue;
            this->label4->Location = System::Drawing::Point(251, 157);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(41, 13);
            this->label4->TabIndex = 11;
            this->label4->Text = L"Carrera";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->BackColor = System::Drawing::Color::AliceBlue;
            this->label5->Location = System::Drawing::Point(243, 200);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(43, 13);
            this->label5->TabIndex = 12;
            this->label5->Text = L"Periodo";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::Color::AliceBlue;
            this->label6->Location = System::Drawing::Point(50, 33);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(111, 13);
            this->label6->TabIndex = 13;
            this->label6->Text = L"Añadir foto tipo carnet";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->BackColor = System::Drawing::Color::AliceBlue;
            this->label7->Location = System::Drawing::Point(237, 251);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(47, 13);
            this->label7->TabIndex = 14;
            this->label7->Text = L"Materias";
            // 
            // matriculaForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LightSteelBlue;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(690, 446);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->checkedListBox1);
            this->Controls->Add(this->comboBox2);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Margin = System::Windows::Forms::Padding(2);
            this->Name = L"matriculaForm";
            this->Text = L"Matricula";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

#pragma endregion

    private:
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ estudiante = textBox1->Text;
            String^ edad = textBox2->Text;
            String^ ci = textBox3->Text;

            String^ carrera = comboBox1->Text;
            String^ periodo = comboBox2->Text;

            StringBuilder^ materias = gcnew StringBuilder();

            for each(String ^ item in checkedListBox1->CheckedItems)
            {
                materias->Append(item + "\n");
            }

            String^ mensaje =
                "ESTUDIANTE: " + estudiante +
                "\nEDAD: " + edad +
                "\nCI: " + ci +
                "\nCARRERA: " + carrera +
                "\nPERIODO: " + periodo +
                "\nMATERIAS:\n" + materias->ToString();

            MessageBox::Show(mensaje, "Matricula Exitosa");
        }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
