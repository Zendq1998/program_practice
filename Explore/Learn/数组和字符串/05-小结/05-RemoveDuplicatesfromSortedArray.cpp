/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() > 1) {
            for (int i = 1; i < nums.size(); i += 1) {
                if (nums[i] == nums[i - 1]) {
                    nums.erase(nums.begin() + i, nums.begin() + i + 1);
                    i -= 1;
                }
            }
        }
        return nums.size();
    }
};