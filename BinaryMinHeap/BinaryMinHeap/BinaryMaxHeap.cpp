#include "BinaryMaxHeap.h"
#include <iostream>
using namespace std;

BinaryMaxHeapInt::BinaryMaxHeapInt(long len)
{
	length = len;
	numOfElements = 0;
	array = new int[length+1];
}

BinaryMaxHeapInt::~BinaryMaxHeapInt()
{
	delete[] array;
}

int BinaryMaxHeapInt::getFirst() const
{
	if (isEmpty())
		throw new exception("The heap is empty");
	return array[1];
}

void BinaryMaxHeapInt::insert(int el)
{
	if (numOfElements == length)
		throw new exception("The heap is full");
	int pos = ++numOfElements;
	while (pos > 1 && array[pos / 2] < el)
	{
		array[pos] = array[pos / 2];
		pos /= 2;
	}
	array[pos] = el;
}

int BinaryMaxHeapInt::deleteRoot()
{
	if (isEmpty())
		throw new exception("The heap is empty");
	int ret = array[1];

	int last = array[numOfElements];
	numOfElements--;
	long pos = 1;
	while (2 * pos <= numOfElements)
	{
		long child = 2 * pos;
		if (child<numOfElements && array[child + 1]>array[child])
			child += 1;
		if (last >= array[child])
			break;
		array[pos] = array[child];
		pos = child;
	}
	array[pos] = last;

	return ret;
}

void BinaryMaxHeapInt::HeapSort(int* a, long n)
{
	BinaryMaxHeapInt heap(n);
	for (int i = 0; i < n; i++)
		heap.insert(a[i]);
	for (int i = 0; i < n; i++)
		a[i] = heap.deleteRoot();
	/*
	for(int i=n;!heap.isEmpty();i--)
		a[i]=heap.deleteRoot();
	*/
}

void BinaryMaxHeapInt::print()
{
	for (int i = 1; i <= numOfElements; i++)
		cout << array[i] << " ";
}

BinaryMaxHeapInt* BinaryMaxHeapInt::mergeMaxHeaps(BinaryMaxHeapInt* h1, BinaryMaxHeapInt* h2)
{
	BinaryMaxHeapInt* heap = new BinaryMaxHeapInt(h1->length + h2->length);
	int num = h1->numOfElements > h2->numOfElements ? h1->numOfElements : h2->numOfElements;
	for (int i = 0; i < num; i++)
	{
		if (i < h1->numOfElements)
			heap->insert(h1->array[i]);
		if (i < h2->numOfElements)
			heap->insert(h2->array[i]);
	}
	return heap;
}
