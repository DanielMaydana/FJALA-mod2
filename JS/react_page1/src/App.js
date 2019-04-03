import React, { Component } from 'react';
import Form from './components/Form';
import MyButton from './components/MyButton';
import MyToolBar from './components/MyToolBar';
import ActionForm from './components/ActionForm';
// import MyInput from './components/MyInput';
import './App.css';

class App extends Component {

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
        }],
      newActions : [
        {
          text: 'Register',
          type: 'button',
          isLoading: false,
          onClick: []
        },{
          text: 'Cancel',
          type: 'button',
          isLoading: false,
          onClick: []
        },{
          text: 'Done',
          type: 'button',
          isLoading: false,
          onClick: []
        }
      ]
    };
  }
  
  printButtonName(text) {
    console.log(text + ' was clicked');
  }

  render() {
    return (
      <div className="App">
        {/* <MyToolBar tittle={this.state.bigName} actions={this.state.buttons}/> */}
        {/* <ActionForm actions={this.state.newActions}> */}
          {/* <Form/> */}
        {/* </ActionForm> */}
        <MyButton onClick={()=>{}} name={'BRMC'} icon={'settings_power'} disabled={false} type={'warning'} isLoading={true}/>
        <MyButton onClick={()=>{}} name={'QOTSA'} icon={'people'} disabled={false} type={'warning'} isLoading={false}/>
      </div>
    );
  }
}

export default App;
