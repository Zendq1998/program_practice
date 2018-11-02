/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
  if (nums.length > 1) {
      let sorted = true
      let leftIndex, rightIndex
      for (let i = nums.length - 1; i > 0; i -= 1) {
          if (nums[i] > nums[i-1]) {
              sorted = false
              leftIndex = i - 1
              break
          }
      }
      if (sorted) {
          nums.sort((a, b) => a - b)
      }
      else {
          for (let i = nums.length - 1; i > leftIndex; i -= 1) {
              if (nums[i] > nums[leftIndex]) {
                  rightIndex = i
                  let t = nums[leftIndex]
                  nums[leftIndex] = nums[rightIndex]
                  nums[rightIndex] = t
                  break
              }
          }
          let t
          for (let i = leftIndex + 1; i < nums.length - 1; i += 1) {
              for (let j = i + 1; j < nums.length; j += 1) {
                  if (nums[j] < nums[i]) {
                      t = nums[j]
                      nums[j] = nums[i]
                      nums[i] = t
                  }
              }
          }
      }
  }
};