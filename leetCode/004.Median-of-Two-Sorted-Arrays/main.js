/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(A, B) {    
    let i = 0, j = 0;
    let f = 0, s = 0;
    
    let N = A.length + B.length;
    let half = Math.floor(N / 2) + 1;
    
    for(let k = 0; k < half; k++) {
        s = f;
        if(i >= A.length) {
            f = B[j];
            j++;
        } else if(j >= B.length) {
            f = A[i];
            i++;
        }else if(A[i] > B[j]) {
            f = B[j];
            j++;
        } else {
            f = A[i];
            i++;
        }
    }
    
    if(N % 2 === 0) {
        return (s + f) / 2;
    } else {
        return f;
    }
};