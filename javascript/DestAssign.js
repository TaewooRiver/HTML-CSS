
//Basic syntax of Destructing Assignments
let lorem = "loremipsum".split("");
let [a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11] = lorem;
console.log(a9); // "u"
console.log(a10); // "m"
console.log(a11); // undefined

//Just have consecutive commas to skip an element
let lorem2 = "loremipsum".split("");
let [b1, , b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12] = lorem2;
console.log(b9); // "m"
console.log(b10); // undefined
console.log(b11); // undefined
console.log(b12); // undefined

//Default values can be assigned
let lorem3 = "loremipsum".split("");
let [c1, , , , , , , , , , , c2 = "what did you expect"] = lorem3;
console.log(c2); // what did you expect

    //Swapping variables the original way
    let a = 1;
    let b = 2;
    let c = undefined;
    console.log(`BEFORE : a = ${a}, b = ${b}`); // BEFORE : a = 1, b = 2

    c = a;
    a = b;
    b = c;
    console.log(`AFTER : a = ${a}, b = ${b}`); // AFTER : a = 2, b = 1

    //Swapping variables with Destructing Assingments
    let x = 1;
    let y = 2;

    console.log(`BEFORE : x = ${x}, y = ${y}`); // BEFORE : x = 1, y = 2

    [x, y] = [y, x];

    console.log(`AFTER : x = ${x}, y = ${y}`); // AFTER : x = 2, y = 1

//Destructive Assignments can be applied to Objcets as well
let user1 = {
    age: 30,
    name: "Mike",
}

let {age, name} = user1;

// the above one line of code is equal to the below
//      let age = user.age;
//      let name = user.name;
// Therefore,
console.log(age); // 30
console.log(name); // "Mike"
//TIP:  let {age, name} = user1; 
//      can also be 
//      let {name, age} = user1;

//You can use other names besides the keys.
let user2 = {
    age: 30,
    name: "Mike",
}

let {age: userAge, name: userName} = user2;
console.log(userAge); // 30
console.log(userName); // Mike


//if there is a key that the original object does not have, then it returns undefined
//---------------[IGNORE BELOW CODE]--------------
let Store = (years, location) => {
    return {
        location: location,
        years: years,
    }
}

let store1 = Store(3, "Seoul");
let store2 = Store(5, "New York");

function Computer(model, version) {
    this.model = model;
    this.version = version;
}
//---------------[IGNORE ABOVE CODE]--------------
let {location1, years1, owner1} = store1;
console.log(owner1); // undefined

    //in ths case, just like how we did with arrays, default values can be set.
    let {location2, years2, owner2 = "DEFAULT NAME"} = store2;
    console.log(owner2); // DEFAULT NAME

    //as these are default values, if there already is a value for the key, default values are ignored.
