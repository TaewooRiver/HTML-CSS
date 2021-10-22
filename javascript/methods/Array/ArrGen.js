
function AscendingRandomArray(numbers){
    this.array = [];
    for(let i = 0; i < numbers; ++i){
        this.array.push(Math.round(Math.random() * 100));
    }
    this.array.sort((a, b) => a - b);
}


let array1 = new AscendingRandomArray(6)
console.log(array1.array); 