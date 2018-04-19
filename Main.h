#pragma once

namespace SDIGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	/*[System.ComponentModel.DesignerCategory("Code")]*/
	public ref class Main : public System::Windows::Forms::Form
	{
	
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  advancedSearch;
	protected:

	private: System::Windows::Forms::Button^  search;
	private: System::Windows::Forms::Button^  dailyLog;
	protected:


	private: System::Windows::Forms::Button^  logOut;
	private: System::Windows::Forms::Label^  welcomeLabel;
	private: System::Windows::Forms::Label^  trekStarLabel;




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
			this->advancedSearch = (gcnew System::Windows::Forms::Button());
			this->search = (gcnew System::Windows::Forms::Button());
			this->dailyLog = (gcnew System::Windows::Forms::Button());
			this->logOut = (gcnew System::Windows::Forms::Button());
			this->welcomeLabel = (gcnew System::Windows::Forms::Label());
			this->trekStarLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// advancedSearch
			// 
			this->advancedSearch->Location = System::Drawing::Point(341, 54);
			this->advancedSearch->Name = L"advancedSearch";
			this->advancedSearch->Size = System::Drawing::Size(81, 44);
			this->advancedSearch->TabIndex = 0;
			this->advancedSearch->Text = L"Advanced Search";
			this->advancedSearch->UseVisualStyleBackColor = true;
			// 
			// search
			// 
			this->search->Location = System::Drawing::Point(314, 12);
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(108, 36);
			this->search->TabIndex = 1;
			this->search->Text = L"Search";
			this->search->UseVisualStyleBackColor = true;
			// 
			// dailyLog
			// 
			this->dailyLog->Location = System::Drawing::Point(12, 226);
			this->dailyLog->Name = L"dailyLog";
			this->dailyLog->Size = System::Drawing::Size(75, 23);
			this->dailyLog->TabIndex = 2;
			this->dailyLog->Text = L"Daily Log";
			this->dailyLog->UseVisualStyleBackColor = true;
			// 
			// logOut
			// 
			this->logOut->Location = System::Drawing::Point(339, 226);
			this->logOut->Name = L"logOut";
			this->logOut->Size = System::Drawing::Size(83, 23);
			this->logOut->TabIndex = 3;
			this->logOut->Text = L"Log Out";
			this->logOut->UseVisualStyleBackColor = true;
			// 
			// welcomeLabel
			// 
			this->welcomeLabel->AutoSize = true;
			this->welcomeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->welcomeLabel->Location = System::Drawing::Point(7, 127);
			this->welcomeLabel->Name = L"welcomeLabel";
			this->welcomeLabel->Size = System::Drawing::Size(242, 25);
			this->welcomeLabel->TabIndex = 4;
			this->welcomeLabel->Text = L"Welcome to Movie Search";
			// 
			// trekStarLabel
			// 
			this->trekStarLabel->AutoSize = true;
			this->trekStarLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->trekStarLabel->Location = System::Drawing::Point(9, 9);
			this->trekStarLabel->Name = L"trekStarLabel";
			this->trekStarLabel->Size = System::Drawing::Size(123, 18);
			this->trekStarLabel->TabIndex = 5;
			this->trekStarLabel->Text = L"TrekStar Pictures";
			this->trekStarLabel->Click += gcnew System::EventHandler(this, &Main::label2_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(434, 261);
			this->Controls->Add(this->trekStarLabel);
			this->Controls->Add(this->welcomeLabel);
			this->Controls->Add(this->logOut);
			this->Controls->Add(this->dailyLog);
			this->Controls->Add(this->search);
			this->Controls->Add(this->advancedSearch);
			this->Name = L"Main";
			this->Text = L"Main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
