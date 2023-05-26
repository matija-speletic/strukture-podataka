#pragma once
#include "LListNode.h"
class LList
{
protected:
	LListNode *head, *tail;
public:
	LList();
	~LList();
	bool isEmpty();
	void addToHead(int el);
	void addToTail(int el);
	int deleteFromHead();
	int deleteFromTail();
	LListNode* findNodePtr(int el);
	LListNode* getHead();
	LListNode* getNext(LListNode* ptr);
	int getHeadEl();
	int getNextEl(int el);
	void printAll();
	void printAllKV();
	bool isInList(int el);
	void deleteEl(int el);
	LListNode* removeNodeFromHead();




	//ISPITNI ZADACI

	//JUN 2021
	LList* extractEven();

	//JUN 2020
	void InsertOrUpdate(int key, int value);

	//SEPTEMBAR 2020
	void UpdateNode(int key, int value);

	//JUN2 2020
	void Exchange(LList* l, int value, int length);

	//DECEMBAR 2020
	static LList* formList(int arr[], int n);

	//KOLOKVIJUM1 2017
	void fillInTheBlanks();
	void fillInTheBlanks2();

	//OKTOBAR 2017(po sicefu)
	void Compact();

	//APRIL 2017
	void MoveToBeginning(int value);

	//FEBRUAR 2017
	void swapMinMax();
};

