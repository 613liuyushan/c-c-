#include <vector>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int iMax = 0;
		if (nums.size() == 1){
			return nums[0];
		}
		for (auto&& elem : nums) {
			if (iMax > 0) {
				iMax += elem;
			}
			else {
				iMax = elem;
			}
		}

		return iMax;
	}
};