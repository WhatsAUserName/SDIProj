#pragma once
#include "binary_search_view.h"
#include "advanced_search_view.h"

namespace SDIGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainScreen
	/// </summary>
	public ref class MainScreen : public System::Windows::Forms::Form
	{
	public:
		MainScreen(void)
		{
			SelectedProject = new Project;

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	public: binary_search_view^ binary_search_form;
	public: search_view^ advanced_search_form;
	private: System::Windows::Forms::Button^  ad_searchBtn;
	private: Project *SelectedProject;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainScreen()
		{
			delete SelectedProject;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Button^  searchBtn;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::ListBox^  listBox3;



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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->ad_searchBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(10, 11);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Project Zeus";
			this->label1->Click += gcnew System::EventHandler(this, &MainScreen::label1_Click);
			// 
			// searchBtn
			// 
			this->searchBtn->Location = System::Drawing::Point(538, 11);
			this->searchBtn->Margin = System::Windows::Forms::Padding(2);
			this->searchBtn->Name = L"searchBtn";
			this->searchBtn->Size = System::Drawing::Size(146, 29);
			this->searchBtn->TabIndex = 1;
			this->searchBtn->Text = L"Search";
			this->searchBtn->UseVisualStyleBackColor = true;
			this->searchBtn->Click += gcnew System::EventHandler(this, &MainScreen::searchBtn_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 82);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Recent Releases";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(251, 82);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Upcoming";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(520, 82);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Now Playing";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Ready Player One" });
			this->listBox1->Location = System::Drawing::Point(16, 119);
			this->listBox1->Margin = System::Windows::Forms::Padding(2);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(164, 147);
			this->listBox1->TabIndex = 5;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainScreen::listBox1_SelectedIndexChanged);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"My Secret Screenplay" });
			this->listBox2->Location = System::Drawing::Point(254, 119);
			this->listBox2->Margin = System::Windows::Forms::Padding(2);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(164, 147);
			this->listBox2->TabIndex = 6;
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Ready Player One" });
			this->listBox3->Location = System::Drawing::Point(522, 119);
			this->listBox3->Margin = System::Windows::Forms::Padding(2);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(164, 147);
			this->listBox3->TabIndex = 7;
			// 
			// ad_searchBtn
			// 
			this->ad_searchBtn->Location = System::Drawing::Point(538, 44);
			this->ad_searchBtn->Margin = System::Windows::Forms::Padding(2);
			this->ad_searchBtn->Name = L"ad_searchBtn";
			this->ad_searchBtn->Size = System::Drawing::Size(145, 29);
			this->ad_searchBtn->TabIndex = 8;
			this->ad_searchBtn->Text = L"Advanced Search";
			this->ad_searchBtn->UseVisualStyleBackColor = true;
			this->ad_searchBtn->Click += gcnew System::EventHandler(this, &MainScreen::ad_searchBtn_Click);
			// 
			// MainScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(694, 376);
			this->Controls->Add(this->ad_searchBtn);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->searchBtn);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainScreen";
			this->Text = L"MainScreen";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	Project *prj = SelectedProject;
}
private: System::Void searchBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();

	if (!binary_search_form)
	{
		binary_search_form = gcnew binary_search_view(this, SelectedProject); //here?
	}
	binary_search_form->ShowDialog();
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	//open relevant movie page
}
private: System::Void ad_searchBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();

	if (!advanced_search_form)
	{
		advanced_search_form = gcnew search_view(this, SelectedProject); //here?
	}
	advanced_search_form->ShowDialog();
}
};
}
