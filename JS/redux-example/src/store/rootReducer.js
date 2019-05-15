import { combineReducers } from 'redux';
import createPerson from '../views/Person/CreatePerson/reducer';
import listUser from '../views/User/UserList/reducer';

const rootReducer = combineReducers({
    createPerson,
    listUser
});

export default rootReducer;