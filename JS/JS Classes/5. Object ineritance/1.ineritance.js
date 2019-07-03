
// “JS doesn't have ‘inheritance’
// in the traditional sense,
// and what it does have is more appropriately
// labeled "behavior delegation"
// the ability of one object to delegate
// a method or property access which it cannot
// handle over to another object which can handle it.


const animal = {
  born: function () {
    console.log('I born');
  },
  die: function () {
    console.log('I die');
  },
  eat: function () {
    console.log('I eat');
  },
}


const dog = Object.create(animal);  // like arrows, dog.prototype =====> animal
dog.sayMyName = function () {
  console.log('Hi guys I am ', this.name);
};

dog.bark = function () {
  console.log('guau guau guau');
};


const brian = Object.create(dog); // like arrows brian.prototype ======> dog
brian.name = 'Brian';
console.log(brian);
brian.born();
brian.sayMyName();
brian.eat();
brian.bark();
brian.die();