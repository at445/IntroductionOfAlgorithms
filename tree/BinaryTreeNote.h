#pragma once
#include <memory>
template<typename Ty_>
class binary_tree_node {
public:
	binary_tree_node(Ty_ k, std::shared_ptr<binary_tree_node> p = nullptr)
		:leftChild(nullptr),
		rightChild(nullptr),
		parent(p),
		key(k) {}
	Ty_ key;
	std::shared_ptr<binary_tree_node> parent;
	std::shared_ptr<binary_tree_node> leftChild;
	std::shared_ptr<binary_tree_node> rightChild;
};