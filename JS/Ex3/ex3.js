class User{
    constructor(nameId, password = "password"){

        this.nameId = nameId;
        this.password = password;
        this.logbook = {
            action : [],
            date : []
        };
    }

    login(){
        this.saveBitacoraOnEachAction("login");
    };

    logout(){
        this.saveBitacoraOnEachAction("logout");
    };

    saveBitacoraOnEachAction(action){
        this.logbook.action.push(action);
        this.logbook.date.push(Date.now());
    };
}

class Visitor extends User{
    
    constructor(nameId, password = "password"){
        
        super(nameId, password);
    }

    visistPage(){
        console.log("Page Visited");
        this.saveBitacoraOnEachAction("visitPage");
    }

    askForPrivilegies(){
        console.log("Ask For Privileges");
        this.saveBitacoraOnEachAction("askForPrivilegies");
    }
}

class privateMember extends User{
    
    constructor(nameId, password = "password"){
        super(nameId, password);
    }

    visitPrivatePage(){
        console.log("Private Page Visited");
        this.saveBitacoraOnEachAction("visitPrivatePage");
    }
}

class Administrator extends privateMember{
    
    constructor(nameId, password = "password"){
        
        super(nameId, password);
        this.allUsers = [];
    }
    
    deleteUser(userName){

        for(var i = 0; i < this.allUsers.length; i++) {

            if(this.allUsers[i].nameId === userName) {
                this.allUsers.splice(i, 1);
                break;
            }
        }
    }

    addUser(userName){
        this.allUsers.push(new User(userName));
        this.saveBitacoraOnEachAction("addUser");
    }

    getPrivilegies(){
        console.log("Privileges Got");
        this.saveBitacoraOnEachAction("getPrivilegies");
    }

    setPrivilegies(){
        console.log("Privileges Set");
        this.saveBitacoraOnEachAction("setPrivilegies");
    }
}

// proof of concept :

const adminMe = new Administrator();

adminMe.addUser("Nick");
adminMe.addUser("Leah");
adminMe.addUser("Peter");
adminMe.addUser("Robert");
adminMe.deleteUser("Nick");

console.log(adminMe.allUsers);
console.log(adminMe.logbook);
