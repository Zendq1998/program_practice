/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (34.62%)
 * Total Accepted:    404.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  const bracketMap = {
    '{': {
      index: 0,
      map: '}'
    },
    '}': {
      index: 1,
      map: '{'
    },
    '(': {
      index: 0,
      map: ')'
    },
    ')': {
      index: 1,
      map: '('
    },
    '[': {
      index: 0,
      map: ']'
    },
    ']': {
      index: 1,
      map: '['
    }
  }
  let stack = []
  for (let i = 0; i < s.length; i += 1) {
    const el = s[i];
    if (bracketMap[el].index === 0) {
      stack.push(el)
    }
    else {
      if (bracketMap[el].map === stack[stack.length-1]) {
        stack.pop()
      }
      else {
        return false
      }
    }
  }
  if (stack.length) {
    return false
  }
  return true
};
