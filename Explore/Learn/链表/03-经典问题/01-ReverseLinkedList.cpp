/*
Reverse a singly linked list.
A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        return reverseListRecurse(head, head);
    }
private:
    ListNode* reverseListRecurse(ListNode *currHead, ListNode* oldHead) {
        if (oldHead->next == NULL) return currHead;
        else {
            ListNode *newHead = oldHead->next;
            oldHead->next = oldHead->next->next;
            newHead->next = currHead;
            return reverseListRecurse(newHead, oldHead);
        }
    }
};