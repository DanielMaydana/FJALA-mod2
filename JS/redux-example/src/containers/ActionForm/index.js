import React, { useState, useEffect } from 'react';
import './ActionForm.css';
import ActionButton from '../../components/ActionButton';
import PropTypes from 'prop-types';


function ActionForm({ actions, title, children }) {
  const [disabled, setDisabled] = useState(false);
  const child = React.Children.only(children);

  useEffect(() => {
    const dirtyInputs = formRef.current.querySelectorAll('input.dirty');
    setDisabled(!!dirtyInputs.length);
  })

  const buttons = actions.map((button, index) =>
    <ActionButton
      key={index} text={button.text} type={button.type} icon={button.icon} onClick={button.onClick} loading={button.loading}
      disabled={button.type === 'primary' ? !disabled : false}>
    </ActionButton>);
  const formRef = React.createRef();
  return (
    <div className="action-form" ref={formRef}>
      <h1>{title}</h1>
      {child}
      {buttons}
    </div>
  );
}

ActionForm.defaultProps = {
  actions: [],
  title: ''
}

ActionForm.propTypes = {
  actions: PropTypes.arrayOf(
    PropTypes.shape({
      text: PropTypes.string,
      type: PropTypes.string,
      icon: PropTypes.string,
      onClick: PropTypes.func,
      loading: PropTypes.bool,
      dirty: PropTypes.bool,
    })
  ),
  title: PropTypes.string,
}

export default ActionForm;