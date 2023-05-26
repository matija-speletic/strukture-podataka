#include "BSTreeInt.h"

void main()
{
	//     17 43 25 14 30 39 38 27 23 12 45 11 24 22 50 -1
	//     17 43 25 14 30 28 38 27 23 12 45 11 24 22 50 -1
	BSTreeInt* tree = new BSTreeInt();
	int br = 0;
	while (br != -1)
	{
		cin >> br;
		if(br!=-1)
			tree->insert(br);
	}
	/*tree->inorder();
	cout << endl;
	tree->postorder();
	cout << endl;
	tree->preorder();
	cout << endl;
	tree->breadthFirstSearch();*/


	//jun2021
	/*cout << endl << tree->countSL();
	*/

	//jun2020
	/*cout << endl << tree->maxZbirPotomaka()->key;
	*/
	
	//septembar2020
	/*BSTreeInt* tree2 = new BSTreeInt();
	int br2 = 0;
	while (br2 != -1)
	{
		cin >> br2;
		tree2->insert(br2);
	}
	cout << endl << BSTreeInt::brojRazlika(tree, tree2);
	delete tree2;*/

	//junII2020
	/*cout << endl << BSTreeInt::findClosestValueLeaf(tree->getRoot(), 29)->getKey();
	* */

	//oktobar2020
	/*BSTNodeInt* leaf = NULL;
	cout << endl << BSTreeInt::findMaxPathLeaf(tree->getRoot(), &leaf) << endl;
	cout << leaf->getKey();*/
	//oktobar2020 (teorijski zadatak)
	/*int a[30];
	int ind = 0;
	BSTreeInt::formirajNizOdBST(a, tree->getRoot(), &ind);
	for (int i = 0; i < tree->getNumOfElements(); i++)
		cout << a[i] << ' ';*/

	//septembar2019
	/*cout << endl << BSTreeInt::deepestLeaf(tree->getRoot())->getKey();
	*/

	//jun2018
	/*cout << endl << tree->maxDifferenceSubtree()->getKey();
	*/
	//jun2018 teorijski zadatak
	/*int a[] = { 17, 43, 25, 14, 30, 39, 38, 27, 23, 12, 45, 11, 24, 22, 50 };
	int n = 15;
	BSTreeInt* t = BSTreeInt::createTreeFromArray(a, n);
	t->breadthFirstSearch(); 
	cout << endl;
	tree->breadthFirstSearch();
	cout << endl;
	t->inorder();
	cout << endl;
	tree->inorder();*/
	
	//septembar2018
	/*BSTNodeInt* res = tree->getRoot();
	int reslev = tree->getNumOfElements();
	tree->topmostNoChildren(tree->getRoot(), 0, &res, &reslev);
	cout << res->key << ' ' << reslev;*/

	//januar2020
	/*cout << endl << tree->GetMaxLevel();
	*/

	//oktobarII2018
	/*int cnt;
	cout << endl << tree->maxLevelNodes2(tree->getRoot(), &cnt);
	cout << endl << cnt;*/

	//april2018
	/*cout << endl << tree->levelDiff(43, 24);
	*/

	//DECEMBAR 2020
	/*tree->findMaxTested(tree->getRoot(), 44);
	cout << endl << endl;
	tree->findMaxTested(tree->getRoot(), 25);
	cout << endl << endl;
	tree->findMaxTested(tree->getRoot(), 15);*/

	//KOLOKVIJUM2(POPRAVNI) 2019
	/*cout << endl << tree->maxDif();
	*/

	//KOLOKVIJUM2 2018
	/*//	   25 12 37 8 16 27 43 4 10 14 -1
	cout << endl << tree->isBalanced();*/

	//KOLOKVIJUM2 2017
	/*BSTNodeInt* ptr = NULL;
	int maxL = 0;
	tree->longestLeftPath(tree->getRoot(), &ptr, &maxL);
	cout << endl << ptr->key << endl << maxL;*/
	
	cout << endl;

	//OKTOBAR 2017
	/*cout << tree->Sum(2, 3);
	*/

	//APRIL 2017
	/*cout << tree->getDepth(17) << endl;
	cout << tree->getDepth(23) << endl;
	cout << tree->getDepth(38) << endl;
	cout << tree->getDepth(10) << endl;*/

	//KOLOKVIJUM2 2021
	/*tree->deleteAllLeftLeaves(tree->getRoot());
	cout << endl;
	tree->inorder();*/

	//MOJ ZADATAK 1
	/*BSTreeInt* t1 = tree->MirrorCopy();
	tree->breadthFirstSearch();
	cout << endl;
	t1->breadthFirstSearch();
	cout << endl << endl << endl;
	tree->inorder();
	cout << endl;
	t1->inorder();
	cout << endl << endl << endl;
	tree->Mirror(tree->getRoot());
	tree->breadthFirstSearch();
	cout << endl;
	t1->breadthFirstSearch();
	cout << endl << endl << endl;
	tree->inorder();
	cout << endl;
	t1->inorder();
	delete t1;*/

	//SEPTEMBAR 2016
	BSTNodeInt* ptr = NULL;
	int n = tree->findPathWithMostOddNodes(tree->getRoot(), &ptr);
	cout << n << ' ' << ptr->key;



	delete tree;
}
