﻿#include "ChainedHashTable.h"

ChainedHashTable::ChainedHashTable(unsigned int len) {
	m = len;
	count = 0;
	array = new LList[len];

	//DODATO: vece celo od exponenta duzine (ceil - ceiling)
	dimExp = ceil(log2(len));

	/*OPCIONO
	umesto m=len je bolje:
	m=1<<dimExp*/
}

ChainedHashTable::~ChainedHashTable() {
	HashObject obj;
	for (unsigned int i = 0; i < m; i++) {
		while (!array[i].isEmpty())
			array[i].deleteFromHead();
	}
	delete[] array;
}
void ChainedHashTable::insert(HashObject obj) {
	array[h(obj.getKey())].addToHead(obj);
	count++;
}
void ChainedHashTable::withdraw(HashObject obj) {
	array[h(obj.getKey())].deleteEl(obj.getKey());
	count--;
}
void ChainedHashTable::withdraw(char* key) {
	HashObject obj = find(key);
	withdraw(obj);
}
HashObject ChainedHashTable::find(char* key) {
	HashObject obj;
	//unsigned int i = f(key) % m; // mora g kad je drugacije
	unsigned int i = h(key);
	obj = array[i].getHeadEl();
	while (!(obj.isEqualKey(key)))
		obj = array[i].getNextEl(obj.getKey());
	return obj;
}

void ChainedHashTable::print()
{
	for (unsigned int i = 0; i < m; i++)
	{
		cout << "[" << i << "]->";
		this->array[i].printAll();
	}
}