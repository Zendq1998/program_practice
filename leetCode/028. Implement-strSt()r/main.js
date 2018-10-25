/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
  var len1 = haystack.length
  var len2 = needle.length
  for (let i = 0; i < len1 - len2 + 1; i += 1) {
    let flag = 1
    for (let j = 0; j < len2; j += 1) {
      if (haystack[i+j] !== needle[j]) {
        flag *= 0
        break
      }
    }
    if (flag === 1) {
      return i
    }
  }
  return -1
};