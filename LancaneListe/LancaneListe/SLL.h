#pragma once
#include "SLLNode.h"
template <class Tip>
class SLL
{
	SLLNode<Tip>* head;
public:
	SLL() { head = NULL; }
	~SLL();
	bool isEmpty() { return head == NULL; }
	SLLNode<Tip>* getHead() { return head; }
	SLLNode<Tip>* findNodePtr(Tip el);
	SLLNode<Tip>* getLink(SLLNode<Tip>* el) { return el->getLink(); }
	void addToHead(Tip el);
	void addToTail(Tip el);
	Tip deleteFromHead();
	Tip deleteFromTail();
	void printAll();
	bool isInList(Tip el);
	void deleteEl(Tip el);
	//void addAfter(SLLNode<Tip> n, Tip el);
	//void addBefore(SLLNode<Tip> n, Tip el);
};

template<class Tip>
inline SLL<Tip>::~SLL()
{
	while (!isEmpty())
		deleteFromHead();
}

template<class Tip>
inline SLLNode<Tip>* SLL<Tip>::findNodePtr(Tip el)
{
	SLLNode<Tip>* ret = head;
	while (ret->getInfo() != el)
		ret = ret->getLink();
	return ret;
}

template<class Tip>
inline void SLL<Tip>::addToHead(Tip el)
{
	SLLNode<Tip>* temp = new SLLNode<Tip>(el, head);
	head = temp;
}

template<class Tip>
inline void SLL<Tip>::addToTail(Tip el)
{
	SLLNode<Tip>* temp = head, * elm = new SLLNode<Tip>(el);
	if (temp != NULL)
	{
		while (temp->getLink() != NULL) temp = temp->getLink();
		temp->setLink(elm);
	}
	else
		head = elm;
}

template<class Tip>
inline Tip SLL<Tip>::deleteFromHead()
{
	if (isEmpty())
		throw "Brisanje iz praznog niza!";
	SLLNode<Tip>* temp = head;
	Tip tempEl = head->getInfo();
	head = head->getLink();
	delete temp;
	return tempEl;
}

template<class Tip>
inline Tip SLL<Tip>::deleteFromTail()
{
	if (isEmpty())
		throw "Brisanje iz praznog niza!";
	SLLNode<Tip>* imd = head, * nxt = head->getLink();
	for (; nxt->getLink() != NULL; imd = nxt, nxt = nxt->getLink());
	Tip el = nxt->getInfo();
	delete nxt;
	imd->setLink(NULL);
	return el;
}

template<class Tip>
inline void SLL<Tip>::printAll()
{
	for (SLLNode<Tip>* temp = head; temp != NULL; cout << temp->getInfo() << ", ", temp = temp->getLink());
	cout << "\n";
}

template<class Tip>
inline bool SLL<Tip>::isInList(Tip el)
{
	for (SLLNode<Tip>* temp = head; temp != NULL; temp = temp->getLink())
		if (temp->getInfo() == el) return true;
	return false;
}

template<class Tip>
inline void SLL<Tip>::deleteEl(Tip el)
{
	if (isEmpty())throw "Brisanje iz prazne liste";
	SLLNode<Tip>* prev = head, * imd = findNodePtr(el);
	if (imd == NULL)return;
	while (prev->getLink() != imd)prev = prev->getLink();
	prev->setLink(imd->getLink());
	delete imd;
}
