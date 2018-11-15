/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int minLen = INT_MAX;
        int start = 0, end = 0;
        int sum = nums[0];
        while (end < nums.size()) {
            if (sum < s) {
                end += 1;
                sum += nums[end];
            }
            else {
                minLen = min(minLen, end - start + 1);
                sum -= nums[start];
                start += 1;
            }
        }
        if (minLen == INT_MAX) return 0;
        return minLen;
    }
};