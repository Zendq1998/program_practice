/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
*/
#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int M = matrix.size();
        if(M == 0) {
            return result;
        }
        int N = matrix[0].size();
        int max_start = (min(M, N) - 1) / 2;
        int width = N, height = M;
        int start = 0;
        int i, j;
        while (width > 0 && height > 0) {
            i = start, j = start;
            do {
                if (width == 1) {
                    while (i <= start + height - 1) {
                        result.push_back(matrix[i][j]);
                        i += 1;
                    }
                    break;
                }
                if (height == 1) {
                    while (j <= start + width - 1) {
                        result.push_back(matrix[i][j]);
                        j += 1;
                    }
                    break;
                }
                result.push_back(matrix[i][j]);
                // cout << matrix[i][j] << width << height;
                if (i == start && j < start + width - 1) {
                    j += 1;
                }
                else if (j == start + width - 1 && i < start + height - 1) {
                    i += 1;
                }
                else if (i == start + height - 1 && j > start) {
                    j -= 1;
                }
                else if (j == start && i > start) {
                    i -= 1;
                }
                else break;
            } while(!(i == start && j == start));
            width -= 2;
            height -= 2;
            start += 1;
        }
        return result;
    }
};