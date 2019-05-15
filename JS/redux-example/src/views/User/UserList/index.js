import React from 'react';
import { connect } from 'react-redux';
import actions from './actions';

class UserList extends React.Component {

  ListUser = () => {
    this.props.getUsers();
  }

  render() {
    const { users } = this.props;
    console.log("users", users);
    return (
      <div className="user-list">
        <button onClick={this.ListUser}>Get Users</button>
      </div>
    );
  }
}

const mapStatesToProps = (state) => {
  return {
    users: state.listUser.users,
  }
}

const mapDispatchToProps = (dispatch) => {
  return {
    getUsers: () => dispatch(actions.REQUEST_GET_USERS()),
  }
}

export default connect(mapStatesToProps, mapDispatchToProps)(UserList);
