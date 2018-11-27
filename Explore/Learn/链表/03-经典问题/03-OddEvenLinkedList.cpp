/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
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
    ListNode* oddEvenList(ListNode* head) {
        if (!(head && head->next && head->next->next)) return head;
        ListNode *lp = head, *fp = head->next, *op = head->next;
        while(fp && fp->next) {
            ListNode *deletedNode = fp->next;
            fp->next = fp->next->next;
            deletedNode->next = op;
            lp->next = deletedNode;
            lp = lp->next;
            fp = fp->next;
        }
        return head;
    }
};