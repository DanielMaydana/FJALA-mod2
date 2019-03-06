

class Animal {
  constructor(name, type, age) {
    this.name = name;
    this.type = type;
    this.age = age;
  }

  born() {
    console.log('I born');
  }

  die() {
    console.log('I die');
  }

  eat() {
    console.log('I eat');
  }

  sleep() {
    console.log('I sleep');
  }
};

class Pet extends Animal{
  constructor(name, age, type, licence) {
    super(name, age, type);
    this.licence = licence;
  }

  getLicence() {
    console.log('getting licence', this.licence);
    return this.licence;
  }
}

class Dog extends Pet {
  constructor(name, age, type, licence) {
    super(name, age, type, licence);
  }

  bark() {
    console.log('wau wau wau wau');
  }
}


const brian = new Dog('I am brian', 'pitbull', 5, {owner: 'Alberto', code: '001aa475h'});
console.log(brian);
brian.born();
brian.getLicence();
brian.bark();
brian.eat();
brian.sleep();
brian.die();


/* 
  If you stop thinking about inheritance,
  and instead think with the arrows
  headed the other way:
  delegation, your JS code will be simpler.
  Remember: it's just objects linked to objects!”
*/