/*
Given a binary tree, return the inorder traversal of its nodes' values.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re;
        stack<TreeNode*> s;
        unordered_set<TreeNode*> map;
        if (!root) {
            return re;
        }
        s.push(root);
        while (!s.empty()) {
            TreeNode* curr = s.top();
            if (!curr->left || map.count(curr->left)) {
                re.push_back(curr->val);
                map.insert(curr);
                s.pop();
                if (curr->right) {
                    s.push(curr->right);
                }
            }
            if (curr->left && !map.count(curr->left)) {
                s.push(curr->left);
            }
        }
        return re;
    }
};