#pragma once
#include "HashObject.h"

template <class T, class R>
class ScatterObject :public HashObject<T, R>
{
protected:
	bool free;
public:
	ScatterObject() :HashObject<T, R>() { free = true; }
	ScatterObject(T k) :HashObject<T, R>(k) { free = true; }
	ScatterObject(T k, R r) :HashObject<T, R>(k, r) { free = true; }
};