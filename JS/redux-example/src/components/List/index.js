import React from 'react';
import Icon from 'material-icons-react';
import Ink from 'react-ink'
import PropTypes from 'prop-types';
import './style-list.css';

/**
    Lists are continuous, vertical indexes of text.
*/


function List({ actions }) {

  const listItems = actions.map((item, index) => 
    


    <li key={index}>
      <div className="list-item">
      <Ink />
        <p>{item.name}</p>
        {/* <div className="primary-area"></div> */}
        {/* <div className="content-area"></div> */}
        {/* <div className="secondary-area"></div> */}
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
  // actions = 
};

List.propTypes = {

}

export default List;