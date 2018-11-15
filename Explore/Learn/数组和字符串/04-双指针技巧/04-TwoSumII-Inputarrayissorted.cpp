/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                i += 1;
                j += 1;
                break;
            }
            else if (numbers[i] +numbers[j] < target) {
                i += 1;
            }
            else {
                j -= 1;
            }
        }
        vector<int> result;
        result.push_back(i);
        result.push_back(j);
        return result;
    }
};