
import React from 'react';
import './Avatar.css';

var getInitials = function (text) {
    
    var names = text.split(' '),
    initials = names[0].substring(0, 1).toUpperCase();
    
    if (names.length > 1) {
        initials += names[names.length - 1].substring(0, 1).toUpperCase();
    }
    return initials;
};

function Avatar({src, name, size}) {
    
    var initials = '';
    if(name) initials = getInitials(name);
    
    const roundImage = <img className="round-identifier" src={src} alt=""/>;
    const roundInitials = <div className="round-identifier"><p>{initials}</p></div>;
    
    const style_size = {
        width : size + 'px',
        height : size + 'px'
    }

    const circleIdentifier = src ? roundImage : roundInitials;

    return (
        <div className = "avatar-component" style={style_size}>
            {circleIdentifier}
        </div>
    );
}

export default Avatar;