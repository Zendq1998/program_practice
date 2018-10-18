/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var rev = 0
    do {
        rev = rev*10 + x%10
        x = parseInt(x/10)
    }while(x!=0)
    if(rev < -2147483648 || rev > 2147483647) {
        return 0
    }
    return rev
};