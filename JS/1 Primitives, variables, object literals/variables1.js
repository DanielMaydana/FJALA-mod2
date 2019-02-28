// var dog = 'brian';
// var dog = 'Chimuelo';
// console.log(dog);

// var has scope contrains what the developers has issues
// let introduced in ES6 and was introduced to mitigate issues posed by variables
// In short, let helps us by making it easier to see where variables live in our code.

// -----

// let dog = 'brian';
// let dog = 'Chimuelo'; //error
// console.log(dog);

// let dog = 'brian';
// dog = chimuelo; //success
// console.log(dog);

// -----

// const is also limited to the scope which it operates. const is declared like var and let.
// Use const when you are sure a variable will not be redeclared.

// const developer = 'Juan';
// developer = 'pedro';   //error

// const usersList; //error

// const students = ['juan', 'penelope'];
// students = []; //error

// -----

// const person = {
//   age: 26,
//   name: josh
// };

// const anotherPerson = {
//   age: 32,
//   name: pedro
// }
// const person = anotherPerson; // error

// -----

const person = {
  age: 26,
  name: 'josh'
};

person.name = 'Daniel'; //success;
person['band'] = 'BRMC';
delete person.age;
console.log(person);

/*
  When declaring variables, it is good practice to avoid using var. Always lean towards let or const based on the following rules.

  Use let when we will be changing the value of the variable
  Use const when you are sure that variable won't change
  Using both let and const will keep our variables in the right scope and make our code easier to manage.
*/