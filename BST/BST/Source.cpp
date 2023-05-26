#include "BSTree.h"
#include <iostream>
using namespace std;

int main()
{
	BSTreeInt* tree = new BSTreeInt();
	int br = 0;
	while (br != -1)
	{
		cin >> br;
		tree->insert(br);
	}
	/*cin >> br;
	cout << endl;
	tree->inorder();
	cout << endl;
	tree->preorder();
	cout << endl;
	tree->postorder();*/
	/*cout << endl;
	tree->breadthFirstSearch();

	cout << endl;
	/*tree->iterativeInorder();
	cout << endl;
	tree->iterativePreorder();
	cout << endl;
	tree->iterativePostorder();
	cout << endl;

	while (br != -1)
	{
		cin >> br;
		tree->deleteByCopying(br);
		cout << endl;
		tree->breadthFirstSearch();
		cin >> br;
		tree->deleteByMerging(br);
		cout << endl;
		tree->breadthFirstSearch();
	}*/
	/*cout << tree->dubina() << endl;
	cout << tree->tezina() << endl;
	tree->obrisiListove();
	tree->breadthFirstSearch();*/
	//cout<<tree->maxBrojCvorovaPoNivou();

	/*BSTreeInt* mir = tree->mirrorCopy();
	mir->inorder();
	mir->iterativeInorder();*/

	//cout << tree->istihIma(tree->getRoot(), 5);
	//cout << tree->brojRazlicitih(tree->getRoot());

	/*tree->findClosestValue(tree->getRoot(), 40)->print();
	cout << " ";
	tree->findClosestValue(tree->getRoot(), 28)->print();
	cout << " ";
	tree->findClosestValue(tree->getRoot(), 21)->print();
	cout << " ";
	tree->findClosestValue(tree->getRoot(), 18)->print();
	cout << " ";
	tree->findClosestValue(tree->getRoot(), 38)->print();
	cout << " ";
	tree->findClosestValue(tree->getRoot(), 87)->print();*/

	/*BSTreeInt* tree2 = new BSTreeInt();
	br = 0;
	while (br != -1)
	{
		cin >> br;
		tree2->insert(br);
	}

	cout << BSTreeInt::brojRazlika(tree->getRoot(), tree2->getRoot());*/

	/*cout << tree->getDepth(tree->search(23)) << ", ";
	cout << tree->getDepth(tree->search(39)) << ", ";
	cout << tree->getDepth(tree->search(38)) << ", ";
	cout << tree->getDepth(tree->search(45)) << ", ";
	cout << tree->getDepth(tree->search(11)) << ", ";
	cout << tree->Sum(tree->getRoot(), 2, 3) << ", ";
	int suma;
	tree->maxChildSum(tree->getRoot(), suma)->print();
	cout << "; " << suma;*/

	/*BSTreeInt* tree2 = new BSTreeInt();
	br = 0;
	while (br != -1)
	{
		cin >> br;
		tree2->insert(br);
	}
	BSTreeInt* merged = BSTreeInt::mergeTrees(tree, tree2);
	merged->preorder();*/

	int nesto = -2;
	BSTNodeInt* p;
	tree->topMostNoChildren(tree->getRoot(), 0, &p, &nesto);
	p->print();
	cout << endl;
	cout << nesto;
	delete tree;
	//delete tree2;
}

//     17 43 25 14 30 39 38 27 23 12 45 11 24 22 50 -1

//	   1 1 2 3 4 4 5 5 5 6 7 8 9 9 9 10 11 11 -1