const jsonData = require('./data.json');
const data = jsonData.users;

const users = data.map(elem => {
    elem.notify = function(name, isActive) {
        if (isActive) {
            console.log("Hello, my name is", elem.name, "... My friend ", name, "is active now");
        } else {
            console.log("Hello, my name is", elem.name, "... My friend ", name, "is not active now");
        }
    }
    return elem;
});

const changeStatus = function(id, users, isActive) {
    const user = users.find(e => e.id == id);
    const follow = user.follow;
    user.isActive = isActive;
    follow.forEach(element => {
        users[element].notify(user.name, isActive);
    });
}

changeStatus(0, users, true);
console.log()
changeStatus(0, users, false);
console.log()
changeStatus(1, users, true);
console.log()
changeStatus(1, users, false);