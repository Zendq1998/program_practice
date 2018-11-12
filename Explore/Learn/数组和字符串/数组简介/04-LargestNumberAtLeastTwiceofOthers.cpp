#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i += 1) {
            if (nums[i] >= nums[maxIndex]) {
                maxIndex = i;
            }
        }
        for (int i = 0; i < nums.size(); i += 1) {
            if(i != maxIndex) {
                if (nums[i] * 2 > nums[maxIndex]) {
                    return -1;
                }
            }
        }
        return maxIndex;
    }
};