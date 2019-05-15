import React, { useState } from 'react';
import PropTypes from 'prop-types';
import './inputField.css';

function InputField({ label, onChange, objectKey, autoFocus, loading, value, type }) {
  const [initialValue] = useState(value);


  const handleInputRef = node => {
    !loading && autoFocus && node && node.focus();
  };

  const handleOnChange = event => {
    onChange(objectKey, event.target.value);
  };

  const isDirty = value === initialValue ? '' : 'dirty';
  return (
    <section className="input-field-component">
      <input className={isDirty}
        disabled={loading}
        ref={handleInputRef}
        value={value}
        onChange={handleOnChange}
        type={type}
      />
      <label> {label} </label>
    </section>
  );
}

InputField.defaultProps = {
  label: '',
  objectKey: '',
  autoFocus: false,
  loading: false,
  value: '',
  type: 'text'
}

InputField.propTypes = {
  /** A label next to the input */
  label: PropTypes.string,
  /** The callback to be executed with an action, that has for parameters the key and value of the input */
  onChange: PropTypes.func,
  /** A unique identifier for the component  */
  objectKey: PropTypes.string,
  /** Places the cursor inside the field   */
  autoFocus: PropTypes.bool,
  /** Enables or disables the input wether a request is going on */
  loading: PropTypes.bool,
  /** The text inside the field */
  value: PropTypes.string,
  /** The input type */
  type: PropTypes.string
}

export default InputField;