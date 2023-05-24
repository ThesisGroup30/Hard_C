class Solution {
public:
    int calculate(string s) {
        stack<int> operands;
        stack<char> signs;
        int operand = 0, result = 0, sign = 1;

        for (char c : s) {
            if (isdigit(c)) {
                operand = operand * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += sign * operand;
                operand = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                operands.push(result);
                signs.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * operand;
                operand = 0;
                result = signs.top() * result + operands.top();
                signs.pop();
                operands.pop();
            }
        }

        result += sign * operand;
        return result;
    }
};
