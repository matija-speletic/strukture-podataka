#include "SLL.h"

void main()
{
	SLL<int> a;
	a.addToTail(1);
	a.addToHead(2);
	a.printAll();
	a.addToHead(3);
	a.printAll();
	a.addToTail(4);
	a.printAll();
	a.addToTail(5);
	a.addToHead(6);
	a.addToTail(7);
	a.printAll();
	a.deleteEl(1);
	a.printAll();
	a.deleteFromHead();
	a.printAll();
	a.deleteFromTail();
	a.printAll();
}