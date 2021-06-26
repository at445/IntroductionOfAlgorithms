#pragma once
template <typename T_>
T_* insort_sort(T_* p, int size)
{
	T_ key;
	long Idx = 0;
	for (int i = 0; i < size; ++i) {
		Idx = i;
		key = p[Idx--];
		while (key < p[Idx]) {
			p[Idx + 1] = p[Idx];
			Idx--;
		}
		p[Idx + 1] = key;
	}
	return p;
}