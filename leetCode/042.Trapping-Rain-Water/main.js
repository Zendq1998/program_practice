/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
  let stk = []
  let result = 0
  for (let i = 0; i < height.length; i += 1) {
    if (stk.length === 0 || stk[0] > height[i]) {
      stk.push(height[i])
    }
    else {
      while (stk.length > 0) {
        result += stk[0] - stk.pop()
      }
      stk.pop()
      i -= 1
    }
  }
  let stk1 = []
  console.log(stk)
  for(let i = stk.length - 1; i >= 0; i -= 1) {
    if (stk1.length === 0 || stk1[0] > stk[i]) {
      stk1.push(stk[i])
    }
    else {
      while (stk1.length > 0) {
        result += stk1[0] - stk1.pop()
      }
      stk1.pop()
      i += 1
    }
  }
  return result
};