const express = require('express');
const userController = require('../controllers/user.controller');
const idsController = require('../controllers/ids.controller');
const cityController = require('../controllers/city.controller');
const officeController = require('../controllers/office.controller');
const router = express.Router();

// User routing
router.route('/users/:id')
    .get(userController.getUserByID);
router.route('/users')
    .get(userController.getUsers)
    .post(userController.addUser);

// Investment routing
router.route('/investments/:id')
    .get(idsController.getInvestmentsByID);
router.route('/investments')
    .get(idsController.getInvestments);

// City routing
router.route('/cities/:id')
    .get(cityController.getCityByID);
router.route('/cities')
    .get(cityController.getCities)
    .post(cityController.addCity);

// Office routing
router.route('/offices/:id')
    .get(officeController.getOfficeByID);
router.route('/offices')
    .get(officeController.getOffices)
    .post(officeController.addOffice);

router.route('/*')
    .all(userController.wrongURL);

module.exports = router;