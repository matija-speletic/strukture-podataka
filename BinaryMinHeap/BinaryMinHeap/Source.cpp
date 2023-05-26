#include <iostream>
#include "BinaryMaxHeap.h"
#include "BinaryMinHeap.h"
using namespace std;

void main()
{
	/*int a[10];
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	BinaryMaxHeapInt::HeapSort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << ", ";
	cout << endl;
	BinaryMinHeapInt::HeapSort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << ", ";*/

	BinaryMinHeapInt heap(15);
	int br;
	for (int i = 0; i < 7; i++)
	{
		cin >> br;
		heap.insert(br);
	}
	heap.print();
	cout << endl;
	heap.convertToMaxHeap();
	heap.print();
}