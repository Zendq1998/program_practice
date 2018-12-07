/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i += 1) {
            if (map.count(s[i])) {
                map[s[i]] += 1;
            } else {
                map[s[i]] = 1;
            }
        }
        for (int i = 0; i < s.size(); i += 1) {
            if (map[s[i]] == 1) return i;
        }
        return -1;
    }
};