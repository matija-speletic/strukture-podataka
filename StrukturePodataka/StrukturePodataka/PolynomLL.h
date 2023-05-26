#pragma once
#include "SLL.h"
#include <iostream>
using namespace std;

class PolyNode
{
	int exp;
	double coef;
	PolyNode* next;
public:
	PolyNode(int e, double c, PolyNode* n) { exp = e; coef = c; next = n; }
	PolyNode(int e, double c) { exp = e; coef = c; next = NULL; }
	~PolyNode(){}
	friend class PolynomLL;
};

class PolynomLL
{
	PolyNode* head;
public:
	PolynomLL() { head = NULL; }
	~PolynomLL()
	{
		while (!isEmpty())
		{
			PolyNode* temp = head;
			head = head->next;
			delete temp;
		}
	}
	bool isEmpty() { return head == NULL; }
	PolyNode* findExp(int exp)
	{
		for (PolyNode* temp = head; temp != NULL; temp = temp->next)
			if (temp->exp == exp)
				return temp;
		return NULL;
	}
	void addToHead(PolyNode* p)
	{
		if (head == NULL)
		{
			head = p;
			p->next = NULL;
			return;
		}
		if (head->exp <= p->exp)
		{
			p->next = head;
			head = p;
			return;
		}
		PolyNode* ptr = head;
		
		while (ptr->next != NULL && ptr->next->exp > p->exp)
			ptr = ptr->next;
		p->next = ptr->next;
		ptr->next = p;
	}
	void AddOne(int e, double c)
	{
		PolyNode* temp = findExp(e);
		if (!temp)
			addToHead(new PolyNode(e, c));
		else
		{
			temp->coef += c;
		}
	}
	PolynomLL* copy()
	{
		PolynomLL* ret = new PolynomLL();
		for (PolyNode* temp = head; temp != NULL; temp = temp->next)
			ret->addToHead(new PolyNode(temp->exp, temp->coef));
		return ret;
	}
	static PolynomLL* Add(PolynomLL* p1, PolynomLL* p2)
	{
		PolynomLL* res;
		res = p1->copy();
		for (PolyNode* temp = p2->head; temp != NULL; temp = temp->next)
			res->AddOne(temp->exp, temp->coef);
		return res;
	}
	void MultiplyOne(int e, double c)
	{
		for (PolyNode* temp = head; temp != NULL; temp = temp->next)
		{
			temp->coef *= c;
			temp->exp += e;
		}
	}
	static PolynomLL* Multiply(PolynomLL* p1, PolynomLL* p2)
	{
		PolynomLL* res = new PolynomLL();
		for (PolyNode* temp = p2->head; temp != NULL; temp = temp->next)
		{
			PolynomLL* temp1 = p1->copy();
			temp1->MultiplyOne(temp->exp, temp->coef);
			//temp1->printPoly();
			PolynomLL* temp2 = res;
			res = Add(res, temp1);
			//res->printPoly();
			delete temp2;
		}
		//res->printPoly();
		return res;
	}
	void printPoly()
	{
		for (PolyNode* temp = head; temp != NULL; temp = temp->next)
		{
			cout << temp->coef << "*x" << temp->exp << " + ";
		}
		cout << '0' << endl;
	}
	void derivative(int n)
	{
		if (n == 0)return;
		
		PolyNode* ptr = head, * ptrPrev = NULL;
		while (ptr != NULL)
		{
			ptr->coef *= ptr->exp;
			ptr->exp--;
			if (ptr->exp < 0)
			{
				ptrPrev->next = ptr->next;
				delete ptr;
				ptr = ptrPrev->next;
			}
			else
			{
				ptrPrev = ptr;
				ptr = ptr->next;
			}
		}

		
		if(n>1)
			derivative(n - 1);
	}
};