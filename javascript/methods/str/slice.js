//the .slice(m, n) method returns a sliced string from index m to index n-1 of the original string.
let str = "loremipsum";

let str1 = str.slice(3, 5); // em
console.log(str1)

//if there is no second arguement, it just returns the rest of the string.
let str2 = str.slice(3); //emipsum
console.log(str2)

//if m is a negative integer, it is counted backwards. Its range goes from m to n -1, and in this case, -2, which is "u".
let str3 = str.slice(3, -1); //
console.log(str3) // emipsu
