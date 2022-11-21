#pragma once
#include <vector>
#include <string>

class Utils {
public:
    static bool compare(std::vector<string>& v, int i, int j);
    static void InitVector(std::vector<int>& nums, int upper);
    static bool VerifySort(std::vector<int>& nums);
    static bool VerifySort(std::vector<string>& nums);
    static bool VerifySort(std::vector<int>& nums, int begin, int end);
    static bool VerifySort(std::vector<string>& nums, int begin, int end);
};
