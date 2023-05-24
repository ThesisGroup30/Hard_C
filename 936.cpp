#include <vector>
#include <string>

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> result;
        vector<bool> visited(target.size(), false);
        int stamped = 0;

        while (stamped < target.size()) {
            bool found = false;

            for (int i = 0; i <= target.size() - stamp.size(); i++) {
                if (!visited[i] && canStamp(target, i, stamp)) {
                    stamped = stampTarget(target, i, stamp.size(), stamped);
                    visited[i] = true;
                    result.push_back(i);
                    found = true;
                    
                    if (stamped == target.size())
                        break;
                }
            }

            if (!found)
                return {};
        }

        reverse(result.begin(), result.end());
        return result;
    }

private:
    bool canStamp(const string& target, int start, const string& stamp) {
        for (int i = 0; i < stamp.size(); i++) {
            if (target[start + i] != '*' && target[start + i] != stamp[i])
                return false;
        }

        return true;
    }

    int stampTarget(string& target, int start, int length, int stamped) {
        for (int i = 0; i < length; i++) {
            if (target[start + i] != '*') {
                target[start + i] = '*';
                stamped++;
            }
        }

        return stamped;
    }
};
