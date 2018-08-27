/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var threeSum = function(nums) {
  let result = []
  nums.sort((a, b) => {return a-b})
  console.log(nums)
  for(let i = 0; i < nums.length-2; i++) {
    if (nums[i] > 0) break;
    let j = i + 1
    let k = nums.length - 1
    while(j < k) {
      let sum = nums[j] + nums[k]
      if (nums[i] + sum == 0) {
        let arr = [nums[i], nums[j], nums[k]]
        result.push(arr)
        j ++
        k --
        while(j < k && nums[j] === nums[j-1]) j++
        while(j < k && nums[k] === nums[k+1]) k++
      }
      else if(nums[i] + sum < 0) {
        j ++
      }
      else {
        k --
      }
    }
  }
  return result
};

let arr = [-1, 0, 1, 2, -1, -4]

threeSum(arr)
