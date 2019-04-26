import './ticketform-style.css';
import React from 'react';
import PropTypes from 'prop-types';

import Input from '../../Components/Input';
import Dropdown from '../../Components/Dropdown';
import ButtonComponent from '../../Components/Button';

function TicketForm({ dropdownArray, inputLabel, buttonState, buttonOnClick, buttonText }) {
  const saveOnClick = ()=> {
    buttonOnClick();
  }

  return (
    <div className='register-form'>
        <Dropdown></Dropdown>
        <Input></Input>
        <ButtonComponent></ButtonComponent>
    </div>
  );
}

TicketForm.defaultProps = {
    dropdownArray: [],
    inputLabel: '',
    buttonState: false,
    buttonOnClick: () => {},
    buttonText: ''
};

TicketForm.propTypes = {
    dropdownArray: PropTypes.array,
    inputLabel: PropTypes.string,
    buttonState: PropTypes.bool,
    buttonOnClick: PropTypes.func,
    buttonText: PropTypes.string
};

export default TicketForm;