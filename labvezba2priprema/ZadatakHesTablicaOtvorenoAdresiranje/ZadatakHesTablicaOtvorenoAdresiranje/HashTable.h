#pragma once
#include"HashObject.h"
#include <iostream>
using namespace std;

class HashTable
{
protected:
	unsigned int m; // velicina tablice
	unsigned int count;  //broj elemenata u tablici

	//DODATO
	unsigned int dimExp;
protected:
	unsigned int h(char* key);

	// primarna transformacija 
	unsigned int f(char * key);
	unsigned int g(unsigned int key);
public:
	unsigned int getLength() { return m; }
	
};

