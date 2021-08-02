#pragma once
#include <Windows.h>
#include <vector>
class PerformanceCounter
{
private:
    LARGE_INTEGER freq;

    LARGE_INTEGER start_t, stop_t;

    double exe_time;
public:
    PerformanceCounter();
    void start();
    void end();
};
std::shared_ptr<std::vector<int>> dataGnerator(int len);
std::shared_ptr<std::vector<int>> dataGneratorRandom(int len);
void verification(const std::vector<int>& p);
void verification(const int* p, int max);
bool binarySearch(const std::vector<int>& nums, int target, int& pos);