#pragma once
namespace QuickSort {
	template <typename Ty_>
	void quick_sort(std::vector<Ty_>& array, int start, int end)
	{
		if (start >= end) return;
		int lIdx = start;
		int rIdx = end;
		Ty_ Tmp = array[lIdx];
		while (lIdx != rIdx) {
			while ((array[rIdx] >= Tmp) && (rIdx > lIdx)) {
				rIdx--;
			}
			array[lIdx] = array[rIdx];
			
			while ((array[lIdx] < Tmp) && (rIdx > lIdx)) {
				lIdx++;
			}
			array[rIdx] = array[lIdx];
		}
		array[lIdx] = Tmp;
		quick_sort(array, start, lIdx - 1);
		quick_sort(array, lIdx + 1, end);
	}
}