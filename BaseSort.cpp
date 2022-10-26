//
// Created by Edith Wang on 2022/10/20.
//

#include "BaseSort.h"
#include "iostream"

/**
 * 选择排序
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)，在原数组空间内操作，需要的额外空间是指针空间
 * @param vector<int> v
 */
void BaseSort::SelectSort(vector<int> &v) {
    int n = v.size();
    if (n == 0) return;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            Swap(&v[min], &v[i]);
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
    for (int i = 0; i < n / 2; i++) {
        int min = i;
        int max = i;
        for (int j = i + 1; j < n - i; j++) {
            if (v[j] < v[min]) {
                min = j;
            } else if (v[j] > v[max]){
                max = j;
            }
        }
        if (min != i)
            Swap(&v[min], &v[i]);

        if (max == i)
            max = min;

        if (max != n - i - 1)
            Swap(&v[max], &v[n - i - 1]);
    }
}

/**
 * 交换元素
 * @param p
 * @param q
 */
void BaseSort::Swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

/**
 * 归并排序_递归法
 * @param vector<int> v
 */
void BaseSort::MergeSort(vector<int> &v) {
    if (v.size() == 0) return;
    MergeSort(v, 0, v.size() - 1);
}

void BaseSort::MergeSort(vector<int> &v, int begin, int end) {
    if (begin == end) return;
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

    for (int seg = 1; seg < n; seg += seg) {
        for (int start = 0; start < n - seg; start += seg + seg) {
            Merge(v, start, start + seg - 1, min(start + seg + seg - 1, n - 1));
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
            Swap(&v[i], &v[lt + 1]);
            i++;
            lt++;
        } else if (v[i] > pivot) { // 当前位置元素大于pivot时，将当前位置元素与大于pivot部分的前一个元素进行交换
            Swap(&v[i], &v[gt - 1]);
            gt--;
        } else {
            i++;
        }
    }
    Swap(&v[low], &v[lt]);

    QuickThreeWaySort(v, low, lt - 1);
    QuickThreeWaySort(v, gt, high);
}

/**
 * 希尔排序_移位法
 * @param vector<int> v
 */
void BaseSort::ShellSort(vector<int> &v) {
    int n = v.size();
    for (int gap = n / 2; gap > 0; gap = gap / 2) {
        for (int i = gap; i < n; i++) {
            int j = i;
            int temp = v[j];
            while (j - gap >= 0 && v[j - gap] > temp) {
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
    for (int gap = n / 2; gap > 0; gap = gap / 2) {
        for (int j = gap; j < n; j++) {
            for (int k = j; k >= 0; k -= gap) {
                if (k - gap >= 0 && v[k] < v[k - gap]) {
                    Swap(&v[k], &v[k - gap]);
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
    int d = MaxBit(v, n);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    //进行d次排序
    for (i = 1; i <= d; i++) {
        //每次分配前清空计数器
        for (j = 0; j < 10; j++)
            count[j] = 0;
        //统计每个桶中的记录数
        for (j = 0; j < n; j++) {
            k = (v[j] / radix) % 10;
            count[k]++;
        }
        //将tmp中的位置依次分配给每个桶,求前缀和
        for (j = 1; j < 10; j++)
            count[j] += count[j - 1];
        //将所有桶中记录依次收集到tmp中
        for (j = n - 1; j >= 0; j--) {
            k = (v[j] / radix) % 10;
            tmp[count[k] - 1] = v[j];
            count[k]--;
        }
        //将临时数组的内容复制到data中
        for (j = 0; j < n; j++)
            v[j] = tmp[j];
        //位数加1
        radix = radix * 10;
    }
    delete[]tmp;
    delete[]count;
}

/**
 * 辅助函数，求数据的最大位数
 * @param v
 * @param n
 */
int BaseSort::MaxBit(vector<int> &v, int n) {
    int maxData = v[0];           // 最大数
    for (int i = 1; i < n; i++) {
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
    // 寻找最大值
    int max = v[0];
    for (int i = 0; i < n; ++i) {
        if (v[i] > max)
            max = v[i];
    }

    // 设置10个桶 0～9
    list<int> bucket[10];

    for (int i = 1; max / i > 0; i *= 10) {
        // 根据位数上的数字将元素放入对应的桶中
        for (int j = 0; j < n; j++) {
            bucket[(v[j] / i) % 10].push_back(v[j]);
        }
        int j, k;
        for (j = k = 0; j < 10; j++) {
            while (!bucket[j].empty()) {
                v[k++] = bucket[j].front();
                bucket[j].pop_front();
            }
        }
    }
}


void BaseSort::Run(vector<int> &v, sort_type type) {
    switch (type) {
        case SELECT:
            SelectSort(v);
            break;
        case BINARY_SELECT:
            BinarySelectSort(v);
            break;
        case MERGE:
            MergeSort(v);
            break;
        case MERGE_ITERATE:
            MergeIterateSort(v);
            break;
        case QUICK:
            QuickSort(v);
            break;
        case QUICK_THREEWAY:
            QuickThreeWaySort(v);
            break;
        case SHELL:
            ShellSort(v);
            break;
        case SHELL_EXCHANGE:
            ShellExchangeSort(v);
            break;
        case RADIX:
            RadixSort(v);
            break;
        case RADIX_BUCKET:
            RadixBucketSort(v);
            break;
    }
}

