import React from 'react';
import './inputField.css';

function InputField({label, onChange, objectKey, autoFocus, loading, onPressEnter, value }) {

  const handleInputRef = node => {
    !loading && autoFocus && node && node.focus();
  };

  const handleOnChange = event => {
    onChange(objectKey, event.target.value);
  };

  const handleKeyPress = event => {

    if(event.key === 'Enter') {
      onPressEnter();
      event.preventDefault();
      event.stopPropagation();
    }
  };

  return (
    <section className="input-field-component">
      <input
        onKeyPress={handleKeyPress}
        disabled={loading}
        ref={handleInputRef}
        value={value}
        onChange={handleOnChange}
      />
      <label> {label} </label>
    </section>
  );
}

export default InputField;