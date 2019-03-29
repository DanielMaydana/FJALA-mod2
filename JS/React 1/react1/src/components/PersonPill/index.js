import React from 'react';
import Avatar from '../Avatar'
import './PersonPill.css';

function PersonPill({id, src, name, size, actions}) {

    const style_A = {
        width : 4.25*size + 'px',
        height : 1.25*size + 'px',
        borderTopLeftRadius : (size/2) + 'px',
        borderBottomLeftRadius : (size/2) + 'px',
        borderTopRightRadius : (size/2) + 'px',
        borderBottomRightRadius : (size/2) + 'px'
    }

    const handler = () => {actions(id);}
    
    return (
        <div className="personpill-component"  style={style_A} onClick={handler}>
            <Avatar src={src} name={name} size={size}/>
            <div className="personpill-text"><p>{name}</p></div>
        </div>
    );
}

export default PersonPill;