/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x<0) {
        return false
    }
    var arr = []
    var f = x
    while(f>0) {
        arr.push(f%10)
        f = parseInt(f/10)
    }
    while(arr.length) {
        if(arr[0] != arr[arr.length-1]) {
            return false
        }
        else {
            arr.pop()
            arr.shift()
        }
    }
    return true
};
