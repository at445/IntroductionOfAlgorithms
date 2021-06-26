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
    p->push_back(12);
    for (; i < len-2; i++) {
        p->push_back(i);
    }
    p->push_back(i);
    std::random_shuffle(p->begin(), p->end());
    return p;
}
void verification(const std::vector<int>& p)
{
    static int i = 1;
    default_random_engine e;

    e.seed(i++);
    int temp = 0;
    for (size_t i = 0; i < 5; ++i) {
        temp = e() % p.size();
        std::cout << "array[" << temp << "] = " << p[temp] << std::endl;
    }

}

void verification(const int* p, int max)
{
    static int i = 1;
    default_random_engine e;

    e.seed(i++);
    int temp = 0;
    for (size_t i = 0; i < 5; ++i) {
        temp = e() % max;
        std::cout << "array[" << temp << "] = " << p[temp] << std::endl;
    }

}