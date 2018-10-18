/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if(numRows == 1) {
        return s
    }
    let convertArr = []
    let ol = numRows, // 单列
        el = numRows-2 // 双列 (斜的都算一列)
    let tl = ol+el 
        
    for(let i=0;i<numRows;i++) {
        convertArr.push("")
    }
    for(let index=0;index<s.length;index++){
        let el = s[index]
        let rowNum = (index)%(tl)
        console.log(rowNum)
        if(rowNum<ol) {
            convertArr[rowNum] += el
        }
        else {
            console.log((rowNum-ol))
            convertArr[ol - (rowNum-ol) - 2] += el
        }
    
}
    console.log(convertArr)
    let out = ""
    for(let i=0;i<convertArr.length;i++) {
        out += convertArr[i]
    }
    console.log(out)
    return out
};
convert("A",1)

