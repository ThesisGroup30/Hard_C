#include <vector>
#include <algorithm>

class Solution {
public:
    int totalStrength(std::vector<int>& strength) {
        int n = strength.size();
        const int MOD = 1e9 + 7;
        std::vector<long long> prefixSum(n + 1);
        std::vector<long long> prefixMin(n + 1);

        prefixSum[0] = 0;
        prefixMin[0] = INT_MAX;

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + strength[i];
            prefixMin[i + 1] = std::min(prefixMin[i], static_cast<long long>(strength[i]));
        }

        long long totalStrength = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long long groupStrength = prefixMin[j + 1] * (prefixSum[j + 1] - prefixSum[i]);
                totalStrength = (totalStrength + groupStrength) % MOD;
            }
        }

        return static_cast<int>(totalStrength);
    }
};
