import React from 'react'
import { BrowserRouter as Router, Route, Link } from 'react-router-dom'
import TeamCreator from '../views/TeamCreator/'
import TeamEditor from '../views/TeamEditor/'
import MyToolBar from '../components/MyToolBar/'

function AppRouter () {
  return (
    <Router>
      <Route path='/' component={MyToolBar}/>
      <Route exact path='/team/create' component={TeamCreator} />
      <Route exact path='/team/edit' component={TeamEditor} />
      {/* <Route exact path='/team' component={TeamCreator} /> */}
    </Router>
  )
}

export default AppRouter
