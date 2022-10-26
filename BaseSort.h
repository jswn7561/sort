//
// Created by Edith Wang on 2022/10/20.
//

#ifndef SORT_BASESORT_H
#define SORT_BASESORT_H
#include <vector>
#include <list>

using namespace std;
enum sort_type {SELECT, BINARY_SELECT, MERGE, MERGE_ITERATE, QUICK, QUICK_THREEWAY, SHELL, SHELL_EXCHANGE, RADIX, RADIX_BUCKET};

class BaseSort {
public:
    void Run(vector<int> &v, enum sort_type);

    // 选择排序
public:
    void SelectSort(vector<int> &v);

    // 选择排序优化版
public:
    void BinarySelectSort(vector<int> &v);

    // 归并排序_递归法
public:
    void MergeSort(vector<int> &v);

private:
    void MergeSort(vector<int> &v, int begin, int end);

private:
    void Merge(vector<int> &v, int left, int mid, int right);

    // 归并排序_迭代法
public:
    void MergeIterateSort(vector<int> &v);

    // 快速排序
public:
    void QuickSort(vector<int> &v);

private:
    void QuickSort(vector<int> &v, int low, int high);

private:
    int Partition(vector<int> &v, int low, int high);

    // 三路快速排序
public:
    void QuickThreeWaySort(vector<int> &v);

private:
    void QuickThreeWaySort(vector<int> &v, int low, int high);

    // 希尔排序_交换法
public:
    void ShellExchangeSort(vector<int> &v);

    // 希尔排序_移位法
public:
    void ShellSort(vector<int> &v);

    // 基数排序_计数
public:
    void RadixSort(vector<int> &v);

private:
    int MaxBit(vector<int> &v, int n);

    // 基数排序_桶
public:
    void RadixBucketSort(vector<int> &v);

private:
    void Swap(int *p, int *q);

};


#endif //SORT_BASESORT_H
