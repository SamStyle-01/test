#include <iostream>
#include <vector>

class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		int mid1 = nums1.size() % 2 ? nums1.size() / 2 : nums1.size() / 2 - 1;
		int mid2 = nums2.size() % 2 ? nums2.size() / 2 : nums2.size() / 2 - 1;

		double median1 = nums1.size() % 2 ? nums1[mid1] : (nums1[mid1] + nums1[mid1 + 1]) / 2;
		double median2 = nums2.size() % 2 ? nums2[mid2] : (nums2[mid2] + nums2[mid2 + 1]) / 2;

		if (median1 < median2) {
			std::swap(nums1, nums2);
			std::swap(median1, median2);
			std::swap(mid1, mid2);
		}

		if (median1 != median2) {
			mid1 = nums1.size() / 2 ? mid1 : mid1 + 1;
			for (int i = 1, j = 1; (mid2 + j < nums2.size()) && (mid1 - i >= 0);) {
				if (nums1[mid1 - i] < nums2[mid2 + j] && i == 1) {
					return ((double)nums1[mid1 - i + 1] + (double)nums2[mid1 - i]) / 2.0;
				}
				else if (nums1[mid1 - i] < nums2[mid2 + j]) {
					return ((double)nums1[mid1 - i + 1] + (double)nums2[mid2 + j - 1]) / 2.0;
				}
				i++;
				j++;
			}
		}
		else {
			return nums1[mid1];
		}
	}
};

using namespace std;

int main() {
	vector<int> nums1{ 1, 2, 3, 7, 8, 10, 12, 15, 18 };
	vector<int> nums2{ 2, 3, 4, 5, 6, 10, 11, 12, 16 };

	Solution sol;
	
	cout << sol.findMedianSortedArrays(nums1, nums2);
}