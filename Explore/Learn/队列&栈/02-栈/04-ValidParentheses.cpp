/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.size(); i += 1) {
            if(isLeft(s[i])) {
                stack.push(s[i]);
            }
            else {
                if (stack.empty()) return false;
                else {
                    if(!isMatch(stack.top(), s[i])) {
                        return false;
                    }
                    stack.pop();
                }
            }
        }
        return stack.empty();
    }
private:
    bool isLeft(char c) {
        if (c == '(' || c == '[' || c == '{') {
            return true;
        }
        return false;
    }
    bool isMatch(char l, char r) {
        return ((l == '(' && r == ')') || (l == '{' && r == '}') || (l == '[' && r == ']'));
    }
};