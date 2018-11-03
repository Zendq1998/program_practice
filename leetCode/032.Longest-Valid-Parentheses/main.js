/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
  let stk = []
  let start = 0
  let max = 0
  for (let i = 0; i < s.length; i += 1) {
      
      if (s[i] === '(') {
          stk.push(i)
      }
      if (s[i] === ')') {
          if (stk.length === 0) {
              start = i + 1
          }
          else {
              stk.pop()
              if (stk.length === 0) {
                  max = Math.max(max, i - start + 1)
              }
              else {
                  max = Math.max(max, i - stk[stk.length - 1])
              }
          }
      }
  }
  return max
};