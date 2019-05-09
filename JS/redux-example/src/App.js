import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';
import TodoList from './views/TodoList'

class App extends Component {
  render() {

    const REACT_VERSION = React.version;
    console.log(REACT_VERSION);
    return (
      <div className="App">
        <TodoList />
      </div>
    );
  }
}

export default App;
