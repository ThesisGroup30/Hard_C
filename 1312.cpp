class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        
        // dp[i][j] stores the minimum number of insertions needed to make
        // the substring s[i..j] a palindrome
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0, j = len - 1; j < n; i++, j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
