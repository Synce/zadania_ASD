
#include <iostream>


#include "AVL.h"
#include "Sorting.h"

#include  "BST.h"
#include "RB.h"

using namespace std;




int main()
{
	int arr[10] = { 4,3,1,5,3,7,8,2,1,4 };
	int arr2[10] = { 4,3,1,5,3,7,8,2,1,4 };
	int arr3[10] = { 4,3,1,5,3,7,8,2,1,4 };
	N::Sorting sorting;



	cout << "InsertSort" << endl;



	sorting.print(arr3, 10);
	sorting.test(arr3, 10);
	sorting.insertSort(arr3, 10);
	sorting.print(arr3, 10);
	sorting.test(arr3, 10);



	cout << "mergeSort" << endl;

	sorting.print(arr2, 10);
	sorting.test(arr2, 10);
	sorting.heapSort(arr2, 10);
	sorting.print(arr2, 10);
	sorting.test(arr2, 10);


	cout << "heapSort" << endl;
	sorting.print(arr, 10);
	sorting.test(arr, 10);
	sorting.heapSort(arr, 10);
	sorting.print(arr, 10);
	sorting.test(arr, 10);



	BST tree_bst = BST();

	tree_bst.Insert(3);

	tree_bst.Insert(5);

	tree_bst.Insert(2);

	tree_bst.Insert(7);

	tree_bst.Insert(8);
	tree_bst.Insert(3);
	cout << endl << "bst " << endl;
	tree_bst.PostOrderPrint();



	AVL avl_tree = AVL();

	avl_tree.Insert(1);

	avl_tree.Insert(3);

	avl_tree.Insert(5);

	avl_tree.Insert(4);
	avl_tree.Insert(2);

	cout << endl << endl << "avl" << endl;
	avl_tree.PostOrderPrint();


	RBTree rb_tree = RBTree();

	rb_tree.Insert(7);
	rb_tree.Insert(3);
	rb_tree.Insert(18);
	rb_tree.Insert(10);
	rb_tree.Insert(22);
	rb_tree.Insert(8);
	rb_tree.Delete(18);
	cout << endl << endl << "rb" << endl;
	rb_tree.PostOrderPrint();




}
