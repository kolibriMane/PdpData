const { DataTypes } = require('sequelize');
const { sequelize } = require('./connection');

const id = sequelize.define('ids',{
    id: {
        type: DataTypes.INTEGER,
        allowNull: false,
        primaryKey: true,
        autoIncrement: true
    },
    investments: {
        type: DataTypes.INTEGER,
        allowNull: false
    }
}, {
    timestamps: false
});

module.exports = { id };