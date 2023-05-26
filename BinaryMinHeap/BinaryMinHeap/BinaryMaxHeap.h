#pragma once
#include "BinaryMinHeap.h"

class BinaryMaxHeapInt
{
private:
	long numOfElements;
	long length;
	int* array;
public:
	BinaryMaxHeapInt(long len);
	~BinaryMaxHeapInt();

	bool isEmpty() const { return numOfElements == 0; }
	int getFirst() const;

	void insert(int el);
	int deleteRoot();

	static void HeapSort(int* a, long n);

	void print();
	static BinaryMaxHeapInt* mergeMaxHeaps(BinaryMaxHeapInt* h1, BinaryMaxHeapInt* h2);
};

