// the .concat(array, array...) method concatenates the arrays/elements given as arguments.
let arr1 = [1, 2, 3];
let arr2 = [4, 5, 6];

// arr1 + arr2 + 7 + 8 + 9 + 0
//also the concat method disassembles the arrays into elements and concatenates as one whole array.
let newArr = arr1.concat(arr2, 7, 8, 9, 0);
console.log(newArr); // [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]

//or
arr1 = [...arr1, ...arr2]
console.log(arr1); // [1, 2, 3, 4, 5, 6]