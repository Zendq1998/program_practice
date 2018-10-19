/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    function Slice(str,rep) {
        this.str = str
        this.rep = rep
    }
    
    function nodeToSlice(str) {
        var arr = []
        if(str.length == 1) {
            arr.push(new Slice(str, true))
            return arr
        }
        else if(str.length > 1){
            arr.push(new Slice(str.slice(0,str.length-1), false))
            arr.push(new Slice(str[str.length-1] ,true))
            return arr
        }
    }
    var arr = []
    if(p[p.length-1] == '*') {
        p.split('*').forEach((el,index) => {
            arr.push(nodeToSlice(el))
        });
        arr.pop()
    }
    else {
        p.split('*').forEach((el,index,arrt) => {
            if(index == arrt.length-1) {
                let arrt1 = []
                arrt1.push(new Slice(el,false))
                arr.push(arrt1)
            }
            else {
                arr.push(nodeToSlice(el))
            }
            
        }); 
    }
    console.log(arr)
    var k = 0 // s的指针
    for(let i=0;i<arr.length;i++) {
        for(let j=0;j<arr[i].length;j++) {
            if(!arr[i][j].rep) {
                // false
                for(let m=0;m<arr[i][j].str.length;m++) {
                    console.log(s[k]," ",arr[i][j].str[m])
                    if(s[k] != arr[i][j].str[m] && arr[i][j].str[m] != '.') {
                        return false
                    }
                    k++
                }
            }
            else {
                // true
                while(s[k] == arr[i][j].str) {
                    // console.log(s[k])
                    k ++
                }
                if(arr[i][j].str == '.') {
                    if(i == arr.length-1 && j == arr[i].length-1) {
                        return true
                    }
                    else {
                        return false
                    }
                }
            }
        }
    }
    if(k == s.length) {
        return true
    }
    else {
        return false
    }
};

s = "aaa"
p = "a*a"




console.log(isMatch(s,p))