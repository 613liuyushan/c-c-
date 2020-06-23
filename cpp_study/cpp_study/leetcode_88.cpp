#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		nums1.insert(nums1.begin() + m, nums2.begin(), nums2.begin() + n);
		sort(nums1.begin(),nums1.end());
		std::vector<int> nums(m + n);
		std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin() + n, nums.begin());
		nums1.assign(nums.begin(), nums.end());
	}
};