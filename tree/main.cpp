// tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random> 
#include <set>
#include "Common.h"
#include "BinaryTree.hpp"
#include "BinarySearchTree.h"


void BSTFunction1()
{
    std::vector<int> p;
    for (int i = 0; i < 100000; i++) {
        p.push_back(i);
    }
    std::shuffle(p.begin(), p.end(), std::default_random_engine(4));
    PerformanceCounter counter;

    counter.start();
    BinarySearchTree bst;
    for (auto i : p) {
        bst.Insert(i);
    }
    counter.end();

    p.clear();

    std::default_random_engine e;
    std::uniform_real_distribution<float> u(1, 100000);
    std::set<int> q;
    for (int i = 0; i < 50000; i++) {
        q.insert(static_cast<int>(u(e)));
    }
    counter.start();
    for (auto i : q) {
        bst.Delete(bst.Search(i));
    }
    counter.end();
    std::cout << "total : " << q.size() << " will be deleted" << std::endl;
    for (auto i : q) {
        if (nullptr != bst.Search(i)) {
            std::cout << "error here" << std::endl;
            return;
        }
    }
    int count = 0;
    bst.inorder_yield(bst.getRoot(), [&count](auto i) { count++; });
    std::cout << "total size of bst is:" << count << std::endl;
    std::cout << std::endl;
}
std::shared_ptr<binary_tree_node<int>> ConstructBST(void)
{
    auto tree = std::make_shared<binary_tree_node<int>>(5);
    auto p = Insert(tree, 2, DIRECTION::LEFT);
    auto q = Insert(tree, 10, DIRECTION::RIGHT);
    Insert(p, 1, DIRECTION::LEFT);
    Insert(Insert(p, 3, DIRECTION::RIGHT), 4, DIRECTION::RIGHT);
    q = Insert(q, 8, DIRECTION::LEFT);
    Insert(Insert(q, 7, DIRECTION::LEFT), 6, DIRECTION::LEFT);
    Insert(q, 9, DIRECTION::RIGHT);
    return tree;
}
int main()
{

    //BinarySearchTree bst(ConstructBST());
    //bst.inorder_yield(bst.getRoot(), [](auto i) { std::cout << i << "  "; });

    BSTFunction1();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
