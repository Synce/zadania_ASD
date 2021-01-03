
#include "AVL.h"

#include <iostream>

using namespace std;

int max(int a, int b);


int NodeAVL::getHeight(NodeAVL* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}


int max(int a, int b)
{
	return (a > b) ? a : b;
}


NodeAVL* NodeAVL::newNode(int key)
{
	NodeAVL* node = new NodeAVL();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}


NodeAVL* NodeAVL::rightRotate(NodeAVL* y)
{
	NodeAVL* x = y->left;
	NodeAVL* T2 = x->right;


	x->right = y;
	y->left = T2;


	y->height = max(getHeight(y->left),
		getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left),
		getHeight(x->right)) + 1;


	return x;
}


NodeAVL* NodeAVL::leftRotate(NodeAVL* x)
{
	NodeAVL* y = x->right;
	NodeAVL* T2 = y->left;


	y->left = x;
	x->right = T2;


	x->height = max(getHeight(x->left),
		getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left),
		getHeight(y->right)) + 1;


	return y;
}
int NodeAVL::getBalance(NodeAVL* N)
{
	if (N == NULL)
		return 0;
	return getHeight(N->left) -
		getHeight(N->right);
}

NodeAVL* NodeAVL::Insert(NodeAVL* node, int key)
{

	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = Insert(node->left, key);
	else if (key > node->key)
		node->right = Insert(node->right, key);
	else
		return node;

	node->height = 1 + max(getHeight(node->left),
		getHeight(node->right));


	int balance = getBalance(node);


	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);


	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}


	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}


	return node;
}


NodeAVL* NodeAVL::getMinimum(NodeAVL* node)
{
	NodeAVL* current = node;


	while (current->left != NULL)
		current = current->left;

	return current;
}


NodeAVL* NodeAVL::deleteNode(NodeAVL* root, int key)
{


	if (root == NULL)
		return root;


	if (key < root->key)
		root->left = deleteNode(root->left, key);


	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{

		if ((root->left == NULL) ||
			(root->right == NULL))
		{
			NodeAVL* temp = root->left ?
				root->left :
				root->right;


			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			NodeAVL* temp = getMinimum(root->right);


			root->key = temp->key;


			root->right = deleteNode(root->right,
				temp->key);
		}
	}

	if (root == NULL)
		return root;


	root->height = 1 + max(getHeight(root->left),
		getHeight(root->right));

	int balance = getBalance(root);

	if (balance > 1 &&
		getBalance(root->left) >= 0)
		return rightRotate(root);


	if (balance > 1 &&
		getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}


	if (balance < -1 &&
		getBalance(root->right) <= 0)
		return leftRotate(root);

	if (balance < -1 &&
		getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}
NodeAVL* NodeAVL::Search(NodeAVL* root, int key)
{

	if (root == NULL || root->key == key)
		return (NodeAVL*)root;

	if (root->key < key)
		return Search(root->right, key);


	return Search(root->left, key);
}

void NodeAVL::PostOrderPrint(NodeAVL* root)
{
	if (!root) {
		return;
	}
	PostOrderPrint(root->left);
	PostOrderPrint(root->right);
	std::cout << root->key;

}


void AVL::PostOrderPrint()
{

	root->PostOrderPrint(root);
}



NodeAVL* AVL::Delete(int key)
{
	root = root->deleteNode(root, key);
	return root;

}
NodeAVL* AVL::Search(int key)
{
	return   root->Search(root, key);

}
NodeAVL* AVL::Insert(int key)
{
	root = root->Insert(root, key);
	return root;

}
AVL::AVL()
{
	root = NULL;
}