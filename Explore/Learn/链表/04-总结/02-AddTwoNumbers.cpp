/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *re = dummy;
        bool over = false;
        ListNode *p = l1, *q = l2;
        while(p || q) {
            int sum = (p ? p->val : 0) + (q ? q->val: 0);
            sum += over ? 1 : 0;
            if (sum >= 10) {
                over = true;
                sum -= 10;
            } else {
                over = false;
            }
            ListNode *node = new ListNode(sum);
            re->next = node;
            re = re->next;
            if(p) p = p->next;
            if(q) q = q->next;
        }
        if (over) {
            ListNode *node = new ListNode(1);
            re->next = node;
        }
        return dummy->next;
    }
};