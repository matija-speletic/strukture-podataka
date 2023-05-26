#pragma once
#include <iostream>
using namespace std;
template <class T>
class DLLNode
{
public:
	DLLNode<T>* prev, * next;
	T info;
	DLLNode() { prev = next = NULL; }
	DLLNode(T el) { prev = next = NULL; info = el; }
	DLLNode(T el, DLLNode<T>* p, DLLNode<T>* n) { prev = p; next = n; info = el; }
	T getInfo() { return info; }
	DLLNode<T>* getPrev() { return prev; }
	DLLNode<T>* getNext() { return next; }
	void setPrev(DLLNode<T>* p) { prev = p; }
	void setNext(DLLNode<T>* n) { next = n; }
	bool isEqual(T el) { el == info; }

};