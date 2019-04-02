import React from 'react';
import MaterialIcon from 'material-icons-react';
import './MyButton.css';

function MyButton({onClick, name, icon, disabled, type, isLoading}) {

    let thumbnail = <MaterialIcon icon={icon}/>;
    if(isLoading) thumbnail = '';
    
    return (
        <button onClick={onClick} disabled={disabled} className={`button-component ${type}`}>
            {thumbnail}
            <span> {name} </span>
        </button>
    );
}

export default MyButton;