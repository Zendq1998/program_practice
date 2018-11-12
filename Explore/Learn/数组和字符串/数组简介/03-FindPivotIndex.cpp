#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 1) {
            sum += nums[i];
        }
        int left = 0, mid, right;
        for (int i = 0; i < nums.size(); i += 1) {
            mid = nums[i];
            right = sum - left - mid;
            if (left == right) {
                return i;
            }
            left += mid;
        }
        return -1;
    }
};