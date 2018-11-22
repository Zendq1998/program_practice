/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int numIslands(vector<vector<char> >& grid) {
      if (grid.empty()) return 0;
      int m = grid.size();
      int n = grid[0].size();
      int re = 0;
      for (int i = 0; i < m; i += 1) {
        for (int j = 0; j < n; j += 1) {
          if (dfsIslands(grid, i, j, m, n)) re += 1;
        }
      }
      return re;
    }

  private:
    bool dfsIslands(vector<vector<char> >& grid, int x, int y, int m, int n) {
      if (grid[x][y] == '1') {
        grid[x][y] = '0';
        if (x + 1 < m) {
          dfsIslands(grid, x + 1, y, m, n);
        }
        if (x - 1 >= 0) {
          dfsIslands(grid, x - 1, y, m, n);
        }
        if (y + 1 < n) {
          dfsIslands(grid, x, y + 1, m, n);
        }
        if (y - 1 >= 0) {
          dfsIslands(grid, x, y - 1, m, n);
        }
        return true;
      }
      return false;
    }
};