function Item(name, price){
    this.price = price;
    this.name = name;
    this.showPrice = function(){
        console.log(`The price is $${price}.`);
    }
}

let item1 = new Item("Doll", 30);
console.log(item1);

item1.showPrice();