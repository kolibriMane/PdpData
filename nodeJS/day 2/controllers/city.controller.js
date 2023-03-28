const { city } = require('../models/city');

const getCities = async function(req, res) {
    try {
        const cities = await city.findAll();
        res.send(cities)
    } catch {
        res.status(505).send({
            message: "Database error"
        });
    }
}

const getCityByID = async function(req, res) {
    const id = req.params.id;
    const cities = await city.findAll({
        where: {
            id: Number(id)
        }
    })
    if (cities && cities.length > 0) {
        res.send(cities[0]);
    } else {
        res.status(405).send({
            message: "Can't find city!"
        });
    }
}

const addCity = async function(req, res) {
    let { name, isCapital, population } = req.body;
    try {
        isCapital = Boolean(isCapital);
        population = Number(population);
        await city.create({ name, isCapital, population });
        res.send({
            message: "City successfully added"
        })
    } catch (err) {
        res.status(505).send({
            message: "Database error"
        });
    }
}

module.exports = {
    getCities,
    getCityByID,
    addCity
}