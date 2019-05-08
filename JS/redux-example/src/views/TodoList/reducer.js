
const initialState = {
	userName: 'anonimous',
  tasks: [],
  taskForm: {
    title: '',
    isDone: false,
  }
};

function ADD_TASK(state, action) {
  const newTasks = [...state.tasks]; //copiando array de taks
  const newTask = {...state.taskForm}; //task a partir del formulario
  newTasks.push(newTask);
  return { ...state, tasks: newTasks };
}

function SET_TASKS(state, action) {
  console.log(action.payload);
  const tasks = action.payload.tasks;
  return { ...state, tasks };
}

function UPDATE_TASK(state, action) {
  const newTasks = [...state.tasks];
  const { index, key , value } = action.payload;
  const task = newTasks[index];
  task[key] = value;
  return { ...state, tasks: newTasks };
}

function UPDATE_FORM(state, action) {
  const newForm = {...state.taskForm}; // saca una copia del form
  newForm[action.payload.key] = action.payload.value;//
  return { ...state, taskForm: newForm }
}

function CLEAR_FORM(state, action) {
  return { ...state, taskForm: initialState.taskForm };
}

export default function TodoListReducer(state = initialState, action) {
  switch(action.type) {
    case 'ADD_TASK':
      return ADD_TASK(state, action);
    case 'UPDATE_FORM':
      return UPDATE_FORM(state, action);
    case 'CLEAR_FORM':
      return CLEAR_FORM(state, action);
    case 'UPDATE_TASK':
      return UPDATE_TASK(state, action);
    case 'SET_TASKS':
      return SET_TASKS(state, action);
    default: 
      return state;
  }
}