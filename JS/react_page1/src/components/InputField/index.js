import React from 'react'
import './InputField.css'

function InputField ({ onChange, autoFocus, errorMessage, label, placeholder }) {
  console.log(people)

  const _handlerChange = () => {
    { onChange };
  }

  var _inputValue = placeholder
  if (errorMessage) _inputValue = errorMessage

  return (
    <div className='inputfield-component'>
      <label>{label}
        <input type='text' onChange={_handlerChange} autoFocus={autoFocus} value={_inputValue} />
      </label>
    </div>
  )
}

export default PeoplePicker
