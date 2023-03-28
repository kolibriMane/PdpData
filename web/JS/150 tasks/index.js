const homework = {};
const tasks = {};

// Implement object copy (should also support nested)
homework.copyV1 = function(obj1, obj2) {
    obj1 = JSON.parse(JSON.stringify(obj2));
    return obj1;
};

homework.copyV2 = function(obj2) {
    // Returns the value, if obj2 is not an object
    if (typeof obj2 !== "object" || obj2 === null) {
        return obj2;
    }

    // Create return object
    let obj1;
    // init return object an array- if value is array
    // Else create object
    if (Array.isArray(obj2)) {
        obj1 = [];
    } else {
        obj1 = {};
    }

    // Copy obj2 to obj1 recursively
    for (let key in obj2) {
        obj1[key] = homework.copyV2(obj2[key])
    }

    return obj1;
}

// Symbol
homework.symbol = function() {
    var sym1 = Symbol();
    var sym2 = Symbol("some");
    var sym3 = Symbol("some");

    // false
    if (sym3 == sym2) {
        console.log("true")
    } else {
        console.log("false")
    }

    // to create symbol-object
    let sym = Symbol("foo");
    // symbol
    typeof sym;
    let symObj = Object(sym);
    // object
    typeof symObj;
}

// *** Data structures ***
homework.map = function() {
    // Map can have any types of key
    // Elements maintains the insertion order
    // Maps are iterable
    let map = new Map();
    map.set("1", "Kolibri");
    map.set(1, "Mane");
    console.log(map);
    // We can get size
    console.log(map.size);
    map.get(1);
    // False
    map.has("some");
    // True
    map.has("1");
    // Iteration
    map.values();
    // Delete all key-values from array
    map.clear();
}

homework.map = function() {
    let set = new Set([1, 2, 3, 4]);
    // Does not added
    set.add(4);
    // Added
    set.add(6);
    set.delete(4);
    // has not value 4
    console.log(set);
    // Is element exists
    set.has(6);
    // Get set size
    set.size
    // Clear set (delete all elements)
    set.clear();
}

homework.map = function() {
    let set = new Set([1, 2, 3, 4]);
    // Does not added
    set.add(4);
    // Added
    set.add(6);
    set.delete(4);
    // has not value 4
    console.log(set);
    // Is element exists
    set.has(6);
    // Get set size
    set.size
    // Clear set (delete all elements)
    set.clear();
}

homework.weakMap = function() {
    // weakMap must has only object keys
    const wm1 = new WeakMap(),
    wm2 = new WeakMap(),
    wm3 = new WeakMap();

    const o1 = {},
    o2 = function(){},
    o3 = window,
    o4 = [1, 2, 3];

    wm1.set(o1, 37);
    wm1.set(o2, 'Mane');
    // Value can be anything, including object and function
    wm2.set(o1, o2);
    wm2.set(o3, undefined);

    // keys and values can be objects. Even weak-map)
    wm2.set(wm1, wm2);
    // 'Mane'
    wm1.get(o2);
    // undefined, not value for 02 in wm2
    wm2.get(o2);
    // undefined, this was initialized
    wm2.get(o3);

    // true
    wm1.has(o2);
    // false
    wm2.has(o2);
    // true (even value equal to 'undefined')
    wm2.has(o3);

    wm3.set(o1, 37);
    // 37
    wm3.get(o1);

    // true
    wm1.has(o1);
    wm1.delete(o1);
    // false
    wm1.has(o1);
}

tasks.weakSet = function() {
    let weakMap = new WeakMap();
    let obj = {};

    // working
    // has object key
    weakMap.set(obj, "ok");

    // Can't use string for key
    // error, because "test" is not an object
    //weakMap.set("test", "Whoops");

    let foo = function() {
        let john = { name: "John" };
        let weakMap = new WeakMap();
        weakMap.set(john, "...");

        // rewriting link on object
        john = null;
        // Object john deleted from memory automatically!
    }
    foo();
}

// 1. Current day and time
tasks.date = function() {
    let now = new Date();
    let day = now.getDay();
    let week = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"];

    console.log("Today is :", week[day - 1]);
    let time = now.getHours();

    if (time > 12) {
        time += " PM ";
    } else {
        time += " AM : ";
    }

    time += now.getMinutes() + " : " + now.getSeconds();
    console.log("Current time is : ", time)
};

// 2. Print the contents of the current window
tasks.content = function() {
    let dom = document.getElementsByTagName("*");
    let size = dom.length;

    for (let i = 0; i < size; ++i) {
        console.log(dom[i]);
    }
};

// 3. Current date.
tasks.currentData = function() {
    let today = new Date();

    let dateV1 = today.getMonth() + 1 + '-' + + today.getDate() + '-' + today.getFullYear();
    let dateV2 = today.getMonth() + 1 + '/' + + today.getDate() + '/' + today.getFullYear();

    let date = dateV1 + ', ' + dateV2;
    console.log(date);
};

// 4. Find the area of a triangle, where lengths of the three sides are 5, 6, 7.
tasks.area = function() {
    let a = 5;
    let b = 6;
    let c = 7;

    let p = (a + b + c) / 2;
    let s = p * (p - a) * (p - b) * (p - c);

    console.log("Area is:", s);
};

// 5. Rotate the string 'w3resource' in right direction by periodically
//  removing one letter from the end of the string and attaching it to the front.
tasks.rotateString = function(string) {
    let size = string.length;
    let rotated = "";

    for (let i = 0; i < size; ++i) {
        rotated = string[size - 1] + string.substring(0, size - 1);
        string = rotated;
        console.log(string)
    }

    // console.log(rotated);
}

// 6. Determine whether a given year is a leap year in the Gregorian calendar.
tasks.calendar = function(year) {
    let isLeap = (year % 4 === 0)? (year % 100 === 0)? (year % 400 === 0)? true: false: true: false;
    if (isLeap) {
        console.log(year, 'is leap');
    } else {
        console.log(year, 'is not leap');
    }
}

// 7.Find 1st January is being a Sunday between 2014 and 2050.
tasks.firstSunday = function() {
    for (let year = 2014; year < 2050; ++year) {
        let day = new Date("January 1," + year);
        if (day.getDay() === 6) {
            console.log(year);
            break;
        }
    }
}

// 8. The program takes a random integer between 1 to 10,
// the user is then prompted to input a guess number.
// If the user input matches with guess number,
// the program will display a message "Good Work" otherwise display a message "Not matched".
var randomNum = function() {
    let value = document.getElementById("number").value;
    let number = Math.floor(Math.random() * 10);
    console.log(number);
    if (parseInt(value) === number) {
        document.getElementById("text").innerHTML = "Good work";
    } else {
        document.getElementById("text").innerHTML = "Not matched";
    }
}

// 9. calculate days left until next Christmas.
tasks.untilChristmas = function() {
    let today = new Date();
    let xMas = new Date(today.getFullYear(), 11, 31);
    if (parseInt(today.getMonth()) === 11 && parsInt(today.getDate()) === 31) {
        xMas.setFullYear(xMas.getFullYear());
    }

    // one day to ms
    let dayMS = 24 * 3600 * 1000;
    let untilChristmas = Math.ceil(xMas.getTime() - today.getTime());
    console.log("Days until Christmas are: ", parseInt(untilChristmas / dayMS));
}

// 10. Calculate multiplication and division of two numbers (input from user).
var getMulDiv = function() {
    let num1 = document.getElementById("num1").value;
    let num2 = document.getElementById("num2").value;
    document.getElementById("mul").innerHTML = "Mul: " + num1 * num2;
    document.getElementById("div").innerHTML = "Div: " + num1 / num2;
}

// 11. Convert temperatures to and from Celsius, Fahrenheit.
var convert = function(string) {
    let num = document.getElementById("t").value;
    if (string === 'cel') {
        let cel = 5 * (num - 32) / 9;
        document.getElementById("label").innerHTML = "Cel: " + cel;
    } else {
        let fah = 9 * num / 5 + 32;
        document.getElementById("label").innerHTML = "Fah: " + fah;
    }
}

// 12. Get the website URL (loading page).
var getURL = function() {
    document.getElementById("url").innerHTML = window.location.href;
}

// 13. Create a variable using a user-defined name.
var createVar = function() {
    let string = document.getElementById("inp").value;
    window[string] = 8;
    console.log(window[string]);
}

// 14. Exercise to get the extension of a filename.
tasks.extension = function(filename) {
    let index = filename.lastIndexOf(".");
    let extension = filename.substring(index);
    console.log(extension);
}

// 15. Get the difference between a given number and 13,
// if the number is greater than 13 return double the absolute difference.
tasks.extension = function(number) {
    const num = 13;
    if (num > number) {
        console.log(num - number);
        return num - number;
    } else if (num < number) {
        console.log((number - num) * 2);
        return (number - num) * 2;
    } else {
        console.log("Are equal");
        return 0;
    }
}

// 16. Compute the sum of the two given integers.
// If the two values are same, then returns triple their sum.

tasks.sum = function(a, b) {
    if (a === b) {
        console.log(6 * a);
        return 6 * a;
    } else {
        console.log(a + b);
        return a + b;
    }
}

// 17. Compute the absolute difference between a specified number and 19.
// Returns triple their absolute difference if the specified number is greater than 19.
tasks.diff = function(a) {
    a = Math.abs(a);
    const b = 19;
    if (a > b) {
        console.log((a - b) * 3);
        return (a - b) * 3;
    } else {
        console.log(a - b);
        return a - b;
    }
}

// 18. Check two given numbers and return true if one of the number is 50 or if their sum is 50.
tasks.check = function(a, b) {
    if (a === 50 || b === 50 || a + b === 50) {
        console.log(true);
        return true;
    } else {
        console.log(false);
        return false;
    }
}

// 19. Check whether a given integer is within 20 of 100 or 400.
tasks.checkRange = function(num) {
    if (num >= 80 && num <= 120) {
        console.log("To 100");
    } else if (num >= 380 && num <= 420) {
        console.log("To 400");
    }
}

// 20. Check from two given integers, whether one is positive and another one is negative.
tasks.isPositiveNegative = function(a, b) {
    if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
        console.log("Good pair");
    } else {
        console.log("Bad pair");
    }
}

// 21. Create a new string adding "Py" in front of a given string.
// If the given string begins with "Py" then return the original string.
tasks.pyString = function(string) {
    if (string.indexOf('py') == 0) {
        return string;
    } else {
        return 'py' + string;
    }
}

// 22. Remove a character at the specified position of a given
// string and return the new string.
tasks.delChar = function(string, n) {
    if (n >= string.length) {
        console.log(string);
        return string;
    } else {
        console.log(string.substring(0, n - 1) + string.substring(n));
        return string.substring(0, n) + string.substring(n + 1);
    }
}

// 23. Create a new string from a given string changing the position of first
// and last characters. The string length must be greater than or equal to 1.
tasks.changeString = function(string) {
    let length = string.length;
    if (length > 0) {
        let newString = string[length - 1] + string.substring(1, length - 1) + string[0];
        console.log(newString);
        return newString;
    } else {
        return string;
    }
}

// 24. Create a new string from a given string with the first character of the
// given string added at the front and back.
tasks.FrontBackString = function(string) {
    let newString = string[0] + string + string[0];
    console.log(newString);
    return newString;
}

// 25. Check whether a given positive number is a multiple of 3 or a multiple of 7.
tasks.isMultiple = function(number) {
    let string = "";
    if (number % 3 === 0 && number % 7 === 0) {
        string = "and 7 and 3";
    } else if (number % 3 === 0) {
        string = "not 7 but 3";
    } else if (number % 7 === 0) {
        string = "not 3 but 7";
    } else {
        string = "not 7 not 3";
    }

    console.log(string);
    return string;
}

// 26. Create a new string from a given string taking the last 3 characters and
// added at both the front and back. The string length must be 3 or more.
tasks.stringChars = function(string) {
    let size = string.length;
    if (size < 3) {
        return string;
    }

    let newString = string.substring(size - 3) + string + string.substring(size - 3);
    console.log(newString);
    return newString;
}

// 27. Check whether a string starts with 'Java' and false otherwise.
tasks.startsJava = function(string) {
    if (string.indexOf("java") == 0) {
        return true;
    } else {
        return false;
    }
}

// 28. Check whether two given integer values are in the range 50..99 (inclusive).
// Return true if either of them are in the said range.
tasks.areInRange = function(num1, num2) {
    let bool = false;
    if (num1 > 50 && num1 < 99) {
        bool = true;
    }

    if (num2 > 50 && num2 < 99) {
        bool = true;
    }

    return bool;
}

// 29. Check whether three given integer values are in the range 50..99 (inclusive).
// Return true if one or more of them are in the said range.
tasks.areInRangeThree = function(...numbers) {
    let bool = false;

    for (let i in numbers) {
        if (numbers[i] > 50 && numbers[i] < 99) {
            bool = true;
        }
    }

    console.log(bool);
    return bool;
}

// 30. Check whether a string "Script" presents at 5th (index 4) position in a
// given string, if "Script" presents in the string return the string without "Script"
// otherwise return the original one.
tasks.script = function(...numbers) {
    let bool = false;

    for (let i in numbers) {
        if (numbers[i] > 50 && numbers[i] < 99) {
            bool = true;
        }
    }

    console.log(bool);
    return bool;
}