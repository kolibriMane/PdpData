const { user } = require('./user');
const { id } = require('./id');
const { city } = require('./city');
const { office } = require('./office');

const usersData = require('../src/user.json');
const idsData = require('../src/ids.json');
const cityData = require('../src/cities.json');
const officeData = require('../src/offices.json');


let connect = async () => {
    try {
        // Create database tables
        await city.sync({ alter: true });
        await office.sync({ alter: true });
        await user.sync({ alter: true });
        await id.sync({ alter: true });

        // Connections
        user.belongsTo(city, {foreignKey: 'cityID'});
        user.belongsTo(office, {foreignKey: 'officeID'});

        // Data normalize
        let users = usersData.peoplesData;
        let ids = idsData.investmentsData;
        let cities = cityData.cities;
        let offices = officeData.offices;

        // Insert data
        for (let i in cities) {
            let elem = cities[i];
            await city.create({
                name: elem.name,
                isCapital: elem.isCapital,
                population: elem.population
            });
        }

        for (let i in offices) {
            let elem = offices[i];
            await office.create({
                name: elem.name
            });
        }

        for (let k in ids) {
            let elem = ids[k];
            await id.create({
                id: Number(elem.id),
                investments: Number(elem.investments)
            });
        }

        for (let i in users) {
            let elem = users[i];
            await user.create({
                name: elem.name,
                id: Number(elem.id),
                surname: elem.surname,
                age: Number(elem.age),
                job: elem.job,
                image: elem.image,
                cityID: elem.cityID,
                officeID: elem.officeID
            });
        }
    } catch (error) {
        console.error('Connect to the MySql Refused:', error);
    }
};

connect();