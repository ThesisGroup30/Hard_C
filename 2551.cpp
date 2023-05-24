#include <vector>
#include <algorithm>

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int bags = countBags(weights, mid);
            
            if (bags > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
private:
    int countBags(vector<int>& weights, int capacity) {
        int bags = 1;
        int currentWeight = 0;
        
        for (int weight : weights) {
            if (currentWeight + weight <= capacity) {
                currentWeight += weight;
            } else {
                bags++;
                currentWeight = weight;
            }
        }
        
        return bags;
    }
};
