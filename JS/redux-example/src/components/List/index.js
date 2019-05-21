import React from 'react';
import Ink from 'react-ink'
import PropTypes from 'prop-types';
import './list.css';

/**
    Lists are continuous, vertical indexes of text.
*/

function List({ actions }) {

  const listItems = actions.map((item, index) => 
    
    <li key={index}>
      <div className="list-item">
      <Ink />
        <p>{item.name}</p>
      </div>
    </li>
  );

  return (
    <div className="list-component">
      {listItems}
    </div>
  );
}

List.defaultProps = {
  actions : []
};

List.propTypes = {
  actions: PropTypes.array
}

export default List;