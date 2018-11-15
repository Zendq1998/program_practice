/*
What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        for (int i = 0; i < (int)haystack.size() - (int)needle.size() + 1; i += 1) {
            if (haystack[i] == needle[0]) {
                bool flag = true;
                for (int j = 1; j < needle.size(); j += 1) {
                    if (haystack[i + j] != needle[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return i;
                }
            }
        }
        return -1;
    }
};