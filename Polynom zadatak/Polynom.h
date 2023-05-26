#include <iostream>

using namespace std;
#pragma once

class CPolynom
{
	double* data;
	int order;

public:
	CPolynom(int order);
	~CPolynom();

	int GetOrder();
	double GetCoefAt(int exp);
	void Coef(int exp, double coef);
	static CPolynom* Add(CPolynom* poly1, CPolynom* poly2);
	void Print();
	CPolynom* Derivate();
	CPolynom* Derivate(int n);
};
