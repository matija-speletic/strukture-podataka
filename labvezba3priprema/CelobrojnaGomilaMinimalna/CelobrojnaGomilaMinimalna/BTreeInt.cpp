﻿#include "BTreeInt.h"

#include <exception>
using namespace std;

#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"

void BTreeInt::deleteTree(BTNodeInt* ptr)
{
	if (ptr != nullptr) {
		deleteTree(ptr->left);
		deleteTree(ptr->right);
		delete ptr;
	}
}

void BTreeInt::preorder(const BTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		ptr->visit();
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void BTreeInt::inorder(const BTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		inorder(ptr->left);
		ptr->visit();
		inorder(ptr->right);
	}
}

void BTreeInt::postorder(const BTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		ptr->visit();
	}
}

void BTreeInt::iterativePreorder() const
{
	BTNodeInt* ptr = root;
	StackAsArrayBSTNodeInt stack(numOfElements);
	if (ptr != nullptr) {
		stack.push(ptr);
		while (!stack.isEmpty()) {
			ptr = stack.pop();
			ptr->visit();
			if (ptr->right != nullptr)	// levi potomak se stavlja u magacin
				stack.push(ptr->right); // posle desnog, da bi se prvi obradio
			if (ptr->left != nullptr)
				stack.push(ptr->left);
		}
	}
}

void BTreeInt::breadthFirstSearch() const
{
	BTNodeInt* ptr = root;
	QueueAsArrayBSTNodeInt queue(numOfElements);
	if (ptr != nullptr) {
		queue.enqueue(ptr);
		while (!queue.isEmpty()) {
			ptr = queue.dequeue();
			ptr->visit();
			if (ptr->left != nullptr)
				queue.enqueue(ptr->left);
			if (ptr->right != nullptr)
				queue.enqueue(ptr->right);
		}
	}
}

BTreeInt* BTreeInt::BinaryTreeFromMinHeap(BinaryMinHeapInt& minHeap)
{
	if (minHeap.isEmpty())
		return NULL;
	BTreeInt* ret = new BTreeInt();
	ret->root = new BTNodeInt(minHeap.getFirst());
	treeFromMinHeapFormation(ret->root, minHeap.getArr(), minHeap.getNumOfElements() + 1, 1);
	return ret;
}

void BTreeInt::treeFromMinHeapFormation(BTNodeInt* node, int minHeap[], int size, int index)
{
	if (node == NULL || index > size)
		return;
	if (2 * index < size)node->left = new BTNodeInt(minHeap[2 * index]);
	if (2 * index + 1 < size)node->right = new BTNodeInt(minHeap[2 * index + 1]);
	treeFromMinHeapFormation(node->left, minHeap, size, 2 * index);
	treeFromMinHeapFormation(node->right, minHeap, size, 2 * index + 1);
}


