#include "BinarySearchTree.h"

void BinarySearchTree::insert(int k)
{
	if (_root == nullptr) {
		_root = new binary_tree_note(k);
		return;
	}
	auto p = _root;
	while (p != nullptr) {
		if (p->key < k) {
			p = p->right;
		}
		else {
			p = p->left;
		}
	}
	p = new binary_tree_note(k);
}