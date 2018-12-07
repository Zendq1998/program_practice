/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i += 1) {
            if (set.count(nums[i]) >= 1) {
                set.erase(nums[i]);
            } else {
                set.insert(nums[i]);
            }
        }
        return *set.begin();
    }
};