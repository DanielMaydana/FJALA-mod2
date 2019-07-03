
/* 
  Sadly boolean objects do not coerce so easily. 
*/

var object = {};
var array = [];
var string = 'Alberto';
var number = 12.36;
var undefinedVar = undefined;
var nullVar = null;
var symbol = Symbol('id');

console.log(typeof object); // object
console.log(typeof array); // array?
console.log(typeof string); // string
console.log(typeof number); // number
console.log(typeof undefinedVar); // undefined
console.log(typeof nullVar); // null?
console.log(typeof symbol); //symbol




/* if (new Boolean(false)) {
  console.log('is true?');
} else {
  console.log('is false');
}

var text = '';
var number = 0;
var object = {};
var array = [];
var func = function () {};

new Boolean(text).valueOf() // ??
new Boolean(number).valueOf() // ??
new Boolean(object).valueOf() // ??
new Boolean(array).valueOf() // ??
new Boolean(func).valueOf() // ??

if(text) {
  console.log('text was true');
}

if(number) {
  console.log('number was true');
}

if(object) {
  console.log('object was true');
}

if(array) {
  console.log('array was true');
}

if(func) {
  console.log('function was true');
} */