/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        for (int i = 1; i <= rowIndex + 1; i += 1) {
            v.push_back(1);
            for (int j = v.size() - 2; j >= 1; j -= 1) {
                v[j] = v[j] + v[j - 1];   
            }
        }
        return v;
    }
};