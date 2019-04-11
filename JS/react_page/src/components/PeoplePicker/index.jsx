import React from 'react'
import PersonPill from '../PersonPill'
import './PeoplePicker.css'

function PeoplePicker ({ people, size, actions, activeMembers }) {
  // console.log(activeMembers.includes(people[0].id))

  const pills = people.map(person =>
    <PersonPill key={person.id}
      id={person.id}
      src={person.avatar}
      name={person.name}
      size={size}
      actions={actions}
      isActive={activeMembers.includes(person.id)} />)
  return (
    <div className='peoplepicker-component'>
      {pills}
    </div>
  )
}

export default PeoplePicker
