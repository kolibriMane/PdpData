module.exports.sum = function(a, b) {
    return a + b;
}

module.exports.prod = function(a, b) {
    if (typeof a == 'number' && typeof b == 'number') {
        return a * b;
    }
}

module.exports.min = function(a, b) {
    if (typeof a == 'number' && typeof b == 'number') {
        return a - b;
    }
}

module.exports.div = function(a, b) {
    if (typeof a == 'number' && typeof b == 'number' && b !== 0) {
        return a / b;
    }
}