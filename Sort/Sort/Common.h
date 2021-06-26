#pragma once
#include <Windows.h>
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
std::shared_ptr<int[]> dataGnerator(int len);
std::shared_ptr<int[]> dataGneratorRandom(int len);
void verification(int* p, int maxSize);