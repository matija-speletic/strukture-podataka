#include "ChainedScatterTable.h"

ChainedScatterTable::ChainedScatterTable(unsigned int length)
{
	m = length;
	count = 0;
	lrmp = m;
	array = new ChainedScatterObject[2*m];
	for (int i = m; i < 2 * m - 1; i++)
	{
		array[i].next = i + 1;
	}
	array[2 * m - 1].next = 0;

	//DODATO: vece celo od exponenta duzine (ceil - ceiling)
	dimExp = ceil(log2(length));

	/*OPCIONO
	umesto m=length je bolje:
	m=1<<dimExp*/
}


ChainedScatterTable::~ChainedScatterTable()
{
	delete[] array;
}

void ChainedScatterTable::insert(ChainedScatterObject obj)
{
	if (count == m)
		throw new exception("Tablica je puna!");
	unsigned int probe = h(obj.getKey());
	if (array[probe].status == 2)
	{
		while (array[probe].status == 2 && array[probe].next != -1 && array[probe].next != 0)
		{
			probe = array[probe].next;
		}
		if (array[probe].next == 0)
			throw new exception("Izdvojeni prostor za sinonime je pun!");
		array[probe].next = lrmp;
		probe = lrmp;
		lrmp = array[probe].next;
	}
	array[probe] = obj;
	array[probe].status = 2; // zauzet
	array[probe].next = -1;
	count++;
}

void ChainedScatterTable::print()
{
	for (unsigned int i = 0; i < 2 * m; i++)
	{
		if (i == m)
			cout << "---------------------------------------" <<endl;
		cout << i << " ";
		array[i].print();
	}
}

ChainedScatterObject ChainedScatterTable::find(char* key)
{
	unsigned int probe = h(key);
	while (probe != -1)
	{
		if (!array[probe].isEqualKey(key))
			probe = array[probe].next;
		else
			return array[probe];
	}
	return ChainedScatterObject();
}

void ChainedScatterTable::withdraw(char* key)
{
	
	
	if (count == 0)
		throw new exception("Tablica je prazna!");

	unsigned int probe = h(key), prev = -1;
	while (probe != -1)//trazenje
	{
		if (array[probe].isEqualKey(key))
			break;
		prev = probe;
		probe = array[probe].next;
	}

	if (probe == -1)
		//throw new exception("Objekat nije nadjen!");
		return;

	//brisanje
	array[probe].deleteRecord();
	array[probe].status = 1;
	count--;
	if (probe<m&& array[probe].next != -1)//objekat u prvoj particiji
	{
		//ako ima sinonima - prelancati ih
		unsigned int syn = array[probe].next;
		array[probe] = array[syn];
		array[syn].next = lrmp;
		lrmp = syn;
		
	}
	else if (probe >= m)//objekat u particiji za sinonime
	{
		array[prev].next = array[probe].next;
		array[probe].next = lrmp;
		lrmp = probe;
	}
}

void ChainedScatterTable::azuriraj(char* key, int status)
{
	unsigned int probe = h(key), start = probe, prev = -1;
	while (probe != -1)
	{
		/*if (!array[probe].isEqualKey(key))
			probe = array[probe].next;
		else break;*/
		prev = probe;
		probe = array[probe].next;
	}
	if (probe == -1)
	{
		cout << "greska";
		return;
	}
	array[probe].status = status;
	if (status == 1)
	{
		char* tempc = array[probe].key;
		unsigned int temps = array[probe].status;
		array[probe].key = array[start].key;
		array[probe].status = array[start].status;
		array[start].key = tempc;
		array[start].status = temps;
	}
}

void ChainedScatterTable::InsertOrUpdate(char* k, char* r)
{
	int hash = h(k), probe = hash, prev = -1;
	while (probe != -1 && probe != 0)
	{
		if (array[probe].status == 0)
			break;
		if (array[probe].isEqualKey(k))
		{
			strcpy(array[probe].record, r);
			return;
		}
		prev = probe;
		probe = array[probe].next;
	}
	if (count == m)
	{
		cout << "tablica je puna";
		return;
	}
	if (array[hash].status < 2)
		probe = hash;
	else
	{
		if (probe == 0)
		{
			cout << "prostor za sinonime je pun";
			return;
		}
		probe = prev;
		array[probe].next = lrmp;
		probe = lrmp;
		lrmp = array[probe].next;		
	}
	array[probe] = ChainedScatterObject(k, r);
	array[probe].next = -1;
	array[probe].status = 2;
	count++;
}

