import React from 'react';
import { connect } from 'react-redux';
import actions from './actions';

import './style-tickets.css';
import TicketForm from '../../Containers/TicketForm';

class CreateTicket extends React.Component {
  constructor() {
    super();
    this.state = {
      buttonState : false,

    }
  }
  render() {
    const raffleType = [
      'Cine NORTE',
      'Aniversario Fundacion',
      'SCRUM fundamentals',
      'MONGO DB básico'
    ];

    const actions = [

    ];
    
    return (
      <div>
        {/* <TicketForm dropdownArray={raffleType} inputLabel={''} buttonState={false} buttonOnClick={} buttonText={}/> */}
        <TicketForm/>
      </div>
    )
  }
}

const mapStatesToProps = (state) => {
  return {
    name: state.buttonState,
    
  }
}

const mapDispatchToProps = (dispatch) => {
  return {

  }
}


export default connect(mapStatesToProps, mapDispatchToProps)(CreateTicket);
