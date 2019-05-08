
//import the middlewares we want to join
//import exampleMiddleware from '..';
import todoListMiddleware from '../views/TodoList/middleware';

//we create an array of the middlewares
const middlewares = [
	todoListMiddleware
	//example middlewares
];

//As you can see, the middleware is a curried function.
//What is a curried function? A curried function is a function that returns another function.

//state: equals store state
//exports a function, that recieves as parameter a estate
//returns a callback that recieves an dispatch a parameter

export default function rootMiddleware(state) {
	return function (dispatch) {
		return function (action) {
			dispatch(action);
			middlewares.forEach(callback => callback(action, dispatch, state.getState()));
		};
	} 
}


//curried function example
/* const foo = a => b => a + b;
foo(1)(2); //=> 3
OR in ES5
function foo(a) {  
  return function(b) {  
   return a + b;  
  } 
} */