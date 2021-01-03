#pragma once
#include "Node.h"

class NodeRB : public Node {
public:
	int key;
	int color;
	NodeRB* left, * right, * parent;

	NodeRB(int val);
	NodeRB* getUncle();
	bool isLeft();
	NodeRB* sibling();
	void moveDown(NodeRB* nParent);
	bool haveRedSubTree();
	void PostOrderPrint(NodeRB* root);
};




class RBTree {



	void leftRotate(NodeRB* x);
	void rightRotate(NodeRB* x);
	void swapColors(NodeRB* a, NodeRB* b);
	void swapValues(NodeRB* a, NodeRB* b);
	void fixRed(NodeRB* x);
	NodeRB* successor(NodeRB* x);
	NodeRB* Replace(NodeRB* x);
	void deleteNode(NodeRB* v);
	void fixBlack(NodeRB* x);

	NodeRB* getRoot();

public:
	NodeRB* search(int n);
	NodeRB* root;
	void Insert(int n);
	void Delete(int n);
	void PostOrderPrint();
	RBTree();
};