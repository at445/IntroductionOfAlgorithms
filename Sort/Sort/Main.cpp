// Sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "common.h"
#include "Main.h"
#include "InsertSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
const int MAX = 6400000;

int main()
{
    std::shared_ptr<std::vector<int>> p = dataGnerator(MAX);

    std::vector<int> copy(*p);
    QuickSortWrapper(copy);

    copy.clear();
    copy = *p;
    MergeSortWrapperSTLWithBuffVersion(copy);

    std::shared_ptr<int[]> arr(new int[p->size()]);

    std::copy(p->begin(), p->end(), arr.get());
    MergeSortWrapperNormalWithoutBuffVersion(arr);

    std::copy(p->begin(), p->end(), arr.get());
    MergeSortWrapperNormalWithBuffVersion(arr);
    return 0;
}
void QuickSortWrapper(std::vector<int>& p)
{
    PerformanceCounter counter;

    counter.start();
    QuickSort::quick_sort(p, 0, p.size()-1);
    counter.end();
    verification(p);
}

void InsertSortWrapper(std::vector<int>& p)
{
    PerformanceCounter counter;

    counter.start();
    InsertSort::insort_sort(p);
    counter.end();
    verification(p);
}
void MergeSortWrapperNormalWithoutBuffVersion(const std::shared_ptr<int[]>& p)
{
    PerformanceCounter counter;
    counter.start();
    MergeSort::merge_sort(p.get(), 0, MAX - 1);
    counter.end();
    verification(p.get(), MAX);
}
void MergeSortWrapperNormalWithBuffVersion(const std::shared_ptr<int[]>& p)
{
    PerformanceCounter counter;
    std::shared_ptr<int[]> q(new int[MAX]);
    counter.start();
    MergeSort::merge_sort(p.get(), q.get(), 0, MAX - 1);
    counter.end();
    verification(p.get(), MAX);
}

void MergeSortWrapperSTLWithBuffVersion(std::vector<int>& p)
{
    PerformanceCounter counter;
    std::shared_ptr<std::vector<int>> q = std::make_shared<std::vector<int>>(MAX);
    counter.start();
    MergeSort::merge_sort(p, *q, 0, MAX - 1);
    counter.end();
    verification(p);
}