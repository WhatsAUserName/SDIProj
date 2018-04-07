#pragma once
#include<string>
#include <iostream>

namespace SDIGUI {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class search : public System::Windows::Forms::Form
	{
	public:
		search(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//



		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~search()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtUserInput;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnSearch;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  lblDisplay;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(search::typeid));
			this->txtUserInput = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblDisplay = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtUserInput
			// 
			this->txtUserInput->Location = System::Drawing::Point(182, 316);
			this->txtUserInput->Name = L"txtUserInput";
			this->txtUserInput->Size = System::Drawing::Size(266, 20);
			this->txtUserInput->TabIndex = 0;
			this->txtUserInput->TextChanged += gcnew System::EventHandler(this, &search::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"DVD Search Page";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(182, 342);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(111, 17);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"Search by film title";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &search::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(315, 342);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(133, 17);
			this->checkBox2->TabIndex = 3;
			this->checkBox2->Text = L"Search by Actor Name";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(454, 323);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Advanced";
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(271, 376);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 23);
			this->btnSearch->TabIndex = 5;
			this->btnSearch->Text = L"Search";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &search::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label3.Image")));
			this->label3->Location = System::Drawing::Point(12, 60);
			this->label3->MinimumSize = System::Drawing::Size(250, 250);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(250, 250);
			this->label3->TabIndex = 6;
			// 
			// lblDisplay
			// 
			this->lblDisplay->AutoSize = true;
			this->lblDisplay->Location = System::Drawing::Point(268, 60);
			this->lblDisplay->MinimumSize = System::Drawing::Size(250, 250);
			this->lblDisplay->Name = L"lblDisplay";
			this->lblDisplay->Size = System::Drawing::Size(250, 250);
			this->lblDisplay->TabIndex = 7;
			this->lblDisplay->Click += gcnew System::EventHandler(this, &search::lblDisplay_Click);
			// 
			// search
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->lblDisplay);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtUserInput);
			this->Name = L"search";
			this->Text = L"search";
			this->ResumeLayout(false);
			this->PerformLayout();

		}



	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {


		string userInput;



	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		// Hash Variabes

		string title = "Fast";
		string summary = "It's about street racing I think? Maybe drag racing, more specifically \n";
		string genre = "VroomVroom \n";
		string releaseDate = "Like, 2002 or something? \n";
		string filmingLocations = "Somewhere in the US \n";
		string language = "English \n";
		string runtime = "2 hours maybe \n";

		String^ title2 = gcnew String(title.c_str());
		String^ summary2 = gcnew String(summary.c_str());
		String^ genre2 = gcnew String(genre.c_str());
		String^ releaseDate2 = gcnew String(releaseDate.c_str());
		String^ filmingLocations2 = gcnew String(filmingLocations.c_str());
		String^ language2 = gcnew String(language.c_str());
		String^ runtime2 = gcnew String(runtime.c_str());


	

		//Unassigned variables
		String^ anythingElse; //other searches
		String^ artist = "artist"; // artist variable
		String^ TitleArtist = "tanda"; // artist and title variable

		if (txtUserInput->Text == "hashy")
		{
			

			/*Hashy.PrintTable();*/
		}

		// Handles Titles search //
		else if ((txtUserInput->Text == title2) && (checkBox1->Checked == true))
		{

			lblDisplay->Text =
				"Here's the information for film title: " + title2 + "\n\n"

				"Name: " + title2 + "\n" +
				"Summary: " + summary2 +
				"Genre: " + genre2 +
				"Released Date: " + releaseDate2 +
				"Filming Location: " + filmingLocations2 +
				"Language: " + language2 +
				"RunTime: " + runtime2;

		}
		else if ((txtUserInput->Text != title2) && (checkBox1->Checked == true)) // if userinput isn't a title and tick box checked
		{
			lblDisplay->Text = "Sorry the information for Title Name: '" + txtUserInput->Text + "' cannot be found";
		}

		// Handles Actor search //
		else if ((txtUserInput->Text == artist) && (checkBox2->Checked == true)) // Searches for actors Name
		{
			lblDisplay->Text = "Here's the information for Actor Name: '" + txtUserInput->Text + "'";
		}
		else if ((txtUserInput->Text != artist) && (checkBox2->Checked == true))
		{
			lblDisplay->Text = "Sorry the information for Actor Name: '" + txtUserInput->Text + "' cannot be found";
		}

		// Handles Title and Artist
		else if ((txtUserInput->Text == TitleArtist) && (checkBox1->Checked == true)) // Searches for both Artists and Film Title
		{
			lblDisplay->Text = "Here are all the resuls for: '" + txtUserInput->Text + "'.";
		}

		// Searches for keywords //
		else
		{
			lblDisplay->Text = "Here's the Search result for input: '" + txtUserInput->Text + "'.";
		}
	}


	private: System::Void txtDisplay_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void lblDisplay_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	};

	//hash table


	//here hash cpp



}