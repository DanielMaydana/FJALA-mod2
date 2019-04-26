import Validator from '../../../Components/Validator';

const initialState = {

};

function UPDATE_BUTTON_STATE(state, action) {

  return {
    ...state
  };
}

export default function Createtrainer(state = initialState, action) {
  switch (action.type) {
    case 'UPDATE_BUTTON_STATE':
      return UPDATE_BUTTON_STATE(state, action);
    default:
      return state;
  }
}