const http = require('http');
const url = require('url');
const data = require('./data');

http.createServer(function(request, response){
    if (request.method === "GET") {
        let pageUrl = url.parse(request.url, true);
        const newData = data.peoplesData.find(elem => {
            if (elem.name === pageUrl.query.name && elem.age === Number(pageUrl.query.age)) {
                return elem;
            }
        });
        response.write(JSON.stringify(newData));
        response.end();
    }
    response.end();
}).listen(3000);