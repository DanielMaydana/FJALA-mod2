// Aca agrupamos todos los reducers de nuestras vistas
// todos los reducers de nuestra applicacion

import { combineReducers } from 'redux';

import todoList from '../views/TodoList/reducer';
//import example from '../views/example/reducer'

const rootReducer = combineReducers({
	todoList,
	//example,
});

export default rootReducer;