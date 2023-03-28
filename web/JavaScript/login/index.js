function logSubmit(event) {
    log.textContent = 'Login: ' + document.getElementById('login').value + '  Password: ' + document.getElementById('password').value;
    event.preventDefault();
}

const form = document.getElementById('form');
const log = document.getElementById('log');
form.addEventListener('submit', logSubmit);