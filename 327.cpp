#include <vector>
#include <iostream>

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int count = 0;
        long long sum = 0;
        std::vector<long long> prefixSums = {0}; // Prefix sums including the sum at index 0
        
        for (int num : nums) {
            sum += num;
            prefixSums.push_back(sum);
        }
        
        count = mergeSortCount(prefixSums, 0, prefixSums.size() - 1, lower, upper);
        
        return count;
    }
    
    int mergeSortCount(std::vector<long long>& prefixSums, int left, int right, int lower, int upper) {
        if (left == right) {
            return (prefixSums[left] >= lower && prefixSums[left] <= upper) ? 1 : 0;
        }
        
        int mid = left + (right - left) / 2;
        int count = 0;
        
        count += mergeSortCount(prefixSums, left, mid, lower, upper); // Count in the left half
        count += mergeSortCount(prefixSums, mid + 1, right, lower, upper); // Count in the right half
        
        int i = left; // Pointer for the left half
        int j = mid + 1; // Pointer for the right half
        int k = mid + 1; // Pointer for merging
        std::vector<long long> merged;
        
        // Merge and count the ranges
        for (; i <= mid; i++) {
            while (j <= right && prefixSums[j] - prefixSums[i] < lower) {
                j++;
            }
            while (k <= right && prefixSums[k] - prefixSums[i] <= upper) {
                k++;
            }
            count += k - j;
        }
        
        // Merge the sorted halves
        i = left;
        j = mid + 1;
        
        while (i <= mid && j <= right) {
            if (prefixSums[i] <= prefixSums[j]) {
                merged.push_back(prefixSums[i]);
                i++;
            } else {
                merged.push_back(prefixSums[j]);
                j++;
            }
        }
        
        while (i <= mid) {
            merged.push_back(prefixSums[i]);
            i++;
        }
        while (j <= right) {
            merged.push_back(prefixSums[j]);
            j++;
        }
        
        // Copy the merged array back to the prefixSums array
        for (int m = left, n = 0; m <= right; m++, n++) {
            prefixSums[m] = merged[n];
        }
        
        return count;
    }
};
