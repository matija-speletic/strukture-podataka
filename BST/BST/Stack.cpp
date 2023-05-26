#include "Stack.h"

Stack::Stack(long s)
{
	size = s;
	arr = new BSTNodeInt * [size];
	top = -1;
}

BSTNodeInt* Stack::getTop() const
{
	if (top == -1)
		return nullptr;
	return arr[top];
}

void Stack::push(BSTNodeInt* el)
{
	if (top == size - 1)
		throw "Stack overflow!";
	arr[++top] = el;
}

BSTNodeInt* Stack::pop()
{
	if (top == -1)
		return nullptr;
	return arr[top--];
}
