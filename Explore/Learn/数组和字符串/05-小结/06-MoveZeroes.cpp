/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        while (len--) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                nums.push_back(0);
            }
            else {
                i += 1;
            }
        }
    }
};