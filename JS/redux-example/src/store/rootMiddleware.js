import userListMiddleware from '../views/User/UserList/middleware';

const middlewares = [
	userListMiddleware
];

export default function rootMiddleware(state) {
	return function (dispatch) {
		return function (action) {
			dispatch(action);
			middlewares.forEach(callback => callback(action, dispatch, state.getState()));
		};
	} 
}