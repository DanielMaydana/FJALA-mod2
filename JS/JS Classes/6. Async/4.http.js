//users https://api.github.com/users
//users https://api.github.com/repositories

const axios = require('axios');

function getUsers() {

  let users = [];

  axios.get('https://api.github.com/users')
  .then(function (response) {
    // handle success
    users = response.data;
    console.log('users', users[0]);
  })
  .catch(function (error) {
    // handle error
    console.log('error');
  });
}


function getUsersAndRepos() {
  const promises = [];
  promises.push(axios.get('https://api.github.com/users'));
  promises.push(axios.get('https://api.github.com/repositories'));

  Promise.all(promises)
  .then(response => {
    const [users, respositories] = response; // is the same doing const users = response[0], const repositories = response[1];
    console.log(response.length, ':: number of responses success');
  })
  .catch(error => {
    console.log(error.length, ':: number of response with error');
    console.log(error.message, ':: the first error appears');
  })
}

async function asyncGetUsers() {
  const response = await axios.get('https://api.github.com/users');
  users = response.data;
  console.log('numero de usuarios es ', users.length);
  //error handling???
}

asyncGetUsers();

async function asyncGetUsersAndRepos() {
  const usersResponse = await axios.get('https://api.github.com/users');
  const reposResponse = await axios.get('https://api.github.com/repositories');
  console.log(usersResponse.data.length, ' usuarios');
  console.log(reposResponse.data.length, ' repos');
}
