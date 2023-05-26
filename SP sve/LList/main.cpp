#include "LList.h"

void main()
{
	LList *list = new LList();
	int br = 0;
	while (true)
	{
		cin >> br;
		if (br == -1)break;
		list->addToTail(br);
	}
	list->printAll();

	//JUN 2021
	/*//2 4 6 8 1 3 5 10 11 12 -1
	LList* even = list->extractEven();
	even->printAll();
	list->printAll();
	delete even;*/

	//JUN 2020
	/*int k, v;
	while (true)
	{
		cin >> k >> v;
		if (k == -1 || v == -1)break;
		list->InsertOrUpdate(k, v);
		list->printAll();
	}
	delete list;*/

	//SEPTEMBAR 2020
	/*int k, v;
	while (true)
	{
		cin >> k >> v;
		if (k == -1 || v == -1)break;
		list->UpdateNode(k, v);
		list->printAll();
	}*/

	//JUN2 2020
	/*//1 2 3 4 5 6 7 8 -1	  3 8 2 5 7 1 6 4 -1
	LList* list2 = new LList();
	br = 0;
	while (true)
	{
		cin >> br;
		if (br == -1)break;
		list2->addToTail(br);
	}
	list2->printAll();
	cout << endl << endl;
	list->Exchange(list2, 5, 3);
	list->printAll();
	list2->printAll();
	cout << endl;
	list->Exchange(list2, 5, 2);
	list->printAll();
	list2->printAll();
	cout << endl;
	list->Exchange(list2, 5, 1);
	list->printAll();
	list2->printAll();
	cout << endl;
	list->Exchange(list2, 3, 3);
	list->printAll();
	list2->printAll();
	cout << endl;
	list->Exchange(list2, 6, 2);
	list->printAll();
	list2->printAll();
	cout << endl;*/

	//DECEMBAR 2020
	/*int a[] = { 5,7,1,3,10,0,4,2 }, n = 8;
	LList* l = LList::formList(a, n);
	l->printAll();*/

	//KOLOKVIJUM1 2017
	list->fillInTheBlanks2();
	list->printAll();

	//OKTOBAR 2017(po sicefu)
	/*int k, v;
	while (true)
	{
		cin >> k >> v;
		if (k == -1 || v == -1)break;
		list->UpdateNode(k, v);

	}
	list->Compact();
	list->printAllKV();*/

	//APRIL 2017
	/*list->MoveToBeginning(18);
	list->printAll();*/

	//FEBRUAR 2017
	/*list->swapMinMax();
	list->printAll();
	list->swapMinMax();
	list->printAll();
	/*
	1 2 3 4 5 6 7 -1
	2 3 1 4 5 7 6 -1
	1 7 2 3 4 5 6 -1
	2 3 4 1 7 5 6 -1
	2 3 4 5 6 1 7 -1
	1 2 7 3 4 5 6 -1
	2 3 1 4 7 5 6 -1
	*/


	delete list;
}