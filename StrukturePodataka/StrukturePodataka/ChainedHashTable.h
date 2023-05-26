#pragma once
#include <iostream>
#include "HashTable.h"
#include "SLL.h"
using namespace std;

template <class T, class R>
class ChainedHashTable : public HashTable<T, R>
{
protected:
	SLL<HashObject<T, R>>* arr;

public:
	ChainedHashTable(unsigned int len)
		:HashTable<T,R>(len)
	{
		arr = new SLL<HashObject<T, R>>[HashTable<T,R>::length];
	}

	~ChainedHashTable()
	{
		for (int i = 0; i < HashTable<T, R>::length; i++)
		{
			try
			{
				while(!arr[i].isEmpty())
				{
					arr[i].deleteFromHead();
				}
			}
			catch (...) {}
		}
		delete[] arr;
	}

	void display()
	{
		for (int i = 0; i < HashTable<T, R>::length; i++)
		{
			cout << "[" << i << "] X -> ";
			arr[i].printAll();
		}
	}

	void insert(HashObject<T, R> obj)
	{
		arr[HashTable<T, R>::h(obj)].addToHead(obj);
	}

	void withdraw(T k)
	{
		int hash = HashTable<T, R>::h(k);
		SLLNode<HashObject<T, R>>* ptr = arr[hash].getHead()
			, * prev = NULL;
		for (; ptr!=NULL && !ptr->getInfo().isEqualKey(k); prev = ptr, ptr = ptr->getLink());
		if (ptr == NULL)
			return;
		if (prev == NULL)
		{
			arr[hash].head = ptr->getLink();
			delete ptr;
		}
		else
		{
			prev->setLink(ptr->getLink());
			delete ptr;
		}
	}
};