/**
 * @param {number} num
 * @return {string}
 */

function letterRepeat(a, n) {
  let str = '';
  for(let i=0; i < n; i++) {
    str += a;
  }
  return str;
}

function intToRomanUnit(n,i) {
  const map = ['M', 'D', 'C', 'L', 'X', 'V', 'I']
  if (i == 0) {
    return n ? letterRepeat('M', n) : ''
  }
  else {
    if (n <= 0 || n >= 10) {
      return '';
    }
    else if (n < 4) {
      return letterRepeat(map[i*2], n)
    }
    else if (n == 4) {
      return map[i*2] + map[i*2-1]
    }
    else if (n < 9) {
      return map[i*2-1] + letterRepeat(map[i*2], n - 5)
    }
    else {
      return map[i*2] + map[i*2-2]
    }
  }
}

 
var intToRoman = function(num) {
  let num_t = num
  let result = ''
  for(let div = 1000, i = 0; div >= 1; div /= 10, i ++) {
    let n = Math.floor(num_t/div)
    num_t %= div
    result += intToRomanUnit(n, i)
  }
  return result
};