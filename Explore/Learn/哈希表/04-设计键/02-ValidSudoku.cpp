/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> set1, set2, set3;
        for (int i = 0; i < 9; i += 1) {
            set1.clear();
            set2.clear();
            set3.clear();
            for (int j = 0; j < 9; j += 1) {
                char item1 = board[i][j];
                char item2 = board[j][i];
                char item3 = board[(i/3)*3+j/3][(i*3)%9+j%3];
                // cout << item1 << " " << item2 << " " << item3 << endl;
                if (item1 != '.') {
                    if (set1.count(item1)) return false;
                    set1.insert(item1);
                }
                if (item2 != '.') {
                    if (set2.count(item2)) return false;
                    set2.insert(item2);
                }
                if (item3 != '.') {
                    if (set3.count(item3)) return false;
                    set3.insert(item3);
                }
            }
            // cout << endl;
        }
        return true;
    }
};