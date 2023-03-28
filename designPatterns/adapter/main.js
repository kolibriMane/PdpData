const parser = require('xml2json');
const { Parser } = require('json2csv');
const fs = require('fs');
const myData = require('./data.json');
const fields = ['carModel', 'price'];

// Converter xml to json
fs.readFile('./data.xml', function(err, data) {
    if (err) {
        console.log("Can not read xml file!");
        throw err;
    }

    console.log();
    console.log("****** Converter xml to json ******");
    let json = parser.toJson(data);
    console.log(json);
});

// Json to csv format
try {
    const parser = new Parser(fields);
    const csv = parser.parse(myData.data);
    console.log("****** Converter json to csv ******");
    console.log(csv);
} catch (err) {
    console.error(err);
}