#pragma once

#include <thread>
#include <vector>

class ThreadSortWrapper {
public:
    typedef void (*sortFunc)(std::vector<int>&, int, int);
    ThreadSortWrapper(sortFunc func, std::vector<int>& nums, int begin, int end)
        : t(func, std::ref(nums), begin, end), begin(begin), end(end) {}
    std::thread t;
    int begin;
    int end;
};