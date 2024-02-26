#pragma once

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
	/// Сводка для MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
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
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::Button^ bHelp;
	private: System::Windows::Forms::Button^ bAddNew;
	private: System::Windows::Forms::Button^ bShowData;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tBoxAnother;
	private: System::Windows::Forms::TextBox^ tBoxNumber;
	private: System::Windows::Forms::TextBox^ tBoxLink;
	private: System::Windows::Forms::TextBox^ tBoxPassword;
	private: System::Windows::Forms::TextBox^ tBoxNameUser;
	private: System::Windows::Forms::TextBox^ tBoxNameSocNet;
	private: System::Windows::Forms::Button^ bGoToLink;
	private: System::Windows::Forms::Label^ label6;
	protected:

	protected:

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
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->bHelp = (gcnew System::Windows::Forms::Button());
			this->bAddNew = (gcnew System::Windows::Forms::Button());
			this->bShowData = (gcnew System::Windows::Forms::Button());
			this->tBoxAnother = (gcnew System::Windows::Forms::TextBox());
			this->tBoxNumber = (gcnew System::Windows::Forms::TextBox());
			this->tBoxLink = (gcnew System::Windows::Forms::TextBox());
			this->tBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->tBoxNameUser = (gcnew System::Windows::Forms::TextBox());
			this->tBoxNameSocNet = (gcnew System::Windows::Forms::TextBox());
			this->bGoToLink = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->bHelp);
			this->splitContainer1->Panel1->Controls->Add(this->bAddNew);
			this->splitContainer1->Panel1->Controls->Add(this->bShowData);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->tBoxAnother);
			this->splitContainer1->Panel2->Controls->Add(this->tBoxNumber);
			this->splitContainer1->Panel2->Controls->Add(this->tBoxLink);
			this->splitContainer1->Panel2->Controls->Add(this->tBoxPassword);
			this->splitContainer1->Panel2->Controls->Add(this->tBoxNameUser);
			this->splitContainer1->Panel2->Controls->Add(this->tBoxNameSocNet);
			this->splitContainer1->Panel2->Controls->Add(this->bGoToLink);
			this->splitContainer1->Panel2->Controls->Add(this->label6);
			this->splitContainer1->Panel2->Controls->Add(this->label5);
			this->splitContainer1->Panel2->Controls->Add(this->label4);
			this->splitContainer1->Panel2->Controls->Add(this->label3);
			this->splitContainer1->Panel2->Controls->Add(this->label2);
			this->splitContainer1->Panel2->Controls->Add(this->label1);
			this->splitContainer1->Size = System::Drawing::Size(846, 434);
			this->splitContainer1->SplitterDistance = 253;
			this->splitContainer1->TabIndex = 0;
			// 
			// bHelp
			// 
			this->bHelp->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bHelp->Location = System::Drawing::Point(57, 270);
			this->bHelp->Name = L"bHelp";
			this->bHelp->Size = System::Drawing::Size(148, 49);
			this->bHelp->TabIndex = 1;
			this->bHelp->Text = L"О приложении";
			this->bHelp->UseVisualStyleBackColor = true;
			this->bHelp->Click += gcnew System::EventHandler(this, &MainWindow::bHelp_Click);
			// 
			// bAddNew
			// 
			this->bAddNew->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bAddNew->Location = System::Drawing::Point(57, 174);
			this->bAddNew->Name = L"bAddNew";
			this->bAddNew->Size = System::Drawing::Size(148, 49);
			this->bAddNew->TabIndex = 1;
			this->bAddNew->Text = L"Добавить новые";
			this->bAddNew->UseVisualStyleBackColor = true;
			this->bAddNew->Click += gcnew System::EventHandler(this, &MainWindow::bAddNew_Click);
			// 
			// bShowData
			// 
			this->bShowData->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bShowData->Location = System::Drawing::Point(57, 68);
			this->bShowData->Name = L"bShowData";
			this->bShowData->Size = System::Drawing::Size(148, 49);
			this->bShowData->TabIndex = 0;
			this->bShowData->Text = L"Показать личные данные";
			this->bShowData->UseVisualStyleBackColor = true;
			this->bShowData->Click += gcnew System::EventHandler(this, &MainWindow::bShowData_Click);
			// 
			// tBoxAnother
			// 
			this->tBoxAnother->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tBoxAnother->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tBoxAnother->Location = System::Drawing::Point(225, 310);
			this->tBoxAnother->Multiline = true;
			this->tBoxAnother->Name = L"tBoxAnother";
			this->tBoxAnother->Size = System::Drawing::Size(275, 26);
			this->tBoxAnother->TabIndex = 7;
			// 
			// tBoxNumber
			// 
			this->tBoxNumber->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tBoxNumber->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tBoxNumber->Location = System::Drawing::Point(225, 262);
			this->tBoxNumber->Multiline = true;
			this->tBoxNumber->Name = L"tBoxNumber";
			this->tBoxNumber->Size = System::Drawing::Size(275, 26);
			this->tBoxNumber->TabIndex = 7;
			// 
			// tBoxLink
			// 
			this->tBoxLink->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tBoxLink->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tBoxLink->Location = System::Drawing::Point(225, 214);
			this->tBoxLink->Multiline = true;
			this->tBoxLink->Name = L"tBoxLink";
			this->tBoxLink->Size = System::Drawing::Size(275, 26);
			this->tBoxLink->TabIndex = 7;
			// 
			// tBoxPassword
			// 
			this->tBoxPassword->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tBoxPassword->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tBoxPassword->Location = System::Drawing::Point(225, 166);
			this->tBoxPassword->Multiline = true;
			this->tBoxPassword->Name = L"tBoxPassword";
			this->tBoxPassword->Size = System::Drawing::Size(275, 26);
			this->tBoxPassword->TabIndex = 7;
			// 
			// tBoxNameUser
			// 
			this->tBoxNameUser->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tBoxNameUser->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tBoxNameUser->Location = System::Drawing::Point(225, 118);
			this->tBoxNameUser->Multiline = true;
			this->tBoxNameUser->Name = L"tBoxNameUser";
			this->tBoxNameUser->Size = System::Drawing::Size(275, 26);
			this->tBoxNameUser->TabIndex = 7;
			// 
			// tBoxNameSocNet
			// 
			this->tBoxNameSocNet->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tBoxNameSocNet->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tBoxNameSocNet->Location = System::Drawing::Point(225, 60);
			this->tBoxNameSocNet->Multiline = true;
			this->tBoxNameSocNet->Name = L"tBoxNameSocNet";
			this->tBoxNameSocNet->Size = System::Drawing::Size(275, 26);
			this->tBoxNameSocNet->TabIndex = 7;
			// 
			// bGoToLink
			// 
			this->bGoToLink->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bGoToLink->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bGoToLink->Location = System::Drawing::Point(486, 385);
			this->bGoToLink->Name = L"bGoToLink";
			this->bGoToLink->Size = System::Drawing::Size(91, 37);
			this->bGoToLink->TabIndex = 6;
			this->bGoToLink->Text = L"Поехали";
			this->bGoToLink->UseVisualStyleBackColor = true;
			this->bGoToLink->Click += gcnew System::EventHandler(this, &MainWindow::bGoToLink_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(31, 318);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(148, 18);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Другая информация";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(31, 270);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(125, 18);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Номер телефона";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(31, 222);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(118, 18);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Ссылка на сайт";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(31, 174);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 18);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Пароль";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(31, 126);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(136, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Имя пользователя";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(31, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Соцсеть/сеть";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(846, 434);
			this->Controls->Add(this->splitContainer1);
			this->MaximumSize = System::Drawing::Size(862, 473);
			this->MinimumSize = System::Drawing::Size(862, 473);
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"  Данные пользователя/добавление новых записей";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void bAddNew_Click(System::Object^ sender, System::EventArgs^ e) 
{
	String^ NameSocNet = tBoxNameSocNet->Text;
	String^ NameUser = tBoxNameUser->Text;
	String^ Password = tBoxPassword->Text;
	String^ LinkOnSite = tBoxLink->Text;
	String^ Number = tBoxNumber->Text;
	String^ Another = tBoxAnother->Text;

	std::string userName_std = msclr::interop::marshal_as<std::string>(NameUser);
	std::string password_std = msclr::interop::marshal_as<std::string>(Password);
	std::string NameSocNet_std = msclr::interop::marshal_as<std::string>(NameSocNet);
	std::string LinkOnSite_std = msclr::interop::marshal_as<std::string>(LinkOnSite);
	std::string Number_std = msclr::interop::marshal_as<std::string>(Number);
	std::string Another_std = msclr::interop::marshal_as<std::string>(Another);

	std::vector<std::string> UserInfo = { NameSocNet_std, userName_std, password_std, LinkOnSite_std, Number_std, Another_std };

	if (userName_std.empty() || password_std.empty() || NameSocNet_std.empty() || containsWhitespace(userName_std) || containsWhitespace(password_std) || containsWhitespace(NameSocNet_std)) /////////разделить вывод предупреждения какое именно поле не заполнено 
	{
		MessageBox::Show("Имя пользователя(пароль) неккоректны!\nИмя пользователя(пароль) не должны содержать пробелом и переводов строки.");
	}
	else
	{
		AddNewInfo(UserInfo);
	}
}

private: System::Void bShowData_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Space::List<Space::String^>^ DataFromFields = gcnew Space::List<Space::String^>();

	String^ Social_Net = tBoxNameSocNet->Text;
	std::string social_net_std = msclr::interop::marshal_as<std::string>(Social_Net);

	DataFromFields = ShowPrivateData(social_net_std);

		// Добавьте код для записи значения в TextBox
	tBoxNameUser->Text += DataFromFields[5] + Environment::NewLine;
	tBoxPassword->Text += DataFromFields[2] + Environment::NewLine;
	tBoxLink	->Text += DataFromFields[4] + Environment::NewLine;
	tBoxNumber  ->Text += DataFromFields[1] + Environment::NewLine;
	tBoxAnother ->Text += DataFromFields[0] + Environment::NewLine;


	
}

private: System::Void bHelp_Click(System::Object^ sender, System::EventArgs^ e) 
{
	/*
	* что-то написать о приложении
	*/
}

private: System::Void bGoToLink_Click(System::Object^ sender, System::EventArgs^ e) 
{
	/*
	переходить по ссылке которую оставил пользователь в tBoxLink
	*/
}
};
}
