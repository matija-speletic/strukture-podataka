#pragma once
#include <iostream>
using namespace std;

template <class T>
class SDNode
{
public:
	T info;
	int prev;
	int next;
	SDNode() { prev = 0; next = 0; };
	SDNode(T i) { info = i; prev = 0; next = 0; };
	SDNode(T i, int p, int n) {
		info = i; prev = p; next = n;
	};
	~SDNode() { };
	T print() { return info; };
	bool isEqual(T el) { return el == info; };
};

template <class T>
class SDLList
{
	SDNode<T>* data;
	int dim;
	int head, tail, lrmp;
public:
	SDLList() { dim = head = tail = 0; }
	SDLList(int n)
	{
		dim = n;
		data = new SDNode<T>[dim + 1];
		head = tail = 0;
		lrmp = 1;
		for (int i = 1; i < dim; i++)
			data[i].next = i + 1;
		data[dim] = 0;
	}
	~SDLList() { delete[]data; }
	void printAsTable()
	{
		for (int i = 0; i < dim; i++)
			cout << data[i].info << ' ' << data[i].prev
			<< ' ' << data[i].next << endl;
	}
	void print()
	{
		cout << "From head:" << endl;
		for (int i = head; i != 0; i = data[i].next)
			cout << data[i].info << ", ";
		cout << endl << "From tail:" << endl;
		for (int i = tail; i != 0; i = data[i].prev)
			cout << data[i].info << ", ";
		cout << endl;
	}
	void addToHead(T el)
	{
		if (lrmp == 0)
			return;
		int temp = data[lrmp].next;
		data[lrmp].info = el;
		data[lrmp].next = head;
		data[lrmp].prev = 0;
		if (head == 0)
			head = tail = lrmp;
		else
			data[head].prev = lrmp;
		head = lrmp;
		lrmp = temp;
	}
	void addToTail(T el)
	{
		if (lrmp == 0)
			return;
		int temp = lrmp;
		lrmp = data[lrmp].next;
		data[temp].info = el;
		data[temp].prev = tail;
		data[temp].next = 0;
		if (tail == 0)
			head = tail = temp;
		else
			data[tail].next = temp;
		tail = temp;
		/*void SDLList<T>::addToTail(T el) {
if (lrmp == 0) {
return;
}
int tmp = lrmp;
lrmp = data[lrmp].next;
data[tmp].info = el;
data[tmp].prev = tail;
data[tmp].next = 0;
if (tail == 0) {
tail = head = tmp;
} else {
data[tail].next = tmp;
tail = tmp;
}
}*/
	}

};
