#include "bubbleSort.h"
void bubbleSort(std::vector<int>& vec)
{
    int lsize = vec.size();
    for (int i = 0; i < lsize - 1;++i) {
        for (int j = 0; j < lsize - 1 - i;++j) {
            if (vec[j] > vec[j+1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
    return;
}