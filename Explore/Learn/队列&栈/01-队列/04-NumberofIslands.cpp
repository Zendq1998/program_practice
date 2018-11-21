/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/* 队列 广度优先 */
class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
      if (grid.empty()) return 0;
      int m = grid.size();
      int n = grid[0].size();
      int re = 0;
      for (int i = 0; i < m; i += 1) {
        for (int j = 0; j < n; j += 1) {
          if(bfs(i, j, grid, m, n)) {
            re += 1;
          }
        }
      }
      return re;
    }
private:
  bool bfs(int x, int y, vector<vector<char> >& grid, int m, int n) {
    struct Point
    {
        int x;
        int y;
    };
    if (grid[x][y] == '0') return false;
    queue<Point> queue;
    Point node = {x, y};
    queue.push(node);
    while(!queue.empty()) {
      int i = queue.front().x, j = queue.front().y;
      queue.pop();
      if (i - 1 >= 0 && grid[i-1][j] == '1') {
        Point node = {i - 1, j};
        grid[i-1][j] = '0';
        queue.push(node);
      }
      if (i + 1 < m && grid[i+1][j] == '1') {
        Point node = {i + 1, j};
        grid[i+1][j] = '0';
        queue.push(node);
      }
      if (j - 1 >= 0 && grid[i][j-1] == '1') {
        Point node = {i, j - 1};
        grid[i][j-1] = '0';
        queue.push(node);
      }
      if (j + 1 < n && grid[i][j+1] == '1') {
        Point node = {i, j + 1};
        grid[i][j+1] = '0';
        queue.push(node);
      }
    }
    return true;
  }
};

/* 递归、深度优先 */
class Solution1 {
public:
    int numIslands(vector<vector<char> >& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int y = 0; y < m; y += 1) {
            for (int x = 0; x < n; x += 1) {
                ans += grid[y][x] - '0';
                dfs(grid, x, y, m, n);
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<char> >& grid, int x, int y, int m, int n) {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == '0') return;
        grid[y][x] = '0';
        dfs(grid, x+1, y, m, n);
        dfs(grid, x-1, y, m, n);
        dfs(grid, x, y+1, m, n);
        dfs(grid, x, y-1, m, n);
    }
};

