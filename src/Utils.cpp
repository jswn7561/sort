#include <cstdlib>
#include <ctime>
#include "Utils.h"

// 字符串比较：如果v[i] > v[j], 返回true
static bool Utils::compare(std::vector<string>& v, int i, int j){
    int i_len = v[i].length(), j_len = v[j].length();
    // 判断正负号
    // 若v[i]为正数, v[j]为负数
    if(v[i][0] != '-' && v[j][0] == '-'){
        return true;
    }
    // 若v[i]为负数, v[j]为正数
    if(v[i][0] == '-' && v[j][0] != '-'){
        return false;
    }else{
        // 若v[i]、v[j]均为正数
        if(v[i][0] != '-' && v[j][0] != '-'){
            if((i_len > j_len) || (i_len == j_len && v[i] > v[j])){
                return true;
            }
        // 若v[i]、v[j]均为负数
        }else{
            if((i_len < j_len) || (i_len == j_len && v[i] < v[j])){
                return true;
            }
        }
        return false;
    }
}

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

bool Utils::VerifySort(std::vector<string>& nums, int begin, int end) {
    for (int i = begin + 1; i <= end; i++) {
        if (compare(nums, i - 1, i)) {
            return false;
        }
    }

    return true;
}
