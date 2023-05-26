#pragma once
#include "iostream"
using namespace std;

class KVNode
{
public:
	int key, value;
	KVNode* next;
	KVNode() { key = value = 0; next = NULL; }
	KVNode(int k, int v) :key(k), value(v) { next = NULL; }
	KVNode(int k, int v, KVNode* n) :key(k), value(v), next(n) { }
	~KVNode(){}
};

class KVList
{
	KVNode* head;
public:
	KVList() :head(NULL) { }
	void print()
	{
		for (KVNode* ptr = head; ptr != NULL; ptr = ptr->next)
			cout << "(" << ptr->key << ")" << ptr->value << ", ";
		cout << endl;
	}




	//uredjena po kljucevima (KS)

	//uradjeno kompletno
	void insertOrUpdate(int k, int v)
	{
		KVNode* ptr = head, * ptrprev = NULL;
		for (; ptr != NULL && ptr->key < k; ptrprev = ptr, ptr = ptr->next);
		if (ptr!=NULL && ptr->key == k)
		{
			ptr->value += v;
			if (ptr->value == 0)
			{
				KVNode* temp = ptr;
				if (ptr != head)
					ptrprev->next = ptr->next;
				else
					head = ptr->next;
				delete temp;
			}
		}
		else
		{
			if (ptrprev == NULL)
				head = new KVNode(k, v, head);
			else
				ptrprev->next = new KVNode(k, v, ptr);
		}
	}
	void insertOrUpdate2(int k, int v)
	{
		KVNode* ptr = head, * prev = NULL;
		while (ptr != NULL && ptr->key < k)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		if (ptr != NULL && ptr->key == k)
		{
			ptr->value = v;
			if (v == 0)
			{
				if (prev == NULL)
					head = ptr->next;
				else
					prev->next = ptr->next;
				delete ptr;
			}
		}
		else
		{
			if (prev==NULL)
				head= new KVNode(k, v, head);
			else
				prev->next = new KVNode(k, v, ptr);
		}
	}
	void UpdateNode(int k, int v)
	{
		KVNode* ptr = head, * prev = NULL, * pprev = NULL;
		while (ptr != NULL && ptr->key != k)
			pprev = prev, prev = ptr, ptr = ptr->next;
		if (ptr == NULL)
			head = new KVNode(k, v, head);
		else
		{
			ptr->value += v;
			if (ptr->value == 0)
			{
				if (prev == NULL)
					head = ptr->next;
				else
					prev->next = ptr->next;
				delete ptr;
			}
			else if (prev!=NULL)
			{
				prev->next = ptr->next;
				ptr->next = prev;
				if (pprev != NULL)
					pprev->next = ptr;
				else
					head = ptr;
			}
		}
	}





	//uredjena po vrednostima (VS)

	//decembar 2017
	int Increment(int id)
	{
		KVNode* ptr = head, * ptrprev = NULL;
		for (; ptr != NULL && ptr->key != id; ptrprev = ptr, ptr = ptr->next);
		if (!ptr)
			return 0;
		ptr->value++;
		int ret = ptr != NULL ? ptr->value : 0;
		if (ptr->next != NULL&&ptr->value>ptr->next->value)
		{
			KVNode* temp = ptr->next;
			ptr->next = temp->next;
			temp->next = ptr;
			if (ptrprev)
				ptrprev->next = temp;
			else
				head = temp;
		}
		return ret;
	}
	int Decrement(int id)
	{
		/* (12 poena) Sortirana jednostruko ulančana, dinamički implementirana, lančana lista se sastoji od
		 * čvorova od kojih svaki ima dva podatka, celobrojni identifikator čvora id i celobrojnu vrednost
		 * value. Implementirati dve funkcije int Decrement(int id) koja dekrementira podatak value čvora
		 * čiji je id prosleđen, pri čemu vraća novu vrednost čvora, kao i funkciju int Increment(int id) koja na
		 * sličan način inkrementira vrednost čvor. Funkcije treba da obezbede da nakon njihovog izvršenja
		 * lista ostane sortirana u neopadajući redosled. 
		 */
		KVNode* ptr = head, * ptrprev = NULL, * ptrprevprev = NULL;
		for (; ptr != NULL && ptr->key != id; ptrprevprev=ptrprev, ptrprev = ptr, ptr = ptr->next);
		if (!ptr)
			return 0;
		ptr->value--;
		int ret = ptr != NULL ? ptr->value : 0;
		if (ptrprev != NULL && ptrprev->value > ptr->value)
		{
			ptrprev->next = ptr->next;
			ptr->next = ptrprev;
			if (ptrprevprev)
				ptrprevprev->next = ptr;
			else
				head = ptr;
		}
		return ret;

	}
};