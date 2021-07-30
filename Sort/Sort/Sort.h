#pragma once

#include <vector>
#include <memory>
namespace Sort {
	void SortTest(void);
	void NthLocation(std::vector<int>& p);
	void InsertSortNormalWrapper(std::vector<int>& p);
	void HeapSortNormalWrapper(std::vector<int>& p);
	void InsertSortRecursionWrapper(std::vector<int>& p);
	void QuickSortWrapper(std::vector<int>& p);
	void QuickInsertSortWrapper(std::vector<int>& p);
	void MergeSortWrapperNormalWithoutBuffVersion(const std::shared_ptr<int[]>& p);
	void MergeSortWrapperNormalWithBuffVersion(const std::shared_ptr<int[]>& p);
	void MergeSortWrapperNormalWithBuffAndInsertVersion(const std::shared_ptr<int[]>& p);
	void MergeSortWrapperSTLWithBuffVersion(std::vector<int>& p);
}