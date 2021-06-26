#pragma once
#include <vector>
namespace InsertSort {
	template <typename T_>
	void insort_sort(std::vector<T_>& p)
	{
		T_ key;
		int Idx = 0;
		for (int i = 1; i < p.size(); ++i) {
			Idx = i;
			key = p[Idx--];
			while (key < p[Idx]) {
				p[static_cast<INT64>(Idx) + 1] = p[Idx];
				if (--Idx < 0) break;
			}
			p[static_cast<INT64>(Idx) + 1] = key;
		}
	}
}