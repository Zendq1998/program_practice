/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    const result = []
    if (nums.length < 4) {
        return result
    }
    nums.sort((a, b) => {return a-b})
    for (let i = 0; i < nums.length - 3; i++) {
        if (i > 0 && nums[i] === nums[i-1]) {
            continue
        }
        for (let j = i + 1; j < nums.length - 2; j++) {
            if (j > i + 1 && nums[j] === nums[j-1]) {
                continue
            }
            let low = j + 1, high = nums.length - 1
            while (low < high) {
                let sum = nums[i] + nums[j] + nums[low] + nums[high]
                if (sum === target) {
                    result.push([nums[i], nums[j], nums[low], nums[high]])
                    while (low < high && nums[low] === nums[low+1]) {
                        low += 1
                    }
                    while (low < high && nums[high] === nums[high-1]) {
                        high -= 1
                    }
                    low += 1
                    high -= 1
                }
                else if (sum > target) {
                    high -= 1
                }
                else {
                    low += 1
                }
            }
        }
    }
    return result
};