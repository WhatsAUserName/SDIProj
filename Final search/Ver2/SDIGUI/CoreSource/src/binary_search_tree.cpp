#include "binary_search_tree.h"


Node::Node(std::string value, Project *project) : parent(NULL), left(NULL), right(NULL)
{
	data = value;
	linkProject = project;
}

std::string Node::getData()
{
	return data;
}


void Node::updateLeft(Node* pointer)
{
	left = pointer;
}

void Node::updateRight(Node* pointer)
{
	right = pointer;
}


void Node::updateParent(Node* pointer)
{
	parent = pointer;
}


Node* Node::getLeft()
{
	return left;
}


Node* Node::getRight()
{
	return right;
}


Node* Node::getParent()
{
	return parent;
}
Project* Node::getlinkProject()
{
	return linkProject;
}

void BinaryTree::removeNode(Node*delNode)
{
	//remove a node will remove all its child node
	if (delNode)
	{
		removeNode(delNode->getLeft());
		removeNode(delNode->getRight());
		delete delNode;
	}
}


BinaryTree:: ~BinaryTree()
{
	removeNode(root);
}


Node* BinaryTree::getRoot()
{
	return root;
}


void BinaryTree::addNode(Node*newNode)
{
	if (!root)
	{
		root = newNode;
	}

	else
	{
		Node*temp = root;
		Node*parent = NULL;

		while (temp)
		{
			parent = std::move(temp);

			//this prevents from the case there are 2 same keyword associated one project added to node
			if ((newNode->getData() == temp->getData()) && (newNode->getlinkProject() == temp->getlinkProject()))
			{
				return;
			}

			//find position to add new node
			if (newNode->getData() >= temp->getData())
			{
				temp = temp->getRight();
			}
			else
			{
				temp = temp->getLeft();
			}
		}

		//add new node to left or right
		if (newNode->getData() >= parent->getData())
		{
			parent->updateRight(newNode);
		}
		else
		{
			parent->updateLeft(newNode);
		}

		newNode->updateParent(parent);

	}
}

void BinaryTree::addNode(std::string nodeVal, Project *linkProject)
{
	Node *newNode = new Node(nodeVal, linkProject);
	this->addNode(newNode);
}

std::vector<Node*> BinaryTree::findNode(std::string key)
{
	std::vector<Node*> nodeList;
	Node*temp = root;

	while (temp)
	{
		std::string nodeVal = temp->getData();

		if (nodeVal == key)
		{
			nodeList.push_back(temp);
			temp = temp->getRight();
		}
		else if (nodeVal > key)
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
	}

	return nodeList;
}


Node* BinaryTree::findMin(Node*current)
{
	Node*temp = current;
	Node*prev;
	while (temp)
	{
		prev = temp;
		temp = temp->getLeft();
	}

	return prev;
}


Node* BinaryTree::findMax(Node*current)
{
	Node*temp = root;
	Node*prev;
	while (temp)
	{
		prev = temp;
		temp = temp->getRight();
	}

	return prev;
}