#include "BinaryMinHeap.h"
#include <iostream>
using namespace std;

BinaryMinHeapInt::BinaryMinHeapInt(long len)
{
	length = len;
	numOfElements = 0;
	array = new int[length+1]();
}

BinaryMinHeapInt::~BinaryMinHeapInt()
{
	delete[] array;
}

int BinaryMinHeapInt::getFirst() const
{
	if (isEmpty())
		throw new exception("The heap is empty");
	return array[1];
}

void BinaryMinHeapInt::insert(int el)
{
	if (numOfElements == length)
		throw new exception("The heap is full");
	numOfElements++;
	int pos = numOfElements;
	while (pos > 1 && array[pos / 2] > el)
	{
		array[pos] = array[pos / 2];
		pos /= 2;
	}
	array[pos] = el;
}

int BinaryMinHeapInt::deleteRoot()
{
	if (isEmpty())
		throw new exception("The heap is empty");

	int ret = array[1];
	int leaf = array[numOfElements--];
	long pos = 1;
	while (2 * pos <= numOfElements)
	{
		long child = 2 * pos;
		if (child < numOfElements && array[child + 1] < array[child])//ovo mora jer hocemo da najmanji element bude na vrhu
			//kada bismo stavili bez ovoga, moglo bi da se desi da roditeljski cvor bude veci od deteta svaki put kada je levo dete vece od desnog
			//jer levo dete preuzima ulogu roditelja prilikom zamene, a ako je desno dete manje od njega, heap nece biti korektan
			child += 1;
		if (leaf <= array[child])
			//kada se dodje do situacije da taj cvor sa kraj koji premestamo postane manji ili jednak svom detetu - dosli smo do kraja sa premestanjem (desi se kada je npr levo dete vece od desnog u poslednja dva cvora)
			break;
		array[pos] = array[child];
		pos = child;
	}
	array[pos] = leaf;
	return ret;

}

void BinaryMinHeapInt::HeapSort(int* a, long n)
{
	BinaryMinHeapInt heap(n);
	for (int i = 0; i < n; i++)
		heap.insert(a[i]);
	for (int i = 0; i < n; i++)
		a[i] = heap.deleteRoot();
}

void podstabloUMaxHeap(int arr[], int rod, int n)
{
	int levi = 2 * rod;
	int desni = 2 * rod + 1;
	int max = rod;

	//trazimo max od cvora i dva njegova deteta
	if (levi<=n && arr[levi]>arr[max])max = levi;
	if (desni<=n && arr[desni]>arr[max])max = desni;

	//ukoliko roditelj vec nije najveci
	if (max != rod)
	{
		//menjamo im mesta
		int pom = arr[rod];
		arr[rod] = arr[max];
		arr[max] = pom;

		//uredjujemo i podstablo, jer nakon ove zamene, moze da
		//se desi da se poremetio redosled u podstablu
		podstabloUMaxHeap(arr, max, n);
	}
}

void BinaryMinHeapInt::convertToMaxHeap()
{
	//potrebno je urediti svako stablo zasebno pozivom napisane funkcije
	//cvorovi sa indeksom <(n-1)/2 su cvorovi koji imaju decu
	//nema smisla pozivati funkciju za cvorove koji nemaju podstablo iza sebe
	for (int i = (numOfElements - 1) / 2; i > 0; i--)
		podstabloUMaxHeap(array, i, numOfElements);
}

void BinaryMinHeapInt::print()
{
	//cout << numOfElements << endl;
	for (int i = 1; i <= numOfElements; i++)
		cout << array[i] << " ";
}
