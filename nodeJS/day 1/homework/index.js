const http = require('http');
const url = require('url');
const data = require('./user');
const otherData = require('./ids');


http.createServer((request, response) => {
    // If request method is GET
    if (request.method === 'GET') {
        // Get request path and queries
        let pageUrl = url.parse(request.url, true);
        let pathName = pageUrl.pathname;

        // Routing urls
        if (pathName === '/users' && !pageUrl.query) {
            response.write(JSON.stringify(data));
            response.end();
        } else if (pathName === '/investments') {
            response.write(JSON.stringify(otherData));
            response.end();
        } else if (pathName === '/users' && pageUrl.query) {
            const ids = otherData.investmentsData;
            const users = data.peoplesData;

            // Merge 2 data by id
            let allData = ids.map(element => {
                let id = element.id;
                user = users.find(user => user.id === id);
                return Object.assign(user, element);
            });
            console.log(allData)

            // Filter data by name if query-> name exists
            if (pageUrl.query.name && allData) {
                allData = allData.find(elem => elem.name === pageUrl.query.name);
                console.log(allData);
            }

            // Filter data by name if query-> age exists and data exists
            if (pageUrl.query.age && Array.isArray(allData)) {
                allData = allData.peoplesData.find(elem => elem.age === Number(pageUrl.query.age));
            } else if (pageUrl.query.age && allData) {
                if (allData.age !== Number(pageUrl.query.age)) {
                    response.statusCode = 404;
                    response.statusMessage = "User not found";
                    response.end();
                    return;
                }
            }

            response.write(JSON.stringify(allData));
            response.end();
        }
    }
}).listen(3000);