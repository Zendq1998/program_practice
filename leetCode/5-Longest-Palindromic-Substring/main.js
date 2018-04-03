/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let sLen = s.length
    if(sLen == 0) {
        return ""
    }
    if(sLen == 1) {
        return s
    }
    if(sLen == 2) {
        if(s[0] == s[1]) {
            return s
        }
        else {
            return ""
        }
    }

    let palindLen = 0,
        palindStart = 0,
        palindEnd = 0
    for(let i=0;i<sLen;i++) {
        // odd
        let j = 1
        while(i-j>=0 && i+j <= sLen-1) {
            if(s[i-j] != s[i+j]) {
                break
            }
            else {
                j++
            }
        }
        j--
        // even
        let m = i,
            n = i+1
        while(m>=0 && n<=sLen-1) {
            if(s[m] != s[n]) {
                break
            }
            else {
                m--
                n++
            }
        }
        m++
        n--
        // console.log(s.slice(m,n+1))
        // odd longer
        if(j*2+1 >= n-m+1) {
            if(j*2+1 > palindLen) {
                palindLen = j*2+1
                palindStart = i-j
                palindEnd = i+j
            }
        }
        
        // even longer
        else {
            if(n-m+1 > palindLen) {
                palindLen = n-m+1
                palindStart = m
                palindEnd = n
            }
        }
    }

    return s.slice(palindStart,palindEnd+1)
};
console.log("haha")
console.log(longestPalindrome("cbbd"))