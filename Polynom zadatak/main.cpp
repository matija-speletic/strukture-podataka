#include "Polynom.h";
void main()
{
	CPolynom* p1, * p2, * res;
	p1 = new CPolynom(5);
	p2 = new CPolynom(7);
	p1->Coef(0, 5);
	p1->Coef(3, 7);
	p1->Coef(4, 2);

	p2->Coef(1, 8);
	p2->Coef(3, 12);
	p2->Coef(6, 7);

	cout << "Prvi polinom:\n";
	p1->Print();
	cout << "Drugi polinom:\n";
	p2->Print();

	res = CPolynom::Add(p1, p2);
	cout << "Rezultujuci polinom:\n";
	res->Print();

	delete p1;
	delete p2;
	delete res;
}