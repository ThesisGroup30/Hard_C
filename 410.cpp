#include <vector>
#include <algorithm>

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end()); // Initialize the left bound with the maximum element in nums
        int right = accumulate(nums.begin(), nums.end(), 0); // Initialize the right bound with the sum of all elements in nums

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 1; // Number of subarrays
            int currSum = 0; // Current sum of the subarray

            for (int num : nums) {
                currSum += num;

                if (currSum > mid) {
                    currSum = num; // Start a new subarray
                    count++;

                    if (count > k) {
                        break; // The current mid is too small, increase it
                    }
                }
            }

            if (count > k) {
                left = mid + 1; // The current mid is too small
            } else {
                right = mid; // The current mid is a valid solution or too large
            }
        }

        return left;
    }
};
