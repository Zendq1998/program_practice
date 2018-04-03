/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */


var findMedianSortedArraysInContinue = function(nums1, nums2, len1, len2) {
    let x = (len1+len2)%2?parseInt((len1+len2)/2):parseInt((len1+len2)/2-1)
    let y = parseInt((len1+len2)/2)
    let sum = 0
    if(nums1[len1-1] <= nums2[0]) {
        if(x<len1) {
            
            sum += nums1[x]
        }
        else {
            sum += nums2[x-len1]
        }
        if(y<len1) {
            sum +=nums1[y]
        }
        else {
            sum += nums2[y-len1]
        }
    }
    else {
        if(x<len2) {
            sum += nums2[x]
        }
        else {
            sum += nums1[x-len2]
        }
        if(y<len2) {
            sum +=nums2[y]
        }
        else {
            sum += nums1[y-len2]
        }
    }
    return sum/2
}

// var findMedianForThree = function(a,b,c) {
//     var max = Math.max(Math.max(a,b),c)
//     var min = Math.min(Math.min(a,b),c)
//     return a+b+c-max-min
    
// }

var sortTowArry = function(arr1,arr2) {
    var i = 0,
        j = 0
        arrOut = [],
    console.log("arr1:"+arr1)
    console.log("arr2:"+arr2)
    while(arr1.length>i && arr2.length>j) {
        if(arr1[i] <= arr2[j]) {
            arrOut.push(arr1[i])
            i++
        }
        else {
            arrOut.push(arr2[j])
            j++
        }
    }
    if(arr1.length==i) {
        arrOut = arrOut.concat(arr2.slice(j))
    }
    if(arr2.length==j) {
        arrOut = arrOut.concat(arr1.slice(i))
    }
    return arrOut
}

var findMedianSortedArrays = function(nums1, nums2) {
    let m = nums1.length,
        n = nums2.length
    if(m>n) {
        let t = nums1
        nums1 = nums2
        nums2 = t
    }
    m = nums1.length,
    n = nums2.length
    let la = m%2?parseInt(m/2):parseInt(m/2-1),
        lb = n%2?parseInt(n/2):parseInt(n/2-1),
        ra = parseInt(m/2),
        rb = parseInt(n/2)
    if(n == 0 && m > 0) {
        return (nums1[la]+nums1[ra])/2
    }
    if(m == 0 && n >0) {
        return (nums2[lb]+nums2[rb])/2
    }
    if(m ==0 && n==0) {
        return null
    }
    if(nums1[m-1] <= nums2[0] || nums1[0] >= nums2[n-1]) {
        return findMedianSortedArraysInContinue(nums1,nums2,m,n)
    }
    console.log("start: la:"+la+" ra:"+ra)
    console.log("start: lb:"+lb+" rb:"+rb)
    while(la>0 && lb>0 && ra<m-1 && rb<n-1) {
        if(nums1[la] > nums2[rb]) {
            if(la != ra) {
                ra --
            }
            la --
            if(lb != rb) {
                lb ++
            }
            rb ++
        }
        else if(nums1[ra] < nums2[lb]) {
            if(la != ra) {
                la ++
            }
            ra ++
            if(lb != rb) {
                rb --
            }
            lb --
        }
        else {
            console.log("la:"+la+","+nums1[la]+"  ra:"+ra+","+nums1[ra])
            console.log("lb:"+lb+","+nums2[lb]+"  rb:"+rb+","+nums2[rb])
            break
        }
    }
    // 总计为奇数
    if((n+m)%2) {
        console.log("奇")
        console.log("la:"+la+","+nums1[la]+"  ra:"+ra+","+nums1[ra])
        console.log("lb:"+lb+","+nums2[lb]+"  rb:"+rb+","+nums2[rb])
        var arr1 = "",
            arr2 = ""
        if(la==ra) {
            if(la==0) {
                arr1 = nums1.slice(la)
            }
            else {
                arr1 = nums1.slice(la-1,ra+2)
            }
            arr2 = nums2.slice(lb,rb+1)
        }
        if(lb==rb) {
            if(lb==0) {
                arr2 = nums2.slice(lb)
            }
            else {
                arr2 = nums2.slice(lb-1,rb+2)
            }
            arr1 = nums1.slice(la,ra+1)
        }
        if(la==ra || lb==rb) {
            var arrOut = sortTowArry(arr1,arr2)
            var mid = parseInt(arrOut.length/2)
            console.log(arrOut)
            return arrOut[mid]
        }
        else {
            var leftNum = ra + rb,
                rightNum = m + n - ra - rb
            if(nums1[ra] < nums2[lb]) {
                return leftNum<rightNum?nums2[lb]:nums1[ra]
            }
            else if(nums1[la] > nums2[rb]) {
                return leftNum<rightNum?nums1[la]:nums2[rb]
            }
            if(leftNum > rightNum) {
                return Math.max(nums1[la],nums2[lb])
            }
            else {
                return Math.min(nums1[ra],nums2[rb])
            }
        }
    }
    // 总计为偶数
    else {
        console.log("偶")
        console.log("la:"+la+","+nums1[la]+"  ra:"+ra+","+nums1[ra])
        console.log("lb:"+lb+","+nums2[lb]+"  rb:"+rb+","+nums2[rb])
        if(la == ra) {
            if(la == 0 && lb != 0) {
                return ((nums1[la]>nums2[lb]?Math.min(nums1[la],nums2[lb+1]):Math.max(nums1[la],nums2[lb-1]))+nums2[lb])/2
            }
            if(lb == 0 && la != 0) {
                return ((nums2[lb]>nums1[la]?Math.min(nums1[la+1],nums2[lb]):Math.max(nums1[la-1],nums2[lb]))+nums1[la])/2
            }
            else {
                return (nums1[la]+nums2[lb])/2
            }
        }
        if(nums1[la] > nums2[rb]) {
            return (Math.min(nums1[la],nums2[rb+1])+nums2[rb])/2
        }
        if(nums1[ra] < nums2[lb]) {
            return (Math.max(nums1[ra],nums2[lb-1])+nums2[lb])/2
        }
        return (Math.max(nums1[la],nums2[lb]) + Math.min(nums1[ra],nums2[rb]))/2 
    }
    
};
var nums1 = [6,7,8]

var nums2 = [1,2,3,4,5,9]
console.log(findMedianSortedArrays(nums1,nums2))
