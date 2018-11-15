/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
*/
#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int M = matrix.size();
        vector<int> result;
        if (M == 0) {
            return result;
        }
        int N = matrix[0].size();
        int T = M + N;
        bool up = true;
        int i, j;
        for (int n = 0; n <= T - 2; n += 1) {
            if (up) {
                if (M - 1 > n) {
                   i = n;
                   j = 0;
                }
                else {
                    i = M - 1;
                    j = n - M + 1;
                }
            }
            else {
                if (N - 1 > n) {
                    i = 0;
                    j = n;
                }
                else {
                    i = n - N + 1;
                    j = N - 1;
                }
            }
            while (i >= 0 && i <= M - 1 && j >= 0 && j <= N -1) {
                result.push_back(matrix[i][j]);
                if (up) {
                    i -= 1;
                    j += 1;
                }
                else {
                    i += 1;
                    j -= 1;
                }
            }
            up = !up;
        }
        return result;
    }
};