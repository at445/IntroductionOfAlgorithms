#pragma once
#include "InsertSort.hpp"
namespace QuickSort {
	template <typename Ty_>
	void quick_sort(std::vector<Ty_>& array, int start, int end)
	{
		//#######implement one
		/*if (start >= end) return;
		int lIdx = start;
		int rIdx = end;
		int pivot = rand() % (end - start + 1) + start;
		std::swap(array[lIdx], array[pivot]);
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
		quick_sort(array, lIdx + 1, end);*/

		//#######implement two
		if (start >= end) return;
		int p = start;
		int q = p + 1;
		int pivot = rand() % (end - start + 1) + start;

		std::swap(array[p], array[pivot]);

		Ty_ temp = array[p];
		while (q <= end) {
			if (array[q] < temp) {
				array[p] = array[q];
				array[q] = array[p + 1];
				p++;
			}
			q++;
		}
		array[p] = temp;
		quick_sort(array, start, p - 1);
		quick_sort(array, p + 1, end);

		//#######implement three
		/*if (start >= end) return;
		int p = start;
		int q = p + 1;

		Ty_ temp = array[p];
		while (q <= end) {
			if (array[q] < temp) {
				std::swap(array[p + 1], array[q]);
				p++;
			}
			q++;
		}
		std::swap(array[p], array[start]);
		quick_sort(array, start, p - 1);
		quick_sort(array, p + 1, end);*/

	}

	template <typename Ty_>
	void quick_sort_and_insert (std::vector<Ty_>& array, int start, int end)
	{
		if ((end - start) < InsertSort::PARTICAL) {
			InsertSort::insert_sort(&array[0], start, end);
			return;
		}

		int lIdx = start;
		int rIdx = end;
		int pivot = rand() % (end - start + 1) + start;
		std::swap(array[lIdx], array[pivot]);
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
	template <typename Ty_>
	Ty_ nth_location(std::vector<Ty_>& array, int n, int start, int end)
	{
		int lIdx = start;
		int rIdx = end;
		int pivot = rand() % (end - start + 1) + start;
		std::swap(array[lIdx], array[pivot]);
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
		if (lIdx == n) return Tmp;
		else if (lIdx < n) return nth_location(array, n, lIdx + 1, end);
		else return nth_location(array, n, start, lIdx - 1);
	}
}