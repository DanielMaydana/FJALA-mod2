import React from 'react'
import MyButton from '../MyButton'
import './ActionForm.css'

function ActionForm ({ children, actions }) {

  const _children = React.Children.only(children)// renderiza formulario dentro de este action form, es mas limpio

  const _buttons = actions.map((single_button) =>
    <MyButton key={Math.round(Math.random()*1000)}
      onClick={single_button.onClick}
      name={single_button.textButton}
      icon={single_button.iconButton}
      type={single_button.typeButton}
      disabled={single_button.isDisabled}
      isLoading={single_button.isLoading} />
  )
  return (
    <div className='actionform-component'>
      <div className="children-div">{_children}</div>
      <div className="buttons-div"> {_buttons}</div>
    </div>
  )
}

export default ActionForm
