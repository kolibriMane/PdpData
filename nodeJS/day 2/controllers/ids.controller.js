const { id } = require('../models/id');

const getInvestments = async function(req, res) {
    try {
        const ids = await id.findAll();
        res.send(ids)
    } catch {
        res.status(505).send({
            message: "Database error"
        });
    }
}

const getInvestmentsByID = async function(req, res) {
    const invest = req.params.id;
    try {
        const ids = await id.findAll({
            where: {
                id: Number(invest)
            }
        })
        if (ids && ids.length > 0) {
            res.send(ids[0]);
        } else {
            res.status(405).send({
                message: "Can't find id!"
            });
        }
    } catch {
        res.status(505).send({
            message: "Database error"
        });
    }
}

module.exports = {
    getInvestments,
    getInvestmentsByID
}