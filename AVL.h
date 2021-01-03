
#include "Node.h"

class NodeAVL : public Node
{
public:

	NodeAVL* left;
	NodeAVL* right;
	int height;
	int getHeight(NodeAVL* N);
	NodeAVL* newNode(int key);
	NodeAVL* rightRotate(NodeAVL* y);
	NodeAVL* leftRotate(NodeAVL* x);
	int getBalance(NodeAVL* N);
	NodeAVL* Insert(NodeAVL* node, int key);
	NodeAVL* getMinimum(NodeAVL* node);
	NodeAVL* deleteNode(NodeAVL* root, int key);
	NodeAVL* Search(NodeAVL* root, int key);
	void PostOrderPrint(NodeAVL*);
};


class AVL
{

public:
	NodeAVL* root;

	void PostOrderPrint();
	NodeAVL* Delete(int key);
	NodeAVL* Search(int key);
	NodeAVL* Insert(int key);
	AVL();
};
