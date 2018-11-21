#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int openLock(vector<string>& deadends, string target) {
    Target node = {target, 1};
    queue<Target> Q;
    Q.push(node);
    while (!Q.empty()) {
      Target temp = Q.front();
      if (temp.str == target) return temp.distance;
      Q.pop();
      for (int i = 0; i < 4; i += 1) {
        string str_t = temp.str;
        string str_t1 = str_t;
        if (str_t[i] == '9') {
          str_t[i] = '0';
        } else {
          str_t[i] += 1;
        }
        if (str_t1[i] == '0') {
          str_t1[i] = '9';
        } else {
          str_t1[i] -= 1;
        }
        if (!ifDead(deadends, str_t) && !ifSearched(str_t)) {
          Target node = {str_t, temp.distance + 1};
          Q.push(node);
        }
        if (!ifDead(deadends, str_t1) && !ifSearched(str_t1)) {
          Target node = {str_t1, temp.distance + 1};
          Q.push(node);
        }
      }
    }
    return -1;
  }

private:
  struct Target {
    string str;
    int distance;
  };
  vector<string> Set;
  bool ifDead(vector<string>& deadends, string str) {
    int len = deadends.size();
    for (int i = 0; i < len; i += 1) {
      if (deadends[i] == str) return true;
    }
    return false;
  }
  bool ifSearched(string str) {
    for (int i = 0; i < Set.size(); i += 1) {
      if (Set[i] == str) return true;
    }
    Set.push_back(str);
    return false;
  }
};