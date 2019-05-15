import actions from './actions';
import UserService from '../../../services/User';
import { async } from 'q';

async function getUsers() {
  return await UserService.getUsers();
}

function REQUEST_GET_USERS(action, dispatch, state) {
  getUsers()
  .then(response => {
		dispatch(actions.SET_USERS({ users: response.data }))
	})
}

function userListMiddleware(action, dispatch, state) {

  switch(action.type) {
    case 'REQUEST_GET_USERS':
		  return REQUEST_GET_USERS(action, dispatch, state);
    default: 
    	return state;
	}
}

export default userListMiddleware;