#include "WindowMenu.h"
#include "Registration.h"
#include "LogIn.h"
#include "Functions.h"
#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	PassManeger::WindowMenu frm;
	Application::Run(% frm);

	CreateFolder();
}