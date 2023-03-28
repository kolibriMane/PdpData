const { DataTypes } = require('sequelize');
const { sequelize } = require('./connection');

const office = sequelize.define('offices', {
    id: {
        type: DataTypes.INTEGER,
        allowNull: false,
        primaryKey: true,
        autoIncrement: true
    },
    name: {
        type: DataTypes.STRING,
        allowNull: false
    }
}, {
    timestamps: false
});

module.exports = { office };