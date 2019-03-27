import React, { Component } from 'react';
import MyToolBar from './components/MyToolBar';
import Avatar from './components/Avatar';
import PersonPill from './components/PersonPill';
import './App.css';

class App extends Component {
  printButtonName(text) {
    console.log(text + ' was clicked');
  }
  constructor(props)
  {
    super(props);
    this.state = {
      bigName : 'MyPlants v0.0',
      size: 100,
      buttons : [{
        name : 'Home',
        id : Math.random(),
        position: 'left',
        icon: 'home',
        onClick : () => {
          this.printButtonName('Home');
        }
      }, {
        name : 'MyAccount',
        id : Math.random(),
        position: 'right',
        icon: 'account_circle',
        onClick : () => {
          this.printButtonName('MyAccount');
        }
      }, {
        name : 'Levels', 
        id : Math.random(),
        position : 'left',
        icon : 'layers',
        onClick : () => {
          this.printButtonName('Levels');
        }
      }],
      people : [
        {
          name: "Gregory Frederickson",
          id: "7c965aad-9986-4eb5-b80b-98f1d5ae2456",
          avatar: "https://lh3.googleusercontent.com/-8Y5l_IGCkc8/AAAAAAAAAAI/AAAAAAAAAAc/hP8pp2loX3I/s96-c/photo.jpg",
          isActive: true,
        }, {
          name: "Anthony Johnson",
          avatar: "https://lh4.googleusercontent.com/-Mq3J6qJaPdA/AAAAAAAAAAI/AAAAAAAAAAc/XRSfECwWYEA/s96-c/photo.jpg",
          email: "engageme.demo1@gmail.com"
        }, {
          name: "Ernest Hemingway",
          email: "cacodemon@gmail.com"
        }
      ]
    };
  }
  
  render() {
    return (
      <div className="App">
        <MyToolBar tittle={this.state.bigName} actions={this.state.buttons}/>
        <Avatar src={this.state.people[1].avatar} name={this.state.people[1].name} size={this.state.size}/>
        <Avatar src={this.state.people[2].avatar} name={this.state.people[2].name} size={this.state.size}/>
        <PersonPill people={this.state.people}/>

      </div>
    );
  }
}

export default App;
