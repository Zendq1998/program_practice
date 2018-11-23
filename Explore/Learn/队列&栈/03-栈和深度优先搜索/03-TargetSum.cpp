/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size() == 0) return re;
        dfs(nums, 0 ,S);
        return re;
    }
private:
    int re = 0;
    void dfs(vector<int>& nums, int index ,int S) {
        if (index == nums.size() - 1) {
            if (nums[index] == S) {
                re += 1;
            }
            if (nums[index] == -S) {
                re += 1;
            }
        }
        else {
            dfs(nums, index + 1, S - nums[index]);
            dfs(nums, index + 1, S + nums[index]);
        }
    }
};