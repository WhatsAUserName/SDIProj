#include "stdafx.h"
#include<iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;

struct  movie {
	char title[100];
	char director[100];
	char actors[100];
	float price;
};

//Struct identifying the informations in the nodes for
//the binary tree search
struct BstNode {
	string data;
	BstNode* left;
	BstNode* right;
};

movie* details(string storage) {
	//include file
	return 0;

}

BstNode* GetNewNode(string data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, string data) {
	if (root == NULL) {
		root = GetNewNode(data);
	}

	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(BstNode* root, string data) {
	if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		return true;
	}
	else if (data <= root->data) {
		return Search(root->left, data);
	}
	else {
		return Search(root->right, data);
	}
}
int main() {
	BstNode* root = NULL;  
	root = Insert(root, "BlackPanther"); //data will be replace with the text file
	root = Insert(root, "Avengers");	//data will be replace with the text file
	root = Insert(root, "Spiderman");	//data will be replace with the text file
	root = Insert(root, "E.T.");	//data will be replace with the text file
	root = Insert(root, "Chronicle");	//data will be replace with the text file
	root = Insert(root, "Matrix");	//data will be replace with the text file

	string userInput;
	cout << "Enter the film/movie you'll like to search(Case sensitive): \n";
	cin >> userInput;

	if (Search(root, userInput) == true)
	{
		cout << "Found\n";
		system("pause");
	}
	else
	{
		cout << "Not Found\n";
		system("pause");
	}
}
