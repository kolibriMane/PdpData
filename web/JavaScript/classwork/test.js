const company = {
    dep1: {
      room1: [
        {name: 'employer1', salary: 1},
        {name: 'employer2', salary: 2},
        {name: 'employer3', salary: 3},
      ],
      room2: [
        {name: 'employer1', salary: 1},
        {name: 'employer2', salary: 2},
        {name: 'employer3', salary: 3},
      ],
    },
    dep2: {
      room1: [
        {name: 'employer1', salary: 1},
        {name: 'employer2', salary: 2},
        {name: 'employer3', salary: 3},
      ],
      room2: [
        {name: 'employer1', salary: 11},
        {name: 'employer2', salary: 2},
        {name: 'employer3', salary: 3},
      ],
    },
};

function foo(company) {
    let sum = 0;
    for (var key in company) {
        if (typeof company[key] == "object" && company[key] !== null) {
            sum += foo(company[key]);
        } else if (key === "salary") {
            sum = sum + company[key];
        }
    }
    return sum;
}

console.log(foo(company));