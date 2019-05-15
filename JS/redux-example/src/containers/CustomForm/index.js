import React from 'react';
import InputField from '../../components/InputField';
import PropTypes from 'prop-types';

function PersonForm({ inputs }) {

  const inputFields = inputs.map((inputField, index) =>
    <InputField
      key={index}
      label={inputField.label}
      onChange={inputField.onChange}
      objectKey={inputField.objectKey}
      value={inputField.value}
      type={inputField.type}
    />
  );

  return (
    <div className="person-form">
      {inputFields}
    </div>
  );
}

PersonForm.defaultProps = {
  inputs: [],
}

PersonForm.propTypes = {
  inputs: PropTypes.arrayOf(
    PropTypes.shape({
      label: PropTypes.string,
      onChange: PropTypes.func,
      objectKey: PropTypes.string,
      autoFocus: PropTypes.bool,
      loading: PropTypes.bool,
      value: PropTypes.string
    })
  ),
}

export default PersonForm;