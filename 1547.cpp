#include <string>

class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.length();
        int k = 0;
        string subtext1, subtext2;

        for (int i = 0; i < n / 2; i++) {
            subtext1 += text[i];
            subtext2 = text.substr(n - i - 1, i + 1);

            if (subtext1 == subtext2) {
                k += 2;
                subtext1 = "";
            }
        }

        if (!subtext1.empty() || n % 2 == 1) {
            k++;
        }

        return k;
    }
};
