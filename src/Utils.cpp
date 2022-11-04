#include <cstdlib>
#include <ctime>
#include "Utils.h"

void Utils::InitVector(std::vector<int>& nums, int upper) {
    srand(time(nullptr));

    for (int& num : nums) {
        num = rand() % upper + 1;
    }
}

bool Utils::VerifySort(std::vector<int>& nums) {
    return VerifySort(nums, 0, nums.size() - 1);
}

bool Utils::VerifySort(std::vector<int>& nums, int begin, int end) {
    for (int i = begin + 1; i <= end; i++) {
        if (nums[i] < nums[i - 1]) {
            return false;
        }
    }

    return true;
}
