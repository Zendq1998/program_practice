/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> re;
        for (int i = 0; i < nums.size(); i += 1) {
            if (map.count(target-nums[i]) > 0) {
                re.push_back(map[target-nums[i]]);
                re.push_back(i);
                return re;
            }
            map[nums[i]] = i;
        }
        return re;
    }
};