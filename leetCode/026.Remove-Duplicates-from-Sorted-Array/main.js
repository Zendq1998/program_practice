/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
  for (let i = 0; i < nums.length;) {
    const el = nums[i];
    if (i > 0) {
      if (nums[i] === nums[i-1]) {
        nums.splice(i, 1)
        continue
      }
    }
    i += 1
  }
  return nums.length
};