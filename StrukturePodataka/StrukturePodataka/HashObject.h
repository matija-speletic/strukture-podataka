#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template <class T, class R>
class HashObject
{
protected:
	T key;
	R record;
public:
	HashObject() {  }
	HashObject(T k) { key = k;  }
	HashObject(T k, R obj) { key = k; record = obj; }
	~HashObject() { }
	HashObject& operator= (HashObject& obj)
	{
		key = obj.key;
		record = obj.record;
		return *this;
	}
	bool operator==(HashObject& obj) { return record == obj.record; }
	//void deleteRecord() 
	//{ 
	//	try
	//	{
	//		//if (record != NULL) { delete record; record = NULL; }
	//	}
	//	catch(...){}
	//}
	T getKey() { return key; }
	R* getRecord() { return record; }
	bool isEqualKey(T k) { return key == k; }
	void print() const { cout << key << '|' << record; }
	friend std::ostream& operator<< <>(std::ostream& out, const HashObject<T, R>& classObj);
}; 


template<class T, class R>
std::ostream& operator<< <>(std::ostream& out, const HashObject<T, R>& classObj)
{
	classObj.print();
	return out;
}