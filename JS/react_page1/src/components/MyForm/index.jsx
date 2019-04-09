import React, { Component } from 'react'
import PeoplePicker from '../PeoplePicker'
import MyInput from '../MyInput'
import './MyForm.css'

function MyForm ({members, people, onPillChange, inputHandler}) {
 
  return (
    <div className='form-component'>
      <PeoplePicker people={people}
          size={100}
          actions={onPillChange}
          activeMembers={members} />
    </div>
  )
}

export default MyForm
