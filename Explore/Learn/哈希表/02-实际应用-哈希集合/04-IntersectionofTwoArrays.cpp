/*
Given two arrays, write a function to compute their intersection.
*/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        vector<int> re;
        for (int i = 0; i < nums1.size(); i += 1) {
            if (set1.count(nums1[i]) <= 0) {
                set1.insert(nums1[i]);
            }
        }
        for (int i = 0; i < nums2.size(); i += 1) {
            if (set2.count(nums2[i]) <= 0) {
                set2.insert(nums2[i]);
            }
        }
        for (auto it = set1.begin(); it != set1.end(); ++it) {
            if (set2.count(*it)) {
                re.push_back(*it);
            }
        }
        return re;
    }
};