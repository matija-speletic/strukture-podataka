#pragma once
#include "HashTable.h"
#include "ScatterObject.h"
class OpenScatterTable :
	public HashTable
{
protected:
	ScatterObject* array;
public:
	OpenScatterTable(unsigned int length);
	~OpenScatterTable();
	unsigned int c(unsigned int i);
	unsigned int findUnoccupied(ScatterObject obj);
	void withdraw(char * key);
	unsigned int findMatch(char* key);
	void insert(ScatterObject obj);
	void print();


	//jun 2020
	void addOrUpdate(ScatterObject obj);

	void InsertOrUpdate(char* k, char* r);
};

