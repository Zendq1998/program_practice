/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
  let result = []
  candidates.sort((a, b) => a - b)
  let combination = function (subSet, maxIndex, target) {
      for (let i = maxIndex; i < candidates.length; i += 1) {
          let subSetTemp = subSet.concat()
          // console.log({i, subSet, target})
          if (candidates[i] < target) {
              subSetTemp.push(candidates[i])
              combination(subSetTemp, i, target - candidates[i])
          }
          else if (candidates[i] === target) {
              // console.log({can:candidates[i], target})
              subSet.push(candidates[i])
              result.push(subSet)
              return
          }
      }
  }
  combination([], 0, target)
  return result
};