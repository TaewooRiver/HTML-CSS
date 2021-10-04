//the .forEach(fn) method takes in a function as an argument.
let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];

let result = 0;

//the parameters that the argument function takes in are fixed. Those are the elements, the indices, and the array itself.
arr.forEach((element, index, theArrayItself) => {
    result += element;
})
console.log(result);

let employees = ["John", "Mary", "Doh"];

employees.forEach((employee, index) => {
    console.log(`${index + 1}. ${employee}`);
})