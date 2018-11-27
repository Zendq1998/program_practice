/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
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
    
    ListNode *detectCycle(ListNode *head) {
        ListNode *lp = head;
        ListNode *fp = head;
        ListNode *p_in_circle = NULL;
        while(fp && fp->next) {
            lp = lp->next;
            fp = fp->next->next;
            if (lp == fp) {
                p_in_circle = lp;
                break;
            }
        }
        if (!p_in_circle) return NULL;
        ListNode *hp = head;
        ListNode *cp = p_in_circle;
        while(hp != cp) {
            cp = cp->next;
            while(cp != p_in_circle) {
                if (hp == cp) break;
                cp = cp->next;
            }
            if (hp == cp) break;
            hp = hp->next;
        }
        return cp;
    }
};