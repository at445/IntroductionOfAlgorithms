#pragma once
#include <string.h>
#include <vector>
#include <algorithm>
namespace MergeSort {
	template<typename Ty_>
	void merge_sort(std::vector<Ty_>& pArray, std::vector<Ty_>& Buff, int start, int end)
	{
		if (end == start) return;
		int middle = (end + start) / 2;
		merge_sort(pArray, Buff, start, middle);
		merge_sort(pArray, Buff, middle + 1, end);

		int lIdx = start;
		int rIdx = middle + 1;
		int size = end - start + 1;
		std::copy(pArray.begin() + start, 
			pArray.begin() + static_cast<INT64>(start) + size, 
			Buff.begin() + start);

		int i = start;
		while ((rIdx <= end) && (lIdx <= middle)) {
			if ((Buff[lIdx] > Buff[rIdx]) && (rIdx <= end)) {
				pArray[i++] = Buff[rIdx++];
				continue;
			}
			if ((Buff[lIdx] <= Buff[rIdx]) && (lIdx <= middle)) {
				pArray[i++] = Buff[lIdx++];
				continue;
			}
		}
		while (lIdx <= middle) {
			pArray[i++] = Buff[lIdx++];
		}
		while (rIdx <= end) {
			pArray[i++] = Buff[rIdx++];
		}
	}

	template<typename Ty_>
	void merge_sort(Ty_* pArray, Ty_* Buff, int start, int end)
	{
		if (end == start) return;
		int middle = (end + start) / 2;
		merge_sort(pArray, Buff, start, middle);
		merge_sort(pArray, Buff, middle+1, end);

		int lIdx = start;
		int rIdx = middle + 1;
		int size = end - start + 1;
		memcpy(Buff + start, pArray + start, size * sizeof(int));
		int i = start;
		while ((rIdx <= end) && (lIdx <= middle)) {
			if ((Buff[lIdx] > Buff[rIdx]) && (rIdx <= end)) {
				pArray[i++] = Buff[rIdx++];
				continue;
			}
			if ((Buff[lIdx] <= Buff[rIdx]) && (lIdx <= middle)) {
				pArray[i++] = Buff[lIdx++];
				continue;
			}
		}
		while (lIdx <= middle) {
			pArray[i++] = Buff[lIdx++];
		}
		while (rIdx <= end) {
			pArray[i++] = Buff[rIdx++];
		}
	}

	template<typename Ty_>
	void merge_sort(Ty_* pArray, int start, int end)
	{
		if (end == start) return;
		int middle = (end + start) / 2;
		merge_sort(pArray,  start, middle);
		merge_sort(pArray,  middle + 1, end);

		int lIdx = 0;
		int rIdx = (end - start) / 2 + 1;
		int size = end - start + 1;
		middle = (end - start) / 2;
		int* Buff = new Ty_[size * sizeof(int)];
		memcpy(Buff, pArray + start, size * sizeof(int));
		int i = start;
		while ((rIdx < size) && (lIdx <= middle)) {
			if ((Buff[lIdx] > Buff[rIdx]) && (rIdx <= size)) {
				pArray[i++] = Buff[rIdx++];
				continue;
			}
			if ((Buff[lIdx] <= Buff[rIdx]) && (lIdx <= middle)) {
				pArray[i++] = Buff[lIdx++];
				continue;
			}
		}
		while (lIdx <= middle) {
			pArray[i++] = Buff[lIdx++];
		}
		while (rIdx < size) {
			pArray[i++] = Buff[rIdx++];
		}
		delete[] Buff;
	}
}
