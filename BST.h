#pragma once
#include "Node.h"

class NodeBST : public Node
{

public:

	NodeBST* left;
	NodeBST* right;
	NodeBST* newNode(int key);
	NodeBST* Search(NodeBST* root, int key);
	NodeBST* Insert(NodeBST* root, int value);
	NodeBST* Delete(NodeBST* root, int key);
	void PostOrderPrint(NodeBST*);
};



class BST
{
public:
	NodeBST* root;

	void PostOrderPrint();
	NodeBST* Delete(int key);
	NodeBST* Search(int key);
	NodeBST* Insert(int key);
	BST();
};

