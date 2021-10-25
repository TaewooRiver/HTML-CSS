function AscendingRandomArray(numbers){
    this.array = [];
    for(let i = 0; i < numbers; ++i){
        this.array.push(Math.round(Math.random() * 100));
    }
    this.array.sort((a, b) => a - b);
}


let array1 = new AscendingRandomArray(6)
console.log(`${array1.array}\nasdf`); 

const minNum = Math.min.apply(null, array1.array); 
const minNum2 = Math.min(...array1.array);
const minNum3 = Math.min.call(null, ...array1.array);
console.log(minNum); // the smallest number of the generated array
console.log(minNum2); // same value as minNum
console.log(minNum3);

if(minNum === minNum2 && minNum2 === minNum3){
    console.log("The three methods return an identical value.");
}else{
    console.log("ERROR");

}

const maxNum = Math.max.apply(null, array1.array);
const maxNum2 = Math.max(...array1.array);
const maxNum3 = Math.max.call(null, ...array1.array);
console.log(maxNum);
console.log(maxNum2);
console.log(maxNum3);

if(maxNum === maxNum2 && maxNum2 === maxNum3){
    console.log("The three methods return an identical value.")
}else{
    console.log("ERROR")
}


const naver = {
    nation: "KOR",
    popularity: "HIGH",
    owner: "NHN Corp.",
    foundYear: "1990",
}

function guideCompany(){
    console.log(`This company is based in ${this.nation}. its popluarity is ${this.popularity}`);
}

guideCompany();
guideCompany.call(naver); // The call method makes the function act as if it was a method of the given parameter object.

function updateCompany(companyCEO, numEmployees){
    this.companyCEO = companyCEO;
    this.numEmployees = numEmployees;
}


const updateNaver = updateCompany.bind(naver);

updateNaver("Some Korean Guy", 100000000);

console.log(naver);