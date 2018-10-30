/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
  if (words.length === 0) {
      return []
  }
  const result = []
  let wordsMap = {}
  words.forEach(el => {
      if (wordsMap[el]) {
          wordsMap[el] += 1
      }
      else {
          wordsMap[el] = 1
      }
  })
  const wordsMapTemp = {}
  words.forEach(el => {
      wordsMapTemp[el] = wordsMap[el]
  })
  const len = words[0].length
  for (let i = 0; i < s.length - len + 1; i += 1) {
      let sTemp = s.substr(i, len)
      let j = i
      while (wordsMap[sTemp]) {
          wordsMap[sTemp] -= 1
          j += len
          sTemp = s.substr(j, len)
      }
      let isMatch = Object.values(wordsMap).every(el => el === 0)
      if (isMatch) {
          result.push(i)
      }
      words.forEach(el => {
          wordsMap[el] = wordsMapTemp[el]
      })
      
  }
  return result
};