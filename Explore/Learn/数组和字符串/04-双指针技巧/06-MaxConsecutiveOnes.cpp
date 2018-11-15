/*
Given a binary array, find the maximum number of consecutive 1s in this array.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int k = 0, i = 0;
        for (; i < nums.size(); i += 1) {
            if (nums[i] == 0) {
                int len = i - k;
                max = len > max ? len : max;
                k = i + 1;
            }
        }
        int len = i - k;
        max = len > max ? len : max;
        return max;
    }
};