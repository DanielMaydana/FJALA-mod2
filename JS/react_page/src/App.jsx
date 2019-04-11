import React, { Component } from 'react'
import Form from './components/MyForm'
import MyButton from './components/MyButton'
import MyToolBar from './components/MyToolBar'
import ActionForm from './components/ActionForm'
import MyInput from './components/MyInput'
import AppRouter from './AppRouter/index'

import './App.css'

class App extends Component {
  constructor (props) {
    super(props)
    this.state = {

    }
  }


  render () {
    return (
      <div className='App'>
        {/* <MyToolBar tittle={this.state.bigName} actions={this.state.buttons} /> */}
        <AppRouter />
      </div>
    )
  }
}

export default App
