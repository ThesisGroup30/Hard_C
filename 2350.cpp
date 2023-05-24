class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n = rolls.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(k * n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k * (i - 1); j++) {
                for (int x = 1; x <= k; x++) {
                    if (j + x <= k * i) {
                        dp[i][j + x] |= dp[i - 1][j];
                    }
                }
            }
        }
        for (int i = 0; i <= k * n; i++) {
            if (!dp[n][i]) {
                return i;
            }
        }
        return k * n + 1;
    }
};
