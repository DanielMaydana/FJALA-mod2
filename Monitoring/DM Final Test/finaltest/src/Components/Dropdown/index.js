import React from 'react';
import PropTypes from 'prop-types';
import './style-dropdown.css';

function Dropdown({ typesList, onClick, placeHolder, title }) {

  const onChangeHandler = event => {
    onClick(event.target.value);
  };

  const optionList = typesList.map((element, i) =>
    <option className='element-dropdown'
      key={i}
      value={element}>
      {element}
    </option>
  );

  return (
    <section className="dropdown-component">
      <label>{title}</label><br/>
      <select className="dropdown" onChange={onChangeHandler}>
        <option>{placeHolder}</option>
        {optionList}
      </select>
    </section>
  )
}

Dropdown.propTypes = {
  typesList: PropTypes.array,
  onClick: PropTypes.func,
  placeHolder: PropTypes.string,
  title: PropTypes.string,
};

Dropdown.defaultProps = {
  typesList: [],
  onClick: function () { },
  placeHolder: '',
  title: '',
};

export default Dropdown;