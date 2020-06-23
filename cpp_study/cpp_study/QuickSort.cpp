#include "QuickSort.h"
int partition(std::vector<int>& vec,int low,int high)
{
    int flag = vec[low];
    while (low < high) {
        while (vec[high] >= flag && high > low) --high;
        vec[low] = vec[high];
        while (vec[low] <= flag && high> low) ++low;
        vec[high] = vec[low];
    }
    vec[low] = flag;
    return low;
}
void QuickSort(std::vector<int>& vec,int low,int high)
{
    if (low < high) {
        int q = partition(vec, low, high);
        QuickSort(vec, low, q-1);
        QuickSort(vec, q+1, high);
    }
}