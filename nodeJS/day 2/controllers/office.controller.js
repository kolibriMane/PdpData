const { office } = require('../models/office');

const getOffices = async function(req, res) {
    try {
        const offices = await office.findAll();
        res.send(offices)
    } catch {
        res.status(505).send({
            message: "Database error"
        });
    }
}

const getOfficeByID = async function(req, res) {
    const id = req.params.id;
    const offices = await office.findAll({
        where: {
            id: Number(id)
        }
    })
    if (offices && offices.length > 0) {
        res.send(offices[0]);
    } else {
        res.status(405).send({
            message: "Can't find office!"
        });
    }
}

const addOffice = async function(req, res) {
    let { name } = req.body;
    try {
        await office.create({ name });
        res.send({
            message: "Office successfully added"
        })
    } catch (err) {
        res.status(505).send({
            message: "Database error"
        });
    }
}

module.exports = {
    getOffices,
    getOfficeByID,
    addOffice
}