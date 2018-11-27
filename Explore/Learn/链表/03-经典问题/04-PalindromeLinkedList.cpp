/*
Given a singly linked list, determine if it is a palindrome.
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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        int len = 0;
        ListNode *p = head;
        while(p) {
            p = p->next;
            len += 1;
        }
        if (len == 1) return true;
        p = head;
        for (int i = 0; i < len / 2 - 1; i += 1) {
            ListNode *deletedNode = p->next;
            p->next = p->next->next;
            deletedNode->next = head;
            head = deletedNode;
        }
        if (len % 2) p = p->next->next;
        else p = p->next;
        ListNode *q = head;
        while(p) {
            if (q->val != p->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};