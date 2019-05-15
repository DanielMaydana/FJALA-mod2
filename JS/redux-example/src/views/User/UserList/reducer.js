const initialState = {
  users: []
};

function SET_USERS(state, action) {
  const users = action.payload.users;
  return { ...state, users };
}


export default function UserReducer(state = initialState, action) {
  switch (action.type) {
    case 'SET_USERS':
      return SET_USERS(state, action);
    default:
      return state;
  }
}