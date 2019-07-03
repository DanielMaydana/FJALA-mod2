//Objects in JavaScript have an internal property,
//denoted in the specification as [[Prototype]],
// which is simply a reference to another object.
// Almost all objects are given a non-null value for this property,
// at the time of their creation.


var anotherObject = {
	a: 2
};

// create an object linked to `anotherObject`
var myObject = Object.create( anotherObject );
myObject.a; // 2


//Prototype chain
//OLOO" (objects-linked-to-other-objects
//In JavaScript, the [[Prototype]] mechanism links objects to other objects.
// There are no abstract mechanisms like "classes"
// When a member of an object is accessed, it is searched from the object's members.
// If it is not found there, then it is searched in its prototype object.
//If it is not found there, then it is searched in the parent object's members and prototype and so on



//JS doesn't have ‘inheritance’ in the traditional sense,
// and what it does have is more appropriately labeled
// "behavior delegation" 
// the ability of one object to delegate a method or property
// access which it cannot handle over to another object which can handle it