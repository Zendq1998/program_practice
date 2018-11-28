/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int len = 0;
        ListNode *p = head;
        while(p) {
            len += 1;
            p = p->next;
        }
        int n = k % len;
        ListNode *fp = head, *lp = head;
        for (int i = 0; i < n; i += 1) {
            fp = fp->next;
        }
        while(fp->next) {
            fp = fp->next;
            lp = lp->next;
        }
        fp->next = head;
        head = lp->next;
        lp->next = NULL;
        return head;
    }
};