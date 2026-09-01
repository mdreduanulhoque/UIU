// // console.log("hello world")

// // let x = 0
// // let y = 5
// // console.log(x+y)
// // //////////////////////////////////////////////
// // let arr = [1,2,3,4]
// // console.log(arr)

// // // arr = "web"
// // // console.log(arr)

// // let sum = 0;
// // for(let i = 0; i < arr.length; i++)
// //     sum += arr[i];

// // console.log(sum)

// // /////////////////////////////////////////////

// // arr = [1,2,'Web',4]

// // sum = 0;
// // for(let i = 0; i < arr.length; i++)
// //     sum += arr[i];

// // console.log(sum)


// let arr = [2,3,5,8,6,7,10,9,1]
// console.log(arr)

// // arr.push(100)
// // console.log(arr)

// // arr.pop()
// // console.log(arr)

// // arr.unshift(100)
// // console.log(arr)

// // arr.shift()
// // console.log(arr)

// let narr = []
// for(let i = 0; i < arr.length; i++)
//     if(arr[i]%2 == 0)
//         narr.push(arr[i])
// console.log(narr)

// narr = arr.filter((temp) =>{
//     if(temp%2 == 0)
//         return true
//     else
//         return false
// })
// console.log(narr)


// //--------------------------------------------

// let narr2 = arr.filter((a, i, arr) =>{
//     if(i > 0  && arr[i-1] >= a)
//         return false
//     if(i < arr.length-1 && arr[i+1] >= a)
//         return false
//     return true
// })
// console.log("Filter 2", narr2)

// --------------------------------------------

function sum(a, b){
    return a+b
}

console.log(sum(4,5))