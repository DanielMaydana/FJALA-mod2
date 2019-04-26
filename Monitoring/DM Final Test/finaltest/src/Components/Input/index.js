import React from 'react';
import PropTypes from 'prop-types';
import './input-style.css';

function Input({ onChange, onBlur, label, placeholder, errormessage, autofocus, value, type, objectKey }) {

  const handleOnChange = event => {
    onChange(objectKey, event.target.value);
  };

  const handleOnBlur = event => {
    onBlur(objectKey);
  };

  return (
    <div className="form-field form-field-invalid">
        <input type={type} required={true} value={value} onChange={handleOnChange} onBlur={handleOnBlur} autoFocus={autofocus} placeholder={placeholder}></input>
        <label className="form-field-label" htmlFor="field-text">{label}</label>
        <label className="form-field-label-error">{errormessage}</label>
    </div>
  )
}

Input.propTypes = {
  value: PropTypes.string,
  onChange: PropTypes.func,
  autoFocus: PropTypes.bool,
  errormessage: PropTypes.string,
  label: PropTypes.string,
  placeholder: PropTypes.string,
  type: PropTypes.string,
  objectKey: PropTypes.string
};

Input.defaultProps = {
  value: '',
  onChange: function () { },
  autoFocus: false,
  errormessage: '',
  label: '',
  placeholder: '',
  type: ''
};

export default Input;