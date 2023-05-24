#include <vector>
#include <queue>

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Create a min-heap to store the current sums
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Add the initial sum
        for (int i = 0; i < m; i++) {
            pq.push(mat[i][0]);
        }
        
        // Perform k-1 merges
        for (int j = 1; j < n; j++) {
            priority_queue<int, vector<int>, greater<int>> nextPq;
            
            while (!pq.empty()) {
                int currSum = pq.top();
                pq.pop();
                
                for (int i = 0; i < m; i++) {
                    int nextSum = currSum + mat[i][j];
                    nextPq.push(nextSum);
                    
                    // Maintain the size of the priority queue to k
                    if (nextPq.size() > k) {
                        nextPq.pop();
                    }
                }
            }
            
            pq = nextPq;
        }
        
        return pq.top();
    }
};
