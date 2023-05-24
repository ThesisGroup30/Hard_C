#include <vector>
#include <deque>
#include <cmath>

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> dq;
        int maxValue = INT_MIN;
        
        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            
            // Remove points that are outside the range |xi - xj| <= k
            while (!dq.empty() && x - dq.front().second > k) {
                dq.pop_front();
            }
            
            if (!dq.empty()) {
                int eqValue = dq.front().first + y + x;
                maxValue = max(maxValue, eqValue);
            }
            
            // Remove points that have smaller yi + xi values
            while (!dq.empty() && y - x >= dq.back().first) {
                dq.pop_back();
            }
            
            dq.emplace_back(y - x, x);
        }
        
        return maxValue;
    }
};
