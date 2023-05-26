#include"ChainedScatterTable.h"

void main()
{
	/*ChainedScatterTable tablica(16);
	ChainedScatterObject o("2907982750051", "Nikola Davidovic");
	tablica.insert(o);
	ChainedScatterObject o1("2706985730058", "Pera Peric");
	ChainedScatterObject o2("2907982750051", "Nikola Davidovic");
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o1);
	tablica.insert(o1);
	tablica.insert(o2);
	tablica.print();

	try
	{
		char k1[] = "2907982750051";
		char k2[] = "2706985730058";
		tablica.withdraw(k1);
		tablica.print();
		tablica.withdraw(k2);
		tablica.print();
		tablica.withdraw(k1);
		tablica.print();
		tablica.withdraw(k1);
		tablica.print();
		tablica.insert(o2);
		tablica.insert(o2);
		tablica.insert(o1);
		tablica.insert(o1);
		tablica.insert(o2);
		tablica.print();
	}
	catch (exception* exc)
	{
		cout << exc->what();
	}
	/*catch (...)
	{
		cout << "Nesto nije dobro";
	}*/
	ChainedScatterTable tablica(8);
	for (int i = 0; i < 15; i++)
	{
		char k[10], n[10];
		cin >> k >> n;
		ChainedScatterObject o2(k, n);
		tablica.InsertOrUpdate(o2.key,o2.record);
		tablica.print();
		cout << endl << endl;
	}

	/*ChainedScatterObject o1("ME2018001", "1");
	ChainedScatterObject o2("ME2018003", "2");
	ChainedScatterObject o3("ME2018004", "3");
	ChainedScatterObject o4("ME2018101", "4");
	ChainedScatterObject o5("ME2018201", "5");
	ChainedScatterObject o6("ME2018001", "1pr");
	ChainedScatterObject o7("ME2018003", "2pr");
	ChainedScatterObject o8("ME2018004", "3pr");
	ChainedScatterObject o9("MA2018001", "6");
	ChainedScatterObject o10("BE2018001", "7");
	ChainedScatterObject o11("MC2018001", "8");
	ChainedScatterObject o12("MD2018001", "9");
	tablica.InsertOrUpdate(o2.key, o2.record);
	tablica.print();
	cout << endl << endl;*/
	
}