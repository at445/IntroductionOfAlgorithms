// Sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "common.h"
#include "insertsort.hpp"
int main()
{
    PerformanceCounter counter;
    const int MAX = 100;

    auto p = dataGnerator(MAX);
    counter.start();
    auto q = insort_sort(p.get(), MAX);
    counter.end();
    verification(q, MAX);

    return 0;
}
