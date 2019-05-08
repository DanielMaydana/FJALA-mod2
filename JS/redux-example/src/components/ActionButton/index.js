import React from 'react';
import Icon from 'material-icons-react';
import Ink from 'react-ink'
import './actionButton.css';

const BUTTON_TYPES = {
  primary: 'primary',
  danger: 'danger',
  default: 'default'
};

function ActionButton({text, type, icon, onClick, loading}) {
  const buttonClass = BUTTON_TYPES[type];
  const iconClass = loading ? 'animate-icon' : '';
  return (
    <button className={`action-button-component ${buttonClass} ${iconClass}`} onClick={onClick} disabled={loading}>
      <Ink />
      {icon && <Icon icon={icon} /> }
      <span>{text}</span>
    </button>
  );
}

ActionButton.defaultProps = {
  text: '',
  type: 'default',
  icon: null,
};

export default ActionButton;