
const initialState = {
    personForm: {
        name: 'Hero',
        age: '12',
        email: 'hero@gmail.com'
    }
};

function UPDATE_FORM_PERSON(state, action) {
    const newPersonForm = { ...state.personForm };
    newPersonForm[action.payload.key] = action.payload.value;
    return { ...state, personForm: newPersonForm }
}

export default function CreatePersonReducer(state = initialState, action) {
    switch (action.type) {
        case 'UPDATE_FORM_PERSON':
            return UPDATE_FORM_PERSON(state, action);
        default:
            return state;
    }
}