#pragma once
#include <list>
#include <vector>

using namespace std;

class BaseSort {
public:
    static void Run();
    // 选择排序
    static void SelectSort(std::vector<int>& v);
    static void SelectSort(std::vector<int>& v, int begin, int end);
    // 二元选择排序
    static void BinarySelectSort(std::vector<int>& v);
    static void BinarySelectSort(std::vector<int>& v, int begin, int end);
    // 归并排序_递归法
    static void MergeSort(std::vector<int>& v);
    static void MergeSort(std::vector<int>& v, int begin, int end);
    // 归并排序_迭代法
    static void MergeIterateSort(std::vector<int>& v);
    static void MergeIterateSort(std::vector<int>& v, int begin, int end);
    // 快速排序
    static void QuickSort(std::vector<int> &v);
    static void QuickSort(std::vector<int> &v, int low, int high);
    // 三路快速排序
    static void QuickThreeWaySort(std::vector<int> &v);
    static void QuickThreeWaySort(std::vector<int> &v, int low, int high);
    // 希尔排序_移位法
    static void ShellSort(std::vector<int>& v);
    static void ShellSort(std::vector<int>& v, int begin, int end);
    // 希尔排序_交换法
    static void ShellExchangeSort(std::vector<int>& v);
    static void ShellExchangeSort(std::vector<int>& v, int begin, int end);
    // 基数排序_计数
    static void RadixSort(std::vector<int>& v);
    static void RadixSort(std::vector<int>& v, int begin, int end);
    // 基数排序_桶
    static void RadixBucketSort(std::vector<int>& v);
    static void RadixBucketSort(std::vector<int>& v, int begin, int end);


private:
    static void Merge(std::vector<int> &v, int left, int mid, int right);
    static int Partition(std::vector<int> &v, int low, int high);
    static int MaxBit(std::vector<int> &v, int begin, int end);

};
