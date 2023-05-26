#include "BinaryMinHeapInt.h"
#include"BTreeInt.h"

#include <iostream>
using namespace std;

void main()
{
	BinaryMinHeapInt h(20);
	h.insert(15);
	h.insert(20);
	h.insert(3);
	h.insert(8);
	h.insert(22);
	h.insert(7);
	h.insert(17);
	h.print();
	BTreeInt* t = BTreeInt::BinaryTreeFromMinHeap(h);
	t->inorder();
	cout << endl;
	t->preorder();
}
