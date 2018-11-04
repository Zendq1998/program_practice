/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
  if (nums.length <= 3) {
      return nums.indexOf(target)
  }
  if (target === nums[0]) {
      return 0
  }
  let left = 0, right = nums.length - 1
  let mid = parseInt((left + right)/2)
  while (true) {
      if (mid === left || mid === right) {
          if (nums[right] < nums[right - 1]) {
              if (target === nums[right]) {
                  return right
              }
              if (target > nums[0]) {
                  left = 0
                  right -= 1
              }
          }
          else {
              left = 0
              right = nums.length - 1
          }
          break
      }
      if (nums[mid] < nums[mid-1]) {
          if (target > nums[0]) {
              left = 0
              right = mid - 1
          }
          else {
              left = mid
              right = nums.length - 1
          }
          break
      }
      if (nums[mid] > nums[left]) {
          left = mid
      }
      if (nums[mid] < nums[left]) {
          right = mid
      }
      mid = parseInt((left + right)/2)
  }
  mid = parseInt((left + right)/2)
  while(left <= right) {
      if (nums[mid] === target) {
          return mid
      }
      else if (nums[mid] > target) {
          right = mid - 1
      }
      else {
          left = mid + 1
      }
      mid = parseInt((left + right)/2)
  }
  return -1
};