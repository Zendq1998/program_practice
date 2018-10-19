/**
 * @param {string[]} strs
 * @return {string}
 */

function minLenth(totoalMin, currentStr) {
  return totoalMin <= currentStr.length ? totoalMin : currentStr.length;
}

function isSame(i, num) {
  return function(temp) {
    return num === temp[i];
  }
}

var longestCommonPrefix = function(strs) {
    if (!strs.length) {
      return ""
    }
    let result = "";
    const minL = strs.reduce(minLenth,strs[0].length);
    for(let i=0;i<minL;i++) {
      let num = strs[0][i]
      if (strs.every(isSame(i, num))) {
        result += num;
      }
      else break;
    }
    return result;
};
