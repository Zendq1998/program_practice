/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
*/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        if (s == "") return "";
        string num_str = "";
        string str_temp = "";
        stack<char> s_re;
        stack<int> s_num;
        stack<char> s_temp;
        for (int i = 0; i < s.size(); i += 1) {
            if (s[i] >= '0' && s[i] <= '9') {
                num_str += s[i];
            }
            else if (s[i] == '[') {
                s_num.push(stoi(num_str));
                s_re.push('[');
                num_str = "";
            }
            else if (s[i] == ']') {
                while(s_re.top() != '[') {
                    s_temp.push(s_re.top());
                    s_re.pop();
                }
                s_re.pop();
                int n = s_num.top();
                s_num.pop();
                while (!s_temp.empty()) {
                    str_temp += s_temp.top();
                    s_temp.pop();
                }
                while (n--) {
                    for (int j = 0; j < str_temp.size(); j += 1) {
                        s_re.push(str_temp[j]);
                    }
                }
                str_temp = "";
            }
            else {
                s_re.push(s[i]);
            }
        }
        while(!s_re.empty()) {
            s_temp.push(s_re.top());
            s_re.pop();
        }
        string re = "";
        while(!s_temp.empty()) {
            re += s_temp.top();
            s_temp.pop();
        }
        return re;
    }
};