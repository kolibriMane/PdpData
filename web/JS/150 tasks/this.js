// 1. In a method, this refers to the owner object.
const obj = {
    a: "5",
    foo: function() {
        console.log(this);
    }
}

obj.foo()

// 2. Alone, this refers to the global object.
console.log(this);

// 3. In a function, this refers to the global object.
let foo = function() {
    console.log(this);
}
foo();

// 4. In a function, in strict mode, this is undefined.
"use strict";
let data = this;
console.log(data);

// 5. In an event, this refers to the element that received the event.
// -> In HTML

// 6. Methods like apply() call() can refer this to any object.
const obj1 = {
    getName: function() {
        return this.name;
    }
}

const obj2 = {
    name: "Mane",
}

obj1.getName.call(obj2);

// 7. Method bind() change function this, but doesn't call it
let some = function() {
    this.name = "Mane";
    var module = {
        name: "Kolibri",
        getName: function() {
            console.log(this.name);
        }
    };

    module.getName();

    let getName = module.getName;
    // Mane
    getName();

    let func = getName.bind(module);
    // Kolibri
    func();
}
some();

// 8. In class this is class
class Cat {
    constructor(name) {
        this.name = name;
    }
}

// 9. But if we use function to create class, this is function
Cat.prototype.speak = function() {
    return this;
}