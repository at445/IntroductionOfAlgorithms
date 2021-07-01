// Sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "common.h"
#include "Main.h"
#include "InsertSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
const int MAX = 10000000;

int main()
{
    std::shared_ptr<std::vector<int>> p = dataGnerator(MAX);

    //std::vector<int> copy(*p);
    //InsertSortNormalWrapper(copy);

    //copy.clear();
    //copy = *p;
    //InsertSortRecursionWrapper(copy);

    //copy.clear();
    //copy = *p;
    //QuickSortWrapper(copy);

    //copy.clear();
    //copy = *p;
    //MergeSortWrapperSTLWithBuffVersion(copy);

    std::shared_ptr<int[]> arr(new int[p->size()]);

    std::copy(p->begin(), p->end(), arr.get());
    MergeSortWrapperNormalWithBuffAndInsertVersion(arr);

    std::copy(p->begin(), p->end(), arr.get());
    MergeSortWrapperNormalWithBuffVersion(arr);
    return 0;
}

void InsertSortNormalWrapper(std::vector<int>& p)
{
    PerformanceCounter counter;

    std::cout << "===========================  Insert sort normal version:" << std::endl;
    counter.start();
    InsertSort::insert_sort(p);
    counter.end();
    verification(p);
}
void InsertSortRecursionWrapper(std::vector<int>& p)
{
    PerformanceCounter counter;

    std::cout << "===========================  Insert sort recursion version:" << std::endl;
    counter.start();
    InsertSort::insert_sort_recursion(p, 1);
    counter.end();
    verification(p);
}
void MergeSortWrapperNormalWithoutBuffVersion(const std::shared_ptr<int[]>& p)
{
    PerformanceCounter counter;

    std::cout << "===========================  Merge sort without buffer version:" << std::endl;
    counter.start();
    MergeSort::merge_sort(p.get(), 0, MAX - 1);
    counter.end();
    verification(p.get(), MAX);
}
void MergeSortWrapperNormalWithBuffVersion(const std::shared_ptr<int[]>& p)
{
    PerformanceCounter counter;

    std::cout << "===========================  Merge sort with buffer version:" << std::endl;
    counter.start();
    std::shared_ptr<int[]> q(new int[MAX]);
    MergeSort::merge_sort(p.get(), q.get(), 0, MAX - 1);
    counter.end();
    verification(p.get(), MAX);
}

void MergeSortWrapperNormalWithBuffAndInsertVersion(const std::shared_ptr<int[]>& p)
{
    PerformanceCounter counter;

    std::cout << "===========================  Merge sort with buffer and insert version:" << std::endl;
    counter.start();
    std::shared_ptr<int[]> q(new int[MAX]);
    MergeSort::merge_sort_insert(p.get(), q.get(), 0, MAX - 1);
    counter.end();
    verification(p.get(), MAX);
}

void MergeSortWrapperSTLWithBuffVersion(std::vector<int>& p)
{
    PerformanceCounter counter;

    std::cout << "===========================  Merge sort with buffer (STL) version:" << std::endl;
    counter.start();
    std::shared_ptr<std::vector<int>> q = std::make_shared<std::vector<int>>(MAX);
    MergeSort::merge_sort(p, *q, 0, MAX - 1);
    counter.end();
    verification(p);
}

void QuickSortWrapper(std::vector<int>& p)
{
    std::cout << "===========================  Quick sort normal version:" << std::endl;
    PerformanceCounter counter;

    counter.start();
    QuickSort::quick_sort(p, 0, p.size() - 1);
    counter.end();
    verification(p);
}