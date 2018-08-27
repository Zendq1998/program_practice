/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var threeSum = function(nums) {
    let result = []
    let result_str = []
    nums.sort((a, b) => {return a-b})
    console.log(nums)
    for(let i = 0; i < nums.length-2; i++) {
      if (nums[i] > 0) break;
      result_str[nums[i]] = result_str[nums[i]] || []
      let j = i + 1
      let k = nums.length - 1
      while(j < k) {
        let sum = nums[j] + nums[k]
        if (nums[i] + sum == 0) {
          let arr = [nums[i], nums[j], nums[k]]
          if (result_str[nums[i]].indexOf(nums[j]) < 0) {
            result.push(arr)
            result_str[nums[i]].push(nums[j])
            console.log(nums[j],result_str)
          }
          j ++;
          k --;
        }
        else if(nums[i] + sum < 0) {
          j ++
        }
        else {
          k --
        }
      }
    }
    console.log(result)
    return result
};

let arr = [-1, 0, 1, 2, -1, -4]

threeSum(arr)
