/**
 * @param {string} digits
 * @return {string[]}
 */

const digitMap = [
  [],[],
  ['a','b','c'],
  ['d','e','f'],
  ['g','h','i'],
  ['j','k','l'],
  ['m','n','o'],
  ['p','q','r','s'],
  ['t','u','v'],
  ['w','x','y','z']
]

function twoArrayGroup(arr1, arr2) {
  let result = []
  arr1.forEach(el1 => {
    arr2.forEach(el2 => {
      result.push(el1+el2)
    })
  })
  return result
}

var letterCombinations = function(digits) {
    if (!digits) {
      return []
    }
    if (digits.length == 1) {
      return digitMap[digits]
    }
    const letterArrs = digits.split('').map(el => {return digitMap[parseInt(el)]})
    return letterArrs.reduce(twoArrayGroup)
};

console.log(letterCombinations("234"))