#pragma once
#include <vector>
#include <memory>
void InsertSortWrapper(std::vector<int>& p);
void QuickSortWrapper(std::vector<int>& p);
void MergeSortWrapperNormalWithoutBuffVersion(const std::shared_ptr<int[]>& p);
void MergeSortWrapperNormalWithBuffVersion(const std::shared_ptr<int[]>& p);
void MergeSortWrapperSTLWithBuffVersion(std::vector<int>& p);