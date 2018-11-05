/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
  let left = 0, right = nums.length - 1
  let mid
  while (left <= right) {
      mid = parseInt((left + right)/2)
      if (nums[mid] === target) {
          return mid
      }
      else if (nums[mid] > target) {
          right = mid - 1
      }
      else {
          left = mid + 1
      }
  }
  if (nums[mid] > target) {
      return mid
  }
  else {
      return mid + 1
  }
};