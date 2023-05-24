class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string res = s;
        priority_queue<string, vector<string>, greater<string>> pq;
        for (int i = 0; i < s.size(); i++) {
            pq.push(s.substr(i) + s.substr(0, i));
        }
        res = pq.top();
        return res;
    }
};
