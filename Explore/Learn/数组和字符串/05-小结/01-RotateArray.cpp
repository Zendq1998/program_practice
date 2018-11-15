/*
Given an array, rotate the array to the right by k steps, where k is non-negative.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    
    void reverse(vector<int>& nums, int start, int end) {
        int i = start, j = end;
        while (i < j) {
            swap(nums[i], nums[j]);
            i += 1;
            j -= 1;
        }
    }
};