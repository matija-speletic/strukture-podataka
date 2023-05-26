#pragma once

#include "BSTNodeInt.h"

class BSTreeInt
{
protected:
	BSTNodeInt* root;
	long numOfElements;

	void deleteTree(BSTNodeInt* ptr);

	void inorder(const BSTNodeInt* ptr) const;
	void preorder(const BSTNodeInt* ptr) const;
	void postorder(const BSTNodeInt* ptr) const;

public:
	BSTreeInt() { root = nullptr; numOfElements = 0; }
	~BSTreeInt() { deleteTree(root); }

	bool isEmpty() const { return root == nullptr; }

	bool isInTree(int el) const { return search(el) != nullptr; }
	BSTNodeInt* search(int el) const;

	void insert(int el);
	void deleteByCopying(int el);
	void deleteByMerging(int el);

	void preorder() const { preorder(root); }
	void inorder() const { inorder(root); }
	void postorder() const { postorder(root); }

	void iterativePreorder() const;
	void breadthFirstSearch() const;

	BSTNodeInt* getRoot() { return root; }
	int getNumOfElements() { return numOfElements; }




	//ispitni zadaci

	//jun2021
	int countSL();
	int zbirPodstablaIBrojSL(BSTNodeInt* node, int* brojSL);
	int countSLHelper(BSTNodeInt* node, int* br);

	//jun2020
	BSTNodeInt* maxZbirPotomaka();
	void traziMaxZbir(int* maxSum, BSTNodeInt** maxNode, BSTNodeInt* node);

	//septembar2020
	static int brojRazlika(BSTreeInt* t1, BSTreeInt* t2);
	static void traziRazlike(int* brojRazlika, BSTNodeInt* n1, BSTNodeInt* n2);

	//junII2020
	static BSTNodeInt* findClosestValueLeaf(BSTNodeInt* root, int value);
	static void traziNajbliziList(BSTNodeInt* node, int value, int* closest, BSTNodeInt** closestNode);

	//oktobar2020
	static int findMaxPathLeaf(BSTNodeInt* root, BSTNodeInt** leaf);
	static void traziMaxPut(BSTNodeInt* node, int currentPath, int* maxPath, BSTNodeInt** maxLeaf);


	//teorijski deo
	static void formirajNizOdBST(int niz[], BSTNodeInt* node, int* index);

	//septembar2019
	static BSTNodeInt* deepestLeaf(BSTNodeInt* root);
	static void traziNajdubljiList(BSTNodeInt* node, int depth, BSTNodeInt** deepestLeaf, int* maxDepth);

	//jun2018
	BSTNodeInt* maxDifferenceSubtree();
	int traziNajvecuRazliku(BSTNodeInt* node, int* maxDiff, BSTNodeInt** maxDiffNode);

	//teorijski deo
	static BSTreeInt* createTreeFromArray(int arr[], int n);

	//septembar2018
	void topmostNoChildren(BSTNodeInt* root, int level, BSTNodeInt** result, int* resultLevel);
	void topmostNoChildren2(BSTNodeInt* root, int level, BSTNodeInt** result, int* resultLevel);

	//januar2020
	int GetMaxLevel();

	//oktobarII2018
	int maxLevelNodes(BSTNodeInt* node, int* count);
	int maxLevelNodes2(BSTNodeInt* node, int* count);

	//april2018
	int levelDiff(int v1, int v2);
	static void findLevelDiff(int v1, int v2, BSTNodeInt* node, int level, int* level1, int* level2);

	//DECEMBAR 2020
	BSTNodeInt* findMaxTested(BSTNodeInt* node, int day);//key igra ulogu i day i broj testiranih
	int findMaxSubtree(BSTNodeInt* node, int day, BSTNodeInt** currentMax, int* maxSum);

	//KOLOKVIJUM2(POPRAVNI) 2019 (vraća info vrednost čvora čija je razlika visina levog i desnog podstabla maksimalna)
	int maxDif();
	int findMaxHeightDiff(BSTNodeInt* n, int* maxHeightDiff, int* maxNode);
	int findMaxHeightDiff2(BSTNodeInt* n, int* maxHeightDiff, int* maxNode);


	//KOLOKVIJUM2 2018
	bool isBalanced();
	int checkIfBalanced(BSTNodeInt* n, bool* balanced);

	//KOLOKVIJUM2 2017
	void longestLeftPath(BSTNodeInt* r, BSTNodeInt** start, int* maxLength);
	int leftPath(BSTNodeInt* n);

	//OKTOBAR 2017
	int Sum(int min, int max);
	void getSum(BSTNodeInt* n, int min, int max, int level, int* sum);

	//APRIL 2017
	int getDepth(int n);
	void findDepth(BSTNodeInt* r, int n, int level, int* depth);

	//KOLOKVIJUM2 2021
	void deleteAllLeftLeaves(BSTNodeInt* n);
	void deleteAllLeftLeaves2(BSTNodeInt* n);

	//MOJ ZADATAK 1
	BSTreeInt* MirrorCopy();
	void mirrorCopyBST(BSTNodeInt* copy, const BSTNodeInt* orig);
	void Mirror(BSTNodeInt* root);

	//SEPTEMBAR 2016
	int findPathWithMostOddNodes(BSTNodeInt* root, BSTNodeInt** leaf);
	void fintPathWithMostOddNodesHelper(BSTNodeInt* n, BSTNodeInt** leaf, int* maxOdd, int currOdds);



	int visina(BSTNodeInt* n, int* maxRazVis, BSTNodeInt** maxRazCvor);
	int maxNode(int& maxDif);

	void maxPathHelper(BSTNodeInt* n, int* maxPath, BSTNodeInt** maxSumLeaf, int trenutnaSuma);
	int findMaxPathLeaf2(BSTNodeInt* root, BSTNodeInt** leaf);

	int GetMaxLevel2();
	
};

