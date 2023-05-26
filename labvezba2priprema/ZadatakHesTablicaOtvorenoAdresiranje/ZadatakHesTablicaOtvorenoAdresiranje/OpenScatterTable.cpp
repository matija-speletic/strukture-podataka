#include "OpenScatterTable.h"
using namespace std;


OpenScatterTable::OpenScatterTable(unsigned int length)
{
	count = 0;
	m = length;
	array = new ScatterObject[m];
	
	//DODATO: vece celo od exponenta duzine (ceil - ceiling)
	dimExp = ceil(log2(length));

	/*OPCIONO
	umesto m=len je bolje:
	m=1<<dimExp*/
}


OpenScatterTable::~OpenScatterTable()
{
	delete[] array;
}

unsigned int OpenScatterTable::c(unsigned int i)
{
	//TODO implementirati sekundarnu funkciju
	//return i*i;

	//jun 2020 modifikovano kvadratno trazenje
	return i+1;
}

unsigned int OpenScatterTable::findUnoccupied(ScatterObject obj)
{
	unsigned int hash = h(obj.getKey());
	unsigned int probe = hash;
	if (array[probe].status < 2)  
		return probe; // slobodan
	int i = 1;
	do {
		probe = (hash + c(i))%m;
		if (array[probe].status < 2)  
			return probe;
		i++;
	} while (probe != hash && i<m);
	throw new exception("Tablica je puna");
}

void OpenScatterTable::withdraw(char * key)
{
	if (count == 0) throw new exception("Tablica je prazna");
	long offset = findMatch(key);
	if (offset < 0) throw new exception("Nije nadjen!");
	array[offset].status = 1; // obrisan
	array[offset].deleteRecord();
	count--;

}

unsigned int OpenScatterTable::findMatch(char* key)
{
	unsigned int hash = h(key);
	for (unsigned int i = 0; i < m; i++)
	{
		unsigned int probe = hash + c(i);
		if (array[probe].status == 0) return -1;
		if (array[probe].isEqualKey(key)) return probe;
	}
	return ~0U;
}

void OpenScatterTable::insert(ScatterObject obj)
{
	if (count == m)
		throw new exception("Tablica je puna!");
	unsigned int offset = findUnoccupied(obj);
	array[offset] = obj;
	array[offset].status = 2; // zauzet
	count++;
}

void OpenScatterTable::print()
{
	for (unsigned int i = 0; i < m; i++)
	{
		cout << i << " ";
		array[i].print();
	}
}

void OpenScatterTable::addOrUpdate(ScatterObject obj)
{
	unsigned int hash = h(obj.getKey()), probe = hash;
	bool prisutan = false;
	for (unsigned int i = 0; i < m; i++)
	{
		probe = (hash + c(i)) % m;
		if (array[probe].status == 0)break;
		if (array[probe].isEqualKey(obj.getKey()))
		{
			prisutan = true;
			break;
		}
	}
	if (prisutan)
		array[probe].record = obj.getRecord();
	else if (count < m)
	{
		array[probe] = obj;
		array[probe].status = 2;
		count++;
	}
}

void OpenScatterTable::InsertOrUpdate(char* k, char* r)
{
	int hash = h(k), probe = hash, prvoSlobodno = -1;
	for (int i = 0; i < m; i++)
	{
		probe = (hash + c(i)) % m;
		if (array[probe].status < 2 && prvoSlobodno == -1)
			prvoSlobodno = probe;
		if (array[probe].status == 0)
			break;
		if (array[probe].isEqualKey(k))
		{
			array[probe].record = r;
			return;
		}
	}
	if (prvoSlobodno == -1)
	{
		cout << "Mesto nije pronadjeno!";
		return;
	}
	else
	{
		array[prvoSlobodno] = ScatterObject(k, r);
		array[prvoSlobodno].status = 2;
		count++;
	}
}
