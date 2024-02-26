#pragma once

#include "Registration.h"
#include "LogIn.h"

namespace PassManeger {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ WindowMenu
	/// </summary>
	public ref class WindowMenu : public System::Windows::Forms::Form
	{
	public:
		WindowMenu(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~WindowMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ bSignIn;
	private: System::Windows::Forms::Button^ bRegistration;
	private: System::Windows::Forms::Label^ label1;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bSignIn = (gcnew System::Windows::Forms::Button());
			this->bRegistration = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// bSignIn
			// 
			this->bSignIn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bSignIn->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bSignIn->Location = System::Drawing::Point(224, 70);
			this->bSignIn->Name = L"bSignIn";
			this->bSignIn->Size = System::Drawing::Size(133, 36);
			this->bSignIn->TabIndex = 1;
			this->bSignIn->Text = L"¬ход";
			this->bSignIn->UseVisualStyleBackColor = true;
			this->bSignIn->Click += gcnew System::EventHandler(this, &WindowMenu::bSignIn_Click);
			// 
			// bRegistration
			// 
			this->bRegistration->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bRegistration->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bRegistration->Location = System::Drawing::Point(224, 207);
			this->bRegistration->Name = L"bRegistration";
			this->bRegistration->Size = System::Drawing::Size(133, 36);
			this->bRegistration->TabIndex = 2;
			this->bRegistration->Text = L"–егистраци€";
			this->bRegistration->UseVisualStyleBackColor = true;
			this->bRegistration->Click += gcnew System::EventHandler(this, &WindowMenu::bRegistration_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(227, 161);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 36);
			this->label1->TabIndex = 3;
			this->label1->Text = L"ƒл€ новых\nпользователей:";
			// 
			// WindowMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(369, 336);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bRegistration);
			this->Controls->Add(this->bSignIn);
			this->MinimumSize = System::Drawing::Size(385, 375);
			this->Name = L"WindowMenu";
			this->Text = L"WindowMenu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bSignIn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//this->Hide();
		LogIn^ login = gcnew LogIn;
		login->ShowDialog();

	}
	private: System::Void bRegistration_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Registration^ regis = gcnew Registration;
		regis->ShowDialog();
	}

};
}
