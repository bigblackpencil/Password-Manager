#pragma once

#include <fstream>
#include <nlohmann/json.hpp>
#include <msclr/marshal_cppstd.h>
#include "Functions.h"

//nlohmann::json User_Data_Array;

namespace PassManeger {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Registration
	/// </summary>
	public ref class Registration : public System::Windows::Forms::Form
	{
	public:
		Registration(void)
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
		~Registration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tBoxPassword;

	protected:

	protected:

	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Button^ bCreateUser;

	private: System::Windows::Forms::TextBox^ tBoxUserName;


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
			this->tBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->bCreateUser = (gcnew System::Windows::Forms::Button());
			this->tBoxUserName = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// tBoxPassword
			// 
			this->tBoxPassword->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tBoxPassword->Location = System::Drawing::Point(75, 100);
			this->tBoxPassword->Name = L"tBoxPassword";
			this->tBoxPassword->Size = System::Drawing::Size(199, 27);
			this->tBoxPassword->TabIndex = 0;
			this->tBoxPassword->Text = L"Password";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(75, 160);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(114, 20);
			this->dateTimePicker1->TabIndex = 1;
			// 
			// bCreateUser
			// 
			this->bCreateUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bCreateUser->Location = System::Drawing::Point(75, 230);
			this->bCreateUser->Name = L"bCreateUser";
			this->bCreateUser->Size = System::Drawing::Size(199, 62);
			this->bCreateUser->TabIndex = 2;
			this->bCreateUser->Text = L"Зарегистрироваться и войти";
			this->bCreateUser->UseVisualStyleBackColor = true;
			this->bCreateUser->Click += gcnew System::EventHandler(this, &Registration::bCreateUser_Click);
			// 
			// tBoxUserName
			// 
			this->tBoxUserName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tBoxUserName->Location = System::Drawing::Point(75, 49);
			this->tBoxUserName->Name = L"tBoxUserName";
			this->tBoxUserName->Size = System::Drawing::Size(199, 26);
			this->tBoxUserName->TabIndex = 0;
			this->tBoxUserName->Text = L"User Name";
			// 
			// Registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(338, 331);
			this->Controls->Add(this->bCreateUser);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->tBoxUserName);
			this->Controls->Add(this->tBoxPassword);
			this->MinimumSize = System::Drawing::Size(354, 370);
			this->Name = L"Registration";
			this->Text = L"Registration";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void bCreateUser_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		System::String^ UserName = tBoxUserName->Text;
		System::String^ Password = tBoxPassword->Text;
		DateTime selectedDate = dateTimePicker1->Value;
		String^ formattedDate = selectedDate.ToString("yyyy-MM-dd");

		std::string DataOfBirth = msclr::interop::marshal_as<std::string>(formattedDate);
		std::string password_std = msclr::interop::marshal_as<std::string>(Password);
		std::string user_name_std = msclr::interop::marshal_as<std::string>(UserName);

		// Получение текущей даты
		DateTime currentDate = DateTime::Now;

		// Вычисление разницы в годах
		int age = currentDate.Year - selectedDate.Year;

		// Проверка, нужно ли скорректировать возраст на основе месяца и дня рождения
		if (currentDate.Month < selectedDate.Month || (currentDate.Month == selectedDate.Month && currentDate.Day < selectedDate.Day))
		{
			age--;
		}

		nlohmann::json UserData =
		{
			{"User_name_for_enter_in_the_programm",		user_name_std},
			{"Password_for_enter_in_the_programm",		password_std},
			{"Age",										age},
			{"Data_Of_birth",							DataOfBirth},
		};

		User_Data_Array.push_back(UserData);

		CreateJsonFile(user_name_std, password_std, DataOfBirth, age, User_Data_Array);
	}

};
}
