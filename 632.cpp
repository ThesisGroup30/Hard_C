class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> indices(k, 0); // current index for each list
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap; // (value, list_index)
        int range_start = 0, range_end = INT_MAX, max_value = INT_MIN;
        
        // add first element of each list to min heap
        for (int i = 0; i < k; i++) {
            if (!nums[i].empty()) {
                min_heap.emplace(nums[i][0], i);
                max_value = max(max_value, nums[i][0]);
            }
        }
        
        // keep removing the smallest element from heap and add the next element from that list
        while (min_heap.size() == k) {
            auto [value, list_index] = min_heap.top();
            min_heap.pop();
            
            // check if current range is smaller than previous ranges
            if (max_value - value < range_end - range_start || (max_value - value == range_end - range_start && value < range_start)) {
                range_start = value;
                range_end = max_value;
            }
            
            // add the next element from the list
            indices[list_index]++;
            if (indices[list_index] < nums[list_index].size()) {
                int next_value = nums[list_index][indices[list_index]];
                min_heap.emplace(next_value, list_index);
                max_value = max(max_value, next_value);
            }
        }
        
        return {range_start, range_end};
    }
};
