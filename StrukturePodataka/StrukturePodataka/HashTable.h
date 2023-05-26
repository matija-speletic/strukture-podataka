#pragma once
#include <math.h>
#include "HashObject.h"

template<class T,class R>
class HashTable
{
protected:
	unsigned int length;
	unsigned int count;
	unsigned int lenExp;
public:
	HashTable(int l)
	{
		//veci ceo deo log2(potrebna duzuna)
		int num = ceil(log2((double)l));
		length = 1 << num ;//2^e
		lenExp = num;
		count = 0;
	}

	virtual unsigned int f(int i) { return abs(i); }

	virtual unsigned int f(double d)
	{
		int exp;
		double m = frexp(d, &exp);
		return (unsigned int)((2 * fabs(m) - 1) * ~0U);
	}

	virtual unsigned int f(const char* c)
	{
		unsigned int res = 0;
		for (int i = 0; c[i]!=0; i++)
			res = res << 7 ^ c[i];
		return res;
	}

	virtual unsigned int f(string str)
	{
		unsigned int res = 0;
		const char* c = str.c_str();
		cout << c;
		for (int i = 0; c[i]!=0; i++)
			res = res << 7 ^ c[i];
		return res;
	}

	unsigned int gMod(unsigned int i)
	{
		return i % length;
	}

	unsigned int gFib(unsigned int i)
	{
		unsigned const int a = 2654435769;
		unsigned const ak = a * i;
		return(ak >> (32 - lenExp));
	}

	unsigned int h(HashObject<T, R> obj)
	{
		return gFib(f(obj.getKey()));
	}

	unsigned int h(T k)
	{
		return gFib(f(k));
	}

	unsigned int getLen() { return length; }

	virtual double getLF()
	{
		return (double)count / (double)length;
	}
};