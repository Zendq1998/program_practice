/*
Given an array of strings, group anagrams together.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<string> str_temp(strs.begin(), strs.end());
        vector<vector<string> > re;
        unordered_map<string, vector<string> > map;
        for (int i = 0; i < strs.size(); i += 1) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (map.count(temp)) {
                map[temp].push_back(strs[i]);
            } else {
                vector<string> new_arr;
                new_arr.push_back(strs[i]);
                map[temp] = new_arr;
            }
        }
        for (auto it = map.begin(); it != map.end(); ++it) {
            re.push_back(it->second);
        }
        return re;
    }
};