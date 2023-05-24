#include <vector>
#include <string>

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word;
        vector<char> candidates(26, 'a'); // Store the candidate letters

        for (int i = 0; i < n; i++) {
            bool found = false;

            for (int j = 0; j < i; j++) {
                int len = lcp[i][j];
                char candidate = word[j + len]; // Get the candidate letter based on the lcp value

                if (candidates[i] < candidate) {
                    candidates[i] = candidate;
                    found = true;
                }
            }

            if (!found && i > 0) {
                return ""; // No valid string exists
            }

            word += candidates[i]; // Add the selected letter to the word
        }

        return word;
    }
};
