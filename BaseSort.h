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
    void static SelectSort(vector<int> &v);
    // 二元选择排序
    void static BinarySelectSort(vector<int> &v);
    // 归并排序_递归法
    void static MergeSort(vector<int> &v);
    // 归并排序_迭代法
    void static MergeIterateSort(vector<int> &v);
    // 快速排序
    void static QuickSort(vector<int> &v);
    // 三路快速排序
    void static QuickThreeWaySort(vector<int> &v);
    // 希尔排序_移位法
    void static ShellSort(vector<int> &v);
    // 希尔排序_交换法
    void static ShellExchangeSort(vector<int> &v);
    // 基数排序_计数
    void static RadixSort(vector<int> &v);
    // 基数排序_桶
    void static RadixBucketSort(vector<int> &v);


private:
    void static MergeSort(vector<int> &v, int begin, int end);
    void static Merge(vector<int> &v, int left, int mid, int right);
    void static QuickSort(vector<int> &v, int low, int high);
    int static Partition(vector<int> &v, int low, int high);
    void static QuickThreeWaySort(vector<int> &v, int low, int high);
    int static MaxBit(vector<int> &v, int n);

};
