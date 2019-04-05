import React from 'react'
import './MyInput.css'

// type: default, primary, warning, info

function MyInput ({ onChange, autoFocus, errorMessage, label, placeholder }) {
  let message = ''
  if (errorMessage) message = <div className='err-message'>{errorMessage}</div>

  return (
    <div className='myinput-component'>
      <div className='label'>{label}</div>
      <input type='text' placeholder={placeholder} autoFocus={autoFocus} />
      {message}
    </div>
  )
}

export default MyInput
