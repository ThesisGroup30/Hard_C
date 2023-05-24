#include <iostream>
#include <string>
#include <map>
#include <stack>

class Solution {
public:
    std::string countOfAtoms(std::string formula) {
        std::map<std::string, int> countMap;
        std::stack<std::map<std::string, int>> countStack;
        int n = formula.size();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                countStack.push(countMap);
                countMap.clear();
                i++;
            } else if (formula[i] == ')') {
                std::map<std::string, int> innerMap = countMap;
                countMap = countStack.top();
                countStack.pop();
                i++;

                int j = i;
                while (j < n && isdigit(formula[j]))
                    j++;

                int factor = (j == i) ? 1 : std::stoi(formula.substr(i, j - i));
                i = j;

                for (auto& entry : innerMap)
                    countMap[entry.first] += entry.second * factor;
            } else {
                int j = i + 1;
                while (j < n && islower(formula[j]))
                    j++;

                std::string element = formula.substr(i, j - i);

                int k = j;
                while (k < n && isdigit(formula[k]))
                    k++;

                int count = (k == j) ? 1 : std::stoi(formula.substr(j, k - j));
                countMap[element] += count;

                i = k;
            }
        }

        std::string result;
        for (auto& entry : countMap) {
            result += entry.first;
            if (entry.second > 1)
                result += std::to_string(entry.second);
        }

        return result;
    }
};
