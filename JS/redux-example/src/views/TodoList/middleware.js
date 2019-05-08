import actions from './actions';

//simulating a promise
function fakePostRequest(task) {
	
	return new Promise((resolve, reject) => {
		setTimeout(function () {
			resolve([{id: Date.now(), title: task.title}]);
		}, 3000);

	});
}

function fakeRequest() {
	return new Promise((resolve, reject) => {
		setTimeout(function () {
			resolve([{id: 1, title: 'make the dinner'}, {id: 2, title: 'make the laundry'}]);
		}, 3000);

	});
}
//--------------------------------------------------------------------------

function ADD_POST_TASK(action, dispatch, state) {
	console.log('Post request', state)
	fakePostRequest(state.todoList.taskForm)
		.then(response => {
			dispatch(actions.ADD_TASK({ taskForm: response }))
		})
}
function REQUEST_TASKS(action, dispatch, state) {
	console.log('requesting tasks......', state);
	fakeRequest()
	.then(response => {
		dispatch(actions.SET_TASKS({ tasks: response }))
	})
	.catch(error => {
		console.error(error);
	});
}

function todoListMiddleware(action, dispatch, state) {

  switch(action.type) {
    case 'REQUEST_TASKS':
			return REQUEST_TASKS(action, dispatch, state);
		case 'ADD_POST_TASK':
			return ADD_POST_TASK(action, dispatch, state);
    default: 
      return state;
	}
}

export default todoListMiddleware;