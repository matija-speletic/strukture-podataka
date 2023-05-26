#pragma once
class Stack
{
protected:
	int* array; 	// polje elemenata
	int size;	// veličina polja
	int top;	// indeks vršnog elementa
public:
	Stack(int nsize);
	bool isEmpty();
	int numberOfElements();
	~Stack();
	void push(int element); 
	int pop(); 
	int getTop();
	void printStack();
};