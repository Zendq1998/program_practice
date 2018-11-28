/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *newListP = dummy;
        RandomListNode *oldListP = head;
        unordered_map<RandomListNode*, RandomListNode*> copyMap;
        while (oldListP) {
            newListP->next = new RandomListNode(oldListP->label);
            newListP->next->random = oldListP->random;
            copyMap[oldListP] = newListP->next;
            oldListP = oldListP->next;
            newListP = newListP->next;
        }
        newListP = dummy->next;
        while(newListP) {
            if (newListP->random) {
                newListP->random = copyMap[newListP->random];
            }
            newListP = newListP->next;
        }
        return dummy->next;
    }
};