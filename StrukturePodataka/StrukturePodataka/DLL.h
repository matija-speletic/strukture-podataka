#pragma once
#include "DLLNode.h"
template <class T>
class DLList
{
protected:
	DLLNode<T>* head, * tail; // pokazivaci pocetka i kraja liste
public:
	DLList() { head = tail = NULL; };
	~DLList();
	bool isEmpty() { return head == NULL; }
	void printAll();
	DLLNode<T>* findNodePtr(T el);
	DLLNode<T>* getHead() { return head; }
	DLLNode<T>* getNext(DLLNode<T>* ptr);
	T getHeadEl();
	T getNextEl(T el);
	bool isInList(T el);
	void deleteEl(T el);
	void addToHead(T el);
	void addToTail(T el);
	T deleteFromHead();
	T deleteFromTail();


	void bubbleSort();
	void selectionSort();

	//2016 kolokvijum 1
	void MovePartToEnd(T val1, T val2);
};

template<class T>
inline void DLList<T>::deleteEl(T el)
{
	if (isEmpty())return;
	if (head == tail && head->getInfo() == el)
	{
		DLLNode<T>* temp = head;
		head = tail = NULL;
		delete temp;
		return;
	}
	if (head->getInfo() == el) { T tmp = deleteFromHead(); return; }
	if (tail->getInfo() == el) { T tmp = deleteFromTail(); return; }

	DLLNode<T>* temp = findNodePtr(el);
	if (temp == NULL)return;
	temp->getNext()->setPrev(temp->getPrev());
	temp->getPrev()->setNext(temp->getNext());
	delete temp;
	return;
}

template<class T>
inline void DLList<T>::addToHead(T el)
{
	if (isEmpty())
	{
		head = tail = new DLLNode<T>(el);
		return;
	}
	DLLNode<T>* tmp = new DLLNode<T>(el, NULL, head);
	head->setPrev(tmp);
	head = tmp;
}

template<class T>
inline void DLList<T>::addToTail(T el)
{
	if (isEmpty())
	{
		head = tail = new DLLNode<T>(el);
		return;
	}
	DLLNode<T>* tmp = new DLLNode<T>(el, tail, NULL);
	tail->setNext(tmp);
	tail = tmp;
}

template<class T>
inline T DLList<T>::deleteFromHead()
{
	if (isEmpty())return NULL;
	DLLNode<T>* tmp = head;
	T ret = head->getInfo();
	if (head == tail)
	{
		delete tail;
		head = tail = NULL;
		return ret;
	}
	head->getNext()->setPrev(NULL);
	head = head->getNext();
	delete tmp;
	return ret;
}

template<class T>
inline T DLList<T>::deleteFromTail()
{
	if (isEmpty())return NULL;
	T ret = tail->getInfo();
	if (head == tail)
	{
		delete tail;
		head = tail = NULL;
		return ret;
	}
	DLLNode<T>* tmp = tail;
	tail = tail->getPrev();
	tail->setNext(NULL);
	delete tmp;
	return ret;
}

template<class T>
inline void DLList<T>::bubbleSort()
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (DLLNode<T>* temp = head; temp->getNext() != NULL; temp = temp->getNext())
		{
			if (temp->getInfo() > temp->getNext()->getInfo())
			{
				sorted = false;
				//namestanje glave tj repa za granicne slucajeve
				if (temp == head)head = temp->getNext();
				if (temp->getNext() == tail)tail = temp;

				//zamena mesta
				if (temp->getNext() != NULL)temp->getNext()->setPrev(temp->getPrev());
				if (temp->getPrev() != NULL)temp->getPrev()->setNext(temp->getNext());
				if (temp != NULL)temp->setPrev(temp->getNext());
				if (temp != NULL)temp->setNext(temp->getNext()->getNext());
				if (temp != NULL && temp->getNext() != NULL)temp->getNext()->setPrev(temp);
				if (temp != NULL && temp->getPrev() != NULL)temp->getPrev()->setNext(temp);

				//ako su zamenili mesta, temp se vraca na prethodni da bi ostao normalan tok for petlje
				temp = temp->getPrev();
				//printAll();
				//cout << endl;
			}

		}
	}
}

//kompletno uradjen
template<class T>
inline void DLList<T>::selectionSort()
{
	/*for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array 
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]);
	}*/


	for (DLLNode<T>* ptr1 = head; ptr1->next != NULL; ptr1 = ptr1->next)
	{
		DLLNode<T>* minptr = ptr1;
		for (DLLNode<T>* ptr2 = ptr1; ptr2 != NULL; ptr2 = ptr2->next)
			if (ptr2->info < minptr->info)
				minptr = ptr2;
		if (ptr1 != minptr)//ako su isti, preskače se korak
		{
			if (ptr1 == head)
				head = minptr;
			if (minptr == tail)
				tail = ptr1;
			if (ptr1->next != minptr)//ako nisu susedni
			{
				DLLNode<T>* ptr3 = ptr1->next;
				ptr1->next = minptr->next;//1
				if (minptr->next != NULL)//ako je prvi head
					minptr->next->prev = ptr1;//2
				ptr3->prev = minptr;//3
				minptr->next = ptr3;//4
				ptr3 = minptr->prev;//5
				ptr3->next = ptr1;//6
				minptr->prev = ptr1->prev;//7
				if (minptr->prev != NULL)//ako je drugi tail
					minptr->prev->next = minptr;//9
				ptr1->prev = ptr3;//10
			}
			else//ako su susedni
			{
				minptr->prev = ptr1->prev;//1
				if (ptr1->prev != NULL)
					ptr1->prev->next = minptr;//2
				if (minptr->next != NULL)
					minptr->next->prev = ptr1;//3
				ptr1->next = minptr->next;//4
				minptr->next = ptr1;//5
				ptr1->prev = minptr;//6
			}
			ptr1 = minptr;//vracanje ptr1 na pocetnu vrednost
		}
	}
}

template<class T>
inline DLList<T>::~DLList()
{
	while (!isEmpty())T temp = deleteFromHead();
}

template<class T>
inline void DLList<T>::printAll()
{
	cout << "From head:" << endl;
	for (DLLNode<T>* temp = head; temp != NULL; temp = temp->getNext())
		cout << temp->getInfo() << ", ";
	cout << endl << "From tail:" << endl;
	for (DLLNode<T>* temp = tail; temp != NULL; temp = temp->getPrev())
		cout << temp->getInfo() << ", ";
	cout << endl;
}

template<class T>
inline DLLNode<T>* DLList<T>::findNodePtr(T el)
{
	if (isEmpty())return NULL;
	DLLNode<T>* temp = head;
	for (; temp != NULL && temp->getInfo() != el; temp = temp->getNext());
	return temp;
}

template<class T>
inline DLLNode<T>* DLList<T>::getNext(DLLNode<T>* ptr)
{
	if (ptr == NULL)
		return NULL;
	return ptr->getNext();
}

//ispitni
template <class T>
void DLList<T>::MovePartToEnd(T val1, T val2)
{
	/* Napisati funkciju void MovePartToEnd(int val1, int val2)
	 * koja izdvaja niz čvorova dvostruko ulančane liste
	 * između čvorova sa vrednosti val1 i val2 i premešta ga
	 * na kraj liste.
	 * Vrednosti u čvorovima lančane liste su jedinstvene.
	 * Smatrati da čvorovi sa vrednostima val1 i val2 postoje
	 * u listi i da čvor sa vrednošću val2 nije ispred čvora sa
	 * vrednošću val1.
	 * Zanemariti poslednje ograničenje*/

	DLLNode<T>* ptr1 = NULL, * ptr2 = NULL, * ptr = head;
	bool order = true;
	while ((ptr1 == NULL || ptr2 == NULL) && ptr != NULL)
	{
		if (ptr->getInfo() == val1)
		{
			ptr1 = ptr;
			if (ptr2 != NULL)
				order = false;
		}
		if (ptr->getInfo() == val2)
			ptr2 = ptr;
		ptr = ptr->getNext();
	}
	if (ptr2 == tail || ptr2 == NULL || ptr1 == NULL)
		return;
	if (!order)
	{
		ptr = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr;
	}
	if (ptr1 == head)
		head = ptr2->getNext();
	else
		ptr1->getPrev()->setNext(ptr2->getNext());
	tail->setNext(ptr1);
	ptr2->getNext()->setPrev(ptr1->getPrev());
	ptr1->setPrev(tail);
	ptr2->setNext(NULL);
	tail = ptr2;
}