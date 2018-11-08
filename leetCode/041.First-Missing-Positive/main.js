/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
  if (nums.length === 0) return 1
  let arr = []
  for (let i = 0; i < nums.length; i += 1) {
    if (nums[i] > 0) {
      arr[nums[i]] = 1
    }
  }
  for (var i = 1; i < arr.length; i += 1) {
    if (arr[i] == undefined) {
      return i
    }
  }
  return i
};