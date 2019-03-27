import React from 'react';
import PersonPill from '../PersonPill'
import './PeoplePicker.css';

function PeoplePicker({people, size}) {
    
    console.log(people);
    const pills = people.map(person => <PersonPill key={person.id} src={person.avatar} name={person.name} size={size}/>);

    return (
        <div className="peoplepicker-component">
            {pills}            
        </div>
    );
}

export default PeoplePicker;