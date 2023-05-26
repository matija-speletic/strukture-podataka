#include"HashTable.h"

unsigned int HashTable::h(char* key)
{
	return g(f(key));
}

unsigned int HashTable::f(char* key)
{
	/*//TODO:Implementirati funkciju koja prevodi char u unsigned int
	unsigned int h = 0;
	for (int i = 0; i < strlen(key); i++)
		h += key[i];
	return h;*/

	/*//XXX-YYYYYYYYYYYYY-ZZ
	//01234567890123456789 - indeksi
	//namerno je naopako x i z
	//cout << key;
	int brX = key[0]-'0' + 10 * (key[1]-'0') + 100 * (key[2]-'0');
	cout << brX << endl;
	int brZ = (key[18] - '0') + 10 * (key[19] - '0');
	cout << brZ << endl;
	unsigned int h = brX * brZ * 33;
	for (int i = 4; i < 17; i++)
		h = (h << 2) ^ key[i];
	cout << h <<endl;
	return h;*/

	/*//XXX-YYYYYYYYYYYYY-ZZ
	//01234567890123456789 - indeksi
	unsigned int h = 0;
	for (int i = 0; i < 21; i++)
		h = (h << 1) ^ key[i];
	cout << h << endl;
	return h;*/

	//jun2020
	//AAA-xxxx/yy-zzz
	//abc-1234/78-638
	//012345678901234
	/*unsigned int a = (key[0] << 14) ^ (key[1] << 7) ^ (key[2]),
		x = (key[4] << 21) ^ (key[5] << 14) ^ (key[6] << 7) ^ key[7],
		y = (key[9] - '0') * 10 + key[10] - '0',
		z = (key[12] - '0') * 100 + (key[13] - '0') * 10 + key[14] - '0',
		ret = a * x ^ y * z;
	cout << a << ' ' << x << ' ' << y << ' ' << z << ' ' << ret << endl;
	return ret;*/


	//blablablabla@acme.org

	//xxx.yyyyyyyyyy.zz
	//

	//XXX YYYYYYYYYYYYYY
	unsigned int p1=0,p2=0;

	int i = 0;
	while (key[i] != '@')
		p1 = key[i++] + (p1 << 6) + (p1 << 16) - p1;
	i++;
	while (key[i] != 0)
		p2 = p2 << 7 ^ key[i++];
	cout << p1 << ' ' << p2 << ' ';
	return p2 * p1;

	
}

unsigned int HashTable::g(unsigned int key)
{
	//TODO:Implementirati funkciju koja prevodu unsigned int u [0...M-1]
	//return key%m;

	//FIBONACIJEV
	unsigned const int a = 2654435769;
	unsigned const ak = a * key;
	unsigned int ret = ak >> (32 - dimExp);
	cout << ret << endl;
	return ret;
}

