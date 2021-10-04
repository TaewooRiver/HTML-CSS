
let myArr = [1, 2, 3, 4, 5, 6, 7, 8,];

let newArr = myArr.reduce((prev, cur) => {
    return prev + cur;
}, 0);

console.log(newArr);