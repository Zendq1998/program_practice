/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 * Backtracking
 */
var isMatch = function(s, p) {
  var i = s.length - 1, j = p.length - 1
  var myMatch = function(s, i, p, j) {
    console.log(s[i], p[j])
    if (j < 0) {
      return i === -1
    }
    if (p[j] === '*') {
      // p[j]是'*', 比较p[j-1]和s
      if (i > -1 && (s[i] === p[j-1] || p[j-1] === '.')) {
        if (myMatch(s, i-1, p, j)) {
          return true
        }
      }
      console.log({'i': s[i], 'j-2': p[j-2]})
      return myMatch(s, i, p, j-2)
    }
    else {
      // 不是'*'
      return (s[i] === p[j] || p[j] === '.') && myMatch(s, i-1, p, j-1)
    }
  }
  return myMatch(s, i, p, j)
};

var ismatch = isMatch("aa", "aa*")
console.log(ismatch)