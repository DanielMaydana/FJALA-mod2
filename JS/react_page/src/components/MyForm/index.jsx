import React from 'react'
import PeoplePicker from '../PeoplePicker'
import MyInput from '../MyInput'
import './MyForm.css'

function MyForm({ members, people, onPillChange, inputHandler }) {
    return (
        <div className='form-component'>
            <PeoplePicker people={people} size={100} actions={onPillChange} activeMembers={members} />
            <MyInput onChange={inputHandler} autoFocus={true} errorMessage={''} label={'Enter team name'} placeholder={''} />
        </div>
    )
}

export default MyForm
