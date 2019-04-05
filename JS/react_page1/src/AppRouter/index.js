import React from 'react'
import { BrowserRouter as Router, Route, Link } from 'react-router-dom'
import TeamCreator from '../views/TeamCreator/index'

function AppRouter () {

    return (
        <Router>
            <Route exact path='/team/create' component={TeamCreator} />
        </Router>
    )
}

export default AppRouter
