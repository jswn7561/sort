#include <vector>
#include <list>
#include <string>

using namespace std;

class BigValueSort {
public:
    static void Run();
    // 选择排序
    static void SelectSort(std::vector<string>& v);
    static void SelectSort(std::vector<string>& v, int n);
    // 归并排序
    static void MergeSort(std::vector<string>& v);
    static void MergeSort(std::vector<string>& v, int begin, int end);
    // 快速排序
    static void QuickSort(std::vector<string>& v);
    static void QuickSort(std::vector<string>& v, int begin, int end);
    // 希尔排序
    static void ShellSort(std::vector<string>& v);
    static void ShellSort(std::vector<string>& v, int n);
    // 基数排序
    static void RadixSort(std::vector<string>& v);
    static void RadixSort(std::vector<string>& v, int begin, int end);

private:
    // 归并排序中调用
    static void Merge(std::vector<string>& v, int left, int mid, int right);
    // 快速排序中调用
    static int Partition(std::vector<string>& v, int low, int high);
};
