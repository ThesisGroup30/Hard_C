#include <vector>
#include <stack>

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> collisionTimes(n, -1);
        stack<int> carStack;
        
        for (int i = n - 1; i >= 0; i--) {
            int currPos = cars[i][0];
            int currSpeed = cars[i][1];
            
            while (!carStack.empty()) {
                int j = carStack.top();
                int nextPos = cars[j][0];
                int nextSpeed = cars[j][1];
                
                if (currSpeed <= nextSpeed || 
                    (collisionTimes[j] > 0 && (nextPos - currPos) / static_cast<double>(currSpeed - nextSpeed) >= collisionTimes[j])) {
                    carStack.pop();
                } else {
                    collisionTimes[i] = (nextPos - currPos) / static_cast<double>(currSpeed - nextSpeed);
                    break;
                }
            }
            
            carStack.push(i);
        }
        
        return collisionTimes;
    }
};
