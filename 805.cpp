class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        double avg = static_cast<double>(sum) / n;
        
        // Check if it's possible to achieve the same average
        bool possible = false;
        for (int k = 1; k <= n / 2; k++) {
            if (abs(avg * k - round(avg * k)) < 1e-6) {
                possible = true;
                break;
            }
        }
        if (!possible) {
            return false;
        }
        
        // Use dynamic programming to check if it's possible to achieve the same sum
        unordered_set<int> sums;
        sums.insert(0);
        for (int i = 0; i < n; i++) {
            unordered_set<int> new_sums;
            for (int x : sums) {
                new_sums.insert(x + nums[i]);
            }
            sums.insert(new_sums.begin(), new_sums.end());
        }
        for (int k = 1; k <= n / 2; k++) {
            if (abs(avg * k - round(avg * k)) < 1e-6) {
                int target_sum = round(avg * k);
                if (sums.count(target_sum)) {
                    return true;
                }
            }
        }
        return false;
    }
};
