
//literal object
const dev = {
  name: 'Alberto',
  team: 'Aktana',
  showInfo: function () {
    console.log(`${this.name} works in ${this.team}`)
  }
}
dev.showInfo();


//Constructor function
function Person (name, team) {
  this.name = name
  this.team = team
}
Person.prototype.showInfo = function () {
  console.log(`${this.name} works in ${this.team}`)
}
const Alberto = new Person('Alberto', 'Aktana2');
Alberto.showInfo();


// Factory function
function PersonFactory (name, team) {
  return {
    name: name,
    team: team,
    showInfo: function () {
      console.log(`${this.name} works in ${this.team}`)
    }
  }
}

const Pedro = PersonFactory('Pedro', 'yourday');
Pedro.showInfo();



// Object Create
const devSkills = {
  showInfo: function () {
    console.log(`${this.name} works in ${this.team}`)
  }
};
var jose = Object.create(devSkills, {
  name: { value: 'Jose' },
  team: { value: 'Xian' }
});

jose.showInfo()




//Class
class DevPerson {
  constructor(name, team) {
    this.name = name;
    this.team = team;
  } 
  showInfo() {
    console.log(`${this.name} works in ${this.team}`)
  }
}

var pablo = new DevPerson('pablo', 'oildex')
pablo.showInfo();









//"Class/Inheritance" describes a certain form
// of code organization and architecture -- 
// a way of modeling real world problem domains in our software.

//JS tries to satisfy the extremely pervasive desire to design
// with classes by providing seemingly class-like syntax.
