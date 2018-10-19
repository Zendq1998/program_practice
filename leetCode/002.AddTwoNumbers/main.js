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
function ListNode(val) {
    this.val = val
    this.next = null
}

var addTwoNumbers = function(l1, l2) {
    var p = l1,
        q = l2,
        flag = 0,
        arr = []
    while(p || q || flag) {
        var e1 = p===null?0:p.val
        var e2 = q===null?0:q.val
        var e = e1 + e2 + flag
        if(e >= 10) {
            flag = 1
        }
        else {
            flag = 0
        }
        arr.push(e%10)
        p = p===null?null:p.next
        q = q===null?null:q.next
    }
    return arr
}; 