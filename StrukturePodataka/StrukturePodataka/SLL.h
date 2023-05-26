#pragma once
#include "SLLNode.h"
template <class T>
class SLL
{
public:
	SLLNode<T>* head;
	void swap(SLLNode<T>* n1bef, SLLNode<T>* n2bef, SLLNode<T>* n1, SLLNode<T>* n2);
public:
	SLL() { head = NULL; }
	~SLL();
	bool isEmpty() { return head == NULL; }
	SLLNode<T>* getHead() { return head; }
	SLLNode<T>* findNodePtr(T el);
	SLLNode<T>* findNodeBefore(SLLNode<T>* n);
	SLLNode<T>* getLink(SLLNode<T>* el) { return el->getLink(); }
	void addToHead(T el);
	void addToTail(T el);
	T deleteFromHead();
	T deleteFromTail();
	void printAll();
	bool isInList(T el);
	void deleteEl(T el);
	//void addAfter(SLLNode<Tip> n, Tip el);
	//void addBefore(SLLNode<Tip> n, Tip el);
	void Exchange(SLL<T>& l1, T value, int length);
	void bubbleSort();
	void selectionSort();
	void insertionSort();

};

template<class T>
inline void SLL<T>::swap(SLLNode<T>* before_n1, SLLNode<T>* before_n2, SLLNode<T>* n1, SLLNode<T>* n2)
{
	//funkcija ne radi kad je n1 posle n2 !!!!!!!!!!!!

	if (n1 == n2)//ako su isti, nema menjanja
		return;

	if (n1 == head)//ako je prvi glava - odmah podesi head pokazivac
		//(jer se ne koristi u daljoj obradi)
	{
		head = n2;
		before_n1 = NULL;//postavljanje na null da ne bi doslo do greske
		//jer u ovom slucaju before_n1 nije validna vrednost
	}

	//prelancavanje (objasnjenje - slika)
	//if-ovi stite od greske i od prelancavanje glave
	SLLNode<T>* temp = n1->getLink();
	if (n1 == before_n2)temp = n1; //kad su susedni cvorovi (slika)
	if (n1)n1->setLink(n2->getLink());
	if (n2)n2->setLink(temp);
	if (before_n2 && before_n2!=n1)before_n2->setLink(n1);//kad su susedni cvorovi (slika)
	if (before_n1) before_n1->setLink(n2);
}

template<class T>
inline SLL<T>::~SLL()
{
	while (!isEmpty())
		deleteFromHead();
}

template<class T>
inline SLLNode<T>* SLL<T>::findNodePtr(T el)
{
	SLLNode<T>* ret = head;
	while (ret->getInfo() != el)
		ret = ret->getLink();
	return ret;
}

template<class T>
inline SLLNode<T>* SLL<T>::findNodeBefore(SLLNode<T>* n)
{
	if (n == head)
		return NULL;
	SLLNode<T>* temp;
	for (temp = head; temp->getLink() != n; temp = temp->getLink());
	return temp;
}

template<class T>
inline void SLL<T>::addToHead(T el)
{
	SLLNode<T>* temp = new SLLNode<T>(el, head);
	head = temp;
}

template<class T>
inline void SLL<T>::addToTail(T el)
{
	SLLNode<T>* temp = head, * elm = new SLLNode<T>(el);
	if (temp != NULL)
	{
		while (temp->getLink() != NULL) temp = temp->getLink();
		temp->setLink(elm);
	}
	else
		head = elm;
}

template<class T>
inline T SLL<T>::deleteFromHead()
{
	if (isEmpty())
		throw "Brisanje iz praznog niza!";
	SLLNode<T>* temp = head;
	T tempEl = head->getInfo();
	head = head->getLink();
	delete temp;
	return tempEl;
}

template<class T>
inline T SLL<T>::deleteFromTail()
{
	if (isEmpty())
		throw "Brisanje iz praznog niza!";
	SLLNode<T>* imd = head, * nxt = head->getLink();
	for (; nxt->getLink() != NULL; imd = nxt, nxt = nxt->getLink());
	T el = nxt->getInfo();
	delete nxt;
	imd->setLink(NULL);
	return el;
}

template<class T>
inline void SLL<T>::printAll()
{
	for (SLLNode<T>* temp = head; temp != NULL; cout << temp->getInfo() << ", ", temp = temp->getLink());
	cout << "\n";
}

template<class T>
inline bool SLL<T>::isInList(T el)
{
	for (SLLNode<T>* temp = head; temp != NULL; temp = temp->getLink())
		if (temp->getInfo() == el) return true;
	return false;
}

template<class T>
inline void SLL<T>::deleteEl(T el)
{
	if (isEmpty())throw "Brisanje iz prazne liste";
	SLLNode<T>* prev = head, * imd = findNodePtr(el);
	if (imd == NULL)return;
	while (prev->getLink() != imd)prev = prev->getLink();
	prev->setLink(imd->getLink());
	delete imd;
}

template<class T>
inline void SLL<T>::Exchange(SLL<T>& list, T value, int length)
{
	SLLNode<T>* temp1 = list.getHead();
	SLLNode<T>* temp2 = this->getHead();
	//trazenje cvora u obe lista ciji je sledeci cvor value
	while (temp1->getLink()->getInfo() != value || temp2->getLink()->getInfo() != value)
	{
		if (temp1->getLink()->getInfo() != value)temp1 = temp1->getLink();
		if (temp2->getLink()->getInfo() != value)temp2 = temp2->getLink();
	}
	//prespajanje ovih cvorova
	SLLNode<T>* tempptr = temp1->getLink();
	temp1->setLink(temp2->getLink());
	temp2->setLink(tempptr);
	//prolazak kroz obe liste duzine length
	for (int i = 0; i < length; i++)
	{
		temp1 = temp1->getLink();
		temp2 = temp2->getLink();
	}
	//prespajanje (cak i ako je u pitanju tail, ne menja se kod)
	tempptr = temp1->getLink();
	temp1->setLink(temp2->getLink());
	temp2->setLink(tempptr);
}

template<class T>
inline void SLL<T>::bubbleSort()
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (SLLNode<T>* p1 = head, *p2 = head; p2->getLink() != NULL; p1 = p2, p2 = p2->getLink())
		{
			if (p2->getInfo() > p2->getLink()->getInfo())
			{
				sorted = false;
				/*//namestanje glave tj repa za granicne slucajeve
				if (p2 == head)head = p2->getLink();

				//zamena mesta
				SLLNode<Tip>* temp = p2->getLink();
				p2->setLink(temp->getLink());
				temp->setLink(p2);
				if (p1 != p2)p1->setLink(temp);

				//ako su zamenili mesta, temp se vraca na prethodni da bi ostao normalan tok for petlje
				p2 = temp;

				*/
				//cout << p2->getInfo() << ' ' << p2->getLink()->getInfo() << endl;
				
				//menjaju mesta cvorovi p2 i link(p2)
				swap(p1, p2, p2, p2->getLink());
				//sobzirom da je p2 promenio poziciju, potrebno je vratiti staru
				p2 = p1->getLink();
				//printAll();
				//cout << endl;
			}
		}
	}
}

template<class T>
inline void SLL<T>::selectionSort()//dodaj bool rastuci
{
	//int i, j, min_idx;

	// Prolazimo kroz listu od glave do pretposlednjeg elementa 
	for (SLLNode<T>* n1 = head, *n1bef = NULL; n1->getLink() != NULL; n1bef = n1, n1 = n1->getLink())
	{
		// Nalazimo minimalni element u pod-listi
		SLLNode<T>* min = n1, * minbef = n1bef;
		for (SLLNode<T>* n2 = n1->getLink(), *n2bef = n1; n2 != NULL; n2bef = n2, n2 = n2->getLink())
			if (n2->getInfo() < min->getInfo())
				min = n2, minbef = n2bef;

		// Zamena minimalnog elementa sa prvim u pod-listi 
		swap(n1bef,minbef,n1,min);

		//korekcija jer su zamenili mesta
		n1 = min;
		n1bef = minbef;
	}
}

template<class T>
inline void SLL<T>::insertionSort()
{
	//prolazimo kroz niz od drugog elementa do kraja (smatramo da je deo niza levo od n1 sortiran)
	for (SLLNode<T>* n1 = head->getLink(), *n1bef = head, *n1befbef = NULL; n1 != NULL; 
		n1befbef = n1bef, n1bef = n1, n1 = n1->getLink())
	{
		//n2 predstavlja trenutni element
		SLLNode<T>* n2 = n1, * n2bef = n1bef, * n2befbef = n1befbef;

		// umetanje trenutnog elementa u sortirani deo niza
		while (n2bef!=NULL && n2->getInfo() < n2bef->getInfo()) 
		{
			//zamena mesta trenutnog elementa i njegovog prethodnika
			swap(n2befbef, n2bef, n2bef, n2);

			//pomeranje za jedno mesto unazad
			n2bef = n2befbef;
			n2befbef = findNodeBefore(n2befbef);
				
		}
	}

	/*NAPOMENA
	n1befbef i n2befbef su prethodnici prethodnika i sluze
	da bi se minimizovao broj poziva funkcije findNodeBefore()*/
}

