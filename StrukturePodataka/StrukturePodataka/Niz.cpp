#include "Niz.h"

ostream& operator<<(ostream& izl, Niz& n)
{
	return izl << n.arr;
}

istream& operator>>(istream& ul, Niz& n)
{
	char* temp = new char[500];
	ul.getline(temp, 500);
	n = temp;
	delete[] temp;
	return ul;
}

int length(const Niz& n) { return Niz::niz_length(n); }
int index(const Niz& t, const Niz& p) { return Niz::niz_index(t, p); }
Niz substring(const Niz& t, int i, int n) { return Niz::niz_substring(t, i, n); }
Niz concat(const Niz& s1, const Niz& s2) { return Niz::niz_concat(s1, s2); }

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