#pragma once
#include "hash0.h";

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
	private:
		HashTableClass * HTPtr;

	private: System::Windows::Forms::TextBox^  KeyTextBox;



	private: System::Windows::Forms::Label^  lblKey;
	private: System::Windows::Forms::TextBox^  ResultTextBox;


	private: System::Windows::Forms::Label^  lblResult;
	private: System::Windows::Forms::Button^  InsertButton;
	private: System::Windows::Forms::Button^  DeleteButton;
	private: System::Windows::Forms::Button^  LookupButton;
	private: System::Windows::Forms::Button^  btnSelect;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ListView^  HashTableListView;

	public:
		search_view(void)
		{
			InitializeComponent();
			//
			HTPtr = new HashTableClass();
			//
		}
		void DisplayTable(void)
		{
			int k;
			ListViewItem^ Item;
			String^ Title = "test";
			String^ summary = "It's about street racing I think? Maybe drag racing, more specifically \n";
			String^ genre = "VroomVroom \n";
			String^ releaseDate = "Like, 2002 or something? \n";
			String^ filmingLocations = "Somewhere in the US \n";
			String^ language = "English \n";
			String^ runtime = "2 hours maybe \n";

			for (k = 0; k < PrimeSize; k++)
			{
				Item = gcnew ListViewItem(k.ToString());
				Item->SubItems->Add(HTPtr->TableArray[k].ToString());
				Item->SubItems->Add(HTPtr->OrderArray[k].ToString());

				Item->SubItems->Add(Title);
				Item->SubItems->Add(summary);
				Item->SubItems->Add(genre);
				Item->SubItems->Add(releaseDate);
				Item->SubItems->Add(filmingLocations);
				Item->SubItems->Add(language);
				Item->SubItems->Add(runtime);


				HashTableListView->Items->Add(Item);
				// if look up true show just the row found
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~search_view()
		{
			delete HTPtr;
			if (components)
			{
				delete components;

			}
		}








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
			this->KeyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->lblKey = (gcnew System::Windows::Forms::Label());
			this->ResultTextBox = (gcnew System::Windows::Forms::TextBox());
			this->lblResult = (gcnew System::Windows::Forms::Label());
			this->InsertButton = (gcnew System::Windows::Forms::Button());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->LookupButton = (gcnew System::Windows::Forms::Button());
			this->HashTableListView = (gcnew System::Windows::Forms::ListView());
			this->btnSelect = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// KeyTextBox
			// 
			this->KeyTextBox->Location = System::Drawing::Point(103, 27);
			this->KeyTextBox->Name = L"KeyTextBox";
			this->KeyTextBox->Size = System::Drawing::Size(159, 20);
			this->KeyTextBox->TabIndex = 4;
			this->KeyTextBox->TextChanged += gcnew System::EventHandler(this, &search_view::textBox1_TextChanged);
			// 
			// lblKey
			// 
			this->lblKey->AutoSize = true;
			this->lblKey->Location = System::Drawing::Point(67, 30);
			this->lblKey->Name = L"lblKey";
			this->lblKey->Size = System::Drawing::Size(28, 13);
			this->lblKey->TabIndex = 9;
			this->lblKey->Text = L"Key:";
			this->lblKey->Click += gcnew System::EventHandler(this, &search_view::label2_Click);
			// 
			// ResultTextBox
			// 
			this->ResultTextBox->Location = System::Drawing::Point(103, 68);
			this->ResultTextBox->Name = L"ResultTextBox";
			this->ResultTextBox->ReadOnly = true;
			this->ResultTextBox->Size = System::Drawing::Size(266, 20);
			this->ResultTextBox->TabIndex = 10;
			// 
			// lblResult
			// 
			this->lblResult->AutoSize = true;
			this->lblResult->Location = System::Drawing::Point(57, 71);
			this->lblResult->Name = L"lblResult";
			this->lblResult->Size = System::Drawing::Size(40, 13);
			this->lblResult->TabIndex = 11;
			this->lblResult->Text = L"Result:";
			// 
			// InsertButton
			// 
			this->InsertButton->Location = System::Drawing::Point(59, 94);
			this->InsertButton->Name = L"InsertButton";
			this->InsertButton->Size = System::Drawing::Size(75, 23);
			this->InsertButton->TabIndex = 12;
			this->InsertButton->Text = L"Insert";
			this->InsertButton->UseVisualStyleBackColor = true;
			this->InsertButton->Click += gcnew System::EventHandler(this, &search_view::InsertButton_Click);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(143, 94);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(75, 23);
			this->DeleteButton->TabIndex = 13;
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &search_view::DeleteButton_Click);
			// 
			// LookupButton
			// 
			this->LookupButton->Location = System::Drawing::Point(600, 27);
			this->LookupButton->Name = L"LookupButton";
			this->LookupButton->Size = System::Drawing::Size(75, 23);
			this->LookupButton->TabIndex = 14;
			this->LookupButton->Text = L"Lookup";
			this->LookupButton->UseVisualStyleBackColor = true;
			this->LookupButton->Click += gcnew System::EventHandler(this, &search_view::LookupButton_Click);
			// 
			// HashTableListView
			// 
			this->HashTableListView->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HashTableListView->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->HashTableListView->GridLines = true;
			this->HashTableListView->Location = System::Drawing::Point(59, 123);
			this->HashTableListView->Name = L"HashTableListView";
			this->HashTableListView->Size = System::Drawing::Size(1276, 302);
			this->HashTableListView->TabIndex = 15;
			this->HashTableListView->UseCompatibleStateImageBehavior = false;
			this->HashTableListView->View = System::Windows::Forms::View::Details;
			this->HashTableListView->SelectedIndexChanged += gcnew System::EventHandler(this, &search_view::HashTableListView_SelectedIndexChanged);
			// 
			// btnSelect
			// 
			this->btnSelect->Location = System::Drawing::Point(681, 27);
			this->btnSelect->Name = L"btnSelect";
			this->btnSelect->Size = System::Drawing::Size(75, 23);
			this->btnSelect->TabIndex = 16;
			this->btnSelect->Text = L"Select";
			this->btnSelect->UseVisualStyleBackColor = true;
			this->btnSelect->Click += gcnew System::EventHandler(this, &search_view::btnSelect_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(308, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(159, 20);
			this->textBox1->TabIndex = 17;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(274, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Title:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Search by ID", L"Search by Title", L"Search by Actor" });
			this->comboBox1->Location = System::Drawing::Point(473, 27);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 19;
			// 
			// search_view
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1360, 461);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btnSelect);
			this->Controls->Add(this->HashTableListView);
			this->Controls->Add(this->LookupButton);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->InsertButton);
			this->Controls->Add(this->lblResult);
			this->Controls->Add(this->ResultTextBox);
			this->Controls->Add(this->lblKey);
			this->Controls->Add(this->KeyTextBox);
			this->Name = L"search_view";
			this->Text = L"search_view";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void HashTableListView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {



}

		 //insert
private: System::Void InsertButton_Click(System::Object^  sender, System::EventArgs^  e) {
	KeyType Key;
	String^ title;

	ResultTextBox->Clear();
	HashTableListView->Clear();

	HashTableListView->Columns->Add("Index", 64, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Key", 64, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Order", 64, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Title", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Summary", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Genre", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Released Date", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Language", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Filming Locations", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Runtime", 120, HorizontalAlignment::Right);
	try
	{
		Key = Int32::Parse(KeyTextBox->Text);
		
		// Insert Key into the table:
		if (HTPtr->Insert(Key))
			ResultTextBox->Text = "Insert succeeded";
		else
			ResultTextBox->Text = "Insert failed";
	}
	catch (...)
	{
		ResultTextBox->Text = "Invalid key";
	}

	DisplayTable();
}
		 //delete
private: System::Void DeleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
	KeyType Key;

	ResultTextBox->Clear();
	HashTableListView->Clear();

	HashTableListView->Columns->Add("Index", 64, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Key", 64, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Order", 64, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Title", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Summary", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Genre", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Released Date", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Language", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Filming Locations", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Runtime", 120, HorizontalAlignment::Right);

	try
	{
		Key = Int32::Parse(KeyTextBox->Text);
		// Delete Key from the table:
		if (HTPtr->Delete(Key))
			ResultTextBox->Text = "Delete succeeded";
		else
			ResultTextBox->Text = "Delete failed";
	}
	catch (...)
	{
		ResultTextBox->Text = "Invalid key";
	}

	DisplayTable();


}
private: System::Void LookupButton_Click(System::Object^  sender, System::EventArgs^  e) {
	KeyType Key;
	int Index;

	ResultTextBox->Clear();
	HashTableListView->Clear();

	HashTableListView->Columns->Add("Index", 64, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Key", 64, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Order", 64, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Title", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Summary", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Genre", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Released Date", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Language", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Filming Locations", 120, HorizontalAlignment::Right);
	HashTableListView->Columns->Add("Runtime", 120, HorizontalAlignment::Right);

	try
	{
		Key = Int32::Parse(KeyTextBox->Text);
		// Lookup Key in the table:
		if (HTPtr->Lookup(Key, Index))
			ResultTextBox->Text = String::Concat("Found at ", Index.ToString());
		else
			ResultTextBox->Text = "Lookup failed";
	}
	catch (...)
	{
		ResultTextBox->Text = "Invalid key";
	}

	int k;


	DisplayTable();
}

private: System::Void btnSelect_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
