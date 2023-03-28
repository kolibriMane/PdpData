const { Sequelize } = require('sequelize');
const configs = require('../configs/config');

// Connecting with database
const sequelize = new Sequelize(configs.database, configs.user, configs.password, {
    host: configs.host,
    dialect: configs.dialect
});

module.exports = { sequelize };