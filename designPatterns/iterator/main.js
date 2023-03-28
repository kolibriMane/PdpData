const array = [1, 2, 3, 4, 5];

console.log("****** V1 ******");
let sum = 0;
let prod = 1;
array.forEach(elem => {
    sum += elem;
    prod *= elem;
});
console.log("Sum  :", sum);
console.log("Prod :", prod);


console.log("****** V2 ******");
sum = 0;
prod = 1;
for (let i = 0; i < array.length; ++i) {
    sum += array[i];
    prod *= array[i];
}
console.log("Sum  :", sum);
console.log("Prod :", prod);

console.log("****** V3 ******");
sum = (accumulator, currentValue) => accumulator + currentValue;
prod = (accumulator, currentValue) => accumulator * currentValue;
console.log("Sum  :", array.reduce(sum));
console.log("Prod :", array.reduce(prod));