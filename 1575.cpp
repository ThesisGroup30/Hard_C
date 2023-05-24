class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const int mod = 1e9 + 7;
        const int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel+1));
        dp[start][0] = 1;
        for (int f = 1; f <= fuel; f++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j && f >= abs(locations[i] - locations[j])) {
                        dp[i][f] = (dp[i][f] + dp[j][f - abs(locations[i] - locations[j])]) % mod;
                    }
                }
            }
        }
        int ans = 0;
        for (int f = 0; f <= fuel; f++) {
            ans = (ans + dp[finish][f]) % mod;
        }
        return ans;
    }
};
