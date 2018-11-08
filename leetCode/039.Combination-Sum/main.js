/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
  if (candidates.length === 0 || candidates == null) return []
  candidates.sort((a, b) => a - b)
  let result = []
  let findCombinationSum = function (subCom, startIndex, target) {
    if (target === 0) {
      result.push(subCom)
      return
    }
    for (let i = startIndex; i < candidates.length; i += 1) {
      if (candidates[i] > target) {
        break
      }
      let subComTemp = subCom.concat(candidates[i])
      findCombinationSum(subComTemp, i, target - candidates[i])
    }
  }
  findCombinationSum([], 0, target)
  return result
};