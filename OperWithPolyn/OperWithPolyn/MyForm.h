#pragma once

namespace OperWithPolyn {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  EXT_BUT;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->EXT_BUT = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// EXT_BUT
			// 
			this->EXT_BUT->Location = System::Drawing::Point(569, 343);
			this->EXT_BUT->Name = L"EXT_BUT";
			this->EXT_BUT->Size = System::Drawing::Size(75, 23);
			this->EXT_BUT->TabIndex = 0;
			this->EXT_BUT->Text = L"Exit";
			this->EXT_BUT->UseVisualStyleBackColor = true;
			this->EXT_BUT->Click += gcnew System::EventHandler(this, &MyForm::EXT_BUT_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(656, 378);
			this->Controls->Add(this->EXT_BUT);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Operations with Polynomials";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void EXT_BUT_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }
	};
}
