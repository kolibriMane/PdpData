const { user } = require('../models/user');
const cityTable = require('../models/city');
const officeTable = require('../models/office');

const getUsers = async function(req, res) {
    try {
        const users = await user.findAll();
        if (users && users.length > 0) {
            let result = [];
            for (i in users) {
                let elem = users[i];
                const { cityID, officeID } = elem;
                const offices = await officeTable.office.findAll({
                    where: {
                        id: Number(officeID)
                    }
                });
                const cities = await cityTable.city.findAll({
                    where: {
                        id: Number(cityID)
                    }
                });

                result += JSON.stringify({
                    name: elem.name,
                    surname: elem.surname,
                    age: elem.age,
                    job: elem.job,
                    image: elem.image,
                    office: offices[0],
                    city: cities[0]
                });
            }
            res.json({
                users: result
            });
        } else {
            res.status(405).send({
                message: "Can't find users!"
            });
        }
    } catch {
        res.status(505).send({
            message: "Database error"
        });
    }
}

const getUserByID = async function(req, res) {
    const id = req.params.id;
    try {
        let users = await user.findAll({
            where: {
                id: Number(id)
            }
        });

        if (users && users.length > 0) {
            users = users[0];
            const { cityID, officeID } = users;
            const offices = await officeTable.office.findAll({
                where: {
                    id: Number(officeID)
                }
            });
            const cities = await cityTable.city.findAll({
                where: {
                    id: Number(cityID)
                }
            });

            res.send({
                name: users.name,
                surname: users.surname,
                age: users.age,
                job: users.job,
                image: users.image,
                office: offices[0],
                city: cities[0]
            });
        } else {
            res.status(405).send({
                message: "Can't find user!"
            });
        }
    } catch {
        res.status(505).send({
            message: "Database error"
        });
    }
}

const addUser = async function(req, res) {
    const { name, surname, age, job, image, city, office } = req.body;
    try {
        let off = await officeTable.office.findAll({
            where: {
                name: office
            }
        });

        let cit = await cityTable.city.findAll({
            where: {
                name: city
            }
        });

        if (cit && off && cit.length > 0 && off.length > 1) {
            await user.create({
                name, surname, age, job, image,
                cityID: cit.id,
                officeID: off.id
            });
            res.send({
                message: "User successfully added"
            })
        } else {
            console.log(cit)
            console.log(off)
            res.status(403).send({
                message: "Bad request"
            })
        }
    } catch (err) {
        res.status(505).send({
            message: "Database error"
        });
    }
}

const wrongURL = async function(req, res) {
    res.status(404).json({
        message: "Can't find this page!"
    });
}

module.exports = {
    getUsers,
    getUserByID,
    wrongURL,
    addUser
}