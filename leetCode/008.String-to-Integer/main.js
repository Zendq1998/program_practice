/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    var base = 0,
        sign = 1,
        i = 0;
    while(str[i] == ' '){
        i++
        console.log(i)
    }
    if(str[i]=='-'||str[i]=='+') {
        sign = str[i++]=='-'?(-1):1
    }
    for(;i<str.length;i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            base = base*10 + parseInt(str[i])
        }
        else {
            break
        }
    }
    if(base*sign>2147483647) {
        return 2147483647
    }
    if(base*sign<-2147483648) {
        return -2147483648
    }
    return base*sign
};
myAtoi("")