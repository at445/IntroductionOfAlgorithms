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
	if (p == nullptr) return false;
	if (p->leftChild == nullptr) {
		translate(p, p->rightChild);
	}
	else if (p->rightChild == nullptr) {
		translate(p, p->leftChild);
	}
	else {
		auto q = GetSuccessor(p);
		translate(q, q->rightChild);
		p->key = q->key;
	}

	return true;
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
	while ((y!= nullptr) && (y->rightChild == p))
	{
		p = y;
		y = y->parent;
	}
	return y;
}

std::shared_ptr<binary_tree_node<int>> BinarySearchTree::GetPredecessor(std::shared_ptr<binary_tree_node<int>> p)
{
	if (p->leftChild != nullptr) return GetMaxmumItem(p->leftChild);
	auto y = p->parent;
	while ((y != nullptr) && (y->leftChild == p))
	{
		p = y;
		y = y->parent;
	}
	return y;
}


void BinarySearchTree::translate(std::shared_ptr<binary_tree_node<int>> op, std::shared_ptr<binary_tree_node<int>> np)
{
	if (op->parent == NULL) root = np;
	else {
		if (op->parent->leftChild == op) op->parent->leftChild = np;
		else op->parent->rightChild = np;
	}
	if (np != nullptr) {
		np->parent = op->parent;
	}
}
