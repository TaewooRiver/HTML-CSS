//the .find(fn) method takes in a function as a parameter.
//the find method returns the element when the parameter function returns true for that element.
//once the find method returns something, it stops.
//
//the .findIndex(fn) method returns the element's index instead of the element itself.

let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
let firstEvenNum = arr.find((num) => {
    return num % 2 === 0; // returns true if an element is an even number.
})

console.log(firstEvenNum); // 2

let indexOfFirstEvenNum = arr.findIndex((num) => {
    return num % 2 === 0; // returns true if an element is an even number.
})

console.log(indexOfFirstEvenNum); // 1



