#include "Queue.h"

Queue::Queue(long s)
{
	size = s;
	head = tail = -1;
	arr = new BSTNodeInt * [size]();
	num = 0;
}

BSTNodeInt* Queue::getHead() const
{
	if (num == 0)
		return nullptr;
	return arr[head];
}

void Queue::enqueue(BSTNodeInt* el)
{
	if (num == size)
		throw "Overflow!";
	tail = (tail + 1) % size;
	arr[tail] = el;
	if (num == 0)
		head = tail;
	num++;
}

BSTNodeInt* Queue::dequeue()
{
	if (num == 0)
		return nullptr;
	BSTNodeInt* ret = arr[head];
	head = (head + 1) % size;
	num--;
	if (num == 0)
		head = tail = -1;
	return ret;
}
