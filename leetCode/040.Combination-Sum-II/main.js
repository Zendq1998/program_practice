/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
  if (candidates.length === 0 || candidates == null) return []
  candidates.sort((a, b) => a - b)
  let result = []
  let findCombinationSum2 = function (comSub, startIndex, target) {
    if (target === 0) {
      if (result.indexOf(comSub) === -1) {
        result.push(comSub)
      }
      return
    }
    for (let i = startIndex; i < candidates.length; i += 1) {
      if (candidates[i] > target) {
        break
      }
      if (candidates[i] === candidates[i-1] && i > startIndex) continue
      let comSubTemp = comSub.concat(candidates[i])
      findCombinationSum2(comSubTemp, i + 1, target - candidates[i])
    }
  }
  findCombinationSum2([], 0, target)
  return result
};