#pragma once
#include "BSTNode.h"
class Stack
{
protected:
	BSTNodeInt** arr;
	long size;
	long top;
public:
	Stack(long s);
	~Stack() { delete[] arr; }
	bool isEmpty() { return top == -1; }
	long numOfEl() { return top + 1; }
	BSTNodeInt* getTop()const;
	void push(BSTNodeInt* el);
	BSTNodeInt* pop();
};


