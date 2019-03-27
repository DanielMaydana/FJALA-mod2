
import React from 'react';
import './Avatar.css';

function Avatar({src, name, size}) {
    const initials = name[0];
    const roundImage = <img src={src} alt=""/>;
    const roundInitials =
        <div className="round-initials">
            <p>{initials}</p>
        </div>;
    
    const style_size = {
        width : size + 'px',
        height : size + 'px',
    }

    const finalRound = src ? roundImage : roundInitials;

    return (
        <div className = "avatar-component" style={style_size}>
            {finalRound}
        </div>
    );
}

export default Avatar;