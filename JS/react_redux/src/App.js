import React, { Component } from 'react';
import './App.css';
import Timer from './components/Timer'
import Slider from './components/Slider'
import CircularSlider from './components/CircularSlider'

class App extends Component {

  render() {

    return (
      <div className="App">
        {/* <CircularSlider /> */}
        <Slider steps={10} size={120} />
      </div>
    );
  }
}

export default App;
