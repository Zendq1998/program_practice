/*
Given an input string, reverse the string word by word.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() >= 1) {
            reverseWord(s, 0, s.size() - 1);
            int i = 0, j = 0;
            for (; i < s.size(); i += 1) {
                if (s[i] == ' ' && i == j) {
                    s.erase(i, 1);
                    i -= 1;
                }
                if (s[i] == ' ' && i != j) {
                    reverseWord(s, j, i - 1);
                    j = i + 1;
                }
            }
            if (s[i - 1] == ' ') {
                while (s[--i] == ' ') {
                    s.erase(i, 1);
                }
            }
            reverseWord(s, j, i - 1);
        }
    }
    void reverseWord(string &s, int start, int end) {
        int i = start, j = end;
        while (i < j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            i += 1;
            j -= 1;
        }
    }
};