#pragma once
#include <iostream>
using namespace std;

class BSTNodeInt
{
public:
	int key;
	BSTNodeInt* left, * right;
	BSTNodeInt()
		:key(), left(nullptr), right(nullptr) {	}
	BSTNodeInt(int br)
		:key(br), left(nullptr), right(nullptr) {	  }
	BSTNodeInt(int br, BSTNodeInt* l, BSTNodeInt* r)
		:key(br), left(l), right(r) {	}
	bool isLT(int el) { return key < el; }
	bool isGT(int el) { return key > el; }
	bool isEQ(int el) { return key == el; }
	void print() const { cout << key << ' '; }

};

