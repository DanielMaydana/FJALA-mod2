import React from 'react'
import './Avatar.css'

var getInitials = function (text) {
  var names = text.split(' ')
  var initials = names[0].substring(0, 1).toUpperCase()

  if (names.length > 1) {
    initials += names[names.length - 1].substring(0, 1).toUpperCase()
  }
  return initials
}

function Avatar ({ src, name, size }) {
  var initials = name ? getInitials(name) : ''

  const avatarImage = <img className='thumbnail' src={src} />
  const avatarInitials = <div className='thumbnail'><p>{initials}</p></div>

  const style_size = {
    width: size + 'px',
    height: size + 'px'
  }

  // const avatar = src ? avatarImage : avatarInitials

  var avatar;
  if(src)
  {
    avatar = avatarImage;
    console.log(src);
  }
  else avatar = avatarInitials;

  return (
    <div className='avatar-component' style={style_size}>
      {avatar}
    </div>
  )
}

export default Avatar
