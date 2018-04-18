#pragma once
#include "binary_search_tree.h"
#include "file_parser.h"

typedef enum
{
	TITLE,
	CREW,
	STATE,
	KEYWORD,
}SearchField;

class BinarySearch
{
private:
	BinaryTree *TitleTree;
	BinaryTree *CrewTree;
	BinaryTree *StateTree;
	BinaryTree *KeyWordTree;

	std::vector<Project> projects;

	bool crewFound(std::vector<Crew> crews, std::string crewName);
	bool dataCompare(std::string data, std::string keyword);
public:
	BinarySearch();
	~BinarySearch();

	/*
	 * Load data to binary search tree
	 */
	void LoadBST();
	std::vector<Project*> SearchIt(std::string keyWord, SearchField field);
};
