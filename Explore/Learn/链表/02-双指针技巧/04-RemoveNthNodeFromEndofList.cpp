/*
Given a linked list, remove the n-th node from the end of list and return its head.
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

// O(2n)
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *p = head;
        while(p) {
            p = p->next;
            len += 1;
        }
        if (n == len) {
            p = head->next;
            delete head;
            return p;
        }
        else {
            int m = len - n - 1;
            p = head;
            while (m--) {
                p = p->next;
            }
            ListNode* deletedNode = p->next;
            p->next = p->next->next;
            delete deletedNode;
            return head;
        }
    }
};

// O(n)
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fp = head, *lp = head;
    int m = n;
    while(m--) {
      fp = fp->next;
    }
    if (fp == NULL) {
      lp = head->next;
      delete head;
      return lp;
    }
    else {
      while(fp->next) {
        fp = fp->next;
        lp = lp->next;
      }
      ListNode *deletedNode = lp->next; 
      lp->next = lp->next->next;
      delete deletedNode;
      return head;
    }
  }
};