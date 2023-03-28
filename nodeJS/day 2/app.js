const { connection } = require('./models/mysql');
const express = require("express");
const bodyParser = require('body-parser');
const router = require('./routers/router');
const cors = require('cors');
const app = express();

// Body parser

app.use(cors());
app.use(bodyParser.json());

app.use((req, res, next) => {
    res.set({
        "Access-Control-Allow-Origin": "*"
    });
    next();
});

app.use((err, req, res, next) => {
    if (err) {
        res.status(405);
        res.json({
            message: "Bad request"
        });
        res.send();
    } else {
        next();
    }
});
app.use('/', router);

app.listen(3000);