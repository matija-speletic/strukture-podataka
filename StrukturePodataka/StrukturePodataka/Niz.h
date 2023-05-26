#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Niz
{
	char* arr;
	void copy(const Niz& n)
	{
		arr = new char[niz_length(n) + 1];
		int i = 0;
		while (n.arr[i])
			arr[i] = n.arr[i++];
		arr[i] = 0;
	}
public:
	Niz() { arr = new char[100]; }
	Niz(int n) { arr = new char[n]; }
	Niz(const char* s)
	{
		arr = nullptr;
		*this = s;
	}
	~Niz() { delete[] arr; }
	Niz(const Niz& n)
	{
		copy(n);
	}
	Niz& operator=(const Niz& n)
	{
		if (this == &n)
			return *this;
		delete[] arr;
		copy(n);
	}
	Niz& operator=(const char* s)
	{
		if (arr)
			delete[] arr;
		arr = new char[strlen(s) + 1];
		strcpy(arr, s);
		return *this;
	}
	static int niz_length(const Niz& n)
	{
		int i = 0;
		while (n.arr[i])
			i++;
		return i;
	}
	static Niz niz_substring(const Niz& s, int i, int n)
	{
		Niz temp(n + 1);
		int j, k;
		for (j = i, k = 0; k < n; j++, k++)
			temp.arr[k] = s.arr[j];
		temp.arr[k] = 0;
		return temp;
	}
	static int niz_index(const Niz& t, const Niz& p)
	{
		bool pronadjen = false;
		int i = 0;
		int np = niz_length(p);
		while (i < niz_length(t) - np && !pronadjen)
		{
			pronadjen = true;
			int j = 0;
			while (t.arr[i + j] == p.arr[j])
				j++;
			if (j < np)
				pronadjen = false;
			i++;
		}
		if (pronadjen)
			return i - 1;
		else
			return -1;
	}
	static Niz niz_concat(const Niz& n1, const Niz& n2)
	{
		Niz temp(niz_length(n1) + niz_length(n2) + 1);
		int i = 0;
		while (n1.arr[i])
			temp.arr[i] = n1.arr[i++];
		int j = 0;
		while (n2.arr[j])
			temp.arr[i++] = n2.arr[j++];
		temp.arr[i] = 0;
		return temp;
	}
	friend ostream& operator<<(ostream& izl, Niz& n);
	friend istream& operator>>(istream& ul, Niz& n);
};

int length(const Niz& n);
int index(const Niz& t, const Niz& p);
Niz substring(const Niz& t, int i, int n);
Niz concat(const Niz& s1, const Niz& s2);
void deleteAll(Niz& t, const Niz& p);
void umetanjeUzorka(Niz& t, const Niz& p, const Niz& q);