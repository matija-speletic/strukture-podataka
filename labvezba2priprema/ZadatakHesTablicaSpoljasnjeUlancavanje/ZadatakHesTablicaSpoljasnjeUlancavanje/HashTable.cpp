#include"HashTable.h"

unsigned int HashTable::h(char* key)
{
	return g(f(key));
}

unsigned int HashTable::f(char* key)
{
	//TODO:Implementirati funkciju koja prevodi char u unsigned int

	/*//ovo dato inicijalno
	for (int i = 0; i < strlen(key); i++)
		h += key[i];*/

	/*//ovo je ok za poslednja 4-5 karaktera
	unsigned int h = 0;
	for (int i = 0; i < strlen(key); i++)
		h = h << 7 ^ key[i];*/

	/*//za sedmocifreni (bitwise - brze)
	unsigned int h = 0;
	for (int i = 0; i < strlen(key); i++)
	{
		h << 4;
		h += key[i] - '0';
	}
	return h;*/

	//za sedmocifreni (mnozenje - sporije)
	/*unsigned int h = 0;
	for (int i = 0; i < strlen(key); i++)
	{
		h *= 10;
		h += key[i] - '0';
	}
	return h;*/

	//djb2 (preporucena verzija)
	//algoritam nadjen na http://www.cse.yorku.ca/~oz/hash.html
	//Department of Electrical Engineering & Computer Science and Engineering
	//York University
	//Toronto, Ontario, Canada
	unsigned int h = 5381;
	int i = 0;
	while (key[i])
		h = /*h * 33 ^ key[i++]*/((h << 5) + h) + key[i++];

	cout << h << endl;
	return h;
}

unsigned int HashTable::g(unsigned int key)
{
	//TODO:Implementirati funkciju koja prevodi unsigned int u [0...M-1]

	/*//PO MODULU
	return key % m;
	*/

	
	//FIBONACIJEV
	unsigned const int a = 2654435769;
	unsigned const ak = a * key;
	unsigned int ret = ak >> (32 - dimExp);
	cout << ret << endl;
	return ret;
	

	/*//SREDINA KVADRATA
	return (key * key) >> (32 - dimExp);*/

	/*//PRESAVIJANJE (sedmocifreni)
	unsigned int h = key % 1000;
	key /= 1000;
	h += key % 1000;
	h += key / 1000;

	//cout << h % m << endl;
	return h % m;*/

	/*//PRESAVIJANJE (modifikovano)
	unsigned int h = key % 1000;
	key /= 100;
	h += key % 1000;
	h += key / 100 % 1000;
	return h % m;*/


}

