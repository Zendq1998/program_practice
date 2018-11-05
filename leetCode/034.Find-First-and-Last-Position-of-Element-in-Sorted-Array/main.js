/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
  let left = 0, right = nums.length - 1
  let mid = parseInt((left + right)/2)
  let someIndex = -1
  while(left <= right) {
      if (nums[mid] === target) {
          someIndex = mid
          break
      }
      else if (nums[mid] > target) {
          right = mid - 1
      }
      else {
          left = mid + 1
      }
      mid = parseInt((left+right)/2)
  }
  if (someIndex === -1) {
      return [-1, -1]
  }
  else {
      let start = someIndex, end = someIndex
      while (start - 1 >= 0 && nums[start - 1] === target) {
          start -= 1
      }
      while (end + 1 <= nums.length - 1 && nums[end + 1] === target) {
          end += 1
      }
      return [start, end]
  }
};