/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        for (; i < s.size(); i += 1) {
            if (s[i] == ' ') {
                if (i - 1 > j) {
                    reverseWord(s, j, i - 1);
                }
                j = i + 1;
            }
        }
        if (i - 1 > j) {
            reverseWord(s, j, i - 1);
        }
        return s;
    }
    void reverseWord(string &s, int start, int end) {
        int i = start, j = end;
        while (i < j) {
            swap(s[i], s[j]);
            i += 1;
            j -= 1;
        }
    }
};