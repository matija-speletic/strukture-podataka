#pragma once
#include <iostream>
using namespace std;

class StaticBSTreeInt
{
private:
	int maxHeight;
	int* tree;
	int numOfElements;
	int size;
	int end;
public:
	StaticBSTreeInt(int mh);
	~StaticBSTreeInt() { delete[] tree; }
	void insert(int x);
	void print();

	//SEPTEMBAR 2019
	int findMatch(int x);

	//APRIL 2019
	void findLeaves(int node, int* count);
	int LeavesCount();
	//teorijski deo
	static StaticBSTreeInt* createTreeFromArray(int arr[], int n, int maxH);

};

