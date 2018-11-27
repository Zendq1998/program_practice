/*
Remove all elements from a linked list of integers that have value val.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        while(p && p->next) {
            if((p->next)->val == val) {
                ListNode *deletedNode = p->next; 
                p->next = p->next->next;
                delete deletedNode;
            }
            else p = p->next;
        }
        return dummy->next;
    }
};