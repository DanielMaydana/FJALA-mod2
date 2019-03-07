// https://api.github.com/users

let urlGithub = 'https://api.github.com/users';
const axios = require('axios');


async function getUsers() {

    let users = [];
    let filteredUsers = [];
    
    axios.get(urlGithub)
    .then(function (response) {
        
        users = response.data;

        filteredUsers = users.map(obj => {
            
            axios.get(urlGithub + obj.id)
            .then(function (responseSingleUser){

                singleUser = responseSingleUser.data;

                singleUser.forEach(element => {
                    
                });
                let newUser = {};

                newUser["id"] = obj.id;
                newUser["picture"] = obj.avatar_url;
                newUser["username"] = obj.login;
                newUser["type"] = obj.type;
                newUser["followersLength"] = obj.followers;
                newUser["followingLength"] = obj.following;
                newUser["url"] = obj.url;
    
                return newUser;
            })
            .catch(function (errorSingleUser){

                console.log(errorSingleUser);
            });
        });

        console.log(filteredUsers[0]);
    })
    .catch(function (error) {
                
        console.log(error);
    });
}

getUsers();