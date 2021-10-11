//a function that returns an object
let Computer = (madeYear, manufacturer) => {
    return {
        madeYear: madeYear,
        manufacturer: manufacturer,
    }
}


let com1 = Computer(2001, "Samsung");
console.log(com1); // prints the object

// the phrase `"(keyname)" in (object)` returns a boolean.

com1 = Object.assign(com1, {CPU: 2});
let com2 = Computer(2010, "Apple");


function isCpuFast(computer){
    if(computer.CPU < 4){
        return false;

    }
    return true;
}

//com2.CPU will return undefined. therefore it may cause bugs.
console.log(isCpuFast(com1));// false
console.log(isCpuFast(com2));// true, but it shouldn't be able to determine

//As a solution, we can use the `"(keyname)" in (object)` phrase.
function newIsCpuFast(computer){
    if(!('CPU' in computer) || computer.CPU < 4){
        return false;
    }
    return true;
}

console.log(newIsCpuFast(com1));// false
console.log(newIsCpuFast(com2));// false