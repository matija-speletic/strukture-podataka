#pragma once
#include "BSTNode.h"
#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;

class BSTreeInt
{
protected:
	BSTNodeInt* root;
	long numOfElements;
public:
	BSTreeInt() :root(nullptr), numOfElements(0) {  }
	~BSTreeInt() { deleteTree(root); }
	BSTNodeInt* getRoot() { return root; }

	bool isEmpty()const { return root == nullptr; }
	BSTNodeInt* search(int el)const;
	bool isInTree(int el)const { return search(el) != nullptr;	}

	void deleteTree(BSTNodeInt* ptr);

	void inorder(const BSTNodeInt* ptr) const;
	void preorder(const BSTNodeInt* ptr) const;
	void postorder(const BSTNodeInt* ptr) const;

	void inorder() const { inorder(root); }
	void preorder() const { preorder(root); }
	void postorder() const { postorder(root); }

	void insert(int el);
	void deleteByCopying(int el);
	void deleteByMerging(int el);

	void balance(int data[], int first, int last);
	void breadthFirstSearch()const;
	void iterativePreorder()const;
	void iterativePostorder()const;
	void iterativeInorder()const;

	void upisi(int data[], BSTNodeInt* ptr, int i);
	int dubina(BSTNodeInt* ptr);
	int dubina() { return dubina(root); }
	void prikazi();

	int tezina(BSTNodeInt* ptr);
	int tezina() { return tezina(root); }
	void obrisiListove(BSTNodeInt* ptr);
	void obrisiListove() { obrisiListove(root); }
	int brojCvorovaUNivou(BSTNodeInt* ptr, int trenutniNivo, int trazeniNivo);
	void upisiBrojeveCvorovaUSvakomNivou(BSTNodeInt* ptr, int trenutniNivo, int* brojeviCvorovaUSvakomNivou);
	int maxBrojCvorovaPoNivou();
	BSTreeInt* mirrorCopy();
	int istihIma(BSTNodeInt* ptr, int referentni);
	int brojRazlicitih(BSTNodeInt* ptr);

	//sa blanketa
	int getMaxLevel();//januar 2020 z3b
	BSTNodeInt* findClosestValue(BSTNodeInt* ptr, int value);
	static int brojRazlika(BSTNodeInt* t1, BSTNodeInt* t2);
	int getDepth(BSTNodeInt* ptr);
	int Sum(BSTNodeInt* p, int min, int max);
	BSTNodeInt* maxChildSum(BSTNodeInt* ptr, int& maxSum);
	static BSTreeInt* mergeTrees(BSTreeInt* t1, BSTreeInt* t2);
	void topMostNoChildren(BSTNodeInt* root, int level, BSTNodeInt** result, int* resultLevel);
};

