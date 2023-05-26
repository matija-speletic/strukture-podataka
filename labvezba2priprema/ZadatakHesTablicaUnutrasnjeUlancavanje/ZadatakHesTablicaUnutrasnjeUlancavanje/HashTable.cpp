#include"HashTable.h"

unsigned int HashTable::h(char* key)
{
	return g(f(key));
}

unsigned int HashTable::f(char* key)
{
	/*//registarske tablice : NI123-MS
	//						01234567
	unsigned int num1 = key[0];
	num1 = (num1 << 7) ^ key[1];
	unsigned int num2 = key[6];
	num2 = (num2 << 7) ^ key[7];
	unsigned int num3 = (key[2] - '0') * 300 + (key[3] - '0') * 30 + key[4] - '0';
	//num1 = (num1 * num3) << num2;
	num1 = (num1 *num2*num3) ^ (num2*num1) ^ (num1*num3);
	cout << num1 << endl;
	return num1;*/

	//jun 2021
	//ME2018012
	//012345678
	unsigned int a = (key[0] << 7) ^ key[1],
		b = (key[2] - '0') * 1000 ^ (key[3] - '0') * 100 ^ (key[4] - '0') * 10 ^ key[5] - '0',
		c = (key[6] - '0') * 100 ^ (key[7] - '0') * 10 ^ key[8] - '0',
		ret = (a * c) ^ (b * c);
	cout << a << ' ' << b << ' ' << c << ' ' << ret << endl;
	return ret;

	//TODO:Implementirati funkciju koja prevodi char u unsigned int
	/*unsigned int h = 0;
	for (int i = 0; i < strlen(key); i++)
		h += key[i];
	return h;*/
}

unsigned int HashTable::g(unsigned int key)
{
	//TODO:Implementirati funkciju koja prevodi unsigned int u [0...M-1]
	//return key%m;

	//FIBONACIJEV
	unsigned const int a = 2654435769;
	unsigned const ak = a * key;
	unsigned int ret = ak >> (32 - dimExp);
	//cout << ret << endl << endl;
	return ret;
}




