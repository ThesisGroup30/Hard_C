class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n = nums.size();
        int xor_sum = 0;
        for (int num : nums) {
            xor_sum ^= num;
        }
        return xor_sum == 0 || n % 2 == 0;
    }
};
