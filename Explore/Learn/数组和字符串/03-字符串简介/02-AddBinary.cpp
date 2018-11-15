/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string r, m;
        if (b.size() > a.size()) {
            r = b;
            m = a;
        }
        else {
            r = a;
            m = b;
        }
        bool over = false;
        int i;
        for (i = 0; i < m.size(); i += 1) {
            // cout << m[m.size() - 1 - i] << ',' << r[r.size() - 1 - i];
            if (m[m.size() - 1 - i] == '1' && r[r.size() - 1 - i] == '1') {
                if (!over) {
                    r[r.size() - 1 - i] = '0';
                }
                over = true;
            }
            else if (m[m.size() - 1 - i] == '0' && r[r.size() - 1 - i] == '0') {
                if (over) {
                    r[r.size() - 1 - i] = '1';
                    over = false;
                }
            }
            else {
                if (over) {
                    r[r.size() - 1 - i] = '0';
                    over = true;
                }
                else {
                    r[r.size() - 1 - i] = '1';
                    over = false;
                }
            }
        }
        for (; i < r.size(); i += 1) {
            if (over) {
                if (r[r.size() - 1 - i] == '1') {
                    r[r.size() - 1 - i] = '0';
                }
                else {
                    r[r.size() - 1 - i] = '1';
                    over = false;
                    break;
                }
            }
        }
        if (over) {
            r = '1' + r;
        }
        return r;
    }
};
