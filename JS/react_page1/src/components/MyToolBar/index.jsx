
import React from 'react'
import IconButton from '../IconButton'
import './MyToolBar.css'

function MyToolBar ({ tittle, actions }) {

  var createdButtons = actions.map(element =>
    
    <IconButton key={element.id} className={element.position} onClick={element.onClick} icon={element.icon} />
  )

  return (

    <div className='toolbar-component'>
      {createdButtons}
      <p>{tittle}</p>
    </div>
  )
}

export default MyToolBar
