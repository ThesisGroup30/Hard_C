#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Term {
    int coeff;
    vector<string> vars;
    Term(int c = 0, vector<string> v = {}) : coeff(c), vars(v) {}
    bool operator<(const Term& other) const {
        if (vars.size() != other.vars.size()) {
            return vars.size() > other.vars.size();
        }
        for (int i = 0; i < vars.size(); i++) {
            if (vars[i] != other.vars[i]) {
                return vars[i] < other.vars[i];
            }
        }
        return false;
    }
    bool operator==(const Term& other) const {
        return coeff == other.coeff && vars == other.vars;
    }
};

class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> evalMap;
        for (int i = 0; i < evalvars.size(); i++) {
            evalMap[evalvars[i]] = evalints[i];
        }
        unordered_map<string, int> vars;
        vector<string> tokens = parseExpression(expression);
        for (string token : tokens) {
            if (token == "+" || token == "-") {
                continue;
            }
            if (token == "*" || token == "(") {
                opStack.push(token);
            } else if (token == ")") {
                while (opStack.top() != "(") {
                    applyOperator();
                }
                opStack.pop(); // discard "("
            } else { // a variable or integer
                Term term;
                if (isdigit(token[0])) {
                    term.coeff = stoi(token);
                } else if (evalMap.count(token)) {
                    term.coeff = evalMap[token];
                } else {
                    term.vars.push_back(token);
                }
                if (!opStack.empty() && opStack.top() == "*") {
                    opStack.pop(); // discard "*"
                    Term top = termStack.top();
                    termStack.pop();
                    top.coeff *= term.coeff;
                    for (string var : term.vars) {
                        top.vars.push_back(var);
                    }
                    term = top;
                }
                termStack.push(term);
            }
        }
        while (!opStack.empty()) {
            applyOperator();
        }
        vector<string> result;
        while (!termStack.empty()) {
            Term term = termStack.top();
            termStack.pop();
            if (term.coeff == 0 || (term.coeff == 1 && term.vars.empty())) {
                continue;
            }
            if (!term.vars.empty()) {
                sort(term.vars.begin(), term.vars.end());
                string termStr;
                for (string var : term.vars) {
                    termStr += var + "*";
                }
                termStr += to_string(term.coeff);
                result.push_back(termStr);
            } else {
                result.push_back(to_string(term.coeff));
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    stack<Term> termStack;
    stack<string> opStack;
    
   
