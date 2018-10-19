/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    nums.sort((a, b) => {return a-b})
    let closet = nums[0] + nums[1] + nums[nums.length-1]
    for(let i=0;i<nums.length-2;i++) {
      let j = i+1
      let k = nums.length-1
      while(j < k) {
        let target_temp = nums[i] + nums[j] + nums[k]
        if (target_temp == target) {
          return target_temp
        }
        if (Math.abs(target - closet) > Math.abs(target - target_temp)) {
          closet = target_temp
        }
        if (target_temp > target) {
          k --
        }
        if (target_temp < target) {
          j ++
        }
      }
    }
    return closet
};

console.log(threeSumClosest([-1, 2, 1, -4],1))