#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> resvec;
        for (auto it = numbers.begin(); it < numbers.end() - 1; it++) {
            if (*it > target) {
                break;
            }
            else {
                for (auto iter = it + 1; iter < numbers.end(); ++iter) {
                    if (*it + *iter == target) {
                        resvec.emplace_back(it - numbers.begin() + 1);
                        resvec.emplace_back(iter - numbers.begin() + 1);
                    }
                }
            }
        }
        return resvec;

    }
};