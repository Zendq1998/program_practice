/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (43.20%)
 * Total Accepted:    411.3K
 * Total Submissions: 952.1K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
  if (l1 === null) {
    return l2
  }
  else if (l2 === null) {
    return l1
  }
  else if (l1.val > l2.val) {
    const l3 = l2
    l2 = l1
    l1 = l3
  }
  let currentNode1 = l1
  let currentNode2 = l2
  while (currentNode2 !== null) {
    if (currentNode1 === null) {
      currentNode1 = currentNode2
      break
    }
    else if (currentNode2.val >= currentNode1.val && currentNode1.next && currentNode2.val < currentNode1.next.val) {
      const tempNode = {val: currentNode2.val, next: currentNode1.next}
      currentNode1.next = tempNode
      currentNode1 = currentNode1.next
      currentNode2 = currentNode2.next
    }
    else if(currentNode1.next === null) {
      currentNode1.next = currentNode2
      break
    } 
    else {
      currentNode1 = currentNode1.next
    }
  }
  return l1
};
