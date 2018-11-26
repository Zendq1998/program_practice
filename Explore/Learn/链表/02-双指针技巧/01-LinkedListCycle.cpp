/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

class Solution {
public:
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
    };

    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *fp = head;
        ListNode *lp = head;
        while (fp && fp->next) {
            fp = fp->next->next;
            lp = lp->next;
            if (fp == lp) return true;
        }
        return false;
    }
};