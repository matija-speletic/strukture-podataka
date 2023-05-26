#include <iostream>
#include"StaticBSTreeInt.h"
using namespace std;

void main()
{
	//3 2 16 12 1 7 10 -1
	//17 43 25 14 30 39 38 27 23 12 45 11 24 22 50 - 1
	/*StaticBSTreeInt t(7);
	int el = 0;
	while (el != -1)
	{
		cin >> el;
		if (el == -1)break;
		t.insert(el);
	}
	t.print();*/
	
	//SEPTEMBAR 2019
	/*cout << t.findMatch(3) << endl;
	cout << t.findMatch(7) << endl;
	cout << t.findMatch(10) << endl;
	cout << t.findMatch(30) << endl;
	cout << t.findMatch(17) << endl;*/

	//APRIL 2019
	/*cout << t.LeavesCount();
	int a[] = { 3, 2, 16, 12, 1, 7, 10 };
	StaticBSTreeInt* t1 = StaticBSTreeInt::createTreeFromArray(a, 7, 5);
	t1->print();*/

	// DECEMBAR 2020
	int a[] = { 22,13,1,18,7 };
	StaticBSTreeInt* t1 = StaticBSTreeInt::createTreeFromArray(a, 5, 5);
	t1->print();

}