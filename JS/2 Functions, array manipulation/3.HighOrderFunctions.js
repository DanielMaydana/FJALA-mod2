/* 
Higher order functions are functions that operate on other functions,
either by taking them as arguments or by returning them.

In simple words, A Higher-Order function is a function
that receives a function as an argument or returns the function as output.
*/

const employes = [{
  name: 'Alberto',
  age: 25,
  area: 'DEV'
},
{
  name: 'Andres',
  age: 22,
  area: 'DEV'
},
{
  name: 'Julian',
  age: 29,
  area: 'DEV'
},
{
  name: 'Jose',
  age: 32,
  area: 'QA'
},
{
  name: 'Maria',
  age: 36,
  area: 'DEV'
}];

//Object, callback(), callback()
function validatePersonal(person, areaValidation, ageValidation) {
  return areaValidation(person) && ageValidation(person);
}

function isDev(person) {
  return person.area === 'DEV';
}

function isQA(person) {
  return person.area === 'QA';
}

function isJoung(person) {
  return person.age <= 25;
}

//lets find all people joung and is DEV
const joungDevs = [];
for (let index = 0; index < employes.length; index++) {
  const person = employes[index];
  if(validatePersonal(person, function (person) {
    return person.area === 'QA'
  }, function(person) {
    return person.age >= 25
  })) {
    joungDevs.push(person.name);
  }
}

console.log(':::JoungDEVS =>', joungDevs); 

//some examples of High order functions are .foreach, map, filter, find, reduce, every, some, findIndex All are array manipulators