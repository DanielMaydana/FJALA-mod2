//1 default values

function linkGenerator(url, color, height) {
  return {
    url: url || 'google.com',
    color: color || 'red',
    height: height || 50
  };
}
const url = linkGenerator();
console.log(url);

function betterLinkGenerator(url = 'google.com', color = 'red', height = 50) {
  return {
    url: url,
    color: color,
    height: height
  };
}
console.log(betterLinkGenerator());


//2. Template Literals in ES6

function printName(first, last) {
  const name = 'Your name is ' + first + ' ' + last + '.'
  console.log(name);
}
printName('Alberto', 'Blacutt');

function betterPrintName(first, last) {
  const name = `Your name is ${first} ${last}.`;
  console.log(name)
}
betterPrintName('Alberto', 'Blacutt')


//3 Destructuring Assignment in ES6

const complexObject = {
  name: 'object',
  id: 'a0002',
  time: 4000,
  color: 'red',
  picture: 'https://localhost/a0002',
  dummy: 4478522577,
  repeaterStart: new Date(),
}

function renderPicture(object) {
  const picture = object.picture;
  const repeaterStart = object.repeaterStart;
  const name = object.name;
  console.log(picture, repeaterStart, name);
}

function coolRenderPicture(object) {
  const { picture, repeaterStart, name } = object;
  console.log(picture, repeaterStart, name);
}

function coolerEverRenderPicture({ picture, repeaterStart, name }) {
  console.log(picture, repeaterStart, name);
}

renderPicture(complexObject);
coolRenderPicture(complexObject);
coolerEverRenderPicture(complexObject);

const VOCALES = ['A', 'E', 'I', 'O', 'U'];
const a = VOCALES[0]
const e = VOCALES[1]
const i = VOCALES[2]
const o = VOCALES[3]
const u = VOCALES[4]

console.log(a, e, i, o, u);

const [betterA, betterE, betterI, betterO, betterU] = VOCALES;
console.log(betterA, betterE, betterI, betterO, betterU);


// spread operator

const newVocales = {...complexObject}

function start(name, age) {

}

start(...complexObject)


// 4 clases o Objects

/* 
  Class Administrador, User, Visitor, privateMember

  Administrador ====> delete users, add users on its own array,
  login, logout, saveBitacoraOnEachAction, visitPrivatePage,
  getPrivilegies, setPrivilegies(User)

  User ===> loging logout, saveBitacoraOnEachAction

  visitor ===> visistPage, login, logout,
  askForPrivilegies, saveBitacoraOnEachAction

  privateMember ===> login, logout, visitPrivatePage,
  saveBitacoraOnEachAction


*/