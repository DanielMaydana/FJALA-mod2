
import React from 'react';
import MaterialIcon from 'material-icons-react';
import './index.css';

function MyToolBar({tittle, actions}) {
    return (

        <div className = "toolbar-component"> {tittle}
        {( () => {
            var createdButtons = [];
            actions.forEach(element => {
                createdButtons.push(
                    <button key={element.id} onClick={element.onClick} className={element.position}>
                        <MaterialIcon icon={element.icon}/>
                    </button>
                );
            });
            return createdButtons;
        })()}
        </div>
    );
}

export default MyToolBar;