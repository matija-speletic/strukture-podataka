#pragma once
#include <iostream>
#include "ScatterObject.h"
#include "HashTable.h"
using namespace std;

template <class T, class R>
class OpenScatterTable : public HashTable<T,R>
{
protected:
	ScatterObject<T, R>* arr;
public:
	OpenScatterTable(unsigned int l) :HashTable<T, R>(l)
	{
		arr = new ScatterObject<T, R>[HashTable<T, R>::length];
	}
	~OpenScatterTable() { delete[] arr; }
protected:
	void display()
	{

	}
public:
};