#pragma once
#include"ChainedHashTable.h"

void main()
{
	/*ChainedHashTable tablica(64);
	char jmbg[] = "2907982750051";
	char ime[] = "Nikola Davidovic";
	HashObject o(jmbg, ime);
	tablica.insert(o);
	char jmbg2[] = "2706985730058";
	char ime2[] = "Pera Peric";
	HashObject o1(jmbg2, ime2);
	HashObject o2(jmbg, ime);
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o1);
	tablica.insert(o1);
	tablica.insert(o2);
	tablica.print();*/

	ChainedHashTable tablica(64);
	for (int i = 0; i < 10; i++)
	{
		char ime[20], broj[7];
		cin >> ime >> broj;
		HashObject o(broj, ime);
		tablica.insert(o);
	}
	tablica.print();

	for (int i = 0; i < 5; i++)
	{
		char broj[7];
		cin >> broj;
		tablica.withdraw(broj);
		system("CLS");
		tablica.print();
	}
}



/*matija 1234567
a 1111111
b 2222222
c 3333333
d 4444444
e 4444445
f 4444446
g 4444447
h 6841254
i 6426462*/