import React from 'react'
import MaterialIcon from 'material-icons-react'
import './MyButton.css'

// type: default, primary, warning, info

function MyButton ({ onClick, name, icon, disabled, type, isLoading }) {
  let thumbnail = <MaterialIcon icon={icon} />
  if (isLoading) thumbnail = <div className='lds-dual-ring' />

  return (
    <button onClick={onClick} disabled={disabled} className={`button-component ${type}`}>
      <span> {name} </span>
      {thumbnail}
    </button>
  )
}

export default MyButton
