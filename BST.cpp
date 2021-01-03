#include "BST.h"

#include <iostream> 
using namespace std;


NodeBST* NodeBST::newNode(int key)
{
	NodeBST* node = new NodeBST();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

NodeBST* NodeBST::Insert(NodeBST* root, int value)
{
	if (!root)
	{
		return newNode(value);
	}


	if (value > root->key)
	{
		root->right = Insert((NodeBST*)root->right, value);
	}
	else
	{
		root->left = Insert((NodeBST*)root->left, value);
	}


	return (NodeBST*)root;
}


NodeBST* NodeBST::Search(NodeBST* root, int key)
{

	if (root == NULL || root->key == key)
		return root;

	if (root->key < key)
		return Search((NodeBST*)root->right, key);


	return Search((NodeBST*)root->left, key);
}

int minValue(NodeBST* root)
{

	if (root->left != NULL)
	{
		return 	minValue(root->left);
	}

	return root->key;
};

NodeBST* NodeBST::Delete(NodeBST* root, int key)
{

	if (root == NULL)
		return (NodeBST*)root;


	if (key < root->key)
		root->left = Delete((NodeBST*)root->left, key);
	else if (key > root->key)
		root->right = Delete((NodeBST*)root->right, key);

	else {

		if (root->left == NULL)
			return (NodeBST*)root->right;
		else if (root->right == NULL)
			return (NodeBST*)root->left;


		root->key = minValue(root->right);


		root->right = Delete((NodeBST*)root->right, root->key);
	}

	return (NodeBST*)root;
}

void NodeBST::PostOrderPrint(NodeBST* root)
{
	if (!root) {
		return;
	}
	PostOrderPrint(root->left);
	PostOrderPrint(root->right);
	std::cout << root->key;

}

void BST::PostOrderPrint()
{

	root->PostOrderPrint(root);
}



NodeBST* BST::Delete(int key)
{
	root = root->Delete(root, key);
	return root;

}
NodeBST* BST::Search(int key)
{
	return   root->Search(root, key);

}
NodeBST* BST::Insert(int key)
{
	root = root->Insert(root, key);
	return root;

}

BST::BST()
{
	root = NULL;
}