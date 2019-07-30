import React, { Component } from 'react';
import './App.css';
import Timer from './components/Timer'
import CircularSlider from './components/CircularSlider'

class App extends Component {

  render() {

    return (
      <div className="App">
        <CircularSlider />
      </div>
    );
  }
}

export default App;
