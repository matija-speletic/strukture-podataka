#pragma once
#include <iostream>
using namespace std;

template <class T>
class Queue
{
public:
	virtual void enqueue(T el) = 0;
	virtual T dequeue() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual int numOfEl() = 0;
	virtual T getHead() = 0;
};

template <class T>
class StaticQueue : public Queue<T>
{
protected:
	T* arr;
	int size;
	int num;
	int head;
	int tail;
public:
	StaticQueue(int s)
	{
		size = s;
		arr = new T[size];
		head = tail = num = 0;
	}
	~StaticQueue() { delete[]arr; }
	bool isEmpty() { return num == 0; }
	bool isFull() { return size == num; }
	int numOfEl() { return num; }
	T getHead()
	{
		if (isEmpty()) return NULL;
		return arr[head];
	}
	void enqueue(T el)
	{
		if (isFull()) return;
		if (isEmpty())
		{
			arr[head = tail = 0] = el;
			num++;
			return;
		}
		tail = (tail + 1) % size;
		num++;
		arr[tail] = el;
	}
	T dequeue()
	{
		if (isEmpty())return NULL;
		T temp = arr[head];
		head = (head + 1) % size;
		num--;
		return temp;
	}

};

template<class T>
class PQElement
{
	T el;
	float priority;
public:
	PQElement() { priority = 0; }
	PQElement(T elm,float pri):el(elm),priority(pri){}
	T get() { return el; }
	void set(T elm) { el = elm; }
	float getPriority() { return priority;}
	void setPriority(float pri) { priority = pri; }
};

template <class T>
class PriorityQueue : public Queue<T>
{
protected:
	PQElement<T>* arr;
	int size;
	int num;
	int head;
	int tail;
public:
	PriorityQueue(int s)
	{
		size = s;
		arr = new PQElement<T>[size];
		head = tail = num = 0;
	}
	~PriorityQueue() { delete[]arr; }
	bool isEmpty() { return num == 0; }
	bool isFull() { return size == num; }
	int numOfEl() { return num; }
	T getHead()
	{
		if (isEmpty()) return NULL;
		return arr[head].get();
	}
	void enqueue(T el)
	{
		if (isFull()) return;
		if (isEmpty())
		{
			arr[head = tail = 0].set(el);
			num++;
			return;
		}
		tail = (tail + 1) % size;
		num++;
		arr[tail].set(el);
	}
	T dequeue()
	{
		if (isEmpty())return NULL;
		T temp = arr[head].get();
		head = (head + 1) % size;
		num--;
		return temp;
	}
	/*void AddPriority(float pri, T el)
	{
		if (isEmpty())
		{
			arr[head = tail = 0].set(el);
			arr[0].setPriority(pri);
			num++;
			return;
		}

		for(int i=head;i!=tail)
	}*/
};