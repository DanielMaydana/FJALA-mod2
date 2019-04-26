import React from "react";
import { BrowserRouter, Route, Switch } from "react-router-dom";
import CreateTicket from '../View/CreateTicket';

function Routes() {
  return (
    <React.Fragment>
      <BrowserRouter>
        <Switch>
          <Route exact path="/TicketCreation" component={CreateTicket}/>
          {/* <Route exact path="/MyTicket" component={MyTicket}/> */}
        </Switch>
      </BrowserRouter>
    </React.Fragment>
  )
}

export default Routes;
