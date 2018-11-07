/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
  let nextSay = function (say) {
      let result = ''
      let c = say[0], n = 1
      for (let i = 1; i < say.length; i += 1) {
          if (say[i] === c) {
              n += 1
          }
          else {
              result += '' + n + c
              c = say[i]
              n = 1
          }
      }
      result += '' + n + c
      return result
  }
  let findSay = function (n) {
      if (n === 1) {
          return '1'
      }
      else {
          return nextSay(findSay(n-1))
      }
  }
  return findSay(n)
};