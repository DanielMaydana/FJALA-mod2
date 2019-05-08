import React from 'react';
import PropTypes from 'prop-types';
import Icon from 'material-icons-react';
import './toolbar.css';
import Ink from 'react-ink'

const POSITIONS = {
  LEFT: 'left',
  RIGHT: 'right',
};

function Buttons({actions}) {
  return (
    actions.map((action, index) => {
      return (
        <div className="buttons-component" onClick={action.onClick} key={index}>
          <Ink />
          <Icon icon={action.icon}/>
        </div>
      )
    })
  );
};

Buttons.propTypes = {
  actions: PropTypes.arrayOf(
    PropTypes.shape({
      onClick: PropTypes.func,
      icon: PropTypes.string,
      position: PropTypes.string,
    })
  ),
};

Buttons.defaultProps = {
  actions: []
};

function Toolbar({title, actions}) {
  const leftActions = actions.filter(action => action.position === POSITIONS.LEFT);
  const rigthActions = actions.filter(action => action.position === POSITIONS.RIGHT);

  return (
    <section className="toolbar-component">
      <div className="left-actions actions">
        <Buttons actions={leftActions} />
      </div>
      <div className="title">
        {title}
      </div>
      <div className="rigth-actions actions">
        <Buttons actions={rigthActions} />
      </div>
    </section>
  );
}

Toolbar.defaultProps = {
  title: '',
  actions: []
}

Toolbar.propTypes = {
  title: PropTypes.string,
  actions: PropTypes.arrayOf(
    PropTypes.shape({
      onClick: PropTypes.func,
      icon: PropTypes.string,
      position: PropTypes.string,
    })
  ),
}

export default Toolbar;