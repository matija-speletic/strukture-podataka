#pragma once
class BinaryMinHeapInt
{
private:
	int* array;
	long length;
	long numOfElements;

public:

	BinaryMinHeapInt(long len);
	~BinaryMinHeapInt();

	bool isEmpty() const { return numOfElements == 0; }
	int getFirst() const;

	void insert(int el);
	int deleteRoot();

	static void HeapSort(int* a, long n);

	void convertToMaxHeap();
	void print();

};

