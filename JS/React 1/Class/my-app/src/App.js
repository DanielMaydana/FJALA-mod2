import React from 'react';
import './App.css';
import Toolbar from './components/toolbar'
import MainLayout from './containers/MainLayout'
class App extends React.Component {

  constructor(props) {
    super();
    this.title = 'DEV272';
    this.id = 'toolbar';
  }

  createPeople() {
    console.log('asdasdasd')
  }

  render() {
    return (
      <div className="my-app">
      <MainLayout></MainLayout>
        <Toolbar title={this.title + this.id} id={this.id}/>
      </div>
    );
  }
}

export default App;
