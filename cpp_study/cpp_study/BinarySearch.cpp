#include "BinarySearch.h"
int BinarySearch(const std::vector<int>& vec,const int val) {
    int vecsize = vec.size();
    int low = 0;
    int high = vecsize -1;
    int mid;
    while (low <= high) {
        mid = (high + low) / 2;
        if (val > vec[mid]) {
            low = mid +1;
        }
        else if (val < vec[mid]) {
            high = mid -1;
        }
        else
            return mid;
    }
    return 0;
}