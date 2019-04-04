import React from 'react';
// import Form from './Form'
import './ActionForm.css';

function ActionForm({title, children, actions}) {
    
    // const pills = people.map(person => <PersonPill key={person.id} id={person.id} src={person.avatar} name={person.name} size={size} actions={actions} isActive={activeMembers.includes(person.id)}/>);
    const _children = React.Children.only(children);// renderiza formulario dentro de este action form, es mas limpio    
    return (
        <div className="actionform-component">
            {_children}
            {title}
        </div>
    );
}

export default ActionForm;