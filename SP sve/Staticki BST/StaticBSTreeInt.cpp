#include "StaticBSTreeInt.h"

StaticBSTreeInt::StaticBSTreeInt(int mh)
	:maxHeight(mh),size(pow(2, maxHeight)),numOfElements(0),end(0)
{
	tree = new int[size];
	for (int i = 0; i < size; i++)
		tree[i] = -1;
}

void StaticBSTreeInt::insert(int x)
{
	if (numOfElements == size - 1)
		return;
	if (numOfElements == 0)
	{
		tree[1] = x;
		end = 1;
		numOfElements++;
		return;
	}
	int probe = 1;
	while (tree[probe] != -1)
		if (x < tree[probe])
			probe = 2 * probe;
		else
			probe = 2 * probe + 1;
	if (probe < size)
	{
		tree[probe] = x;
		numOfElements++;
		if (probe > end)
			end = probe;
	}
}

void StaticBSTreeInt::print()
{
	for (int i = 0; i < end+1; i++)
		if(tree[i]!=-1)
			cout << i << '\t' << tree[i] << endl;
		else
			cout << i << '\t' << endl;
	cout << "END:\t" << end << endl;
}

int StaticBSTreeInt::findMatch(int x)
{
	if (numOfElements == 0)
		return -1;
	int probe = 1;
	while (probe <= end && tree[probe] != x && tree[probe] != -1)
	{
		if (x < tree[probe])
			probe = 2 * probe;
		else
			probe = 2 * probe + 1;
	}
	if (probe <= end && tree[probe] == x)
		return probe;
	else
		return -1;
}

void StaticBSTreeInt::findLeaves(int node, int* count)
{
	if (node > end || tree[node] == -1)
		return;
	if (2 * node < size && tree[2 * node] == -1 && 2 * node + 1 < size && tree[2 * node + 1] == -1)
	{
		(*count)++;
		return;
	}
	findLeaves(2 * node, count);
	findLeaves(2 * node + 1, count);
}

int StaticBSTreeInt::LeavesCount()
{
	int count = 0;
	findLeaves(1, &count);
	return count;
}

StaticBSTreeInt* StaticBSTreeInt::createTreeFromArray(int arr[], int n, int maxH)
{
	StaticBSTreeInt* t = new StaticBSTreeInt(maxH + 1);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			t->tree[1] = arr[0];
		else
		{
			int probe = 1;
			while (t->tree[probe] != -1)
				if (arr[i] < t->tree[probe])probe = 2 * probe;
				else probe = 2 * probe + 1;
			t->tree[probe] = arr[i];
			if (probe > t->end)
				t->end = probe;
		}
	}
	t->numOfElements = n;
	return t;
}


