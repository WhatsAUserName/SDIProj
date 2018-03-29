#pragma once

namespace SDIGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			#pragma region Setting text
			//Strings for passthrough from controller layer and setting text to given fields
			//languages are stored as one string
			System::String^ movieTitle("Current movie name goes here");
			System::String^ summary("sum here");
			System::String^ genre("genre here");
			System::String^ releaseDate ("rel date here");
			System::String^ sales("1234");
			System::String^ language("lan here");
			System::String^ runTime(" runtime here");
			System::String^ releaseState("release state here");
			InitializeComponent();
			this->Text = movieTitle;		
			this->movieTitle->Text = movieTitle;
			this->summaryTxt->Text = summary;
			this->releaseDateTxt->Text = releaseDate;
			this->genreTxt->Text = genre;
			this->saleTxt->Text = "$" + sales;
			this->languageTxt->Text = language;
			this->runtimeTxt->Text = runTime + "Mins"; 
			this->releaseStateTxt->Text = releaseState;
			#pragma endregion
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  movieTitle;
	private: System::Windows::Forms::Label^  summaryTxt;

	protected:


	protected:


	private: System::Windows::Forms::Label^  Genre;
	private: System::Windows::Forms::Label^  Summary;
	private: System::Windows::Forms::Label^  genreTxt;

	private: System::Windows::Forms::Label^  releaseDate;
	private: System::Windows::Forms::Label^  releaseDateTxt;
	private: System::Windows::Forms::Label^  releaseState;
	private: System::Windows::Forms::TreeView^  treeView1;
	private: System::Windows::Forms::Label^  releaseStateTxt;
	private: System::Windows::Forms::Label^  Language;
	private: System::Windows::Forms::Label^  languageTxt;
	private: System::Windows::Forms::Label^  Runtime;
	private: System::Windows::Forms::Label^  keywordList;
	private: System::Windows::Forms::Label^  keywords;
	private: System::Windows::Forms::Label^  ticketSales;
	private: System::Windows::Forms::Label^  runtimeTxt;
	private: System::Windows::Forms::Label^  saleTxt;
	private: System::Windows::Forms::Button^  button1;






	protected:

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
			System::Windows::Forms::TreeNode^  treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"The Wachowski Brothers"));
			System::Windows::Forms::TreeNode^  treeNode2 = (gcnew System::Windows::Forms::TreeNode(L"Director(s)", gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode1 }));
			System::Windows::Forms::TreeNode^  treeNode3 = (gcnew System::Windows::Forms::TreeNode(L"The Wachowski Brothers"));
			System::Windows::Forms::TreeNode^  treeNode4 = (gcnew System::Windows::Forms::TreeNode(L"Writer(s)", gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode3 }));
			System::Windows::Forms::TreeNode^  treeNode5 = (gcnew System::Windows::Forms::TreeNode(L"Keanu Reeves"));
			System::Windows::Forms::TreeNode^  treeNode6 = (gcnew System::Windows::Forms::TreeNode(L"Laurence Fishburne"));
			System::Windows::Forms::TreeNode^  treeNode7 = (gcnew System::Windows::Forms::TreeNode(L"Carrie-Anne Moss"));
			System::Windows::Forms::TreeNode^  treeNode8 = (gcnew System::Windows::Forms::TreeNode(L"Starring", gcnew cli::array< System::Windows::Forms::TreeNode^  >(3) {
				treeNode5,
					treeNode6, treeNode7
			}));
			System::Windows::Forms::TreeNode^  treeNode9 = (gcnew System::Windows::Forms::TreeNode(L"Node8"));
			System::Windows::Forms::TreeNode^  treeNode10 = (gcnew System::Windows::Forms::TreeNode(L"Camera Crew", gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode9 }));
			System::Windows::Forms::TreeNode^  treeNode11 = (gcnew System::Windows::Forms::TreeNode(L"Crew", gcnew cli::array< System::Windows::Forms::TreeNode^  >(4) {
				treeNode2,
					treeNode4, treeNode8, treeNode10
			}));
			this->movieTitle = (gcnew System::Windows::Forms::Label());
			this->summaryTxt = (gcnew System::Windows::Forms::Label());
			this->Genre = (gcnew System::Windows::Forms::Label());
			this->Summary = (gcnew System::Windows::Forms::Label());
			this->genreTxt = (gcnew System::Windows::Forms::Label());
			this->releaseDate = (gcnew System::Windows::Forms::Label());
			this->releaseDateTxt = (gcnew System::Windows::Forms::Label());
			this->releaseState = (gcnew System::Windows::Forms::Label());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->releaseStateTxt = (gcnew System::Windows::Forms::Label());
			this->Language = (gcnew System::Windows::Forms::Label());
			this->languageTxt = (gcnew System::Windows::Forms::Label());
			this->Runtime = (gcnew System::Windows::Forms::Label());
			this->keywordList = (gcnew System::Windows::Forms::Label());
			this->keywords = (gcnew System::Windows::Forms::Label());
			this->ticketSales = (gcnew System::Windows::Forms::Label());
			this->runtimeTxt = (gcnew System::Windows::Forms::Label());
			this->saleTxt = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// movieTitle
			// 
			this->movieTitle->AutoSize = true;
			this->movieTitle->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->movieTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 41.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->movieTitle->Location = System::Drawing::Point(23, 32);
			this->movieTitle->Name = L"movieTitle";
			this->movieTitle->Size = System::Drawing::Size(289, 63);
			this->movieTitle->TabIndex = 0;
			this->movieTitle->Text = L"The Matrix";
			this->movieTitle->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// summaryTxt
			// 
			this->summaryTxt->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->summaryTxt->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->summaryTxt->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->summaryTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->summaryTxt->Location = System::Drawing::Point(36, 148);
			this->summaryTxt->MaximumSize = System::Drawing::Size(300, 220);
			this->summaryTxt->Name = L"summaryTxt";
			this->summaryTxt->Size = System::Drawing::Size(300, 220);
			this->summaryTxt->TabIndex = 1;
			this->summaryTxt->Text = L"A computer hacker learns from mysterious rebels about the true nature of his real"
				L"ity and his role in the war against its controllers.";
			// 
			// Genre
			// 
			this->Genre->AutoSize = true;
			this->Genre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Genre->Location = System::Drawing::Point(520, 403);
			this->Genre->Name = L"Genre";
			this->Genre->Size = System::Drawing::Size(52, 17);
			this->Genre->TabIndex = 2;
			this->Genre->Text = L"Genre:";
			this->Genre->Click += gcnew System::EventHandler(this, &MyForm::Genre_Click);
			// 
			// Summary
			// 
			this->Summary->AutoSize = true;
			this->Summary->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Summary->Location = System::Drawing::Point(36, 128);
			this->Summary->Name = L"Summary";
			this->Summary->Size = System::Drawing::Size(71, 17);
			this->Summary->TabIndex = 3;
			this->Summary->Text = L"Summary:";
			// 
			// genreTxt
			// 
			this->genreTxt->AutoSize = true;
			this->genreTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->genreTxt->Location = System::Drawing::Point(627, 403);
			this->genreTxt->MaximumSize = System::Drawing::Size(300, 200);
			this->genreTxt->Name = L"genreTxt";
			this->genreTxt->Size = System::Drawing::Size(43, 17);
			this->genreTxt->TabIndex = 4;
			this->genreTxt->Text = L"Sci-Fi";
			this->genreTxt->Click += gcnew System::EventHandler(this, &MyForm::genreName_Click);
			// 
			// releaseDate
			// 
			this->releaseDate->AutoSize = true;
			this->releaseDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->releaseDate->Location = System::Drawing::Point(520, 465);
			this->releaseDate->Name = L"releaseDate";
			this->releaseDate->Size = System::Drawing::Size(98, 17);
			this->releaseDate->TabIndex = 5;
			this->releaseDate->Text = L"Release Date:";
			this->releaseDate->Click += gcnew System::EventHandler(this, &MyForm::releaseDate_Click);
			// 
			// releaseDateTxt
			// 
			this->releaseDateTxt->AutoSize = true;
			this->releaseDateTxt->Enabled = false;
			this->releaseDateTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->releaseDateTxt->Location = System::Drawing::Point(627, 465);
			this->releaseDateTxt->Name = L"releaseDateTxt";
			this->releaseDateTxt->Size = System::Drawing::Size(95, 17);
			this->releaseDateTxt->TabIndex = 6;
			this->releaseDateTxt->Text = L"11 June 1999";
			this->releaseDateTxt->Click += gcnew System::EventHandler(this, &MyForm::releaseDateTxt_Click);
			// 
			// releaseState
			// 
			this->releaseState->AutoSize = true;
			this->releaseState->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->releaseState->Location = System::Drawing::Point(520, 435);
			this->releaseState->Name = L"releaseState";
			this->releaseState->Size = System::Drawing::Size(101, 17);
			this->releaseState->TabIndex = 7;
			this->releaseState->Text = L"Release State:";
			this->releaseState->Click += gcnew System::EventHandler(this, &MyForm::releaseState_Click);
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(523, 148);
			this->treeView1->Name = L"treeView1";
			treeNode1->Name = L"DirectorTxt";
			treeNode1->Text = L"The Wachowski Brothers";
			treeNode2->Name = L"Director";
			treeNode2->Text = L"Director(s)";
			treeNode3->Name = L"WriterTxt";
			treeNode3->Text = L"The Wachowski Brothers";
			treeNode4->Name = L"Writer(s)";
			treeNode4->Text = L"Writer(s)";
			treeNode5->Name = L"Star1";
			treeNode5->Text = L"Keanu Reeves";
			treeNode6->Name = L"Star2";
			treeNode6->Text = L"Laurence Fishburne";
			treeNode7->Name = L"Star3";
			treeNode7->Text = L"Carrie-Anne Moss";
			treeNode8->Name = L"Starring";
			treeNode8->Text = L"Starring";
			treeNode9->Name = L"Node8";
			treeNode9->Text = L"Node8";
			treeNode10->Name = L"Camera Crew";
			treeNode10->Text = L"Camera Crew";
			treeNode11->Name = L"Crew";
			treeNode11->Text = L"Crew";
			this->treeView1->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode11 });
			this->treeView1->Size = System::Drawing::Size(320, 220);
			this->treeView1->TabIndex = 8;
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MyForm::treeView1_AfterSelect);
			// 
			// releaseStateTxt
			// 
			this->releaseStateTxt->AutoSize = true;
			this->releaseStateTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->releaseStateTxt->Location = System::Drawing::Point(627, 435);
			this->releaseStateTxt->Name = L"releaseStateTxt";
			this->releaseStateTxt->Size = System::Drawing::Size(86, 17);
			this->releaseStateTxt->TabIndex = 9;
			this->releaseStateTxt->Text = L"Full Release";
			this->releaseStateTxt->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// Language
			// 
			this->Language->AutoSize = true;
			this->Language->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Language->Location = System::Drawing::Point(41, 403);
			this->Language->Name = L"Language";
			this->Language->Size = System::Drawing::Size(93, 17);
			this->Language->TabIndex = 10;
			this->Language->Text = L"Language(s):";
			// 
			// languageTxt
			// 
			this->languageTxt->AutoSize = true;
			this->languageTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->languageTxt->Location = System::Drawing::Point(147, 403);
			this->languageTxt->Name = L"languageTxt";
			this->languageTxt->Size = System::Drawing::Size(54, 17);
			this->languageTxt->TabIndex = 11;
			this->languageTxt->Text = L"English";
			// 
			// Runtime
			// 
			this->Runtime->AutoSize = true;
			this->Runtime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Runtime->Location = System::Drawing::Point(39, 435);
			this->Runtime->Name = L"Runtime";
			this->Runtime->Size = System::Drawing::Size(64, 17);
			this->Runtime->TabIndex = 12;
			this->Runtime->Text = L"Runtime:";
			// 
			// keywordList
			// 
			this->keywordList->AutoSize = true;
			this->keywordList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->keywordList->Location = System::Drawing::Point(147, 506);
			this->keywordList->Name = L"keywordList";
			this->keywordList->Size = System::Drawing::Size(69, 17);
			this->keywordList->TabIndex = 13;
			this->keywordList->Text = L"Keywords";
			// 
			// keywords
			// 
			this->keywords->AutoSize = true;
			this->keywords->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->keywords->Location = System::Drawing::Point(41, 506);
			this->keywords->Name = L"keywords";
			this->keywords->Size = System::Drawing::Size(73, 17);
			this->keywords->TabIndex = 14;
			this->keywords->Text = L"Keywords:";
			// 
			// ticketSales
			// 
			this->ticketSales->AutoSize = true;
			this->ticketSales->Cursor = System::Windows::Forms::Cursors::Default;
			this->ticketSales->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->ticketSales->Location = System::Drawing::Point(39, 452);
			this->ticketSales->Name = L"ticketSales";
			this->ticketSales->Size = System::Drawing::Size(89, 34);
			this->ticketSales->TabIndex = 15;
			this->ticketSales->Text = L"\r\nTicket Sales:";
			// 
			// runtimeTxt
			// 
			this->runtimeTxt->AutoSize = true;
			this->runtimeTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->runtimeTxt->Location = System::Drawing::Point(147, 435);
			this->runtimeTxt->Name = L"runtimeTxt";
			this->runtimeTxt->Size = System::Drawing::Size(65, 17);
			this->runtimeTxt->TabIndex = 16;
			this->runtimeTxt->Text = L"136 Mins";
			this->runtimeTxt->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_2);
			// 
			// saleTxt
			// 
			this->saleTxt->AutoSize = true;
			this->saleTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->saleTxt->Location = System::Drawing::Point(147, 465);
			this->saleTxt->Name = L"saleTxt";
			this->saleTxt->Size = System::Drawing::Size(96, 17);
			this->saleTxt->TabIndex = 17;
			this->saleTxt->Text = L"$463,517,383";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(523, 506);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 23);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Store Material";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(884, 561);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->saleTxt);
			this->Controls->Add(this->runtimeTxt);
			this->Controls->Add(this->ticketSales);
			this->Controls->Add(this->keywords);
			this->Controls->Add(this->keywordList);
			this->Controls->Add(this->Runtime);
			this->Controls->Add(this->languageTxt);
			this->Controls->Add(this->Language);
			this->Controls->Add(this->releaseStateTxt);
			this->Controls->Add(this->treeView1);
			this->Controls->Add(this->releaseState);
			this->Controls->Add(this->releaseDateTxt);
			this->Controls->Add(this->releaseDate);
			this->Controls->Add(this->genreTxt);
			this->Controls->Add(this->Summary);
			this->Controls->Add(this->Genre);
			this->Controls->Add(this->summaryTxt);
			this->Controls->Add(this->movieTitle);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Selected Movie";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
			 
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void genreName_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
}
private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Genre_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void releaseDateTxt_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void releaseDate_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void releaseState_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click_2(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {








}
};
}
