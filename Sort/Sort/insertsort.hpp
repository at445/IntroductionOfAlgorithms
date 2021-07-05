#pragma once
#include <vector>
namespace InsertSort {
	const int PARTICAL = 128;
	template <typename T_>
	void insert_sort(std::vector<T_>& p)
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
	template <typename T_>
	void insert_sort_recursion(std::vector<T_>& p, int i)
	{
		if (i == p.size()) return;
		T_ key = p[i];
		int idx = i - 1;
		while (p[idx] > key) {
			p[idx + 1] = p[idx];
			if (--idx < 0) break;
		}
		p[idx + 1] = key;
		insert_sort_recursion(p, i + 1);
	}

	template <typename T_>
	void insert_sort(T_* p, int s, int e)
	{
		T_ key;
		int size = e - s + 1;
		int Idx = 0;
		for (int i = s + 1; i < size + s; ++i) {
			Idx = i;
			key = p[Idx--];
			while (key < p[Idx]) {
				p[Idx + 1] = p[Idx];
				if (--Idx < s) break;
			}
			p[Idx + 1] = key;
		}
	}
}