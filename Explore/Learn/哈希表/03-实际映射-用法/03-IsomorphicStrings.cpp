/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> map, map1;
        for (int i = 0; i < s.size(); i += 1) {
            if (map.count(t[i]) <= 0) {
                map[t[i]] = s[i];
            } else {
                if (map[t[i]] != s[i]) return false;
            }
            if (map1.count(s[i]) <= 0) {
                map1[s[i]] = t[i];
            } else {
                if (map1[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};