/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(num1, num2) {
  if (num1 === '0' || num2 === '0') return '0'
  let multiplySingle = function (num, s) {
    let result = [0]
    for (let i = num.length - 1; i >= 0; i -= 1) {
      let n = num[i] * s
      if ((result[0] + n % 10) >= 10) {
        result[0] = (result[0] + n % 10) % 10
        result.unshift(1)
      }
      else {
        result[0] += n % 10
        result.unshift(0)
      }
      result[0] += Math.floor(n / 10)
    }
    return result
  }
  
  let addTowNumArr = function (result, arr) {
    result.unshift(0)
    for (let i = arr.length - 1; i >= 0; i -= 1) {
      if (result[i] + arr[i] >= 10) {
        result[i] = (result[i] + arr[i]) % 10
        result[i - 1] += 1
      }
      else result[i] += arr[i]
    }
    return result
  }

  let arrPlus = []
  for (let i = num2.length - 1; i >= 0; i -= 1) {
    arrPlus.push(multiplySingle(num1, num2[i]))
  }
  let resultArr = arrPlus.reduce(addTowNumArr)
  if (resultArr[0] === 0) resultArr.shift()
  return resultArr.reduce((a, b) => a + b, '')
};