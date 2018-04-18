#pragma once
#include <string>
#include <vector>
#include "file_parser.h"

class Node
{
private:
	std::string data;
	Node *left;
	Node *right;
	Node *parent;

	//this pointer shall link point to Project contain data of this node
	Project *linkProject;

public:
	Node(std::string value, Project *project);
	~Node() {};
	std::string getData();
	void updateLeft(Node* pointer);
	void updateRight(Node* pointer);
	void updateParent(Node* pointer);
	Node* getLeft();
	Node* getRight();
	Node* getParent();
	Project* getlinkProject();
};

class BinaryTree
{
private:
	Node *root;
	void removeNode(Node *delNode);

public:
	BinaryTree() : root(NULL) {}
	~BinaryTree();
	Node* getRoot();
	Node* findMin(Node *current);
	Node* findMax(Node *current);
	std::vector<Node*> findNode(std::string key);
	void addNode(Node *newNode);
	void addNode(std::string nodeVal, Project *linkProject);
};