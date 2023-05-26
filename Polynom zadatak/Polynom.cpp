#include "Polynom.h"


CPolynom::CPolynom(int order)
{
	this->order = order;
	this->data = new double[order];
	for (int i = 0; i < order; i++)
	{
		this->data[i] = 0.0;
	}
}


CPolynom::~CPolynom(void)
{
	delete[] this->data;
}

void CPolynom::Coef(int exp, double coef)
{
	this->data[exp] = coef;
}

int CPolynom::GetOrder()
{
	return this->order;
}

double CPolynom::GetCoefAt(int exp)
{
	return this->data[exp];
}

void CPolynom::Print()
{

	for (int i = 0; i < order - 1; i++)
		printf("%3.2lf*x%d + ", data[i], i);
	printf("%3.2lf*x%d\n", data[order - 1], order - 1);
}

CPolynom* CPolynom::Add(CPolynom* poly1, CPolynom* poly2)
{
	//odredjivanje polinoma veceg stepena
	int ord = poly1->order > poly2->order ? poly1->order : poly2->order;
	CPolynom * sum = new CPolynom(ord);//inicijalizovanje novog polinoma koji ce cuati zbir
	//prepisivanje prvog polinoma u polinom koji cuva zbir
	for (int i = 0; i < poly1->order; i++)
		sum->Coef(i, poly1->GetCoefAt(i));
	//sabiranje prvog polinoma sa drugim
	for (int i = 0; i < poly2->order; i++)
		sum->Coef(i, sum->GetCoefAt(i)+poly2->GetCoefAt(i));
	return sum;
}

CPolynom* CPolynom::Derivate()
{
	CPolynom* derivate = NULL;
	if (order > 0)
	{
		derivate = new CPolynom(this->GetOrder() - 1);
		for (int i = 1; i < this->GetOrder(); i++)
		{
			derivate->Coef(i - 1, this->GetCoefAt(i) * i);
		}

	}
	return derivate;
}


CPolynom* CPolynom::Derivate(int n)
{
	CPolynom* derivate = NULL;
	if (n < order && n>0)
	{
		derivate = this->Derivate();
		for (int i = 2; i <= n; i++)
		{
			CPolynom* newDerivate = derivate->Derivate();
			delete derivate;
			derivate = newDerivate;
		}
	}
	return derivate;
}



