
let myArr = [1, 2, 3, 4, 5, 6, 7, 8,];

const result = myArr.map((nameVal, index) => {
    let newArr = [];
    if(nameVal % 2 === 0){
        console.log(`${myArr[index]} is an even number.`);
        newArr.push(`${nameVal} (even)`);
    } else {
        newArr.push("odd");
    }
    return newArr;
})

console.log(result);
console.log(myArr);