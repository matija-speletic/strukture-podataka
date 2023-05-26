#include"Stack.h"
#include <iostream>
using namespace std;
Stack::Stack(int nsize) 
{
	size = nsize;
	array = new int[size];
	top = -1;
};

bool Stack::isEmpty()
{ 
	return (top == -1); 
};

int Stack::numberOfElements()
{ 
	return (top + 1); 
};

Stack::~Stack()
{ 
	delete[] array; 
};

void Stack::push(int element)
{
	if (top == (size - 1))
		throw new exception("Stack overflow!");
	array[++top] = element;
};

int Stack::pop()
{
	if (top == -1)
		throw new exception("Stack underflow!");
	char result = array[top--];
	return result;
};

int Stack::getTop()
{
	if (top == -1)
		throw new exception("Stack underflow!");
	return array[top];
};

void Stack::printStack()
{
	for (int i = 0; i <= top; i++)
		cout << array[i] << ' ';
	cout << endl;
};

