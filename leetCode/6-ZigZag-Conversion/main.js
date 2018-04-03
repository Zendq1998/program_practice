/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    let convertArr = []
    let ol = numRows, // 单列
        el = parseInt(numRows/2) // 双列
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
            console.log((rowNum-ol+1)*2-1)
            convertArr[(rowNum-ol+1)*2-1] += el
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
convert("ABC",2)

