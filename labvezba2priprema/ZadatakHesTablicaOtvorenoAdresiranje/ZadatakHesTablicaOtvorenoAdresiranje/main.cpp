#include"OpenScatterTable.h"

void main()
{
	/*OpenScatterTable tablica(64);
	ScatterObject o("2907982750052", "Nikola Davidovic");
	tablica.insert(o);
	ScatterObject o1("2706985730058", "Pera Peric");
	ScatterObject o2("2907982750052", "Nikola Davidovic");
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o1);
	tablica.print();*/

	/*OpenScatterTable tablica(64);
	for (int i = 0; i < 10; i++)
	{
		char ime[20], broj[21];
		cin >> ime >> broj;
		//broj[20] = 0;
		//cout << broj;
		ScatterObject o(broj, ime);
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
	}*/

	//AAA - xxxx / yy - zzz
	/*ScatterObject o1("abc-1234/56-789", "1");
	ScatterObject o2("abd-1234/56-789", "2");
	ScatterObject o3("abc-1235/57-789", "3");
	ScatterObject o4("abc-1234/56-788", "4");
	ScatterObject o5("jhd-6387/33-987", "5");
	ScatterObject o6("abc-1235/57-789", "6");
	ScatterObject o7("jhd-6387/33-987", "7");
	OpenScatterTable tablica(8);
	tablica.addOrUpdate(o1);
	tablica.print();
	tablica.addOrUpdate(o2);
	tablica.print();
	tablica.addOrUpdate(o3);
	tablica.print();
	tablica.addOrUpdate(o4);
	tablica.print();
	tablica.addOrUpdate(o5);
	tablica.print();
	tablica.addOrUpdate(o6);
	tablica.print();
	tablica.addOrUpdate(o7);
	tablica.print();*/


	//ScatterObject o1("h2j8ch3k9xg4b@ao0m", "1");
	//ScatterObject o2("h3j8ch3k9xg4b@ao0m", "2");
	//ScatterObject o3("h2j8ch3k9xg4b@ao07", "3");
	//ScatterObject o4("asdf456ghj86f@4d3n", "4");
	OpenScatterTable tablica(8);
	tablica.findMatch("abc@def");

	tablica.InsertOrUpdate("h2j8ch3k9xg4b@ao0m", "1");
	tablica.InsertOrUpdate("h3j8ch3k9xg4b@ao0m", "2");
	tablica.InsertOrUpdate("h2j8ch3k9xg4b@ao07", "3");
	tablica.InsertOrUpdate("asdf456ghj86f@4d3n", "4");
	tablica.print();
	tablica.InsertOrUpdate("h2j8ch3k9xg4b@ao0m", "promenjen1");
	tablica.InsertOrUpdate("h3j8ch3k9xg4b@ao0m", "promenjen2");
	tablica.InsertOrUpdate("h2j8ch3k9xh4b@ao07", "5");
	tablica.print();
	tablica.InsertOrUpdate("asds456ghj86f@4d3n", "6");
	tablica.InsertOrUpdate("jajajajajajja@ao07", "7");
	tablica.InsertOrUpdate("asds456ghj86f@aaaa", "8");
	tablica.InsertOrUpdate("asbbbbbghj86f@aaaa", "9");
	tablica.print();
	tablica.InsertOrUpdate("jajajajajajja@ao07", "promenjen7");
	tablica.InsertOrUpdate("asds456ghj86f@aaaa", "promenjen8");
	tablica.print();
	tablica.print();
	
}