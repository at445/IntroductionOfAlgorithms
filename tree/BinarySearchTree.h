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
class BinarySearchTree
{
public:
	BinarySearchTree()
		:root(nullptr),
		maxHeight(0){}
	template <typename Ty_, class Function>
	void inorder_yield(std::shared_ptr<binary_tree_node<Ty_>> cld, Function func){
		if (cld != nullptr) {
			inorder_yield(cld->leftChild, func);
			func(cld->key);
			inorder_yield(cld->rightChild, func);
		}
	}
	const std::shared_ptr<binary_tree_node<int>> getRoot() { return root; }
	const int getMaxHeight() { return maxHeight; }
	void Insert(int k);
	std::shared_ptr<binary_tree_node<int>> Search(int k);
	bool Delete(std::shared_ptr<binary_tree_node<int>>);
private:
	std::shared_ptr<binary_tree_node<int>> root;
	int maxHeight;
};

