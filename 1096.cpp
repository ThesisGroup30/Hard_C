#include <vector>
#include <set>
#include <string>
#include <stack>

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        stack<set<string>> stk;
        stk.push({""});

        for (char c : expression) {
            if (c == '{') {
                stk.push({""});
            } else if (c == '}') {
                evaluate(stk);
            } else if (c == ',') {
                stk.top().insert("");
            } else {
                stk.top().insert(string(1, c));
            }
        }

        vector<string> result(stk.top().begin(), stk.top().end());
        sort(result.begin(), result.end());
        return result;
    }

private:
    void evaluate(stack<set<string>>& stk) {
        set<string> topSet = stk.top();
        stk.pop();
        set<string> newSet;

        for (const string& word : topSet) {
            for (const string& nextWord : stk.top()) {
                newSet.insert(word + nextWord);
            }
        }

        stk.top().swap(newSet);
    }
};
