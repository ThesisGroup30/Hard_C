#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        unordered_map<int, int> freq;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            freq[target[i]]--;
        }
        
        vector<int> diff;
        for (auto& it : freq) {
            if (it.second != 0) {
                diff.push_back(it.second);
            }
        }
        
        sort(diff.begin(), diff.end());
        
        long long minOperations = 0;
        int i = 0, j = diff.size() - 1;
        while (i < j) {
            minOperations += abs(diff[i]);
            diff[j] += diff[i];
            i++;
            j--;
        }
        
        return minOperations;
    }
};
