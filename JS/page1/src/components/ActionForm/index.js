import React from 'react';
// import Form from './Form'
import './ActionForm.css';

function ActionForm({children, actions}) {
    
    // const pills = people.map(person => <PersonPill key={person.id} id={person.id} src={person.avatar} name={person.name} size={size} actions={actions} isActive={activeMembers.includes(person.id)}/>);
    return (
        <div className="actionform-component">
            {children}
            {
                actions.map((action) => {
                    console.log(action);
                    // return <p>BRMC</p>;
                })
            }
        </div>
    );
}

export default ActionForm;