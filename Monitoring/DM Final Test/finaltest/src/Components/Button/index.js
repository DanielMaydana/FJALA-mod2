import React from 'react';
import PropTypes from 'prop-types';
import './style-button.css';

const ButtonComponent = ({ onClick, disabled, text}) => {
  
  const onClickButton = () => {
    onClick();
  }

  return (
    <button className={"button-component"} disabled={disabled} onClick={onClickButton}>
      <div>{text}</div>
    </button>
  )
};

ButtonComponent.defaultProps = {
  onClick: () => { },
  disabled: false,
  text: ''
}

ButtonComponent.propTypes = {
  onClick: PropTypes.func,
  disabled: PropTypes.bool,
  text: PropTypes.string
}

export default ButtonComponent;