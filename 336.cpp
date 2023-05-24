class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            reverse(s.begin(), s.end());
            m[s] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            for (int j = 0; j <= s.size(); j++) {
                string left = s.substr(0, j);
                string right = s.substr(j);
                if (m.count(left) && isPalindrome(right) && m[left] != i) {
                    res.push_back({i, m[left]});
                }
                if (m.count(right) && isPalindrome(left) && m[right] != i && j > 0) {
                    res.push_back({m[right], i});
                }
            }
        }
        return res;
    }
    
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};
