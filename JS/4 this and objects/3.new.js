function constructor(name, age) {
  this.name = name;
  this.age = age;
}

// with new in front of it, we've constructed a new object
// and set that new object as the this for the call of foo(..)
const person = new constructor('juan', 12);
console.log(person);

//const person2 = constructor('pedro', 25);
//console.log(person2, global.name, global.age);




