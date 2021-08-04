#pragma once
#include <memory>
#include "BinaryTreeNote.h"
class BinarySearchTree
{
public:
	BinarySearchTree()
		:root(nullptr){}
	BinarySearchTree(std::shared_ptr<binary_tree_node<int>> p)
		:root(p) {}
	template <typename Ty_, class Function>
	void inorder_yield(std::shared_ptr<binary_tree_node<Ty_>> cld, Function func){
		if (cld != nullptr) {
			inorder_yield(cld->leftChild, func);
			func(cld->key);
			inorder_yield(cld->rightChild, func);
		}
	}
	const std::shared_ptr<binary_tree_node<int>> getRoot() { return root; }
	void Insert(int k);
	std::shared_ptr<binary_tree_node<int>> Search(int k);
	bool Delete(std::shared_ptr<binary_tree_node<int>>);
	std::shared_ptr<binary_tree_node<int>> GetMaxmumItem(std::shared_ptr<binary_tree_node<int>> p);
	std::shared_ptr<binary_tree_node<int>> GetMinmumItem(std::shared_ptr<binary_tree_node<int>> p);
	std::shared_ptr<binary_tree_node<int>> GetSuccessor(std::shared_ptr<binary_tree_node<int>> p);
	std::shared_ptr<binary_tree_node<int>> GetPredecessor(std::shared_ptr<binary_tree_node<int>> p);
private:
	void translate(std::shared_ptr<binary_tree_node<int>> op, std::shared_ptr<binary_tree_node<int>> np);
	std::shared_ptr<binary_tree_node<int>> root;
};

