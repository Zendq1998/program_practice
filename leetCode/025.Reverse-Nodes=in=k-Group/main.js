/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
	if (head === null || head.next === null) {
			return head
	}
	var nodeArr = []
var HeadNode = {}
var tempNode = head
while(tempNode != null) {
	nodeArr.push(tempNode)
	tempNode = tempNode.next
}
var nodeArr2 = []
while(nodeArr.length >= k) {
			var arr1 = nodeArr.splice(0, k).reverse()
			// console.log({nodeArr})
			// console.log(arr1)
	nodeArr2 = nodeArr2.concat(arr1)
}
if(nodeArr.length) {
	nodeArr2 = nodeArr2.concat(nodeArr)
}
HeadNode = nodeArr2[0]
tempNode = nodeArr2[0]
for (var i = 0; i < nodeArr2.length; i += 1) {
	if(i === nodeArr2.length - 1) {
		tempNode.next = null
	}
	else {
		tempNode.next = nodeArr2[i+1]
		tempNode = tempNode.next
	}
}
	// console.log(HeadNode)
return HeadNode
};