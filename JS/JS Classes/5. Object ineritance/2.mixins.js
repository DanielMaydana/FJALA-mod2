

const cat = {
  type: 'kitty',
  miau: function () {
    console.log('miau miau miau');
  }
};

const fish = {
  gulp: function () {
    console.log('gulp gulp gulp');
  }
};

const dog = {
  type: 'pitbull',
  bark: function () {
    console.log('wau wau wau ');
  }
};

const pet = {
  sayHi: function () {
    console.log('Hi mortals, i am ' + this.name);
  }
};


const catDogFish = Object.assign({}, cat, dog, fish, pet);
catDogFish.name = 'catDogFishGod';
console.log(catDogFish);

catDogFish.sayHi();
catDogFish.miau();
catDogFish.gulp();
catDogFish.bark();
console.log(catDogFish.type);
