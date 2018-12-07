/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0;i < nums.size(); i += 1) {
            if (set.count(nums[i]) > 0) {
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
    }
};