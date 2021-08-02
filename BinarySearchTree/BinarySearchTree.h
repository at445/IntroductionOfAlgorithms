#pragma once
class binary_tree_note {
public:
	binary_tree_note(int k)
		:key(k),
		left(nullptr),
		right(nullptr)
	{
	}
	int key;
	binary_tree_note* left;
	binary_tree_note* right;
};
class BinarySearchTree
{
public:
	BinarySearchTree(int k) 
	:_root(new binary_tree_note(k)){}

	BinarySearchTree()
	:_root(nullptr){}

	template<class Function>
	void preorder_yield(binary_tree_note* p, Function func)
	{
		if (p != nullptr) {
			fn(p);
			preorder_yield(p->left);
			preorder_yield(p->right);
		}
	}

	template<class Function>
	void inorder_yield(binary_tree_note* p, Function func)
	{
		if (p != nullptr) {
			inorder_yield(p->left);
			fn(p);
			inorder_yield(p->right);
		}
	}
	binary_tree_note* root(){return _root;}

	void insert(int k);
private:
	binary_tree_note* _root;
};

