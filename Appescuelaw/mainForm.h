#pragma once
#include "loginForm.h"

namespace Appescuelaw {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class mainForm : public System::Windows::Forms::Form
    {
    public:
        mainForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~mainForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::PictureBox^ pictureBox1;

    protected:
    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(mainForm::typeid));
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(675, 399);
            this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(112, 41);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Continuar";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &mainForm::button1_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::AliceBlue;
            this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36));
            this->label1->Location = System::Drawing::Point(218, 9);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(354, 55);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Escuela chiquitos";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::AliceBlue;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(223, 415);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(330, 25);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Wladimir Gadiel Sandoval Vinces";
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
            this->pictureBox1->Location = System::Drawing::Point(248, 139);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(306, 164);
            this->pictureBox1->TabIndex = 3;
            this->pictureBox1->TabStop = false;
            // 
            // mainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LightSteelBlue;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(798, 447);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button1);
            this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->Name = L"mainForm";
            this->Text = L"MyForm1";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

#pragma endregion

    private:
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
        {
            loginForm^ login = gcnew loginForm();
            login->Show();
            this->Hide();
        }
    };
}