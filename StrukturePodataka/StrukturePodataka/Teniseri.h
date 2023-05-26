#pragma once
#include <iostream>
using namespace std;

class TNode
{
public:
	int jedBr;
	int brPob;
	char* ime;
	TNode* next;
	TNode(const char* name, int jb, int bp)
	{
		jedBr = jb, brPob = bp;
		ime = new char[strlen(name) + 1];
		strcpy(ime, name);
	}
	~TNode() { delete[] ime; }
};

class Lista
{
	TNode* head;
public:
	void AddToHead(TNode* n)
	{
		n->next = head;
		head = n;
	}
	Lista()
	{
		head = NULL;
	}
	~Lista()
	{
		while (head != NULL)
		{
			TNode* tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	void UpdatePlayer(const char* name, int noWin)
	{
		TNode* ptr, * ptr2, * ptrprev;
		for (ptr = head,ptrprev=NULL; ptr != NULL && strcmp(name, ptr->ime) != 0; ptrprev=ptr, ptr = ptr->next);
		if (ptr == NULL)return;
		ptr->brPob += noWin;
		if (ptr->next == NULL || ptr->brPob < ptr->next->brPob)return;
		for (ptr2 = ptr; ptr2->next != NULL && ptr2->next->brPob < ptr->brPob; ptr2 = ptr2->next);

		if (ptr == head)
			head = ptr->next;
		else
			ptrprev->next = ptr->next;
		ptr->next = ptr2->next;
		ptr2->next = ptr;
	}
	void print()
	{
		for (TNode* ptr = head; ptr != NULL; ptr = ptr->next)
		{
			cout << ptr->jedBr << ' ' << ptr->ime << ' ' << ptr->brPob << endl;
		}
		cout << endl;
	}
};


/*Aplikacija vodi evidenciju o broju pobeda aktivnih tenisera u
toku karijere. Informacije o teniserima su zapamćene u
lančanoj listi uređenoj po broju pobeda. Za svakog tenisera se
pamti jedinstveni broj (int), ime i prezime i broj pobeda. Nakon
svakog teniskog turnira se ažuriraju bodovi svih učesnika
turnira. Napisati funkciju void UpdatePlayer(char *name, int
noWin) koja ažurira (povećava) broj pobeda zadatog tenisera,
čije je ime name, za zadatu vrednost noWin, ali tako da
korišćena struktura ostane uređena.*/