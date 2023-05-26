#pragma once
#include <iostream>
using namespace std;
template <class T>
class SLLNode
{
	SLLNode<T>* link;
	T info;
public:
	SLLNode() { link = NULL; }
	SLLNode(T el) { link = NULL; info = el; }
	SLLNode(T el, SLLNode<T>* n) { info = el; link = n; }
	T getInfo() { return info; }
	SLLNode<T>* getLink() { return link; }
	void setLink(SLLNode<T>* lnk) { link = lnk; }
	bool isEqual(T el) { return el == info; }
};
