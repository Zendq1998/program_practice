/*
Given two arrays, write a function to compute their intersection.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1, map2;
        vector<int> re;
        for(int i = 0; i < nums1.size(); i += 1) {
            if(map1.count(nums1[i])) {
                map1[nums1[i]] += 1;
            } else {
                map1[nums1[i]] = 1;
            }
        }
        for(int i = 0; i < nums2.size(); i += 1) {
            if(map2.count(nums2[i])) {
                map2[nums2[i]] += 1;
            } else {
                map2[nums2[i]] = 1;
            }
        }
        for (auto it = map1.begin(); it != map1.end(); ++it) {
            if (map2.count(it->first)) {
                int len = min(it->second, map2[it->first]);
                for (int i = 0; i < len; i += 1) {
                    re.push_back(it->first);
                }
            }
        }
        return re;
    }
};