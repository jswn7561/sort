//
// Created by Edith Wang on 2022/10/20.
//

#pragma once
#include <vector>
#include <list>

using namespace std;

class BaseSort {
public:
    static void Run();
    // 选择排序
    static void SelectSort(vector<int>& v);
    static void SelectSort(vector<int>& v, int begin, int end);
    // 二元选择排序
    static void BinarySelectSort(vector<int>& v);
    static void BinarySelectSort(vector<int>& v, int begin, int end);
    // 归并排序_递归法
    static void MergeSort(vector<int>& v);
    static void MergeSort(vector<int>& v, int begin, int end);
    // 归并排序_迭代法
    static void MergeIterateSort(vector<int>& v);
    static void MergeIterateSort(vector<int>& v, int begin, int end);
    // 快速排序
    static void QuickSort(vector<int> &v);
    static void QuickSort(vector<int> &v, int low, int high);
    // 三路快速排序
    static void QuickThreeWaySort(vector<int> &v);
    static void QuickThreeWaySort(vector<int> &v, int low, int high);
    // 希尔排序_移位法
    static void ShellSort(vector<int>& v);
    static void ShellSort(vector<int>& v, int begin, int end);
    // 希尔排序_交换法
    static void ShellExchangeSort(vector<int>& v);
    static void ShellExchangeSort(vector<int>& v, int begin, int end);
    // 基数排序_计数
    static void RadixSort(vector<int>& v);
    static void RadixSort(vector<int>& v, int begin, int end);
    // 基数排序_桶
    static void RadixBucketSort(vector<int>& v);
    static void RadixBucketSort(vector<int>& v, int begin, int end);


private:
    static void Merge(vector<int> &v, int left, int mid, int right);
    static int Partition(vector<int> &v, int low, int high);
    static int MaxBit(vector<int> &v, int begin, int end);

};
