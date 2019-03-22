import React, { Component } from 'react';
import MyToolBar from './components/MyToolBar';
import './App.css';

class App extends Component {
  printButtonName(text) {
    console.log(text + ' was clicked');
  }
  constructor()
  {
    super();
    this.bigName = 'MyPlants v0.0';
    // this.action = {
    //   printButtonName : function(text) {
    //     console.log(text + ' was clicked');
    //   }
    //   // (text){ console.log( 'I was clicked'); }
    // }

    this.buttons = [{
      name : 'Home',
      id : Math.random(),
      position: 'left',
      icon: 'home',
      onClick : (name) => {
        
        this.printButtonName(name);
        console.log(name);
      }
    }, {
      name : 'MyAccount',
      id : Math.random(),
      position: 'right',
      icon: 'account_circle',
      onClick : (name) => {
        this.printButtonName(name);
      }
    }, {
      name : 'Levels', 
      id : Math.random(),
      position : 'left',
      icon : 'layers',
      onClick : (name) => {
        this.printButtonName(name);
      }
    }];
  }
  
  render() {
    return (
      <div className="App">
        <MyToolBar tittle={this.bigName} actions={this.buttons}/>

      </div>
    );
  }
}

export default App;
