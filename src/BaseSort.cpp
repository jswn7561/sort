//
// Created by Edith Wang on 2022/10/20.
//

#include "BaseSort.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;
/**
 * 选择排序
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)，在原数组空间内操作，需要的额外空间是指针空间
 * @param vector<int> v
 */
void BaseSort::SelectSort(vector<int> &v) {
    int n = v.size();
    if (n == 0) return;
    SelectSort(v, 0, n - 1);
}

void BaseSort::SelectSort(vector<int>& v, int begin, int end) {
    if (begin >= end) {
        return;
    }

    for (int i = begin; i < end; i++) {
        int min = i;
        for (int j = i + 1; j <= end; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(v[min], v[i]);
        }
    }
}

/**
 * 选择排序优化
 * 使用二元选择排序，即在一次遍历中，找到最大值和最小值，将两个最值放到数组的两端，然后再递归处理夹在两个最值中间的待排数组
 * @param vector<int> v
 */
void BaseSort::BinarySelectSort(vector<int> &v) {
    int n = v.size();
    if (n == 0) return;
    BinarySelectSort(v, 0, n - 1);
}

void BaseSort::BinarySelectSort(vector<int>& v, int begin, int end) {
    if (begin >= end) {
        return;
    }

    const auto interval = end - begin + 1;
    for (int i = begin, len = begin + interval / 2; i < len; i++) {
        int min = i;
        int max = i;
        const auto newEnd = end - i + begin;
        for (int j = i + 1; j <= newEnd; j++) {
            if (v[j] < v[min]) {
                min = j;
            } else if (v[j] > v[max]) {
                max = j;
            }
        }
        if (min != i)
            swap(v[min], v[i]);

        if (max == i)
            max = min;

        if (max != newEnd)
            swap(v[max], v[newEnd]);
    }
}

/**
 * 归并排序_递归法
 * @param vector<int> v
 */
void BaseSort::MergeSort(vector<int> &v) {
    int n = v.size();
    if (n == 0) return;
    MergeSort(v, 0, n - 1);
}

void BaseSort::MergeSort(vector<int> &v, int begin, int end) {
    if (begin >= end) {
        return;
    }

    int mid = begin + (end - begin) / 2;
    MergeSort(v, begin, mid);
    MergeSort(v, mid + 1, end);
    Merge(v, begin, mid, end);
}

/**
 * 归并排序_迭代法
 * @param v
 */
void BaseSort::MergeIterateSort(vector<int> &v) {
    int n = v.size();
    if (n == 0) return;
    MergeIterateSort(v, 0, n - 1);
}

void BaseSort::MergeIterateSort(vector<int>& v, int begin, int end) {
    if (begin >= end) {
        return;
    }

    const auto interval = end - begin + 1;
    for (int seg = 1; seg < interval; seg += seg) {
        for (int start = begin, len = interval - seg + begin; start < len; start += seg + seg) {
            Merge(v, start, start + seg - 1, min(start + seg + seg - 1, end));
        }
    }
}

void BaseSort::Merge(vector<int> &v, const int left, const int mid, const int right) {
    int *temp = new int[right - left + 1]; // 辅助空间
    int tempIndex = 0; // 辅助空间index
    int leftIndex = left; //左侧数组指针
    int rightIndex = mid + 1; //右侧数组指针

    while (leftIndex <= mid && rightIndex <= right)  //较小的元素赋值进数组
        temp[tempIndex++] = v[leftIndex] <= v[rightIndex] ? v[leftIndex++] : v[rightIndex++];

    //将两侧剩余的元素赋值进去
    while (leftIndex <= mid)
        temp[tempIndex++] = v[leftIndex++];

    while (rightIndex <= right)
        temp[tempIndex++] = v[rightIndex++];

    //将辅助空间数组赋值到原数组中
    for (int i = 0; i < right - left + 1; i++) {
        v[left + i] = temp[i];
    }

    delete[]temp; // 释放内存
}

/**
 * 快速排序
 * @param vector<int> v
 */
void BaseSort::QuickSort(vector<int> &v) {
    if (v.size() == 0) return;
    QuickSort(v, 0, v.size() - 1);
}

void BaseSort::QuickSort(vector<int> &v, int low, int high) {
    if (low < high) {
        int pivotpos = Partition(v, low, high);
        QuickSort(v, low, pivotpos - 1);
        QuickSort(v, pivotpos + 1, high);
    }
}

int BaseSort::Partition(vector<int> &v, int low, int high) {
    int pivot = v[low];//第一个元素作为主元
    while (low < high) {
        while (low < high && v[high] >= pivot) high--;
        v[low] = v[high];
        while (low < high && v[low] <= pivot) low++;
        v[high] = v[low];
    }
    v[low] = pivot;
    return low;
}

/**
 * 三路快速排序
 * @param vector<int> v
 */
void BaseSort::QuickThreeWaySort(vector<int> &v) {
    if (v.size() == 0) return;
    QuickThreeWaySort(v, 0, v.size() - 1);
}

void BaseSort::QuickThreeWaySort(vector<int> &v, int low, int high) {
    if (low >= high) return;

    int pivot = v[low];
    int lt = low;
    int gt = high + 1;
    int i = low + 1;
    while (i < gt) {
        if (v[i] < pivot) { // 当前位置元素小于pivot时，则将当前位置元素与等于pivot部分的第一个元素进行交换
            swap(v[i], v[lt + 1]);
            i++;
            lt++;
        } else if (v[i] > pivot) { // 当前位置元素大于pivot时，将当前位置元素与大于pivot部分的前一个元素进行交换
            swap(v[i], v[gt - 1]);
            gt--;
        } else {
            i++;
        }
    }
    swap(v[low], v[lt]);

    QuickThreeWaySort(v, low, lt - 1);
    QuickThreeWaySort(v, gt, high);
}

/**
 * 希尔排序_移位法
 * @param vector<int> v
 */
void BaseSort::ShellSort(vector<int> &v) {
    int n = v.size();
    if (n == 0) return;
    ShellSort(v, 0, n - 1);
}

void BaseSort::ShellSort(vector<int>& v, int begin, int end) {
    if (begin >= end) {
        return;
    }

    const auto interval = end - begin + 1;
    for (int gap = interval / 2; gap > 0; gap = gap / 2) {
        for (int i = begin + gap; i <= end; i++) {
            int j = i;
            int temp = v[j];
            while (j - gap >= begin && v[j - gap] > temp) {
                v[j] = v[j - gap];
                j = j - gap;
            }
            v[j] = temp;
        }
    }
}

/**
 * 希尔排序_交换法
 * @param vector<int> v
 */
void BaseSort::ShellExchangeSort(vector<int> &v) {
    int n = v.size();
    if (n == 0) return;
    ShellExchangeSort(v, 0, n - 1);
}

void BaseSort::ShellExchangeSort(vector<int>& v, int begin, int end) {
    if (begin >= end) {
        return;
    }

    const auto interval = end - begin + 1;
    for (int gap = interval / 2; gap > 0; gap = gap / 2) {
        for (int j = begin + gap; j <= end; j++) {
            for (int k = j; k >= begin; k -= gap) {
                if (k - gap >= begin && v[k] < v[k - gap]) {
                    swap(v[k], v[k - gap]);
                }
            }
        }
    }
}

/**
 * 基数排序
 * @param vector<int> v
 */
void BaseSort::RadixSort(vector<int> &v) {
    int n = v.size();
    if (n == 0) return;
    RadixSort(v, 0, n - 1);
}

void BaseSort::RadixSort(vector<int>& v, int begin, int end) {
    if (begin >= end) {
        return;
    }

    const auto interval = end - begin + 1;
    int d = MaxBit(v, begin, end);
    int* tmp = new int[interval];
    int* count = new int[10];  //计数器
    int i, j, k;
    int radix = 1;
    //进行d次排序
    for (i = 1; i <= d; i++) {
        //每次分配前清空计数器
        for (j = 0; j < 10; j++)
            count[j] = 0;
        //统计每个桶中的记录数
        for (j = begin; j <= end; j++) {
            k = (v[j] / radix) % 10;
            count[k]++;
        }
        //将tmp中的位置依次分配给每个桶,求前缀和
        for (j = 1; j < 10; j++)
            count[j] += count[j - 1];
        //将所有桶中记录依次收集到tmp中
        for (j = end; j >= begin; j--) {
            k = (v[j] / radix) % 10;
            tmp[count[k] - 1] = v[j];
            count[k]--;
        }
        //将临时数组的内容复制到data中
        for (j = begin; j <= end; j++)
            v[j] = tmp[j - begin];
        //位数加1
        radix = radix * 10;
    }
    delete[] tmp;
    delete[] count;
}

/**
 * 辅助函数，求数据的最大位数
 * @param v
 * @param n
 */
int BaseSort::MaxBit(vector<int> &v, int begin, int end) {
    int maxData = v[begin];           // 最大数
    for (int i = begin + 1; i <= end; i++) {
        if (maxData < v[i])
            maxData = v[i];
    }

    int d = 1;
    int p = 10;
    while (maxData >= p) {
        maxData /= 10;
        d++;
    }
    return d;
}

void BaseSort::RadixBucketSort(vector<int> &v) {
    int n = v.size();
    if (n == 0) return;
    RadixBucketSort(v, 0, n - 1);
}

void BaseSort::RadixBucketSort(vector<int>& v, int begin, int end) {
    if (begin >= end) {
        return;
    }

    // 寻找最大值
    int max = v[begin];
    for (int i = begin; i <= end; ++i) {
        if (v[i] > max)
            max = v[i];
    }

    // 设置10个桶 0～9
    list<int> bucket[10];

    for (int i = 1; max / i > 0; i *= 10) {
        // 根据位数上的数字将元素放入对应的桶中
        for (int j = begin; j <= end; j++) {
            bucket[(v[j] / i) % 10].push_back(v[j]);
        }
        int j, k;
        for (j = 0, k = begin; j < 10; j++) {
            while (!bucket[j].empty()) {
                v[k++] = bucket[j].front();
                bucket[j].pop_front();
            }
        }
    }
}


void BaseSort::Run() {
    int n[] = {1000, 5000, 10000, 50000, 80000, 100000};
    for (int j = 0; j < 6; j++) {
        vector<int> v1(n[j], 0);
        srand((unsigned) time(NULL));
        for (int i = 0; i < n[j]; i++) {
            v1[i] = rand() % 50000 + 1; // rand()函数在stdlib.h头文件中
        }
        vector<int> v2 = v1;
        vector<int> v3 = v1;
        vector<int> v4 = v1;
        vector<int> v5 = v1;
        vector<int> v6 = v1;
        vector<int> v7 = v1;
        vector<int> v8 = v1;
        vector<int> v9 = v1;
        vector<int> v10 = v1;
        cout <<  "规模为大小为" << n[j] << "各排序耗时" << endl;
        clock_t startTime, endTime;
        // 选择排序
        startTime = clock();
        BaseSort::SelectSort(v1);
        endTime = clock();
        cout <<  "选择排序耗时：" << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

        // 二元选择排序
        startTime = clock();
        BaseSort::BinarySelectSort(v2);
        endTime = clock();
        cout <<  "二元选择排序耗时：" << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

        // 归并排序_递归法
        startTime = clock();
        BaseSort::MergeSort(v3);
        endTime = clock();
        cout <<  "归并排序_递归法耗时：" << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

        // 归并排序_迭代法
        startTime = clock();
        BaseSort::MergeIterateSort(v4);
        endTime = clock();
        cout <<  "归并排序_迭代法耗时：" << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

        // 快速排序
        startTime = clock();
        BaseSort::QuickSort(v5);
        endTime = clock();
        cout <<  "快速排序耗时：" << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

        // 三路快速排序
        startTime = clock();
        BaseSort::QuickThreeWaySort(v6);
        endTime = clock();
        cout <<  "快速排序耗时：" << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

        // 希尔排序_移位法
        startTime = clock();
        BaseSort::ShellSort(v7);
        endTime = clock();
        cout <<  "希尔排序_移位法耗时：" << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

        // 希尔排序_交换法
        startTime = clock();
        BaseSort::ShellExchangeSort(v8);
        endTime = clock();
        cout <<  "希尔排序_交换法耗时：" << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

        // 基数排序_计数
        startTime = clock();
        BaseSort::RadixSort(v9);
        endTime = clock();
        cout <<  "基数排序_计数耗时：" << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

        // 基数排序_桶
        startTime = clock();
        BaseSort::RadixBucketSort(v10);
        endTime = clock();
        cout <<  "基数排序_桶耗时：" << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

    }
}

