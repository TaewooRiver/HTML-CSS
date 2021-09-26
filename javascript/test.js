function Item(name, price){
    this.price = price;
    this.name = name;
    this.showPrice = function(){
        console.log(`The price is $${price}.`);
    }
}

function myClass(para1, para2){
    return {
        [para1] : para2,
        [1+2+3] : 33,
    }
}

let item1 = new Item("Doll", 30);
console.log(item1);

item1.showPrice();

let object1 = new myClass("key1", "val1");
console.log(object1);
console.log(Object.keys(object1),
Object.values(object1),
Object.entries(object1))