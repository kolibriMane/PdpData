const calc = require('./main');
const test = {};

test.sumTest = function() {
    console.log("SUM");
    if (calc.sum(1, 2) === 3 && calc.sum(1, -1) === 0) {
        console.log("pass");
    } else {
        console.log("fail");
    }

    if (calc.sum(1, "hell") === "1hell" && calc.sum("Ma", "ne") === "Mane") {
        console.log("pass")
    } else {
        console.log("fail");
    }
}

test.prodTest = function() {
    console.log("PROD");
    if (calc.prod(1, 2) === 2 && calc.prod(1, -1) === -1) {
        console.log("pass");
    } else {
        console.log("fail");
    }

    if (calc.prod(1, "hell") === undefined && calc.prod("Ma", "ne") === undefined) {
        console.log("pass")
    } else {
        console.log("fail");
    }
}

test.divTest = function() {
    console.log("DIV");
    if (calc.div(1, 2) === 0.5 && calc.div(1, -1) === -1) {
        console.log("pass");
    } else {
        console.log("fail");
    }

    if (calc.div(1, 0) === undefined) {
        console.log("pass");
    } else {
        console.log("fail");
    }

    if (calc.div(1, "hell") === undefined && calc.div("Ma", "ne") === undefined) {
        console.log("pass")
    } else {
        console.log("fail");
    }
}

test.minTest = function() {
    console.log("MIN");
    if (calc.min(1, 2) === -1 && calc.min(1, -1) === 2) {
        console.log("pass");
    } else {
        console.log("fail");
    }

    if (calc.min(1, "hell") === undefined && calc.min("Ma", "ne") === undefined) {
        console.log("pass")
    } else {
        console.log("fail");
    }
}

test.prodTest();
test.sumTest();
test.minTest();
test.divTest();