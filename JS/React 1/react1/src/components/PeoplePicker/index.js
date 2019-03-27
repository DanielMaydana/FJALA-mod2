import React from 'react';
import PersonPill from '../PersonPill'
import './PersonPill.css';

function PeoplePicker({people, size}) {


    const pills = people.map(person => <PersonPill src={person.avatar} name={person.name} size={size}/>);

    const style_size = {
        width : 4.25*size + 'px',
        height : 1.25*size + 'px',
        borderTopLeftRadius : (size/2) + 'px',
        borderBottomLeftRadius : (size/2) + 'px',
        borderTopRightRadius : (size/2) + 'px',
        borderBottomRightRadius : (size/2) + 'px'
    }

    return (
        <div className="personpill-component" style={style_size}>
            <Avatar src={src} name={name} size={size}/>
            <p>{name}</p>
        </div>
    );
}

export default PeoplePicker;