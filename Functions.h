#pragma once
#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>

namespace Space
{
	using namespace System;
	using namespace System::Collections::Generic;
}


extern nlohmann::json User_Data_Array;


void CreateFolder();
void CreateJsonFile(std::string UserName, std::string Password, std::string DataOfBirth, int age, nlohmann::json &User_Data_Array);
void LogInTOtheSystem(std::string targetFileName, std::string password_std);
void CheckPasswordUser(std::string password_std, std::string fullPath);
bool containsWhitespace(const std::string& str);
void AddNewInfo(const std::vector<std::string>& UserInfo);
Space::List<Space::String^>^ ShowPrivateData(std::string &social_net_std);