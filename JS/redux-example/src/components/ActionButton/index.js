import React from 'react';
import Icon from 'material-icons-react';
import Ink from 'react-ink'
import PropTypes from 'prop-types';
import './actionButton.css';

const BUTTON_TYPES = {
  primary: 'primary',
  danger: 'danger',
  default: 'default'
};

/**
Use our custom button styles for actions in forms, dialogs, and more.
*/

function ActionButton({text, type, icon, onClick, disabled}) {
  const buttonClass = BUTTON_TYPES[type];
  
  return (
    <button className={`action-button-component ${buttonClass}`} onClick={onClick} disabled={disabled} >
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
  onClick: () => {},
  disabled: false,
};

ActionButton.propTypes = {
  /** The text on the button */
  text: PropTypes.string,
  /** The type of style of the button */
  type: PropTypes.string,
  /** The name of the icon class from material-icons */
  icon: PropTypes.string,
  /** The callback to execute when it's clicked-on */
  onClick: PropTypes.func,
  /** Enables or disables the button */
  disabled: PropTypes.bool,
}

export default ActionButton;