#include <iostream>
#include "BigValueSort.h"
#include "Utils.h"

// 选择排序
void BigValueSort::SelectSort(std::vector<string>& v){
    int n = v.size();
    if(n == 0) return;
    SelectSort(v, n);
}

void BigValueSort::SelectSort(std::vector<string>& v, int DataNum){
    for(int i = 0; i < DataNum - 1; i++){
        int min = i;
        for(int j = i + 1; j < DataNum; j++){
            if(Utils::compare(v, min, j)){
                min = j;
            }
        }
        if(min != i){
            swap(v[i], v[min]);
        }
    }
}

// 归并排序
void BigValueSort::MergeSort(std::vector<string>& v){
    int n = v.size();
    if(n == 0) return;
    MergeSort(v, 0, n - 1);
}

void BigValueSort::MergeSort(std::vector<string>& v, int begin, int end){
    if(begin < end){
        int mid = (begin + end) / 2;
        MergeSort(v, begin, mid);
        MergeSort(v, mid + 1, end);
        Merge(v, begin, mid, end);
    }
}

void BigValueSort::Merge(std::vector<string>& v, const int begin, const int mid, const int end){
    vector<string> tmp(end - begin + 1);
    int i = begin, j = mid + 1, k = begin;
    while(i <= mid && j <= end){
        if(!Utils::compare(v, i, j)){
            tmp[k++] = v[i++];
        }
        else{
            tmp[k++] = v[j++];
        }
    }
    while(i <= mid){
        tmp[k++] = v[i++];
    }
    while(j <= end){
        tmp[k++] = v[j++];
    }
    for(k = begin; k <= end; k++){
        v[k] = tmp[k];
    }
}

// 快速排序
void BigValueSort::QuickSort(std::vector<string>& v){
    int n = v.size();
    if(n == 0) return;
    QuickSort(v, 0, n - 1);
}

void BigValueSort::QuickSort(std::vector<string>& v, int begin, int end){
    if(begin < end){
        int pivot = Partition(v, begin, end);
        QuickSort(v, begin, pivot - 1);
        QuickSort(v, pivot + 1, end);
    }
}

int BigValueSort::Partition(std::vector<string>& v, int begin, int end){
    // 末端元素作为主元
    int i = begin - 1, pivot = end;
    for(int j = begin; j < end; j++){
        // s[i]及之前元素都小于s[p]
        if(!Utils::compare(v, j, pivot)){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[pivot]);
    return i + 1;
}

// 希尔排序
void BigValueSort::ShellSort(std::vector<string>& v){
    int n = v.size();
    if(n == 0) return;
    ShellSort(v, n);

}

void BigValueSort::ShellSort(std::vector<string>& v, int DataNum){
    // 希尔排序：每一轮按照间隔d分组进行插入排序
    for(int d = DataNum / 2; d > 0; d /= 2){
        // 依次处理d个分组
        for(int i = 0; i < d; i++){
            // 在每个分组内进行插入排序
            for(int j  = i + d; j < DataNum; j += d){
                int k = j;
                // 如果后面元素比前面元素大，则交换
                while(k > i && Utils::compare(v, k - d, k)){
                    swap(v[k - d], v[k]);
                    k -= d;
                }
            }
        }
    }
}

// 基数排序
void BigValueSort::RadixSort(std::vector<string>& v){
    int n = v.size();
    if(n == 0) return;
    for(int i = 0; i < n; i++){
        // 对每一位数字分别进行一次基数排序，按绝对值升序排列
        RadixSort(v, n, i);
    }
    // 
    vector<string> tmp(n);
    int cnt = 0;
    // 倒序遍历，从小到大取出负数
    for(int i = n - 1; i >= 0; i--){
        if(v[i][0] == '-'){
            tmp[cnt++] = v[i];
        }
    }
    // 正序遍历，从小到大取出非负数
        for(int i = 0; i < n; i++){
        if(v[i][0] != '-'){
            tmp[cnt++] = v[i];
        }
    }
    for(int i = 0; i < n; i++){
        v[i] = tmp[i];
    }
}

void BigValueSort::RadixSort(std::vector<string>& v, int DataNum, int DigitIdx){
    // 为0-9每一位数字分别创建一个桶
    list<string> bucket[10];

    for(int i = 0; i < DataNum; i++){
        // 从个位（string末尾算起），取string的第DigitIdx位数字
        int j = (int)v[i].length() - DigitIdx;
        int idx = 0;
        // 如果该位不存在，则记为0
        if(j > 0){
            // 如果是符号位，则记为0
            if(v[i][j - 1] == '-'){
                idx = 0;
            }
            // 如果是数字位，则记录对应数值
            else{
                idx = v[i][j - 1] - '0';
            }
        }
        bucket[idx].push_back(v[i]);
    }
    // 将桶内元素按数字依次放回原数组中
    int i = 0;
    for(int j = 0; j < 10; j++){
        while(!bucket[j].empty()){
            v[i++] = bucket[j].front();
            bucket[j].pop_front();
        }
    }
}

void BigValueSort::Run(){
    int DataNum = 20;
    int DigitNum = 100;
    string str[DataNum]; 
    // 生成DataNum个[-10^100, 10^100]范围内随机数
    for(int i = 0; i < DataNum; i++){
        // 生成符号位
        if(rand() % 2){
            str[i] = '-';
        }
        int m = rand() % DigitNum + 1;
        // 最高位非0
        string a = to_string(rand() % 9 + 1); 
        str[i] += a;
        for(int j = 2; j <= m ; j++){
            a = to_string(rand() % 10);
            str[i] += a;
        }
    }
    vector<string> v0(str, str + DataNum);
    vector<string> v1 = v0;
    vector<string> v2 = v0;
    vector<string> v3 = v0;
    vector<string> v4 = v0;
    vector<string> v5 = v0;
    printf("The time consuming of sorting \033[0m\033[1;31m%d\033[0m numbers:\n", DataNum);
    clock_t startTime, endTime;
    startTime = clock();
    // 选择排序
    BigValueSort::SelectSort(v1);
    endTime = clock();
    printf("Select sort: \033[0m\033[1;33m%fs\033[0m, validation results: \033[0m\033[1;32m%s\033[0m\n", (double) (endTime - startTime) / CLOCKS_PER_SEC, Utils::VerifySort(v1) ? "True" : "False");
    // 归并排序
    BigValueSort::MergeSort(v2);
    endTime = clock();
    printf("Merge sort: \033[0m\033[1;33m%fs\033[0m, validation results: \033[0m\033[1;32m%s\033[0m\n", (double) (endTime - startTime) / CLOCKS_PER_SEC, Utils::VerifySort(v1) ? "True" : "False");
    // 快速排序
    BigValueSort::QuickSort(v3);
    endTime = clock();
    printf("Quick sort: \033[0m\033[1;33m%fs\033[0m, validation results: \033[0m\033[1;32m%s\033[0m\n", (double) (endTime - startTime) / CLOCKS_PER_SEC, Utils::VerifySort(v1) ? "True" : "False");
    // 希尔排序
    BigValueSort::ShellSort(v4);
    endTime = clock();
    printf("Shell sort: \033[0m\033[1;33m%fs\033[0m, validation results: \033[0m\033[1;32m%s\033[0m\n", (double) (endTime - startTime) / CLOCKS_PER_SEC, Utils::VerifySort(v1) ? "True" : "False"); 
    // 基数排序
    BigValueSort::RadixSort(v5);
    endTime = clock();
    printf("Radix sort: \033[0m\033[1;33m%fs\033[0m, validation results: \033[0m\033[1;32m%s\033[0m\n", (double) (endTime - startTime) / CLOCKS_PER_SEC, Utils::VerifySort(v1) ? "True" : "False");  
}
