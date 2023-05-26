#pragma once
#include <iostream>
#include "SLL.h"
using namespace std;

template<class T>
class Stack
{
public:
	virtual void push(T el) = 0;
	virtual T pop() = 0;
	virtual T getHead() = 0;
	virtual bool isEmpty() = 0;
	//virtual bool isFull() = 0;
	virtual int numOfEl() = 0;
	virtual void printStack(){}
	static void ReverseAStack(Stack<T>* s_src, Stack<T>* s_dest);
};

template <class T>
class DynamicStack : public Stack<T>
{
	SLL<T>* sll;
public:
	DynamicStack() { sll = new SLL<T>(); }
	~DynamicStack() { delete sll; }
	void push(T el) { sll->addToHead(el); }
	T pop() { return sll->deleteFromHead(); }
	bool isEmpty() { return sll->isEmpty(); }
	int numOfEl()
	{
		int i=0;
		for (SLLNode<T>* tmp = sll->getHead(); tmp != NULL; i++, tmp = tmp->getLink());
		return i;
	}
	T getHead() { return sll->getHead()->getInfo(); }
	void printStack()
	{
		int i = 0;
		for (SLLNode<T>* tmp = sll->getHead(); tmp != NULL; i++, tmp = tmp->getLink())
			cout << tmp->getInfo() << endl;
		cout << endl;
	}
};

template<class T>
class StaticStack :public Stack<T>
{
	T* arr;
	int cap;
	int top;
public:
	StaticStack(int c) 
	{
		cap = c;
		arr = new T[cap];
		top = -1;
	}
	~StaticStack() { delete[] arr; }
	void push(T el)
	{
		if (top + 1 == cap)throw "Stack overflow!";
		arr[++top] = el;
	}
	T pop()
	{
		if (top == -1)throw "Stack underflow!";
		return arr[top--];
	}
	T getHead() { return arr[top]; }
	bool isEmpty() { return top == -1; }
	int numOfEl() { return top + 1; }
	void printStack()
	{
		for (int i = top; i >= 0; i--)
			cout << arr[i] << endl;
		cout << endl;
	}
};

template<class T>
inline void Stack<T>::ReverseAStack(Stack<T>* s_src, Stack<T>* s_dest)
{
	Stack<T>* temp = new DynamicStack<T>();
	while (!s_src->isEmpty())
	{
		s_dest->push(s_src->getHead());
		temp->push(s_src->pop());
	}
	while (!temp->isEmpty())
		s_src->push(temp->pop());
}
