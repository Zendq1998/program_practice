/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (50.61%)
 * Total Accepted:    254.8K
 * Total Submissions: 503.5K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const result = []
    var digui = function(str, left, right) {
      if (left === right && left === 0) {
        result.push(str)
      }
      else if (left === right) {
        digui(str + '(', left - 1, right)
      }
      else {
        if (left > 0) {
          digui(str + '(', left - 1, right)
        }
        if (right > 0) {
          digui(str + ')', left, right - 1)
        }
      }
    }
    digui('', n, n)
    return result
};
