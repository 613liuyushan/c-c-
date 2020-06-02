#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
		return nums.size();
	}
};