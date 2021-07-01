#include <Windows.h>
#include <iostream>
#include <random>
#include <algorithm>
#include "Common.h"
PerformanceCounter::PerformanceCounter()
{
    QueryPerformanceFrequency(&freq);
}
void PerformanceCounter::start()
{
    QueryPerformanceCounter(&start_t);
}
void PerformanceCounter::end()
{
    QueryPerformanceCounter(&stop_t);

    exe_time = 1e3 * (stop_t.QuadPart - start_t.QuadPart) / freq.QuadPart;

    std::cout << "Your program executed time is:" << exe_time/1000.0 << "s" << std::endl;
}

using std::default_random_engine;
std::shared_ptr<std::vector<int>> dataGnerator(int len)
{
    auto p = std::make_shared<std::vector<int>>();
    int i = 0;
    for (; i < len; i++) {
        p->push_back(i);
    }
    std::random_shuffle(p->begin(), p->end());
    return p;
}

std::shared_ptr<std::vector<int>> dataGneratorRandom(int len)
{
    auto p = std::make_shared<std::vector<int>>();
    
    for (int i = 0; i < len; i++) {
        p->push_back( rand() % len );
    }
    return p;
}
void verification(const std::vector<int>& p)
{
#ifdef _DEBUG
    if (p.size() < 11) {
        for (int i = 0; i < p.size(); i++) {
            std::cout << "array[" << i << "] = " << p[i] << std::endl;
        }
        return;
    }

    for (int i = 0; i < 5; i++) {
        std::cout << "array[" << i << "] = " << p[i] << std::endl;
    }

    for (int i = p.size() - 6; i < p.size(); i++) {
        std::cout << "array[" << i << "] = " << p[i] << std::endl;
    }

#endif
}

void verification(const int* p, int max)
{
#ifdef _DEBUG
    if (max < 11) {
        for (int i = 0; i < max; i++) {
            std::cout << "array[" << i << "] = " << p[i] << std::endl;
        }
        return;
    }

    for (int i = 0; i < 5; i++) {
        std::cout << "array[" << i << "] = " << p[i] << std::endl;
}

    for (int i = max - 6; i < max; i++) {
        std::cout << "array[" << i << "] = " << p[i] << std::endl;
    }
#endif
}

bool binarySearch(const std::vector<int>& nums, int target, int& pos)
{
    int start = 0;
    int end = nums.size() - 1;
    int middle = 0;
    while (start != end) {
        middle = (start + end) / 2;
        if (nums[middle] == target)
        {
            pos = middle;
            return true;
        }
        else if (nums[middle] < target)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }
    if (nums[start] == target)
    {
        pos = start;
        return true;
    }

    return false;
}