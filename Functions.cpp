#include "Functions.h"
#include <Windows.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <filesystem>
#include "MainWindow.h"
#include <cctype> // Для использования isspace


std::string FILENAME;
nlohmann::json User_Data_Array;
const std::string PATH_TO_DIRECTORY = "C:\\Password Maneger\\";

/*
создание директории где будет храниться информация о пользователях
!!!!!!!
доделать: проверка существования директории и свободного протранства на диске
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
создание json-файла в нем будет храниться информация о пользователе при регестрации
*/
void CreateJsonFile(std::string UserName, std::string Password, std::string DataOfBirth, int age, nlohmann::json& User_Data_Array)               ////////////////////передать через ссылки
{
	std::string file_name = UserName + ".json";
	//FILENAME = msclr::interop::marshal_as<std::string>(file_name);
	std::string file_path = PATH_TO_DIRECTORY + file_name;

	// Запись JSON-строки в файл
	std::ofstream file(file_path);
	if (file.is_open())
	{
		file << User_Data_Array.dump(4);  // dump(4) для красивого форматирования с отступами
		file.close();
		System::Windows::Forms::MessageBox::Show("Пользователь успешно создан.", "Успех!");
	}
	else
	{
		System::Windows::Forms::MessageBox::Show("Нет возможности открыть файл.", "Ошибка!");
	}
}


/*
* проверка введеного логина пользователя а затем последуюущая проверка пароля
*/
void LogInTOtheSystem(std::string targetFileName, std::string password_std)
{
	bool CheckUser = false;

	FILENAME = targetFileName;

	for (const auto& entry : std::filesystem::directory_iterator(PATH_TO_DIRECTORY))
	{
		if (entry.is_regular_file()) {  // Проверяем, что это обычный файл, а не директория
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
		System::Windows::Forms::MessageBox::Show("Пользователь не создан");
	}
}
	
/*
* проверка введнного пароля пользователем
*/
void CheckPasswordUser(std::string password_std, std::string fullPath)
{
	// Загружаем JSON файл
	std::ifstream jsonFile(fullPath);
	if (!jsonFile.is_open()) 
	{
		System::Windows::Forms::MessageBox::Show("Ошибки с открытием файла: " + gcnew System::String(fullPath.c_str()));
	}

	// Читаем JSON из файла
	nlohmann::json jsonData;

	try 
	{
		jsonFile >> jsonData;
	}
	catch (const nlohmann::json::parse_error& e)
	{
		System::Windows::Forms::MessageBox::Show("Ошибки с парсингом файла: " + gcnew System::String(fullPath.c_str()));
	}

	// Закрываем файл, так как мы больше его не используем
	jsonFile.close();

	std::string fieldName = "Password_for_enter_in_the_programm";
	std::string targetValue = password_std;	

		if (jsonData[0][fieldName] == targetValue) 
		{
			//System::Windows::Forms::MessageBox::Show("!!!!!!!!!!!!!!" );
			/*
			открытие окна где можно получить свои даные либо добавить новые
			*/
			PassManeger::MainWindow^ mainwin = gcnew PassManeger::MainWindow;
			mainwin->Show();
		}
		else 
		{
			System::Windows::Forms::MessageBox::Show("Невереный логин или пароль.");
		}
}

/*
* проверка что пользователь не ввел в поле имяпользователя и пароль пробел или enter
*/
bool containsWhitespace(const std::string& str)
{
	for (char ch : str) {
		// Проверка на пробел или перевод строки
		if (std::isspace(static_cast<unsigned char>(ch))) {
			return true; // Если найден пробел или перевод строки, возвращаем true
		}
	}
	return false; // Если пробелов или переводов строки нет, возвращаем false
}

/*
* добавление новой записи
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
		System::Windows::Forms::MessageBox::Show("Невоможно прочитать файл!");
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

	// 3. Запись обновлённого JSON в файл
	std::ofstream outputFile(path);
	if (outputFile.is_open()) {
		outputFile << User_Full_Data.dump(4);  // dump(4) для красивого форматирования с отступами
		outputFile.close();
		System::Windows::Forms::MessageBox::Show("Запись добалена. Успех!");
	}
	else
	{
		System::Windows::Forms::MessageBox::Show("Невоможно записать в файл!");
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
		System::Windows::Forms::MessageBox::Show("Невозможно прочитать файл!");
		return DataFromFields;  // Вернем пустой список, так как чтение файла не удалось
	}

	// Поиск объекта по полю
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
		System::Windows::Forms::MessageBox::Show("Объект не найден!");
		return DataFromFields;  // Вернем пустой список, так как объект не найден
	}

	// Проходимся по всем ключам объекта и добавляем их в список
	for (auto it = foundObject.begin(); it != foundObject.end(); ++it)
	{
		if (!it.value().is_null())
		{
			Space::String^ fieldValue = gcnew Space::String((it.value().dump(0)).c_str());
			if (fieldValue->Length > 1)
			{
				// Создаем подстроку, исключая первый и последний символ
				fieldValue = fieldValue->Substring(1, fieldValue->Length - 2);
			}
			DataFromFields->Add(fieldValue);
		}
	}

	return DataFromFields;
}



