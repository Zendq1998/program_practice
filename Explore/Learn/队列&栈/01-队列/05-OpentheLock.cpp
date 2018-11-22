/*
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int openLock(vector<string>& deadends, string target) {
    const string start = "0000";
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count(start)) return -1;
    
    queue<string> q;
    unordered_set<string> visited;
    visited.insert(start);
    
    int steps = 0;
    q.push(start);
    while(!q.empty()) {
      steps += 1;
      const int size = q.size();
      for (int i = 0; i < size; i += 1) {
        const string curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i += 1) {
          for (int j = -1; j <= 1; j += 2) {
            string next = curr;
            next[i] = (next[i] - '0' + j + 10) % 10 + '0';
            if (next == target) return steps;
            if (dead.count(next) || visited.count(next)) continue;
            q.push(next);
            visited.insert(next);
          }
        }
      }
    }
    return -1;
  }
};