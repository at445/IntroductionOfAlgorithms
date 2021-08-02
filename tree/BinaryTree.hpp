#pragma once
#include <iostream>
#include "BinaryTreeNote.h"
enum class DIRECTION
{
	LEFT = 0,
	RIGHT
};
std::shared_ptr<binary_tree_node<int>> Insert(std::shared_ptr<binary_tree_node<int>> p, int k, DIRECTION dir)
{
	if (dir == DIRECTION::LEFT) {
		p->leftChild = std::make_shared<binary_tree_node<int>>(k,p);
		return p->leftChild;
	}
	else {
		p->rightChild = std::make_shared<binary_tree_node<int>>(k,p);
		return p->rightChild;
	}
}

void InoderPrint(std::shared_ptr<binary_tree_node<int>> p)
{
	if (p != nullptr) {
		InoderPrint(p->leftChild);
		std::cout << p->key << " ";
		InoderPrint(p->rightChild);
	}
}
