import React from 'react';
import { connect } from 'react-redux';
import actions from './actions';
import InputField from '../../components/InputField';
import Toolbar from '../../components/Toolbar';
import Task from '../../components/Task';
import './todoList.css';
import ScrollContainer from '../../components/ScrollContainer';

class TodoList extends React.Component {
	
	componentDidMount() {
		this.props.requestTasks();
	}

	onScrolled = (position) => {
		console.log(position);
	};

	render() {
		const { tasks, taskForm } = this.props;
		return (
			<div className="todo-list-component">
				<Toolbar title="Todo list with redux" />
				<InputField
					onChange={this.handleChange}
					onPressEnter={this.handlePressEnter}
					label="Create a new task"
					objectKey="title"
					value={taskForm.title}
				/>
				<ScrollContainer onScroll={this.onScrolled}>

					{ tasks.map((task, index) => <Task
							key={index}
							index={index}
							toggleDone={this.handleToggleDone}
							title={task.title}
							isDone={task.isDone}
					/>)}

				</ScrollContainer>
			</div>
		);
	}

	handleChange = (key, value) => {
		this.props.updateForm({ key, value });
	}

	handlePressEnter = () => {
		this.props.addPostTask();
		this.props.clearForm();
	}

	handleToggleDone = (index, value) => {
		this.props.updateTask({index, key: 'isDone', value});
	}
}

const mapStatesToProps = (state) => {
  return {
		tasks: state.todoList.tasks,
		taskForm: state.todoList.taskForm,
  }
}

const mapDispatchToProps = (dispatch) => {
  return {
		addTask: () => dispatch(actions.ADD_TASK()),
		updateTask: payload => dispatch(actions.UPDATE_TASK(payload)),
		clearForm: () => dispatch(actions.CLEAR_FORM()),
		updateForm: (payload) => dispatch(actions.UPDATE_FORM(payload)),
		requestTasks: () => dispatch(actions.REQUEST_TASKS()),
		addPostTask: () => dispatch(actions.ADD_POST_TASK())
  }
}

export default connect(mapStatesToProps, mapDispatchToProps)(TodoList);
