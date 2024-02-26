#pragma once

#include "Registration.h"
#include "LogIn.h"
#include <nlohmann/json.hpp>
#include <msclr/marshal_cppstd.h>
#include "Functions.h"

namespace PassManeger {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для LogIn
	/// </summary>
	public ref class LogIn : public System::Windows::Forms::Form
	{
	public:
		LogIn(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~LogIn()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tBoxUserName;
	private: System::Windows::Forms::Button^ bSignIn;
	protected:

	protected:


	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::TextBox^ tBoxPassword;
	private: System::Windows::Forms::Button^ bRegestration;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tBoxUserName = (gcnew System::Windows::Forms::TextBox());
			this->bSignIn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->bRegestration = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// tBoxUserName
			// 
			this->tBoxUserName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tBoxUserName->Location = System::Drawing::Point(39, 53);
			this->tBoxUserName->Multiline = true;
			this->tBoxUserName->Name = L"tBoxUserName";
			this->tBoxUserName->Size = System::Drawing::Size(199, 24);
			this->tBoxUserName->TabIndex = 0;
			this->tBoxUserName->Text = L"User Name";
			// 
			// bSignIn
			// 
			this->bSignIn->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bSignIn->Location = System::Drawing::Point(12, 189);
			this->bSignIn->Name = L"bSignIn";
			this->bSignIn->Size = System::Drawing::Size(250, 39);
			this->bSignIn->TabIndex = 1;
			this->bSignIn->Text = L"Вход";
			this->bSignIn->UseVisualStyleBackColor = true;
			this->bSignIn->Click += gcnew System::EventHandler(this, &LogIn::bSignIn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(26, 287);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 19);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Если Вы новый пользователь";
			// 
			// tBoxPassword
			// 
			this->tBoxPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tBoxPassword->Location = System::Drawing::Point(39, 107);
			this->tBoxPassword->Multiline = true;
			this->tBoxPassword->Name = L"tBoxPassword";
			this->tBoxPassword->Size = System::Drawing::Size(199, 24);
			this->tBoxPassword->TabIndex = 0;
			this->tBoxPassword->Text = L"Password";
			// 
			// bRegestration
			// 
			this->bRegestration->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bRegestration->Location = System::Drawing::Point(12, 309);
			this->bRegestration->Name = L"bRegestration";
			this->bRegestration->Size = System::Drawing::Size(250, 39);
			this->bRegestration->TabIndex = 1;
			this->bRegestration->Text = L"Регистрация";
			this->bRegestration->UseVisualStyleBackColor = true;
			this->bRegestration->Click += gcnew System::EventHandler(this, &LogIn::bRegestration_Click);
			// 
			// LogIn
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(268, 360);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bRegestration);
			this->Controls->Add(this->bSignIn);
			this->Controls->Add(this->tBoxPassword);
			this->Controls->Add(this->tBoxUserName);
			this->MaximumSize = System::Drawing::Size(284, 399);
			this->Name = L"LogIn";
			this->Text = L"LogIn";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/*
	* проверка введнных даннах пользователем
	*/
	private: System::Void bSignIn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ userName = tBoxUserName->Text;
		String^ password = tBoxPassword->Text;

		std::string userName_std = msclr::interop::marshal_as<std::string>(userName);
		std::string password_std = msclr::interop::marshal_as<std::string>(password);

		std::string targetFileName = userName_std + ".json";
		
		LogInTOtheSystem(targetFileName, password_std);
		this->Close();
	
	}
	/*
	перенаправления на окно регистрации 
	если пользователь ошибся и нажал не на ту кнопку на окне WindowMenu
	*/
	private: System::Void bRegestration_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Registration^ regis = gcnew Registration;
		regis->ShowDialog();
	}

};
}
