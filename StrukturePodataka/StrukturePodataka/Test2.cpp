#include "Test2.h"
#include "ChainedHashTable.h"
#include <iostream>
#include <stdlib.h>
using namespace std;



void Test2::CHTTest()
{
	ChainedHashTable<int, int> cht(63);
	for (unsigned int i = 0, j=9274934; i < 50; i++,j+=847985)
	{
		HashObject<int, int> h1(j,i);
		cht.insert(h1);
	}
	cht.display();
	while (true)
	{
		int broj;
		cin >> broj;
		if (broj < 0)break;
		cht.withdraw(broj);
		system("CLS");
		cht.display();
	}
	
}

void Test2::CHTTest2()
{
	ChainedHashTable<string,int> tab(29);
	/*while (true)
	{
		string s;
		int br;
		cin >> s >> br;
		if (br == -1)break;
		HashObject<string, int> h1(s, br);
		tab.insert(h1);
		system("CLS");
		tab.display();
	}*/
	for(int i=0;i<30;i++)
	{
		//ovaj primer se koristi za miki milane

		string s;
		//int br;
		cin >> s ;
		
		HashObject<string, int> h1(s, i);
		tab.insert(h1);
		system("CLS");
		tab.display();
	}
	for(int i=0;i<5;i++)
	{
		string s;
		cin >> s;
		tab.withdraw(s);
		system("CLS");
		tab.display();
	}
}

void Test2::StringJun2021Test()
{
	Niz t = "Moj ujak i moj otac su generacija";
	Niz s1 = "otac";
	Niz s2 = "tata";
	Niz s3 = "moj ";
	ZamenaJun2021(t, s1, s2, s3);
	cout << t;
}

void Test2::ZamenaJun2021(Niz& t, Niz s1, Niz s2, Niz s3)
{
	int ind = index(t, s1);
	if (ind == index(t, s3) + length(s3))
	{
		Niz str1 = substring(t, 0, ind);
		Niz str2 = substring(t, ind + length(s1), length(t) - ind - length(s1));
		t = concat(concat(str1, s2), str2);
	}
}


