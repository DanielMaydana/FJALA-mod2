
import React from 'react'
import IconButton from '../IconButton'
import './MyToolBar.css'

function MyToolBar ({ tittle, actions }) {

  var toolbarButtons = actions.map(element =>

      <IconButton key={element.id} onClick={element.onClick} icon={element.icon} />
  )

  return (

    <div className='toolbar-component'>
      <div className="title-div"> {tittle} </div>
      <div className="button-div"> {toolbarButtons} </div>
    </div>
  )
}

export default MyToolBar
