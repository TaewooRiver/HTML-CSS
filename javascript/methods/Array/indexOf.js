//the .indexOf(element, startingIndex) method returns the index of the element it is looking for.
let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 3];
let index = arr.indexOf(3, 0);
console.log(index); // 2
let otherIndex = arr.indexOf(3, 9);
console.log(otherIndex); // 10

//the .lastIndexOf(element) goes backwarts when looking for an element.
let anotherIndex = arr.lastIndexOf(3);
console.log(anotherIndex); // 10