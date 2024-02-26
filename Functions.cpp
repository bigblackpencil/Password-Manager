#include "Functions.h"
#include <Windows.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <filesystem>
#include "MainWindow.h"
#include <cctype> // ��� ������������� isspace


std::string FILENAME;
nlohmann::json User_Data_Array;
const std::string PATH_TO_DIRECTORY = "C:\\Password Maneger\\";

/*
�������� ���������� ��� ����� ��������� ���������� � �������������
!!!!!!!
��������: �������� ������������� ���������� � ���������� ����������� �� �����
!!!!!!!
*/
void CreateFolder()
{
	std::wstring path = TEXT("C:\\Password Maneger\\");

	if (!CreateDirectory(path.c_str(), NULL))
	{
		return;
	}
}

/*
�������� json-����� � ��� ����� ��������� ���������� � ������������ ��� �����������
*/
void CreateJsonFile(std::string UserName, std::string Password, std::string DataOfBirth, int age, nlohmann::json& User_Data_Array)               ////////////////////�������� ����� ������
{
	std::string file_name = UserName + ".json";
	//FILENAME = msclr::interop::marshal_as<std::string>(file_name);
	std::string file_path = PATH_TO_DIRECTORY + file_name;

	// ������ JSON-������ � ����
	std::ofstream file(file_path);
	if (file.is_open())
	{
		file << User_Data_Array.dump(4);  // dump(4) ��� ��������� �������������� � ���������
		file.close();
		System::Windows::Forms::MessageBox::Show("������������ ������� ������.", "�����!");
	}
	else
	{
		System::Windows::Forms::MessageBox::Show("��� ����������� ������� ����.", "������!");
	}
}


/*
* �������� ��������� ������ ������������ � ����� ������������ �������� ������
*/
void LogInTOtheSystem(std::string targetFileName, std::string password_std)
{
	bool CheckUser = false;

	FILENAME = targetFileName;

	for (const auto& entry : std::filesystem::directory_iterator(PATH_TO_DIRECTORY))
	{
		if (entry.is_regular_file()) {  // ���������, ��� ��� ������� ����, � �� ����������
			std::string currentFileName = entry.path().filename().string();

			if (currentFileName == targetFileName)
			{
				CheckUser = true;
				CheckPasswordUser(password_std, PATH_TO_DIRECTORY + targetFileName);           /////////////correct///////////////////////
			}
		}
	}
	if (!CheckUser)
	{
		System::Windows::Forms::MessageBox::Show("������������ �� ������");
	}
}
	
/*
* �������� ��������� ������ �������������
*/
void CheckPasswordUser(std::string password_std, std::string fullPath)
{
	// ��������� JSON ����
	std::ifstream jsonFile(fullPath);
	if (!jsonFile.is_open()) 
	{
		System::Windows::Forms::MessageBox::Show("������ � ��������� �����: " + gcnew System::String(fullPath.c_str()));
	}

	// ������ JSON �� �����
	nlohmann::json jsonData;

	try 
	{
		jsonFile >> jsonData;
	}
	catch (const nlohmann::json::parse_error& e)
	{
		System::Windows::Forms::MessageBox::Show("������ � ��������� �����: " + gcnew System::String(fullPath.c_str()));
	}

	// ��������� ����, ��� ��� �� ������ ��� �� ����������
	jsonFile.close();

	std::string fieldName = "Password_for_enter_in_the_programm";
	std::string targetValue = password_std;	

		if (jsonData[0][fieldName] == targetValue) 
		{
			//System::Windows::Forms::MessageBox::Show("!!!!!!!!!!!!!!" );
			/*
			�������� ���� ��� ����� �������� ���� ����� ���� �������� �����
			*/
			PassManeger::MainWindow^ mainwin = gcnew PassManeger::MainWindow;
			mainwin->Show();
		}
		else 
		{
			System::Windows::Forms::MessageBox::Show("��������� ����� ��� ������.");
		}
}

/*
* �������� ��� ������������ �� ���� � ���� ��������������� � ������ ������ ��� enter
*/
bool containsWhitespace(const std::string& str)
{
	for (char ch : str) {
		// �������� �� ������ ��� ������� ������
		if (std::isspace(static_cast<unsigned char>(ch))) {
			return true; // ���� ������ ������ ��� ������� ������, ���������� true
		}
	}
	return false; // ���� �������� ��� ��������� ������ ���, ���������� false
}

/*
* ���������� ����� ������
*/
void AddNewInfo(const std::vector<std::string>& UserInfo)
{
	std::string path = PATH_TO_DIRECTORY + FILENAME;

	std::ifstream inputFile(path); 
	nlohmann::json User_Full_Data;

	if (inputFile.is_open()) 
	{
		inputFile >> User_Full_Data;
	}
	else 
	{
		System::Windows::Forms::MessageBox::Show("��������� ��������� ����!");
	}

	nlohmann::json User_Data_Private = 
	{
		{"Social_network(site)_" + UserInfo[0],						 UserInfo[0]},
		{"User_name_for_the_social_network(site)_" + UserInfo[0],	 UserInfo[1]},
		{"Password_for_the_social_network(site)_" + UserInfo[0],	 UserInfo[2]},
		{"URL_" + UserInfo[0],										 UserInfo[3]},
		{"Number_" + UserInfo[0],									 UserInfo[4]},
		{"Another_" + UserInfo[0],									 UserInfo[5]}
	};

	User_Full_Data.push_back(User_Data_Private);
	inputFile.close();

	// 3. ������ ����������� JSON � ����
	std::ofstream outputFile(path);
	if (outputFile.is_open()) {
		outputFile << User_Full_Data.dump(4);  // dump(4) ��� ��������� �������������� � ���������
		outputFile.close();
		System::Windows::Forms::MessageBox::Show("������ ��������. �����!");
	}
	else
	{
		System::Windows::Forms::MessageBox::Show("��������� �������� � ����!");
	}
}

Space::List<Space::String^>^ ShowPrivateData(std::string& social_net_std)
{
	Space::List<Space::String^>^ DataFromFields = gcnew Space::List<Space::String^>();

	std::ifstream inputFile(PATH_TO_DIRECTORY + FILENAME);
	nlohmann::json UserData;

	if (inputFile.is_open())
	{
		inputFile >> UserData;
		inputFile.close();
	}
	else
	{
		System::Windows::Forms::MessageBox::Show("���������� ��������� ����!");
		return DataFromFields;  // ������ ������ ������, ��� ��� ������ ����� �� �������
	}

	// ����� ������� �� ����
	nlohmann::json foundObject;

	for (const auto& object : UserData)
	{
		if (object.find("Social_network(site)_" + social_net_std) != object.end())
		{
			foundObject = object;
			break;
		}
	}

	if (foundObject.empty())
	{
		System::Windows::Forms::MessageBox::Show("������ �� ������!");
		return DataFromFields;  // ������ ������ ������, ��� ��� ������ �� ������
	}

	// ���������� �� ���� ������ ������� � ��������� �� � ������
	for (auto it = foundObject.begin(); it != foundObject.end(); ++it)
	{
		if (!it.value().is_null())
		{
			Space::String^ fieldValue = gcnew Space::String((it.value().dump(0)).c_str());
			if (fieldValue->Length > 1)
			{
				// ������� ���������, �������� ������ � ��������� ������
				fieldValue = fieldValue->Substring(1, fieldValue->Length - 2);
			}
			DataFromFields->Add(fieldValue);
		}
	}

	return DataFromFields;
}



