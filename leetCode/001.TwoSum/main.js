/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */



var twoSum = function(nums, target) {
    //var len = nums.length
    var result = []
    nums.every((el_a,index_a,nums_a) => {
        let index_b = nums_a.indexOf(target - el_a)
        if(index_b != -1 && index_b != index_a) {
            result.push(index_a)
            result.push(index_b)
            return false
        }
        else
            return true
    })
    return result
};

var nums = [3,2,4]

console.log(twoSum(nums,6))