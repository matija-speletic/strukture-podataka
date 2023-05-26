#include"DList.h"
#include <iostream>
using namespace std;

void main()
{
	/*
	10 20 30 40 50 60 70 80 90 -1 55 75 25 95 5 -1
	*/
	DList* list = new DList();
	int br = 0;
	while (true)
	{
		cin >> br;
		if (br == -1)break;
		list->addToTail(br);
	}
	list->printAll();
	DList* list2 = new DList();
	br = 0;
	while (true)
	{
		cin >> br;
		if (br == -1)break;
		list2->addToTail(br);
	}
	list2->printAll();
	DList::UmetniListu(list, list2);
	list->printAll();

	delete list;
}