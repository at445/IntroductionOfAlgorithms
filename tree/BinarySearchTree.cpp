#include "BinarySearchTree.h"

void BinarySearchTree::Insert(int k)
{
	if (root == nullptr) {
		root = std::make_shared<binary_tree_node<int>>(k);
		maxHeight++;
		return;
	}
	auto p = root;
	int h = 1;
	while (true) {
		if (k > p->key) {
			if (p->rightChild == nullptr) {
				p->rightChild = std::make_shared<binary_tree_node<int>>(k, p);
				h++;
				break;
			}
			p = p->rightChild;
			
		}
		else {
			if (p->leftChild == nullptr) {
				p->leftChild = std::make_shared<binary_tree_node<int>>(k, p);
				h++;
				break;
			}
			p = p->leftChild;
		}
		h++;
	}
	maxHeight = (maxHeight > h) ? maxHeight : h;
}

std::shared_ptr<binary_tree_node<int>> BinarySearchTree::Search(int k)
{
	return std::shared_ptr<binary_tree_node<int>>();
}


bool BinarySearchTree::Delete(std::shared_ptr<binary_tree_node<int>>)
{
	return false;
}
