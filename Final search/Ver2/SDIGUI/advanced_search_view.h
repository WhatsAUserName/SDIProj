#pragma once
#include "advanced_search.h"
#include <msclr\marshal_cppstd.h>

namespace SDIGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for search_view
	/// </summary>
	public ref class search_view : public System::Windows::Forms::Form
	{

	public:

		search_view(System::Windows::Forms::Form ^ mainForm, Project *PRJ)
		{
			InitializeComponent();
			MainScreen = mainForm;
			SelectedProject = PRJ;

			this->searchComp = new Search;
			this->ProjectList = new std::vector<Project*>;
			//
			//TODO: Add the constructor code here
			//
		}
	public: Search *searchComp;
	private: Project *SelectedProject;



	private: std::vector<Project*> *ProjectList;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~search_view()
		{
			if (components)
			{
				delete components;
			}

			if (searchComp)
			{
				delete searchComp;
			}

			if (ProjectList)
			{
				delete ProjectList;
			}
		}
	private: System::Windows::Forms::Form ^ MainScreen;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  search;









	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TextBox^  filmNameTxt;
	private: System::Windows::Forms::TextBox^  crewNameTxt;
	private: System::Windows::Forms::ComboBox^  releaseStateTxt;










	private: System::Windows::Forms::Label^  crew;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  view;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Title;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Genre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ReleaseDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  CrewList;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Language;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Runtime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  State;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  keyWordTxt;
















	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->search = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Genre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ReleaseDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CrewList = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Language = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Runtime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->State = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->filmNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->crewNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->releaseStateTxt = (gcnew System::Windows::Forms::ComboBox());
			this->crew = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->view = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->keyWordTxt = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(73, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Film Title";
			// 
			// search
			// 
			this->search->Location = System::Drawing::Point(488, 147);
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(75, 23);
			this->search->TabIndex = 6;
			this->search->Text = L"Search";
			this->search->UseVisualStyleBackColor = true;
			this->search->Click += gcnew System::EventHandler(this, &search_view::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Title,
					this->Genre, this->ReleaseDate, this->CrewList, this->Language, this->Runtime, this->State
			});
			this->dataGridView1->Location = System::Drawing::Point(26, 198);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(693, 218);
			this->dataGridView1->TabIndex = 7;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &search_view::dataGridView1_CellContentClick);
			// 
			// Title
			// 
			this->Title->HeaderText = L"Title";
			this->Title->Name = L"Title";
			this->Title->ReadOnly = true;
			this->Title->Width = 150;
			// 
			// Genre
			// 
			this->Genre->HeaderText = L"Genre";
			this->Genre->Name = L"Genre";
			this->Genre->ReadOnly = true;
			// 
			// ReleaseDate
			// 
			this->ReleaseDate->HeaderText = L"Release Date";
			this->ReleaseDate->Name = L"ReleaseDate";
			this->ReleaseDate->ReadOnly = true;
			// 
			// CrewList
			// 
			this->CrewList->HeaderText = L"Crew Members";
			this->CrewList->Name = L"CrewList";
			this->CrewList->ReadOnly = true;
			// 
			// Language
			// 
			this->Language->HeaderText = L"Language";
			this->Language->Name = L"Language";
			this->Language->ReadOnly = true;
			// 
			// Runtime
			// 
			this->Runtime->HeaderText = L"Runtime";
			this->Runtime->Name = L"Runtime";
			this->Runtime->ReadOnly = true;
			// 
			// State
			// 
			this->State->HeaderText = L"State";
			this->State->Name = L"State";
			this->State->ReadOnly = true;
			// 
			// filmNameTxt
			// 
			this->filmNameTxt->Location = System::Drawing::Point(179, 22);
			this->filmNameTxt->Name = L"filmNameTxt";
			this->filmNameTxt->Size = System::Drawing::Size(253, 20);
			this->filmNameTxt->TabIndex = 8;
			// 
			// crewNameTxt
			// 
			this->crewNameTxt->Location = System::Drawing::Point(179, 66);
			this->crewNameTxt->Name = L"crewNameTxt";
			this->crewNameTxt->Size = System::Drawing::Size(253, 20);
			this->crewNameTxt->TabIndex = 9;
			// 
			// releaseStateTxt
			// 
			this->releaseStateTxt->FormattingEnabled = true;
			this->releaseStateTxt->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"released", L"unreleased", L"Playing" });
			this->releaseStateTxt->Location = System::Drawing::Point(179, 106);
			this->releaseStateTxt->Name = L"releaseStateTxt";
			this->releaseStateTxt->Size = System::Drawing::Size(253, 21);
			this->releaseStateTxt->TabIndex = 10;
			this->releaseStateTxt->SelectedIndexChanged += gcnew System::EventHandler(this, &search_view::releaseState_SelectedIndexChanged);
			// 
			// crew
			// 
			this->crew->AutoSize = true;
			this->crew->Location = System::Drawing::Point(73, 66);
			this->crew->Name = L"crew";
			this->crew->Size = System::Drawing::Size(31, 13);
			this->crew->TabIndex = 11;
			this->crew->Text = L"Crew";
			this->crew->Click += gcnew System::EventHandler(this, &search_view::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(73, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"State";
			// 
			// view
			// 
			this->view->Location = System::Drawing::Point(41, 441);
			this->view->Name = L"view";
			this->view->Size = System::Drawing::Size(75, 23);
			this->view->TabIndex = 13;
			this->view->Text = L"View";
			this->view->UseVisualStyleBackColor = true;
			this->view->Click += gcnew System::EventHandler(this, &search_view::view_Click);
			this->view->MouseCaptureChanged += gcnew System::EventHandler(this, &search_view::view_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(73, 152);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Keyword";
			// 
			// keyWordTxt
			// 
			this->keyWordTxt->Location = System::Drawing::Point(179, 145);
			this->keyWordTxt->Name = L"keyWordTxt";
			this->keyWordTxt->Size = System::Drawing::Size(253, 20);
			this->keyWordTxt->TabIndex = 15;
			// 
			// search_view
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(745, 501);
			this->Controls->Add(this->keyWordTxt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->view);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->crew);
			this->Controls->Add(this->releaseStateTxt);
			this->Controls->Add(this->crewNameTxt);
			this->Controls->Add(this->filmNameTxt);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->search);
			this->Controls->Add(this->label1);
			this->Name = L"search_view";
			this->Text = L"search_view";
			this->Load += gcnew System::EventHandler(this, &search_view::search_view_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//clear dataGrid on last searching
		dataGridView1->Rows->Clear();

		//delete data from last search
		if (ProjectList && !ProjectList->empty())
		{
			delete ProjectList;
		}

		//convert text from textbox to a string
		std::string filmName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->filmNameTxt->Text);
		std::string crewName = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->crewNameTxt->Text);
		std::string state = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->releaseStateTxt->Text);
		std::string keyWord = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->keyWordTxt->Text);

		std::vector<Project*> foundPrj = searchComp->SearchIt(filmName, crewName, state, keyWord);

		if (foundPrj.empty())
		{
			MessageBox::Show("Sorry search not found", "Sorry search not found!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}

		//copy search data to list
		ProjectList = new std::vector<Project*>(foundPrj);

		for each (Project *prj in foundPrj)
		{
			//prepare data for a row
			System::String^title = gcnew System::String(prj->title.c_str());
			System::String^genre = gcnew System::String(prj->genre.c_str());
			System::String^releaseDate = gcnew System::String(prj->releaseDate.c_str());

			std::string allCrewMembers;
			for each (struct Crew crewMember in prj->crewMembers)
			{
				allCrewMembers = allCrewMembers + crewMember.job + ":" + crewMember.name + "; ";
			}

			//delete last 2 char "<semi colon><space>"
			allCrewMembers.pop_back();
			allCrewMembers.pop_back();

			System::String^crewMembers = gcnew System::String(allCrewMembers.c_str());

			System::String^language = gcnew System::String(prj->language.c_str());
			System::String^runtime = gcnew System::String(prj->runtime.c_str());
			System::String^state = gcnew System::String(prj->state.c_str());

			//add data to new row
			dataGridView1->Rows->Add(title, genre, releaseDate, crewMembers, language, runtime, state);
		}
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
	private: System::Void search_view_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void releaseState_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void view_Click(System::Object^  sender, System::EventArgs^  e) {
		if (dataGridView1->SelectedRows->Count)
		{
			int selectedRow = dataGridView1->CurrentRow->Index;

			if (selectedRow >= 0)
			{
				(*SelectedProject) = (*(*ProjectList)[selectedRow]);

				MainScreen->Show();
				this->Hide();
			}
		}
	}
	private: System::Void norSearchBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
	}
};
}