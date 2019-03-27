
import React from 'react';
import MaterialIcon from 'material-icons-react';
import './MyToolBar.css';

function MyToolBar({tittle, actions}) {

    var createdButtons = actions.map(element =>
        <button key={element.id} onClick={element.onClick} className={element.position}>
            <MaterialIcon icon={element.icon}/>
        </button>
    );

    return (

        <div className = "toolbar-component"> {tittle}
            {createdButtons}
        </div>
    );
}

export default MyToolBar;