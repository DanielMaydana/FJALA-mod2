import React, { Component } from 'react'
import AppRouter from './AppRouter/index'

import './App.css'

class App extends Component {
    constructor(props) {
        super(props)
        this.state = {

        }
    }


    render() {
        return (
            <div className='App'>
                {/* <MyToolBar tittle={this.state.bigName} actions={this.state.buttons} /> */}
                <AppRouter />
            </div>
        )
    }
}

export default App
