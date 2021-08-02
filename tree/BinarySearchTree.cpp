#include "BinarySearchTree.h"

void BinarySearchTree::Insert(int k)
{
	if (root == nullptr) {
		root = std::make_shared<binary_tree_node<int>>(k);
		return;
	}
	auto p = root;
	while (true) {
		if (k > p->key) {
			if (p->rightChild == nullptr) {
				p->rightChild = std::make_shared<binary_tree_node<int>>(k, p);
				break;
			}
			p = p->rightChild;
			
		}
		else {
			if (p->leftChild == nullptr) {
				p->leftChild = std::make_shared<binary_tree_node<int>>(k, p);
				break;
			}
			p = p->leftChild;
		}
	}
}

std::shared_ptr<binary_tree_node<int>> BinarySearchTree::Search(int k)
{
	auto p = root;
	while (p != nullptr) {
		if (k == p->key) {
			return p;
		} else if (k > p->key) {
			p = p->rightChild;
		}
		else {
			p = p->leftChild;
		}
	}
	return nullptr;
}


bool BinarySearchTree::Delete(std::shared_ptr<binary_tree_node<int>> p)
{
	if ((p->leftChild == nullptr) && (p->rightChild == nullptr)) {
		auto q = p->parent;
		if (q->leftChild == p) q->leftChild = nullptr;
		else q->rightChild = nullptr;
	}
	else if (p->leftChild == nullptr) {
		if (p->parent->leftChild == p) p->parent->leftChild = p->rightChild;
		else p->parent->rightChild = p->rightChild;
		p->rightChild->parent = p->parent;
	}
	else if (p->rightChild == nullptr) {
		if (p->parent->leftChild == p) p->parent->leftChild = p->leftChild;
		else p->parent->rightChild = p->leftChild;
		p->leftChild->parent = p->parent;
	}
	else {
		auto q = GetSuccessor(p);
		q->leftChild = p->leftChild;
		if (p->parent->leftChild == p) {
			p->parent->leftChild = q;
		}
		else {
			p->parent->rightChild = q;

		}
		q->parent = p->parent;
	}

	return false;
}

std::shared_ptr<binary_tree_node<int>> BinarySearchTree::GetMaxmumItem(std::shared_ptr<binary_tree_node<int>> p)
{
	while (p->rightChild != nullptr) {
		p = p->rightChild;
	}
	return p;
}


std::shared_ptr<binary_tree_node<int>> BinarySearchTree::GetMinmumItem(std::shared_ptr<binary_tree_node<int>> p)
{
	while (p->leftChild != nullptr) {
		p = p->leftChild;
	}
	return p;
}

std::shared_ptr<binary_tree_node<int>> BinarySearchTree::GetSuccessor(std::shared_ptr<binary_tree_node<int>> p)
{
	if (p->rightChild != nullptr) { return GetMinmumItem(p->rightChild); }
	auto y = p->parent;
	while (y->rightChild == p)
	{
		p = y;
		y = y->parent;
	}
	return y;
}
