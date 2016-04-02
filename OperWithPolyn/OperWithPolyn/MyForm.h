#pragma once

#include "Polynomial.h"

namespace OperWithPolyn {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Polynomial *P; // Полином P
	Polynomial *Q; // Полином Q
	int maxCount; // Максимальное количество переменных
	int maxPower; // Максимальная степень

	string SystemToStl(String ^s) // Перевод типа String ^ в тип string
	{
		using namespace Runtime::InteropServices;
		const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		return string(ptr);
	};

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  EXT_BUT;
	private: System::Windows::Forms::TextBox^  MAXCOUNT_TXTBOX;
	private: System::Windows::Forms::TextBox^  MAXPOWER_TXTBOX;
	private: System::Windows::Forms::Button^  INPUT_BUT;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  RESULT_TXTBOX;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  POLY_P;
	private: System::Windows::Forms::TextBox^  POLY_Q;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  ADD_MON_P;
	private: System::Windows::Forms::TextBox^  ADD_MON_Q;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  ADD_P_BUT;
	private: System::Windows::Forms::Button^  ADD_Q_BUT;
	private: System::Windows::Forms::Button^  ADDITION_BUT;
	private: System::Windows::Forms::Button^  SUBTRACTION_BUT;
	private: System::Windows::Forms::Button^  MULT_BUT;
	private: System::Windows::Forms::Button^  MULT_K_BUT;
	private: System::Windows::Forms::TextBox^  K_TXTBOX;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	protected: 

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->EXT_BUT = (gcnew System::Windows::Forms::Button());
			this->MAXCOUNT_TXTBOX = (gcnew System::Windows::Forms::TextBox());
			this->MAXPOWER_TXTBOX = (gcnew System::Windows::Forms::TextBox());
			this->INPUT_BUT = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->RESULT_TXTBOX = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->POLY_P = (gcnew System::Windows::Forms::TextBox());
			this->POLY_Q = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->ADD_MON_P = (gcnew System::Windows::Forms::TextBox());
			this->ADD_MON_Q = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->ADD_P_BUT = (gcnew System::Windows::Forms::Button());
			this->ADD_Q_BUT = (gcnew System::Windows::Forms::Button());
			this->ADDITION_BUT = (gcnew System::Windows::Forms::Button());
			this->SUBTRACTION_BUT = (gcnew System::Windows::Forms::Button());
			this->MULT_BUT = (gcnew System::Windows::Forms::Button());
			this->MULT_K_BUT = (gcnew System::Windows::Forms::Button());
			this->K_TXTBOX = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// EXT_BUT
			// 
			this->EXT_BUT->Location = System::Drawing::Point(562, 263);
			this->EXT_BUT->Name = L"EXT_BUT";
			this->EXT_BUT->Size = System::Drawing::Size(75, 23);
			this->EXT_BUT->TabIndex = 14;
			this->EXT_BUT->Text = L"Выход";
			this->EXT_BUT->UseVisualStyleBackColor = true;
			this->EXT_BUT->Click += gcnew System::EventHandler(this, &MyForm::EXT_BUT_Click);
			// 
			// MAXCOUNT_TXTBOX
			// 
			this->MAXCOUNT_TXTBOX->Location = System::Drawing::Point(210, 27);
			this->MAXCOUNT_TXTBOX->Name = L"MAXCOUNT_TXTBOX";
			this->MAXCOUNT_TXTBOX->Size = System::Drawing::Size(52, 20);
			this->MAXCOUNT_TXTBOX->TabIndex = 1;
			// 
			// MAXPOWER_TXTBOX
			// 
			this->MAXPOWER_TXTBOX->Location = System::Drawing::Point(418, 27);
			this->MAXPOWER_TXTBOX->Name = L"MAXPOWER_TXTBOX";
			this->MAXPOWER_TXTBOX->Size = System::Drawing::Size(52, 20);
			this->MAXPOWER_TXTBOX->TabIndex = 2;
			// 
			// INPUT_BUT
			// 
			this->INPUT_BUT->Location = System::Drawing::Point(506, 25);
			this->INPUT_BUT->Name = L"INPUT_BUT";
			this->INPUT_BUT->Size = System::Drawing::Size(84, 23);
			this->INPUT_BUT->TabIndex = 3;
			this->INPUT_BUT->Text = L"Ввести";
			this->INPUT_BUT->UseVisualStyleBackColor = true;
			this->INPUT_BUT->Click += gcnew System::EventHandler(this, &MyForm::INPUT_BUT_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(179, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Введите количество переменных:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(272, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(140, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"и максимальную степень:";
			// 
			// RESULT_TXTBOX
			// 
			this->RESULT_TXTBOX->Location = System::Drawing::Point(28, 265);
			this->RESULT_TXTBOX->Name = L"RESULT_TXTBOX";
			this->RESULT_TXTBOX->ReadOnly = true;
			this->RESULT_TXTBOX->Size = System::Drawing::Size(526, 20);
			this->RESULT_TXTBOX->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 249);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(204, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Результат сложения полиномов P и Q:";
			// 
			// POLY_P
			// 
			this->POLY_P->Location = System::Drawing::Point(28, 105);
			this->POLY_P->Name = L"POLY_P";
			this->POLY_P->Size = System::Drawing::Size(384, 20);
			this->POLY_P->TabIndex = 4;
			// 
			// POLY_Q
			// 
			this->POLY_Q->Location = System::Drawing::Point(28, 155);
			this->POLY_Q->Name = L"POLY_Q";
			this->POLY_Q->Size = System::Drawing::Size(384, 20);
			this->POLY_Q->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(25, 89);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Введите полином P:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 139);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(110, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Введите полином Q:";
			// 
			// ADD_MON_P
			// 
			this->ADD_MON_P->Location = System::Drawing::Point(437, 105);
			this->ADD_MON_P->Name = L"ADD_MON_P";
			this->ADD_MON_P->Size = System::Drawing::Size(119, 20);
			this->ADD_MON_P->TabIndex = 6;
			// 
			// ADD_MON_Q
			// 
			this->ADD_MON_Q->Location = System::Drawing::Point(437, 155);
			this->ADD_MON_Q->Name = L"ADD_MON_Q";
			this->ADD_MON_Q->Size = System::Drawing::Size(117, 20);
			this->ADD_MON_Q->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(434, 89);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(121, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Приписать моном к P:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(434, 139);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(122, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Приписать моном к Q:";
			// 
			// ADD_P_BUT
			// 
			this->ADD_P_BUT->Location = System::Drawing::Point(562, 103);
			this->ADD_P_BUT->Name = L"ADD_P_BUT";
			this->ADD_P_BUT->Size = System::Drawing::Size(75, 23);
			this->ADD_P_BUT->TabIndex = 7;
			this->ADD_P_BUT->Text = L"Добавить";
			this->ADD_P_BUT->UseVisualStyleBackColor = true;
			this->ADD_P_BUT->Click += gcnew System::EventHandler(this, &MyForm::ADD_P_BUT_Click);
			// 
			// ADD_Q_BUT
			// 
			this->ADD_Q_BUT->Location = System::Drawing::Point(560, 153);
			this->ADD_Q_BUT->Name = L"ADD_Q_BUT";
			this->ADD_Q_BUT->Size = System::Drawing::Size(75, 23);
			this->ADD_Q_BUT->TabIndex = 9;
			this->ADD_Q_BUT->Text = L"Добавить";
			this->ADD_Q_BUT->UseVisualStyleBackColor = true;
			this->ADD_Q_BUT->Click += gcnew System::EventHandler(this, &MyForm::ADD_Q_BUT_Click);
			// 
			// ADDITION_BUT
			// 
			this->ADDITION_BUT->Location = System::Drawing::Point(28, 203);
			this->ADDITION_BUT->Name = L"ADDITION_BUT";
			this->ADDITION_BUT->Size = System::Drawing::Size(120, 23);
			this->ADDITION_BUT->TabIndex = 10;
			this->ADDITION_BUT->Text = L"P + Q";
			this->ADDITION_BUT->UseVisualStyleBackColor = true;
			this->ADDITION_BUT->Click += gcnew System::EventHandler(this, &MyForm::ADDITION_BUT_Click);
			// 
			// SUBTRACTION_BUT
			// 
			this->SUBTRACTION_BUT->Location = System::Drawing::Point(154, 203);
			this->SUBTRACTION_BUT->Name = L"SUBTRACTION_BUT";
			this->SUBTRACTION_BUT->Size = System::Drawing::Size(120, 23);
			this->SUBTRACTION_BUT->TabIndex = 11;
			this->SUBTRACTION_BUT->Text = L"P - Q";
			this->SUBTRACTION_BUT->UseVisualStyleBackColor = true;
			this->SUBTRACTION_BUT->Click += gcnew System::EventHandler(this, &MyForm::SUBTRACTION_BUT_Click);
			// 
			// MULT_BUT
			// 
			this->MULT_BUT->Location = System::Drawing::Point(280, 203);
			this->MULT_BUT->Name = L"MULT_BUT";
			this->MULT_BUT->Size = System::Drawing::Size(120, 23);
			this->MULT_BUT->TabIndex = 12;
			this->MULT_BUT->Text = L"P * Q";
			this->MULT_BUT->UseVisualStyleBackColor = true;
			this->MULT_BUT->Click += gcnew System::EventHandler(this, &MyForm::MULT_BUT_Click);
			// 
			// MULT_K_BUT
			// 
			this->MULT_K_BUT->Location = System::Drawing::Point(406, 203);
			this->MULT_K_BUT->Name = L"MULT_K_BUT";
			this->MULT_K_BUT->Size = System::Drawing::Size(120, 23);
			this->MULT_K_BUT->TabIndex = 14;
			this->MULT_K_BUT->Text = L"P * k";
			this->MULT_K_BUT->UseVisualStyleBackColor = true;
			this->MULT_K_BUT->Click += gcnew System::EventHandler(this, &MyForm::MULT_K_BUT_Click);
			// 
			// K_TXTBOX
			// 
			this->K_TXTBOX->Location = System::Drawing::Point(579, 205);
			this->K_TXTBOX->Name = L"K_TXTBOX";
			this->K_TXTBOX->Size = System::Drawing::Size(44, 20);
			this->K_TXTBOX->TabIndex = 13;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(551, 208);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(22, 13);
			this->label8->TabIndex = 23;
			this->label8->Text = L"k =";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(25, 249);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(261, 13);
			this->label9->TabIndex = 24;
			this->label9->Text = L"Результат вычитания из полинома P полинома Q:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(25, 249);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(211, 13);
			this->label10->TabIndex = 25;
			this->label10->Text = L"Результат умножения полиномов P и Q:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(25, 249);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(241, 13);
			this->label11->TabIndex = 26;
			this->label11->Text = L"Результат умножения полинома P на число k:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(660, 303);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->K_TXTBOX);
			this->Controls->Add(this->MULT_K_BUT);
			this->Controls->Add(this->MULT_BUT);
			this->Controls->Add(this->SUBTRACTION_BUT);
			this->Controls->Add(this->ADDITION_BUT);
			this->Controls->Add(this->ADD_Q_BUT);
			this->Controls->Add(this->ADD_P_BUT);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->ADD_MON_Q);
			this->Controls->Add(this->ADD_MON_P);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->POLY_Q);
			this->Controls->Add(this->POLY_P);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->RESULT_TXTBOX);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->INPUT_BUT);
			this->Controls->Add(this->MAXPOWER_TXTBOX);
			this->Controls->Add(this->MAXCOUNT_TXTBOX);
			this->Controls->Add(this->EXT_BUT);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Операции над полиномами";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EXT_BUT_Click(System::Object^  sender, System::EventArgs^  e) {
				Close();
			 }
	private: System::Void INPUT_BUT_Click(System::Object^  sender, System::EventArgs^  e) {
				Graphics^ g = CreateGraphics();
				g->DrawLine(Pens::LightGray, 0, 70, ClientSize.Width, 70);
				ClientSize = Drawing::Size(ClientSize.Width, 303);
				if (MAXCOUNT_TXTBOX->Text != "")
					maxCount = Convert::ToInt32(MAXCOUNT_TXTBOX->Text);
				else
					maxCount = 0;
				if (MAXPOWER_TXTBOX->Text != "")
					maxPower = Convert::ToInt32(MAXPOWER_TXTBOX->Text);
				else
					maxPower = 0;
				P = new Polynomial("", maxCount, maxPower);
				Q = new Polynomial("", maxCount, maxPower);
			 }
private: System::Void ADD_P_BUT_Click(System::Object^  sender, System::EventArgs^  e) {
			 delete P;
			 string strPol = SystemToStl(POLY_P->Text);
			 P = new Polynomial(strPol, maxCount, maxPower);
			 string strMonomial = SystemToStl(ADD_MON_P->Text);
			 P->Input(strMonomial);
			 POLY_P->Text = gcnew System::String(P->Output().c_str());
		 }
private: System::Void ADD_Q_BUT_Click(System::Object^  sender, System::EventArgs^  e) {
			 delete Q;
			 string strPol = SystemToStl(POLY_P->Text);
			 Q = new Polynomial(strPol, maxCount, maxPower);
			 string strMonomial = SystemToStl(ADD_MON_Q->Text);
			 Q->Input(strMonomial);
			 POLY_Q->Text = gcnew System::String(Q->Output().c_str());
		 }
private: System::Void ADDITION_BUT_Click(System::Object^  sender, System::EventArgs^  e) {
			 label3->Visible = true;
			 label9->Visible = false;
			 label10->Visible = false;
			 label11->Visible = false;
			 delete P;
			 delete Q;
			 string strPolP = SystemToStl(POLY_P->Text);
			 string strPolQ = SystemToStl(POLY_Q->Text);
			 P = new Polynomial(strPolP, maxCount, maxPower);
			 Q = new Polynomial(strPolQ, maxCount, maxPower);
			 Polynomial A("", maxCount, maxPower);
			 A = *P + *Q;
			 RESULT_TXTBOX->Text = gcnew System::String(A.Output().c_str());

		 }
private: System::Void SUBTRACTION_BUT_Click(System::Object^  sender, System::EventArgs^  e) {
			 label3->Visible = false;
			 label9->Visible = true;
			 label10->Visible = false;
			 label11->Visible = false;
		 }
private: System::Void MULT_BUT_Click(System::Object^  sender, System::EventArgs^  e) {
			 label3->Visible = false;
			 label9->Visible = false;
			 label10->Visible = true;
			 label11->Visible = false;
		 }
private: System::Void MULT_K_BUT_Click(System::Object^  sender, System::EventArgs^  e) {
			 label3->Visible = false;
			 label9->Visible = false;
			 label10->Visible = false;
			 label11->Visible = true;
		 }
};
}
