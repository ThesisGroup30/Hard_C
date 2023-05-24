class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cost[i][j] = cost[i+1][j-1] + (s[i] != s[j]);
            }
        }
        vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (j == 1) {
                    dp[i][j] = cost[0][i-1];
                } else {
                    for (int p = j-1; p < i; p++) {
                        dp[i][j] = min(dp[i][j], dp[p][j-1] + cost[p][i-1]);
                    }
                }
            }
        }
        return dp[n][k];
    }
};
