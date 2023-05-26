#include "Niz.h"

ostream& operator<<(ostream& izl, Niz& n)
{
	return izl << n.arr;
}

istream& operator>>(istream& ul, Niz& n)
{
	char* temp=new char[500];
	ul.getline(temp, 500);
	n = temp;
	delete[] temp;
	return ul;
}

 int length(const Niz& n) { return Niz::niz_length(n); }
 int index(const Niz& t, const Niz& p) { return Niz::niz_index(t, p); }
 Niz substring(const Niz& t, int i, int n) { return Niz::niz_substring(t, i, n); }
 Niz concat(const Niz& s1, const Niz& s2) { return Niz::niz_concat(s1, s2); }
