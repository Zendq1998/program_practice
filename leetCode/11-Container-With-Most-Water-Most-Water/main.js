/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let max = 0
    const len = height.length
    for (let l = 0;l < len - 1;l ++) {
      for (let r = l + 1;r < len;r ++) {
        let tempArea
        if (height[l] < height[r]) {
          tempArea = height[l] * (r - l)
        }
        else {
          tempArea = height[r] * (r - l)
        }
        if (tempArea > max) {
          max = tempArea
        }
      }
    }
    return max
}