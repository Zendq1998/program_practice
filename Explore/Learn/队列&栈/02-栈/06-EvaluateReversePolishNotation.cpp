/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i += 1) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int node;
                if (tokens[i] == "+") {
                    node = a + b;
                }
                else if (tokens[i] == "-") {
                    node = a - b;
                }
                else if (tokens[i] == "*") {
                    node = a * b;
                }
                else {
                    node = a / b;
                }
                s.push(node);
            }
            else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};