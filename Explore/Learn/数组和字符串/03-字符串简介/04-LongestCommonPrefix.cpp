/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/
#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        int commonLen = strs[0].size();
        for (int i = 1; i < strs.size(); i += 1) {
            for (int j = 0; j < commonLen; j += 1) {
                if (strs[0][j] != strs[i][j]) {
                    commonLen = j;
                    break;
                }
                if (commonLen == 0) {
                    break;
                }
            }
        }
        if (commonLen == 0) {
            return "";
        }
        else {
            return strs[0].substr(0, commonLen);
        }
    }
};