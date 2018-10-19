/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let Sub = ""
    let start = 0
    let longestLen = 0
    for(let i=0;i<s.length;i++) {
        let newIndex = Sub.indexOf(s[i])
        if(newIndex == -1) {
            Sub += s[i]
        }
        else {
            if(Sub.length > longestLen) {
                longestLen = Sub.length
            }
            start = newIndex + 1
            Sub = Sub.substring(start) + s[i]
            // console.log(Sub)
        }
    }
    if(Sub.length > longestLen) {
                longestLen = Sub.length
            }
    return longestLen
};