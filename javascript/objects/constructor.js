//a constructor fucntion is useful for creating lots of similar objects
function User(name, age){

}

//this is a constructor function
let User = (name, age) => {
    this.name = name;
    this.age = age;
}

//to use a constructor, you need to prefix the word `new`.
//what `new` does is it calls the function in the below way so that it looks like:
//
//let User = (name, age) => {
//    this = {}
//    this.name = name;
//    this.age = age;
//    return this;
//}

let user1 = new User("John", 23);


console.log(user1.name); // "John"

//this is just a function that returns an object literal
let Uzer = (name, age) => {
    return{
        name: name,
        age: age,
    }
}

let user2 = Uzer("Matt", 22);
console.log(user2.name); // "Matt"