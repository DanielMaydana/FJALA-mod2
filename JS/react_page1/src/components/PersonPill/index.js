import React from 'react';
import Avatar from '../Avatar'
import './PersonPill.css';

function PersonPill({id, src, name, size, actions, isActive}) {

    const style_A = {
    }

    const handler = () => {actions(id);}
    
    let addedClass = '';

    if(isActive) addedClass = 'clicked';

    return (
        <div className={`personpill-component ${addedClass}`} style={style_A} onClick={handler} size={size}>
            <Avatar src={src} name={name} size={size}/>
            <div className="personpill-text"><p>{name}</p></div>
        </div>
    );
}

export default PersonPill;