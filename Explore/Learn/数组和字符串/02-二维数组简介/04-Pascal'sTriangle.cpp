/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
*/
#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 1; i <= numRows; i += 1) {
            if (i == 1) {
                vector<int> row(1, 1);
                result.push_back(row);
            }
            else {
                vector<int> row(result[i-2]);
                row.insert(row.begin(), 1);
                for (int i = 1; i < row.size() - 1; i += 1) {
                    row[i] = row[i] + row[i + 1];
                }
                result.push_back(row);
            }
        }
        return result;
    }
};