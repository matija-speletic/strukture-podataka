#include "LList.h"


LList::LList()
{
	head=NULL;
}


LList::~LList()
{
	while(!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}


bool LList::isEmpty()
{
	return head==NULL;
}

void LList::addToHead(int el)
{
	head = new LListNode(el, head);
}

void LList::addToTail(int el)
{
	if(!isEmpty())
	{
		LListNode* tmp = head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new LListNode(el);
	}
	else
		addToHead(el);
}

int LList::deleteFromHead()
{
	if(isEmpty())
		throw new exception("List is empty");
	int el = head->info;
	LListNode *tmp = head;
	head = head->next;
	delete tmp;
	return el;
}

int LList::deleteFromTail()
{
	if(isEmpty())
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
		LListNode* prev = head;
		LListNode *tmp = head;
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

LListNode* LList::findNodePtr(int el)
{
	if(isEmpty())
		throw new exception("List is empty");
	LListNode *ret = head;
	while(ret!=NULL && ret->info!=el)
	{
		ret = ret->next;
	}
	return ret;
}

LListNode* LList::getHead()
{
	return head;
}

LListNode* LList::getNext(LListNode* ptr)
{
	if(isEmpty())
		throw new exception("List is empty");
	return ptr->next;
}

int LList::getHeadEl()
{
	if(isEmpty())
		throw new exception("List is empty");
	return head->info;
}

int LList::getNextEl(int el)
{
	if(isEmpty())
		throw new exception("List is empty");
	LListNode* tmp = findNodePtr(el);
	if(tmp==NULL)
		throw new exception("Node doesn't exist");
	if(tmp->next == NULL)
		throw new exception("Element doesn't have next node");
	return tmp->next->info;
}

void LList::printAll()
{
	LListNode* tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->print() << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

void LList::printAllKV()
{
	LListNode* tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->key << "(" << tmp->info << "), ";
		tmp = tmp->next;
	}
	cout << endl;
}

bool LList::isInList(int el)
{
	if(isEmpty())
		return false;
	LListNode* tmp = findNodePtr(el);
	if(tmp==NULL)
		return false;
	else
		return true;
}

void LList::deleteEl(int el)
{
	if (!isEmpty())
	if (head->isEqual(el)) 
	{
		LListNode *tmp = head;
		head = head->next;
		delete tmp;
	}
	else 
	{
		LListNode *pred, *tmp; 
		for (pred = head, tmp = head->next; tmp != NULL && !(tmp->isEqual(el));
			  pred = pred->next, tmp = tmp->next);
		if (tmp != NULL) 
		{
			pred->next = tmp->next;
			delete tmp;
		}
    }
}

LListNode* LList::removeNodeFromHead()
{
	if(isEmpty())
		return NULL;
	LListNode *tmp = head;
	head = head->next;
	return tmp;
}

LList* LList::extractEven()
{
	if (head == NULL)
		return NULL;
	LList* even = new LList();
	LListNode* prev = NULL, * ptr = head, * eprev = NULL;
	while (ptr != NULL)
	{
		if (ptr->info % 2 == 0)
		{
			if (prev == NULL)
				head = ptr->next;
			else
				prev->next = ptr->next;
			if (eprev == NULL)
				even->head = ptr;
			else
				eprev->next = ptr;
			ptr->next = NULL;
			eprev = ptr;
			if (prev == NULL)
				ptr = head;
			else
				ptr = prev->next;
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}
	return even;
}

void LList::InsertOrUpdate(int key, int value)
{
	LListNode* ptr = head, * prev = NULL;
	while (ptr != NULL && ptr->key < key)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr != NULL && ptr->key == key)//brisanje ili azuriranje
	{
		if (value == 0)
		{
			if (prev == NULL)
				head = ptr->next;
			else
				prev->next = ptr->next;
			delete ptr;
		}
		else
			ptr->info = value;
	}
	else
	{
		LListNode* temp = new LListNode();
		temp->info = value;
		temp->key = key;
		temp->next = ptr;
		if (prev == NULL)
			head = temp;
		else
			prev->next = temp;
	}

}



LListNode* addAfter = head, * ptr = head, * prev = NULL;
	while (addAfter != NULL && addAfter->info != points)
		addAfter = addAfter->next;
	if (addAfter == NULL)
		return;
	prev = addAfter;
	ptr = addAfter->next;
	while (ptr != NULL)
	{
		if (ptr->info != points)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		else if (prev == addAfter)
		{
			addAfter = ptr;
			prev = ptr;
			ptr = ptr->next;
		}
		else
		{
			prev->next = ptr->next;
			ptr->next = addAfter->next;
			addAfter->next = ptr;
			addAfter = ptr;
			ptr = prev->next;
		}
	}


	
void LList::UpdateNode(int key, int value)
{
	LListNode* ptr = head, * prev = NULL, * pprev = NULL;
	while (ptr != NULL && ptr->key != key)
	{
		pprev = prev;
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr == NULL)
	{
		head = new LListNode(value, head);
		head->key = key;
		return;
	}
	else
	{
		ptr->info += value;
		if (ptr->info == 0)
		{
			if (prev == NULL)
				head = ptr->next;
			else
				prev->next = ptr->next;
			delete ptr;
			return;
		}
		else
		{
			if (prev == NULL)
				return;
			prev->next = ptr->next;
			ptr->next = prev;
			if (pprev == NULL)
				head = ptr;
			else
				pprev->next = ptr;
		}
	}
}

void LList::Exchange(LList* l, int value, int length)
{
	LListNode* ptr1 = NULL, * pos1 = head, * ptr3 = NULL, * pos3 = l->head;
	while (pos1->info != value || pos3->info != value)
	{
		if (pos1->info != value)
		{
			ptr1 = pos1;
			pos1 = pos1->next;
		}
		if (pos3->info != value)
		{
			ptr3 = pos3;
			pos3 = pos3->next;
		}
	}
	LListNode* ptr2 = ptr1, * pos2 = pos1, * ptr4 = ptr3, * pos4 = pos3;
	for (int i = 0; i < length; i++)
	{
		ptr2 = pos2;
		pos2 = pos2->next;
		ptr4 = pos4;
		pos4 = pos4->next;
	}
	if (ptr1 != NULL)
		ptr1->next = pos3;
	else
		head = pos3;
	if (ptr3 != NULL)
		ptr3->next = pos1;
	else
		l->head = pos1;
	ptr2->next = pos4;
	ptr4->next = pos2;
}

LList* LList::formList(int arr[], int n)
{
	LList* ret = new LList();
	for (int i = 0; i < n; i++)
	{
		LListNode* ptr = ret->head, * prev = NULL;
		while (ptr != NULL && ptr->info < arr[i])
			prev = ptr, ptr = ptr->next;
		if (prev == NULL)
			ret->head = new LListNode(arr[i], ret->head);
		else
			prev->next = new LListNode(arr[i], ptr);
	}
	return ret;
}

void LList::fillInTheBlanks()
{
	if (head == NULL)
		return;
	LListNode* ptr = head->next, * prev = head;
	while (ptr != NULL)
	{
		if (ptr->info == prev->info)
		{
			prev->next = ptr->next;
			delete ptr;
			ptr = prev->next;
		}
		else if (ptr->info != prev->info + 1)
		{
			prev->next = new LListNode(prev->info + 1, ptr);
			prev = prev->next;
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}
}

void LList::fillInTheBlanks2()
{
	if (head == NULL)return;
	LListNode* ptr = head;
	int num = ptr->info;
	while (ptr != NULL)
	{
		if (ptr->next != NULL && ptr->info == ptr->next->info)
		{
			LListNode* temp = ptr->next;
			ptr->next = ptr->next->next;
			delete temp;
		}
		else if (ptr->next != NULL && ptr->next->info != num + 1)
		{
			ptr->next = new LListNode(num + 1, ptr->next);
			num++;
			ptr = ptr->next;
		}
		else
		{
			num++;
			ptr = ptr->next;
		}
	}
}

void LList::Compact()
{
	if (head == NULL)
		return;
	LListNode* ptrCurr = head;
	while (ptrCurr != NULL)
	{
		LListNode* ptr = ptrCurr->next, * prev = ptrCurr;
		while (ptr != NULL)
		{
			if (ptr->key == ptrCurr->key)
			{
				ptrCurr->info += ptr->info;
				prev->next = ptr->next;
				delete ptr;
				ptr = prev->next;
			}
			else
			{
				prev = ptr;
				ptr = ptr->next;
			}
		}
		ptrCurr = ptrCurr->next;
	}
}

void LList::MoveToBeginning(int value)
{
	LListNode* prev = NULL, * ptr = head, * addAfter = NULL;
	while (ptr != NULL)
	{
		if (ptr->info < value && prev != NULL)
		{
			prev->next = ptr->next;
			if (addAfter != NULL)
			{
				ptr->next = addAfter->next;
				addAfter->next = ptr;
			}
			else
			{
				ptr->next = head;
				head = ptr;
			}
			addAfter = ptr;
			ptr = prev->next;
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}
}

void LList::swapMinMax()
{
	LListNode* ptr = head, * prev = NULL, * minp = NULL, * maxp = NULL, * minPrev = NULL, * maxPrev = NULL;
	while (ptr != NULL)
	{
		if (minp == NULL || ptr->info < minp->info)
		{
			minp = ptr;
			minPrev = prev;
		}
		if (maxp == NULL || ptr->info > maxp->info)
		{
			maxp = ptr;
			maxPrev = prev;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	if (minp == NULL || maxp == NULL)return;
	if (maxp->next == minp)
	{
		maxp->next = minp->next;
		minp->next = maxp;
		if (maxPrev == NULL)head = minp;
		else maxPrev->next = minp;
	}
	else if (minp->next == maxp)
	{
		minp->next = maxp->next;
		maxp->next = minp;
		if (minPrev == NULL)head = maxp;
		else minPrev->next = maxp;
	}
	else
	{
		ptr = minp->next;
		minp->next = maxp->next;
		maxp->next = ptr;
		if (minPrev == NULL)head = maxp;
		else minPrev->next = maxp;
		if (maxPrev == NULL)head = minp;
		else maxPrev->next = minp;
	}
}
