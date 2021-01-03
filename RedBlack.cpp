#include <iostream> 

#include "RB.h"

using namespace std;


NodeRB::NodeRB(int val) {
	key = val;
	parent = left = right = NULL;
	color = 1;
}

NodeRB* NodeRB::getUncle() {
	if (parent == NULL || parent->parent == NULL)
		return NULL;

	if (parent->isLeft())
		return parent->parent->right;

	return parent->parent->left;
}

bool NodeRB::isLeft() { return this == parent->left; }


NodeRB* NodeRB::sibling() {

	if (parent == NULL)
		return NULL;

	if (isLeft())
		return parent->right;

	return parent->left;
}


void NodeRB::moveDown(NodeRB* nParent) {
	if (parent != NULL) {
		if (isLeft()) {
			parent->left = nParent;
		}
		else {
			parent->right = nParent;
		}
	}
	nParent->parent = parent;
	parent = nParent;
}

bool NodeRB::haveRedSubTree() {
	return (left != NULL && left->color == 1) ||
		(right != NULL && right->color == 1);
}





void RBTree::leftRotate(NodeRB* x) {

	NodeRB* nParent = x->right;


	if (x == root)
		root = nParent;

	x->moveDown(nParent);


	x->right = nParent->left;

	if (nParent->left != NULL)
		nParent->left->parent = x;


	nParent->left = x;
}

void RBTree::rightRotate(NodeRB* x) {

	NodeRB* nParent = x->left;


	if (x == root)
		root = nParent;

	x->moveDown(nParent);


	x->left = nParent->right;

	if (nParent->right != NULL)
		nParent->right->parent = x;


	nParent->right = x;
}

void RBTree::swapColors(NodeRB* a, NodeRB* b) {
	int temp;
	temp = a->color;
	a->color = b->color;
	b->color = temp;
}

void RBTree::swapValues(NodeRB* a, NodeRB* b) {
	int temp;
	temp = a->key;
	a->key = b->key;
	b->key = temp;
}


void RBTree::fixRed(NodeRB* x) {

	if (x == root) {
		x->color = 0;
		return;
	}


	NodeRB* parent = x->parent;
	NodeRB* secondParent = parent->parent;
	NodeRB* uncle = x->getUncle();

	if (parent->color != 0) {
		if (uncle != NULL && uncle->color == 1) {

			parent->color = 0;
			uncle->color = 0;
			secondParent->color = 1;
			fixRed(secondParent);
		}
		else {

			if (parent->isLeft()) {
				if (x->isLeft()) {

					swapColors(parent, secondParent);
				}
				else {
					leftRotate(parent);
					swapColors(x, secondParent);
				}

				rightRotate(secondParent);
			}
			else {
				if (x->isLeft()) {

					rightRotate(parent);
					swapColors(x, secondParent);
				}
				else {
					swapColors(parent, secondParent);
				}


				leftRotate(secondParent);
			}
		}
	}
}


NodeRB* RBTree::successor(NodeRB* x) {
	NodeRB* temp = x;

	while (temp->left != NULL)
		temp = temp->left;

	return temp;
}


NodeRB* RBTree::Replace(NodeRB* x) {

	if (x->left != NULL && x->right != NULL)
		return successor(x->right);


	if (x->left == NULL && x->right == NULL)
		return NULL;


	if (x->left != NULL)
		return x->left;

	return x->right;
}

void RBTree::deleteNode(NodeRB* v) {
	NodeRB* u = Replace(v);

	bool uvBlack = ((u == NULL || u->color == 0) && (v->color == 0));
	NodeRB* parent = v->parent;

	if (u == NULL) {

		if (v == root) {

			root = NULL;
		}
		else {
			if (uvBlack) {

				fixBlack(v);
			}
			else {

				if (v->sibling() != NULL)

					v->sibling()->color = 1;
			}


			if (v->isLeft()) {
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}
		}
		delete v;
		return;
	}

	if (v->left == NULL || v->right == NULL) {

		if (v == root) {

			v->key = u->key;
			v->left = v->right = NULL;
			delete u;
		}
		else {

			if (v->isLeft()) {
				parent->left = u;
			}
			else {
				parent->right = u;
			}
			delete v;
			u->parent = parent;
			if (uvBlack) {

				fixBlack(u);
			}
			else {

				u->color = 0;
			}
		}
		return;
	}


	swapValues(u, v);
	deleteNode(u);
}

void RBTree::fixBlack(NodeRB* x) {
	if (x == root)

		return;

	NodeRB* sibling = x->sibling(), * parent = x->parent;
	if (sibling == NULL) {

		fixBlack(parent);
	}
	else {
		if (sibling->color == 1) {

			parent->color = 1;
			sibling->color = 0;
			if (sibling->isLeft()) {

				rightRotate(parent);
			}
			else {

				leftRotate(parent);
			}
			fixBlack(x);
		}
		else {

			if (sibling->haveRedSubTree()) {

				if (sibling->left != NULL && sibling->left->color == 1) {
					if (sibling->isLeft()) {

						sibling->left->color = sibling->color;
						sibling->color = parent->color;
						rightRotate(parent);
					}
					else {

						sibling->left->color = parent->color;
						rightRotate(sibling);
						leftRotate(parent);
					}
				}
				else {
					if (sibling->isLeft()) {

						sibling->right->color = parent->color;
						leftRotate(sibling);
						rightRotate(parent);
					}
					else {

						sibling->right->color = sibling->color;
						sibling->color = parent->color;
						leftRotate(parent);
					}
				}
				parent->color = 0;
			}
			else {

				sibling->color = 1;
				if (parent->color == 0)
					fixBlack(parent);
				else
					parent->color = 0;
			}
		}
	}
}



void NodeRB::PostOrderPrint(NodeRB* root)
{
	if (!root) {
		return;
	}
	PostOrderPrint(root->left);
	PostOrderPrint(root->right);
	std::cout << root->key;

}


void RBTree::PostOrderPrint()
{

	root->PostOrderPrint(root);
}



RBTree::RBTree()
{
	root = NULL;
}

NodeRB* RBTree::getRoot() { return root; }


NodeRB* RBTree::search(int n) {
	NodeRB* temp = root;
	while (temp != NULL) {
		if (n < temp->key) {
			if (temp->left == NULL)
				break;

			temp = temp->left;
		}
		else if (n == temp->key) {
			break;
		}
		else {
			if (temp->right == NULL)
				break;

			temp = temp->right;
		}
	}

	return temp;
}


void RBTree::Insert(int n) {
	NodeRB* newNode = new NodeRB(n);
	if (root == NULL) {

		newNode->color = 0;
		root = newNode;
	}
	else {
		NodeRB* temp = search(n);

		if (temp->key == n) {

			return;
		}


		newNode->parent = temp;

		if (n < temp->key)
			temp->left = newNode;
		else
			temp->right = newNode;

		fixRed(newNode);
	}
}


void RBTree::Delete(int n) {
	if (root == NULL)
		return;

	NodeRB* v = search(n);

	deleteNode(v);
}


