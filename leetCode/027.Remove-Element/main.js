/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
  for (let i = 0; i < nums.length;) {
    const el = nums[i];
    if (el === val) {
      nums.splice(i, 1)
      continue
    }
    i += 1
  }
  return nums.length
};