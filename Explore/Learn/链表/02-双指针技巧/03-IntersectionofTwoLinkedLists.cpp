/*
Write a program to find the node at which the intersection of two singly linked lists begins.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_a = 0, len_b = 0;
        ListNode *p_a = headA, *p_b = headB;
        while(p_a) {
            p_a = p_a->next;
            len_a += 1;
        }
        while(p_b) {
            p_b = p_b->next;
            len_b += 1;
        }
        p_a = headA;
        p_b = headB;
        int dis = 0;
        cout << endl;
        while (len_a - len_b - dis > 0) {
            p_a = p_a->next;
            dis += 1;
        }
        dis = 0;
        while (len_b - len_a - dis > 0) {
            p_b = p_b->next;
            dis += 1;
        }
        cout << endl;
        while(p_a && p_b) {
            if (p_a == p_b) return p_a;
            p_a = p_a->next;
            p_b = p_b->next;
        }
        return NULL;
    }
};