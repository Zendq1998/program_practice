/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int len = (int)sqrt(n);
        vector<int> given;
        struct Node {
            int sum;
            int startIndex;
        };
        queue<Node> q;
        unordered_set<int> visited;
        for (int i = 1; i <= len; i += 1) {
            int num = i * i;
            given.push_back(num);
            visited.insert(num);
            q.push({(int)num, (int)i - 1 });
        }
        int steps = 0;
        int currSize;
        Node curr;
        while (!q.empty()) {
            steps += 1;
            currSize = q.size();
            for (int i = 0; i < currSize; i += 1) {
                curr = q.front();
                if (curr.sum == n) return steps;
                if (curr.sum < n) {
                    for (int j = curr.startIndex; j < len; j += 1) {
                        if (visited.count(curr.sum + given[j])) continue;
                        q.push({curr.sum + given[j], j});
                        visited.insert(curr.sum + given[j]);
                    }
                }
                q.pop();
            }
        }
    }
};