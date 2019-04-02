import React from 'react';
import MaterialIcon from 'material-icons-react';
import './IconButton.css';

function IconButton({onClick, className, icon}){
    return (
        <div className = "iconbutton-component">
            <button onClick={onClick} className={className}>
                <MaterialIcon icon={icon}/>
            </button>
        </div>
    );
}

export default IconButton;