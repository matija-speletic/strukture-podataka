#pragma once
#include <iostream>
using namespace std;

template <class T>
class SMNode
{
public:
	T el;
	SMNode<T>* right, * down;
	int row, col;
	SMNode(T e, int r, int c) :el(e), row(r), col(c) { right = down = NULL; }
	~SMNode(){}
	//friend class SparseMatrix;
};


template <class T>
class SparseMatrix
{
	SMNode<T>** rows, ** cols;
	int n, m;
public:
	SparseMatrix(int n_dim, int m_dim)
		:n(n_dim), m(m_dim)
	{
		rows = new SMNode<T>*[m];
		cols = new SMNode<T>*[n];
		for (int i = 0; i < m; i++)rows[i] = NULL;
		for (int i = 0; i < n; i++)cols[i] = NULL;
	}
	T getAt(int i, int j)
	{
		SMNode<T>* tempR = rows[i];
		while (tempR != NULL && tempR->col != j)
			tempR = tempR->right;
		if (tempR != NULL)
			return tempR->el;
		return 0;
	}
	T getAt2(int i, int j)
	{
		SMNode<T>* tempR = cols[j];
		while (tempR != NULL && tempR->row != i)
			tempR = tempR->down;
		if (tempR != NULL)
			return tempR->el;
		return 0;
	}
	void setAt(int i, int j, T el)
	{
		SMNode<T>* n = new SMNode<T>(el, i, j);
		if (rows[i] == NULL)
			rows[i] = n;
		else
		{
			//ptr1 - trenutni el, ptr2 - prethodni
			SMNode<T>* ptr1 = rows[i], * ptr2 = NULL;
			for (; ptr1 != NULL && ptr1->col < n->col; ptr2 = ptr1, ptr1 = ptr1->right);

			n->right = ptr1;
			if (ptr2 != NULL)
				ptr2->right = n;
			else
				rows[i] = n;
		}

		if (cols[j] == NULL)
			cols[j] = n;
		else
		{
			//ptr1 - trenutni el, ptr2 - prethodni
			SMNode<T>* ptr1 = cols[j], * ptr2 = NULL;
			for (; ptr1 != NULL && ptr1->row < n->row; ptr2 = ptr1, ptr1 = ptr1->down);

			n->down = ptr1;
			if (ptr2 != NULL)
				ptr2->down = n;
			else
				cols[j] = n;
		}
		
	}
	void load()
	{
		for(int i=0;i<m;i++)
			for (int j = 0; j < n; j++)
			{
				T el;
				cin >> el;
				if (el)
					setAt(i, j, el);
				print();
			}
	}
	void print()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << getAt2(i, j) << ' ';
			cout << endl;
		}
	}
};