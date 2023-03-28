const tasks = {};


// 1. Need to get all data using "Promises.all" function.
// ... You can use fetch for example
tasks.taskOne = function() {
    const urls = [
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/id.json',
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/users.json',
    ];

    // Recreate every URL to promise, returned fetch
    let requests = urls.map(url => fetch(url), {
        credentials: 'same-origin'
    });

    // Promise.all will wait for done all promises
    Promise.all(requests)
    .then(responses => responses.forEach(response => console.log(response.json())))
    .catch(error => alert("Something went wrong in 1st function!"));

};


// 2. Get rows from investment data in which investments are not less then 500
// and then get the that people's info from people's data and combine.
tasks.taskTwo = function() {
    const urls = [
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/id.json',
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/users.json',
    ];

    // Recreate every URL to promise, returned fetch, parse from json to js object
    let requests = urls.map(url => fetch(url).then(data => data.json()));

    Promise.all(requests)
    .then(data => {
        ids = data[0].investmentsData;
        users = data[1].peoplesData;
        let filtered = ids.filter(element => element.investments >= 500);
        const allData = filtered.map(element => {
            let id = element.id;
            user = users.find(user => user.id === id);
            return Object.assign(user, element);
        });
        console.log(allData);
    })
    .catch((err) => {
        alert("Something went wrong in 2nd function!");
        console.log(err.status);
    });
};


// 3. Write the function which can save the top 3 investors names in the array
tasks.taskThree = function() {
    const urls = [
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/id.json',
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/users.json',
    ];

    // Recreate every URL to promise, returned fetch, parse from json to js object
    let requests = urls.map(url => fetch(url).then(data => data.json()));

    Promise.all(requests)
    .then(data => {
        ids = data[0].investmentsData;
        users = data[1].peoplesData;
        const allData = ids.map(element => {
            let id = element.id;
            user = users.find(user => user.id === id);
            return Object.assign(user, element);
        });
        // Sorting data by investments and get first 3 investors
        let topValues = allData.sort((elem1, elem2) => elem2.investments - elem1.investments).slice(0, 3);
        const names = topValues.map(elem => elem.name)
        console.log(names);
    })
    .catch((err) => {
        alert("Something went wrong in 3rd function!");
        console.log(err.status);
    });
};


// 4. Combine all peoples all data in one array
// ... Each element of the array will contain id, name, age, job, investments.
// ... Then convert the data to entries and save in weekMap
tasks.taskFour = function() {
    const urls = [
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/id.json',
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/users.json',
    ];

    // Recreate every URL to promise, returned fetch, parse from json to js object
    let requests = urls.map(url => fetch(url).then(data => data.json()));

    Promise.all(requests)
    .then(data => {
        ids = data[0].investmentsData;
        users = data[1].peoplesData;
        const allData = ids.map(element => {
            let id = element.id;
            user = users.find(user => user.id === id);
            return Object.assign(user, element);
        });
        const entries = Object.entries(allData);
        let weakMap = new WeakMap();
        for (let i in entries) {
            weakMap.set(entries[i], i);
        }
        console.log(weakMap);
    })
    .catch((err) => {
        alert("Something went wrong in 4th function!");
        console.log(err.status);
    });
};
