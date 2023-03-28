const { DataTypes } = require('sequelize');
const { sequelize } = require('./connection');

const city = sequelize.define('cities', {
    id: {
        type: DataTypes.INTEGER,
        allowNull: false,
        primaryKey: true,
        autoIncrement: true
    },
    name: {
        type: DataTypes.STRING,
        allowNull: false
    },
    isCapital: {
        type: DataTypes.BOOLEAN,
        allowNull: false,
        defaultValue: false
    },
    population: {
        type: DataTypes.INTEGER,
        allowNull: false
    }
}, {
    timestamps: false
});

module.exports = { city };