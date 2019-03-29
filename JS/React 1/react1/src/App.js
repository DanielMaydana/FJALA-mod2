import React, { Component } from 'react';
import MyToolBar from './components/MyToolBar';
import Form from './components/Form'
import './App.css';

class App extends Component {
  printButtonName(text) {
    console.log(text + ' was clicked');
  }
  constructor(props) {
    super(props);
    this.state = {
      bigName: 'MyPlants v0.0',
      buttons: [
        {
          name: 'Home',
          id: Math.random(),
          position: 'left',
          icon: 'home',
          onClick: () => {
            this.printButtonName('Home');
          }
        }, {
          name: 'MyAccount',
          id: Math.random(),
          position: 'right',
          icon: 'account_circle',
          onClick: () => {
            this.printButtonName('MyAccount');
          }
        }, {
          name: 'Levels',
          id: Math.random(),
          position: 'left',
          icon: 'layers',
          onClick: () => {
            this.printButtonName('Levels');
          }
        }]
    };
  }

  render() {
    return (
      <div className="App">
        <MyToolBar tittle={this.state.bigName} actions={this.state.buttons}/>
        <Form/>
      </div>
    );
  }
}

export default App;
