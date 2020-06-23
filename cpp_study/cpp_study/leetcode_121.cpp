#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int vecsize = prices.size();
        int iRMax = prices[vecsize-1];
        int iLMin=prices[0];
        for (int i = 1, j = vecsize - 2; i<=j; ++i, --j) {
            iRMax = max(prices[j],iRMax);
            iLMin = min(prices[i],iLMin);
        }
        int res = iRMax - iLMin;
        if (res < 0) {
            return 0;
        }

        return res;
//         size_t vecsize = prices.size();
//         int iMax = 0;
//         for (size_t i = 0; i < vecsize; ++i) {
//             for (size_t j = 1; j < vecsize; ++j) {
//                 iMax = max(prices[j]-prices[i],iMax);
//             }
//         }
//         return iMax;
    }
};