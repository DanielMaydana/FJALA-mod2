// https://api.github.com/users

let urlGithub = 'https://api.github.com/users';
const axios = require('axios');
let filteredUsers = [];

async function getSingleUsers(userLogin) {
    
    var axiosAux = axios.get(urlGithub + "/" + userLogin);
    return axiosAux;
 
}
async function getAllUsers() {

    let usersRaw = [];
    
    axios.get(urlGithub)
    .then(function (response) {
        
        usersRaw = response.data;

        filteredUsers = usersRaw.map(obj => {
           
            let newUser = {};

            getSingleUsers(obj.login).then((userSingle) => {

                newUser["id"] = userSingle.id;
                newUser["picture"] = userSingle.avatar_url;
                newUser["username"] = userSingle.login;
                newUser["type"] = userSingle.type;
                newUser["followersLength"] = userSingle.followers;
                newUser["followingLength"] = userSingle.following;
                newUser["url"] = userSingle.url;
                
                return newUser;
            });
            console.log(newUser);
        });
            
    })
    .catch(function (error) {
                
        console.log(error);
    });
}

getAllUsers();