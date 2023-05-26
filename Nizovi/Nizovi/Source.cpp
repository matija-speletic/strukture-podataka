#include "Niz.h"
#include <iostream>

void umetanjeUzorka(Niz& t, const Niz& p, const Niz& q)
{
	int i = index(t, p);
	if (i < 0)
		return;
	Niz s1 = substring(t, 0, i);
	Niz s2 = substring(t, i, length(t) - i);
	Niz s3 = concat(s1, q);
	t = concat(s3, s2);
	return;
}

void deleteAll(Niz& t, const Niz& p)
{
	int k = index(t, p);
	int n = length(p);
	while (k >= 0)
	{
		Niz s1 = substring(t, 0, k);
		Niz s2 = substring(t, k + n, length(t) - n - k);
		t = concat(s1, s2);
		k = index(t, p);
	}
	return;
}

//SEPTEMBAR 2019
void Zamena(Niz& t, const Niz& p, const Niz& q)
{
	int i1 = index(t, p), i2 = index(t, q);
	int l1 = length(p), l2 = length(q);
	bool sw = false;
	if (i2 < i1)
	{
		int temp;
		temp = i1, i1 = i2, i2 = temp;
		temp = l1, l1 = l2, l2 = temp;
		sw = true;
	}
	Niz s1 = substring(t, 0, i1);
	Niz s2 = substring(t, i1 + l1, i2 - i1 - l1);
	Niz s3 = substring(t, i2 + l2, length(t) - i2 - l2);
	if (!sw)
		t = concat(concat(concat(s1, q), concat(s2, p)), s3);
	else
		t = concat(concat(concat(s1, p), concat(s2, q)), s3);
}

void main()
{
	/*Niz text = "abcdefghijklmnopqrstuvwxyzabcdefgihabcdebeobfabcefoiesfn";
	umetanjeUzorka(text, "jkl", "123");
	deleteAll(text, "abc");
	cout << text;*/

	//SEPTEMBAR 2019
	Niz t = "Petar Petrovic Milan Aleksandar Zoran Jovanovic ";
	Zamena(t, "Jovanovic", "Petrovic");
	cout << t;

	
}