#pragma once
#include <iostream>
using namespace std;
class Node
{
public:
	int info;
	Node* next;
	Node()	{next = NULL;}
	Node(int i)
	{
		info = i;
		next = NULL;
	}
	Node(int i, Node* n)
	{
		info = i;
		next = n;
	}
	int print(){ return info;}
	bool isEqual(int el)
	{
		return el == this->info;
	}
	~Node(){}
};

class LList
{
protected:
	Node* head/*, * tail*/;
public:
	LList()
	{
		head = NULL;
	}
	~LList()
	{
		while (!isEmpty())
		{
			int tmp = deleteFromHead();
		}
	}
	bool isEmpty()
	{
		return head == NULL;
	}
	void addToHead(int el)
	{
		head = new Node(el, head);
	}
	void addToTail(int el)
	{
		if (!isEmpty())
		{
			Node* tmp = head;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new Node(el);
		}
		else
			addToHead(el);
	}
	int deleteFromHead()
	{
		if (isEmpty())
			throw new exception("List is empty");
		int el = head->info;
		Node* tmp = head;
		head = head->next;
		delete tmp;
		return el;
	}
	int deleteFromTail()
	{
		if (isEmpty())
			throw new exception("List is empty");
		int el;
		if (head->next == NULL)
		{
			el = head->info;
			delete head;
			head = NULL;
		}
		else
		{
			Node* prev = head;
			Node* tmp = head;
			while (tmp->next != NULL)
			{
				prev = tmp;
				tmp = tmp->next;
			}
			el = tmp->info;
			delete tmp;
			prev->next = NULL;
		}
		return el;
	}
	Node* findNodePtr(int el)
	{
		if (isEmpty())
			throw new exception("List is empty");
		Node* ret = head;
		while (ret != NULL && ret->info != el)
		{
			ret = ret->next;
		}
		return ret;
	}
	Node* getHead()
	{
		return head;
	}
	Node* getNext(Node* ptr)
	{
		if (isEmpty())
			throw new exception("List is empty");
		return ptr->next;
	}

	int getHeadEl()
	{
		if (isEmpty())
			throw new exception("List is empty");
		return head->info;
	}
	int getNextEl(int el)
	{
		if (isEmpty())
			throw new exception("List is empty");
		Node* tmp = findNodePtr(el);
		if (tmp == NULL)
			throw new exception("Node doesn't exist");
		if (tmp->next == NULL)
			throw new exception("Element doesn't have next node");
		return tmp->next->info;
	}
	void printAll()
	{
		Node* tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->print() << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	bool isInList(int el)
	{
		if (isEmpty())
			return false;
		Node* tmp = findNodePtr(el);
		if (tmp == NULL)
			return false;
		else
			return true;
	}
	void deleteEl(int el)
	{
		if (!isEmpty())
			if (head->isEqual(el))
			{
				Node* tmp = head;
				head = head->next;
				delete tmp;
			}
			else
			{
				Node* pred, * tmp;
				for (pred = head, tmp = head->next; tmp != NULL && !(tmp->isEqual(el));
					pred = pred->next, tmp = tmp->next);
				if (tmp != NULL)
				{
					pred->next = tmp->next;
					delete tmp;
				}
			}
	}
	Node* removeNodeFromHead()
	{
		if (isEmpty())
			return NULL;
		Node* tmp = head;
		head = head->next;
		return tmp;
	}


	//na dalje su ispitni

	static LList* Merge(LList* l1, LList* l2)
	{
		LList* l3 = new LList();
		Node* ptr1 = l1->head, * ptr2 = l2->head;
		Node* tailPtr = NULL;//dovrsi da se dodaje na kraj
		while (ptr1 != NULL || ptr2 != NULL)
		{
			Node* temp = NULL;
			if (ptr1 != NULL && ptr2 != NULL)
			{
				if (ptr1->info < ptr2->info)
				{
					temp = ptr1;
					ptr1 = ptr1->next;
				}
				else
				{
					temp = ptr2;
					ptr2 = ptr2->next;
				}
			}
			else if (ptr1 == NULL)
			{
				temp = ptr2;
				ptr2 = ptr2->next;
			}
			else if (ptr2 == NULL)
			{
				temp = ptr1;
				ptr1 = ptr1->next;
			}
			if (l3->head == NULL)
				tailPtr = l3->head = temp;
			else
			{
				tailPtr->next = temp;
				tailPtr = tailPtr->next;
			}
			temp->next = NULL;
		}
		return l3;
	}
	void insertionSortOptimized()
	{
		if (head == NULL || head->next == NULL)return;
		Node* ptr1, * ptr2, * ptr4;
		ptr1 = head;
		ptr4 = ptr1->next;

		int i = 1;
		for (ptr2 = head; ptr2->next->next != NULL; ptr2 = ptr2->next, i++);

		while (i>0)
		{
			i--;
			Node* ptr3 = ptr2;
			for (; ptr3->next != NULL && ptr1->info >= ptr3->next->info; ptr3 = ptr3->next);

			//za testiranje
			//cout << ptr1->info << ' ' << ptr2->info << ' ' << ptr3->info << ' ' << ptr4->info << endl;

			head = ptr4;
			ptr1->next = ptr3->next;
			ptr3->next = ptr1;

			ptr1 = ptr4;
			ptr4 = ptr4->next;

			//printAll();/za testiranje
		}
	}
	void groupDuplicates()
	{
		Node* ptr1 = head, * ptr2 = head, * ptr3 = head->next;
		while (ptr1->next != NULL)
		{
			while (ptr3 != NULL && ptr3->info != ptr1->info)
				ptr2 = ptr3, ptr3 = ptr3->next;
			if (ptr3 != NULL && ptr2!=ptr1)
			{
				ptr2->next = ptr3->next;
				ptr3->next = ptr1->next;
				ptr1->next = ptr3;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr1;
			ptr3 = ptr2->next;
		}
	}
	void fillInTheBlanks()
	{
		/*   Napisati funkciju void LList::fillInTheBlanks() koja iz dinamički implementirane
		 *   lančane liste, čiji su info delovi celi brojevi, uređene u neopadajući redosled, briše sve duple
		 *   čvorove a dodaje čvorove za sve one vrednosti koje nedostaju između vrednosti dva uzastopna
		 *   čvora liste. Na primer, ukoliko su info delovi dva uzastopna čvora vrednosti 1 i 4, između njih je
		 *   potrebno dodati i čvorove sa vrednostima 2 i 3. 
		 */
		//insertionSortOptimized();
		Node* ptr = head;
		while (ptr->next != NULL)
		{
			if (ptr->info == ptr->next->info)
			{
				Node* temp = ptr->next;
				ptr->next = temp->next;
				delete temp;
			}
			else
			{
				int i = ptr->info + 1;
				if (ptr->next->info > i)
				{
					Node* n = new Node(i, ptr->next);
					ptr->next = n;
				}
				ptr = ptr->next;
			}
		}
	}
	//april 2017
	int MoveToBeginning(int value)
	{
		/*		April 2017 
		 *
		 * Napisati funkciju int MoveToBeginning(int value), koja pomera sve elemente
		 * jednostruko ulančane liste manje od zadate vrednosti value na početak liste. Nakon pomeranja
		 * se zadržava redosled unutar prvog dela liste (vrednosti manje od value) i drugog dela liste
		 * (vrednosti veće ili jednake value) koji je bio u početnoj listi, tj. ako je element bio ispred drugog
		 * ostaće ispred i nakon pomeranja. Funkcija vraća broj pomerenih čvorova. Napomena: Algoritmi
		 * koji nemaju linearnu efikasnost i korišćenje pomoćnih struktura umanjuju broj poena.
		 */

		Node* start = NULL
			, * ptr = head;
		int ret = 0;
		while (ptr->next != NULL)
		{
			if (ptr->next->info < value)
			{
				Node* temp = ptr->next;
				ptr->next = temp->next;
				ret++;
				if (start == NULL)
				{
					temp->next = head;
					head = temp;
					start = head;
				}
				else
				{
					temp->next = start->next;
					start->next = temp;
					start = temp;
				}
			}
			else
				ptr = ptr->next;
		}
		return ret;
	}
	//februar 2017
	void swapMinMax()
	{
		//ako ima 0 ili 1 element
		if (head == NULL || head->next == NULL)
			return;

		Node* ptrMin = head, * ptrMax = head,
			* prevMin = NULL, * prevMax = NULL;

		for (Node* ptr = head, *prev = NULL; ptr != NULL; prev = ptr, ptr = ptr->next)
		{
			if (ptr->info > ptrMax->info)
				ptrMax = ptr, prevMax = prev;
			if (ptr->info < ptrMin->info)
				ptrMin = ptr, prevMin = prev;
		}

		//ako su isti, nema smisla menjati mesta
		if (ptrMin == ptrMax)
			return;

		//ako nisu susedni
		if (prevMax != ptrMin || ptrMax->next != ptrMin)
		{
			if (prevMin != NULL)
				prevMin->next = ptrMax;
			else
				head = ptrMax;
			if (prevMax != NULL)
				prevMax->next = ptrMin;
			else
				head = ptrMin;
			Node* temp = ptrMin->next;
			ptrMin->next = ptrMax->next;
			ptrMax->next = temp;
		}

		//ako su susedni i max ide posle min
		else if (prevMax == ptrMin)
		{
			prevMin->next = ptrMax;
			ptrMin->next = ptrMax->next;
			ptrMax->next = ptrMin;
		}
		//ako su susedni i min ide posle max
		else if (prevMin == ptrMax)
		{
			ptrMax->next = ptrMin->next;
			ptrMax->next = ptrMin;
			ptrMin->next = ptrMax;
		}

	}
};


