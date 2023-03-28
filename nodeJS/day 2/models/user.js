const { DataTypes } = require('sequelize');
const { sequelize } = require('./connection');

const user = sequelize.define('users', {
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
    surname: {
        type: DataTypes.STRING,
        allowNull: false
    },
    age: {
        type: DataTypes.INTEGER,
        allowNull: false
    },
    job: {
        type: DataTypes.STRING
    },
    image: {
        type: DataTypes.STRING
    },
    cityID: {
        type: DataTypes.INTEGER,
        allowNull: false,
        defaultValue: 0,
    },
    officeID: {
        type: DataTypes.INTEGER,
        allowNull: false,
        defaultValue: 0,
    }
}, {
    timestamps: false
});

module.exports = { user };