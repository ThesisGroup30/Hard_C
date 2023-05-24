#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int smallest = *min_element(nums.begin(), nums.end());
        int deletions = 0;
        
        for (int num : numsDivide) {
            if (num % smallest != 0) {
                return -1;
            }
            
            while (num % smallest == 0) {
                num /= smallest;
                deletions++;
            }
        }
        
        return deletions;
    }
};
