#pragma once
#include <vector>
#include <string>

class Utils {
public:
    static bool Compare(std::vector<std::string>& v, int i, int j);
    static void InitVector(std::vector<int>& nums, int upper);
    static bool VerifySort(std::vector<int>& nums);
    static bool VerifySort(std::vector<std::string>& nums);
    static bool VerifySort(std::vector<int>& nums, int begin, int end);
    static bool VerifySort(std::vector<std::string>& nums, int begin, int end);
};
