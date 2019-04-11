import React, { Component } from 'react';
import {withRouter} from 'react-router';
import IconButton from '../IconButton'
import './MyToolBar.css'

class MyToolBar extends Component{

  constructor (props) {
    super(props)
    this.state = {
      title: 'Super Band Lineup',
      buttons: [
        {
          name: 'Home',
          id: Math.round(Math.random() * 10000),
          position: 'left',
          icon: 'home',
          onClick: () => {
            this.redirectTo('/');
            this.printButtonName('Home')
          }
        }, {
          name: 'Band members',
          id: Math.round(Math.random() * 10000),
          position: 'right',
          icon: 'people',
          onClick: () => {
            this.printButtonName('Band Members')
            this.redirectTo('/team/create')
          }
        }, {
          name: 'Edit Band',
          id: Math.round(Math.random() * 10000),
          position: 'left',
          icon: 'library_music',
          onClick: () => {
            this.printButtonName('Levels')
            this.redirectTo('/team/edit')
          }
        }],
      newActions: [
        {
          text: 'Register',
          type: 'button',
          isLoading: false,
          onClick: []
        }, {
          text: 'Cancel',
          type: 'button',
          isLoading: false,
          onClick: []
        }, {
          text: 'Done',
          type: 'button',
          isLoading: false,
          onClick: []
        }
      ]
    }
  }

  redirectTo = (path) => {
    this.props.history.push(path);
  }

  printButtonName (text) {
    console.log(text + ' was clicked')
  }

  render() {

    var toolbarButtons = this.state.buttons.map(element =>
      <IconButton key={element.id} onClick={element.onClick} icon={element.icon} />
    )

    return (
      <div className='toolbar-component'>
        {/* <MyToolBar tittle={this.state.bigName}actions={this.state.buttons} /> */}
        <div className="title-div"> {this.state.title} </div>
        <div className="button-div"> {toolbarButtons} </div>
      </div>
    )
  }
}

export default withRouter(MyToolBar);
