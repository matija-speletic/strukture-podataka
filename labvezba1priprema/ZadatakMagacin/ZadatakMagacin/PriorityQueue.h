#pragma once
#include "iostream";
using namespace std;

class PQNode
{
public:
	int value;
	PQNode* next;
	PQNode(int val,PQNode*nxt):value(val),next(nxt){}
};

class PriorityQueue
{
private:
	PQNode** arr;
	PQNode* head;
	int n;
	int numOfElements;
public:
	PriorityQueue(int n)
	{
		this->n = n;
		arr = new PQNode * [n];
		for(int i=0;i<n;i++)
		numOfElements = 0;
		
	}
	void enqueue(int val, int priority)
	{
		arr[priority] = new PQNode(val, arr[priority]);
		if (priority == 0)
			head = arr[priority];
		else
			arr[priority - 1] = arr[priority];
		numOfElements++;
	}
};

