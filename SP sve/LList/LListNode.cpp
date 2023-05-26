#include "LListNode.h"


LListNode::LListNode()
{
	next=NULL;
	key = -1;
	info = -1;
}

LListNode::LListNode(int i) 
{ 
	info = i;
	next=NULL;
	key = -1;
}

LListNode::LListNode(int i, LListNode* n)
{
	info = i;
	next = n;
	key = -1;
}

int LListNode::print()
{
	return info;
}

bool LListNode::isEqual(int el)
{
	return el == this->info;
}

LListNode::~LListNode()
{
}
