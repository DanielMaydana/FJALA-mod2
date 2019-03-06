//Objects come in two forms:
//the declarative (literal) form,
//and the constructed form.

var myObj = {
	key: 'value'
	// ...
};

//*******************

var myObj = new Object();
myObj.key = 'value';


// reference and copy

const object = {
  name: 'table',
  age: 3
};

const object2 = {
  name: 'chair',
  age: 4
};

const object3 = {
  name: 'room',
  age: 20
};

const ObjectsContainer = {
  a: object,
  b: object2,
  list: [object3]
};


console.log(object);
ObjectsContainer.a.name = null;
console.log(object);

console.log(object3);
ObjectsContainer.list[0].name = 'second object are undefined';
console.log(object3);



const objectToCopy = {}
//One subset solution is that objects which are JSON-safe
//can easily be duplicated with deep copy:
const newObj1 = JSON.parse( JSON.stringify(objectToCopy));

// or

//first level duplicate ES6
const newObj2 = Object.assign( {}, objectToCopy );











/* const searchDocument = {
  person: {
    name: 'Pedro',
    age: 25,
    app: {
      link: 'https://yourday.app',
      name: 'Yourday'
    }
  },
  source: {
    code: 2123,
    role: 'employe',
    build: 'C3-05'
  }
}

const copySearchDocument = Object.assign({}, searchDocument);
copySearchDocument.person.app.name = 'fakeYourday';
console.log(searchDocument);
console.log(copySearchDocument); */