#pragma once
#include "BSTNode.h"

class Queue
{
protected:
	BSTNodeInt** arr;
	long size;
	long head;
	long tail;
	long num;
public:
	Queue(long s);
	~Queue() { delete[] arr; }
	bool isEmpty() { return num == 0; }
	long numOfEl() { return num; }
	BSTNodeInt* getHead()const;
	void enqueue(BSTNodeInt* el);
	BSTNodeInt* dequeue();
};

