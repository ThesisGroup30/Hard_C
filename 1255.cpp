class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26);
        for (char c : letters) {
            ++freq[c - 'a'];
        }
        return dfs(words, freq, score, 0);
    }
    
    int dfs(const vector<string>& words, vector<int>& freq, const vector<int>& score, int index) {
        if (index == words.size()) {
            return 0;
        }
        int ans = 0;
        for (int i = index; i < words.size(); ++i) {
            const string& word = words[i];
            bool valid = true;
            int points = 0;
            vector<int> delta(26);
            for (char c : word) {
                int f = --freq[c - 'a'];
                if (f < 0) {
                    valid = false;
                }
                delta[c - 'a'] -= 1;
                points += score[c - 'a'];
            }
            if (valid) {
                points += dfs(words, freq, score, i + 1);
                ans = max(ans, points);
            }
            for (char c : word) {
                freq[c - 'a'] += 1;
                delta[c - 'a'] += 1;
            }
        }
        return ans;
    }
};
