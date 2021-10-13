//closure is about persisting the variables' values after the function has been exited.
function makeCounter(){
    let num = 0;
    return function() {
        return ++num;
    };
}

// if javascript did not have closure, when makeCounter() has exited, the variable num should have been blown away.
let count = makeCounter();

// we can see that every time when we call the count() function, the variable num increments. This can happen because those values are within closures.
console.log(count()); // 1
console.log(count()); // 2
console.log(count()); // 3
