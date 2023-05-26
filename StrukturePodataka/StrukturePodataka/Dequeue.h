#pragma once
#include "Queue.h"
template <class T>
class Dequeue
{
public:
	virtual T getHead() = 0;
	virtual T getTail() = 0;
	virtual bool isEmpty() = 0;
	virtual int numOfEl() = 0;
	virtual void enqueueTail(T el) = 0;
	virtual void enqueueHead(T el) = 0;
	virtual T dequeueTail() = 0;
	virtual T dequeueHead() = 0;
	virtual void printDequeue(){}
};

template <class T>
class StaticDequeue :public Dequeue<T>, public StaticQueue<T>
{
public:
	StaticDequeue(int s):StaticQueue<T>(s){}
	//~StaticDequeue() { ~StaticQueue<T>(); }
	void enqueueHead(T el)
	{
		if (StaticQueue<T>::isEmpty())StaticQueue<T>::head = StaticQueue<T>::tail = 0;
		if (StaticQueue<T>::isFull())throw "Dequeue overflow!";
		StaticQueue<T>::head = (StaticQueue<T>::head - 1) % StaticQueue<T>::size;
		StaticQueue<T>::arr[StaticQueue<T>::head] = el;
		StaticQueue<T>::num++;
	}
	void enqueueTail(T el) { StaticQueue<T>::enqueue(el); }
	T dequeueHead() { return StaticQueue<T>::dequeue(); }
	T dequeueTail()
	{
		if (StaticQueue<T>::isEmpty())throw "Dequeue underflow!";
		T temp= StaticQueue<T>::arr[StaticQueue<T>::tail];
		StaticQueue<T>::tail = (StaticQueue<T>::tail - 1) % StaticQueue<T>::size;
		StaticQueue<T>::num--;
		if (StaticQueue<T>::isEmpty())this->head = this->tail = 0;
		return temp;
	}
	T getTail() { return this->arr[this->tail]; }
};