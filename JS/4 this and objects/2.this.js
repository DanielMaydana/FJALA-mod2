
/*
function foo() {
	console.log( this.a );
}

var obj1 = {
	a: 2,
	foo: foo
};

var obj2 = {
	a: 3,
	foo: foo
};

obj1.foo(); // ??
obj2.foo(); // ??

obj1.foo.call( obj2 ); // ??
obj2.foo.call( obj1 ); // ??

*/



/* //If strict mode is in effect, the global object is not eligible
//for the default binding, so the this is instead set to undefined.

function foo() {
  "use strict"
	console.log( this.a );
}
global.a = 2;
foo(); // TypeError: `this` is `undefined` */




/* // Because obj is the this for the sayA() call,
// this.a is synonymous with obj.a.
function sayA() {
	console.log( this.a );
}
var obj = {
	a: 2,
	sayA: sayA
};

obj.sayA(); // ???? */






/* // Only the top/last level of an object property
// reference chain matters to the call-site.
function sayA() {
	console.log( this.a );
}

var obj2 = {
	a: 42,
	sayA: sayA
};

var obj1 = {
	a: 2,
	obj2: obj2
};

obj1.obj2.sayA(); // 2 or 42? */






/* 
// Loose this?
//The more common, and more unexpected way this occurs
// is when we consider passing a callback function:

global.a = "oops, global"; // `a` also property on global object

function sayA() {
	console.log(this.a , '???');
}

function executeCallback(callback) {
  // `fn` is just another reference to `foo`
	callback(); // <-- call-site!
}

var obj = {
	a: 2,
	sayA: sayA
};

executeCallback(obj.sayA); // 2 or "oops, global" */
