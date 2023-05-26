#include <iostream>
using namespace std;

#include "LinkedNodeInt.h"

LinkedNodeInt::LinkedNodeInt()
	: node(), adj(nullptr), next(nullptr), status(), stanica(true)
{

}

LinkedNodeInt::LinkedNodeInt(int nodeN)
	: node(nodeN), adj(nullptr), next(nullptr), status(), stanica(true)
{

}

LinkedNodeInt::LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN)
	: node(nodeN), adj(adjN), next(nextN), status(), stanica(true)
{

}

LinkedNodeInt::LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN, int statusN)
	: node(nodeN), adj(adjN), next(nextN), status(statusN), stanica(true)
{

}

void LinkedNodeInt::visit()
{
	cout << node << " ";
}
