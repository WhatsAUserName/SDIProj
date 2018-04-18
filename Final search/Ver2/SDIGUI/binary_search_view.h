#pragma once
#include "binary_search.h"
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
	public ref class binary_search_view : public System::Windows::Forms::Form
	{

	public:
		
		binary_search_view(System::Windows::Forms::Form ^ mainForm, Project *PRJ)
		{
			InitializeComponent();
			MainScreen = mainForm;
			SelectedProject = PRJ;

			this->searchComp = new BinarySearch;
			this->ProjectList = new std::vector<Project*>;
			//
			//TODO: Add the constructor code here
			//
		}

	public: BinarySearch *searchComp;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Title;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Genre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ReleaseDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  CrewList;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Language;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Runtime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  State;

	private: std::vector<Project*> *ProjectList;

	private: Project *SelectedProject;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~binary_search_view()
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
	private: System::Windows::Forms::Form ^ AdvancedSearchForm;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  searchBtn;










	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TextBox^  keyWordTxt;
	private: System::Windows::Forms::ComboBox^  searchFieldTxt;
	private: System::Windows::Forms::Button^  viewBtn;

	private:








































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
			this->searchBtn = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Genre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ReleaseDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CrewList = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Language = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Runtime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->State = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->keyWordTxt = (gcnew System::Windows::Forms::TextBox());
			this->searchFieldTxt = (gcnew System::Windows::Forms::ComboBox());
			this->viewBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"key word";
			this->label1->Click += gcnew System::EventHandler(this, &binary_search_view::label1_Click);
			// 
			// searchBtn
			// 
			this->searchBtn->Location = System::Drawing::Point(522, 47);
			this->searchBtn->Name = L"searchBtn";
			this->searchBtn->Size = System::Drawing::Size(75, 23);
			this->searchBtn->TabIndex = 6;
			this->searchBtn->Text = L"Search";
			this->searchBtn->UseVisualStyleBackColor = true;
			this->searchBtn->Click += gcnew System::EventHandler(this, &binary_search_view::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Title,
					this->Genre, this->ReleaseDate, this->CrewList, this->Language, this->Runtime, this->State
			});
			this->dataGridView1->Location = System::Drawing::Point(24, 96);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(693, 314);
			this->dataGridView1->TabIndex = 7;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &binary_search_view::dataGridView1_CellContentClick);
			this->dataGridView1->RowHeaderMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &binary_search_view::dataGridView1_RowHeaderMouseDoubleClick);
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
			// 
			// ReleaseDate
			// 
			this->ReleaseDate->HeaderText = L"Release Date";
			this->ReleaseDate->Name = L"ReleaseDate";
			// 
			// CrewList
			// 
			this->CrewList->HeaderText = L"Crew Members";
			this->CrewList->Name = L"CrewList";
			// 
			// Language
			// 
			this->Language->HeaderText = L"Language";
			this->Language->Name = L"Language";
			// 
			// Runtime
			// 
			this->Runtime->HeaderText = L"Runtime";
			this->Runtime->Name = L"Runtime";
			// 
			// State
			// 
			this->State->HeaderText = L"State";
			this->State->Name = L"State";
			// 
			// keyWordTxt
			// 
			this->keyWordTxt->Location = System::Drawing::Point(87, 47);
			this->keyWordTxt->Name = L"keyWordTxt";
			this->keyWordTxt->Size = System::Drawing::Size(253, 20);
			this->keyWordTxt->TabIndex = 8;
			// 
			// searchFieldTxt
			// 
			this->searchFieldTxt->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->searchFieldTxt->FormattingEnabled = true;
			this->searchFieldTxt->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Search by title", L"Search by state", L"Search by crew",
					L"Search by keyword"
			});
			this->searchFieldTxt->Location = System::Drawing::Point(369, 47);
			this->searchFieldTxt->Name = L"searchFieldTxt";
			this->searchFieldTxt->Size = System::Drawing::Size(136, 21);
			this->searchFieldTxt->TabIndex = 10;
			// 
			// viewBtn
			// 
			this->viewBtn->Location = System::Drawing::Point(24, 431);
			this->viewBtn->Name = L"viewBtn";
			this->viewBtn->Size = System::Drawing::Size(75, 23);
			this->viewBtn->TabIndex = 13;
			this->viewBtn->Text = L"View";
			this->viewBtn->UseVisualStyleBackColor = true;
			this->viewBtn->Click += gcnew System::EventHandler(this, &binary_search_view::view_Click);
			// 
			// binary_search_view
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(745, 501);
			this->Controls->Add(this->viewBtn);
			this->Controls->Add(this->searchFieldTxt);
			this->Controls->Add(this->keyWordTxt);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->searchBtn);
			this->Controls->Add(this->label1);
			this->Name = L"binary_search_view";
			this->Text = L"search_view";
			this->Load += gcnew System::EventHandler(this, &binary_search_view::search_view_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


	SearchField searchField;

	//clear data on dataGrid from last search
	dataGridView1->Rows->Clear();

	//delete data from last search
	if (ProjectList && !ProjectList->empty())
	{
		delete ProjectList;
	}

	//convert keyword from textbox to string
	std::string keyword = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->keyWordTxt->Text);

	//define search field
	if (this->searchFieldTxt->Text == "Search by title")
	{
		searchField = TITLE;
	}
	else if (this->searchFieldTxt->Text == "Search by state")
	{
		searchField = STATE;
	}
	else if (this->searchFieldTxt->Text == "Search by crew")
	{
		searchField = CREW;
	}
	else if (this->searchFieldTxt->Text == "Search by keyword")
	{
		searchField = KEYWORD;
	}
	else
	{
		return;
	}

	std::vector<Project*> foundPrj = searchComp->SearchIt(keyword, searchField);

	//copy search data to list
	ProjectList = new std::vector<Project*>(foundPrj);

	if (foundPrj.empty())
	{
		MessageBox::Show("Sorry search not found", "Sorry search not found!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}

	for each (Project *prj in foundPrj)
	{
		//prepare data to add new row
		System::String^title = gcnew System::String(prj->title.c_str());
		System::String^genre = gcnew System::String(prj->genre.c_str());
		System::String^releaseDate = gcnew System::String(prj->releaseDate.c_str());

		std::string allCrewMembers;
		for each (struct Crew crewMember in prj->crewMembers)
		{
			allCrewMembers = allCrewMembers + crewMember.job + ":" + crewMember.name + "; ";
		}
		//delete last 2 char "<semi-colon><space>"
		allCrewMembers.pop_back();
		allCrewMembers.pop_back();

		System::String^crewMembers = gcnew System::String(allCrewMembers.c_str());
		
		System::String^language = gcnew System::String(prj->language.c_str());
		System::String^runtime = gcnew System::String(prj->runtime.c_str());
		System::String^state = gcnew System::String(prj->state.c_str());

		//add new row
		dataGridView1->Rows->Add(title, genre, releaseDate, crewMembers, language, runtime, state);
	}
}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}	 
private: System::Void search_view_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void dataGridView1_RowHeaderMouseDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {

}
private: System::Void adSearchBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	AdvancedSearchForm->Show();
}
};
}