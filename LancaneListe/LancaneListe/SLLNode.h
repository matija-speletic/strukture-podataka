#pragma once
#include <iostream>
using namespace std;
template <class Tip>
class SLLNode
{
	SLLNode<Tip>* link;
	Tip info;
public:
	SLLNode() { link = NULL; }
	SLLNode(Tip el) { link = NULL; info = el; }
	SLLNode(Tip el, SLLNode<Tip>* n) { info = el; link = n; }
	Tip getInfo() { return info; }
	SLLNode<Tip>* getLink() { return link; }
	void setLink(SLLNode<Tip>* lnk) { link = lnk; }
	bool isEqual(Tip el) { return el == info; }
};

