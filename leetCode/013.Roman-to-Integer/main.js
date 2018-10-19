/**
 * @param {string} s
 * @return {number}
 */
const map = {
  'I': 1,
  'IV': 4,
  'V': 5,
  'IX': 9,
  'X': 10,
  'XL': 40,
  'L': 50,
  'XC': 90,
  'C': 100,
  'CD': 400,
  'D': 500,
  'CM': 900,
  'M': 1000
}

var romanToInt = function(s) {
    let result = 0
    let temp
    for(let i=0; i < s.length;) {
      if (i < s.length-1) {
        if (map[s[i]+s[i+1]]) {
          result += map[s[i]+s[i+1]]
          i += 2
        }
        else {
          result += map[s[i]]
          i ++
        }
      }
      else {
        result += map[s[i]]
        i ++
      }
    }
    return result
};
