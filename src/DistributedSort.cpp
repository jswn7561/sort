#include <vector>
#include <thread>
#include <future>
#include "DistributedSort.h"
#include "Utils.h"
#include "BaseSort.h"

ThreadSortWrapper::sortFunc DistributedSort::sortFuncs[sortFuncNum] = {
    BaseSort::SelectSort,        BaseSort::BinarySelectSort, BaseSort::MergeSort,         BaseSort::MergeIterateSort, BaseSort::QuickSort,
    BaseSort::QuickThreeWaySort, BaseSort::ShellSort,        BaseSort::ShellExchangeSort, BaseSort::RadixSort,        BaseSort::RadixBucketSort
};

void DistributedSort::SyncSort(std::vector<int>& nums) {
    std::vector<ThreadSortWrapper> wrappers;
    std::vector<int> indices;
    const int n = nums.size();
    const auto interval = n % 10 ? n / 10 + 1 : n / 10;

    for (int i = 0, j = 0; i < n; i += interval, ++j) {
        wrappers.emplace_back(sortFuncs[j], std::ref(nums), i, min(i + interval - 1, n - 1));
        indices.push_back(i);
    }

    for (auto& item : wrappers) {
        item.t.join();
    }

    std::vector<int> temp(n);
    const int groupNum = wrappers.size();
    auto tempIndex = 0;
    auto flag = true;

    while (flag) {
        flag = false;
        int minValue = INT32_MAX;
        int minGroup = -1;
        for (int i = 0; i < groupNum; ++i) {
            const auto index = indices[i];
            if (index <= wrappers[i].end) {
                flag = true;
                if (nums[index] < minValue) {
                    minValue = nums[index];
                    minGroup = i;
                }
            }
        }

        if (minGroup >= 0) {
            temp[tempIndex++] = minValue;
            indices[minGroup]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        nums[i] = temp[i];
    }
}

std::future<void> DistributedSort::AsyncSort(std::vector<int>& nums) {
    return std::async(std::launch::async, &SyncSort, ref(nums));
}

void DistributedSort::Run() {
    printf("\nDistributedSort:\n");
    vector<int> nums(2000000);
    Utils::InitVector(nums, 1000000);
    std::clock_t startTime = clock();
    SyncSort(nums);
    std::clock_t endTime = clock();
    printf("The result of sorting %lld numbers using the synchronous sort method is %s. Time spent: %fs.\n", nums.size(),
           Utils::VerifySort(nums) ? "true" : "false", static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC);

    Utils::InitVector(nums, 1000000);
    startTime = clock();
    auto f = AsyncSort(nums);
    f.wait();
    endTime = clock();
    printf("The result of sorting %lld numbers using the asynchronous sort method is %s. Time spent: %fs\n", nums.size(),
           Utils::VerifySort(nums) ? "true" : "false", static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC);
}