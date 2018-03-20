#include "MyForm.h"
#include "windows.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ argv)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	SDIGUI::MyForm form;
	Application::Run(%form);
}

