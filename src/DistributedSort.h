#pragma once
#include <future>
#include <vector>
#include "ThreadSortWrapper.h"

class DistributedSort {
public:
    static void SyncSort(std::vector<int>& nums);
    static std::future<void> AsyncSort(std::vector<int>& nums);
    static void Run();

private:
    static const int sortFuncNum = 10;
    static ThreadSortWrapper::sortFunc sortFuncs[];
};