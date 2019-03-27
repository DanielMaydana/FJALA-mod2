
import './Form.css';
import React from 'react';
import PeoplePicker from '../PeoplePicker';

class Form extends Component {
    printPersonName(text) {
      console.log(text + ' was clicked');
    }
    constructor(props)
    {
        super(props);
        this.state = {
            size : 100,
            onChange : this.printPersonName,
            people : [
                {
                    name: "Gregory Frederickson",
                    id: "7c965aad-9986-4eb5-b80b-98f1d5ae2456",
                    avatar: "https://lh3.googleusercontent.com/-8Y5l_IGCkc8/AAAAAAAAAAI/AAAAAAAAAAc/hP8pp2loX3I/s96-c/photo.jpg",
                    isActive: true,
                }, {
                    name: "Anthony Johnson",
                    id: "7c965aad-9986-4eb5-b80b-98f1d5ae2486",
                    avatar: "https://lh4.googleusercontent.com/-Mq3J6qJaPdA/AAAAAAAAAAI/AAAAAAAAAAc/XRSfECwWYEA/s96-c/photo.jpg",
                    email: "engageme.demo1@gmail.com"
                }, {
                    name: "Ernest Hemingway",
                    id: "7c965aad-9986-4eb5-b80b-98f1d5ae2451",
                    email: "cacodemon@gmail.com"
                }
            ]
        };  
    
    }
    
    render() {
      return (
        <div className="form-component">
            <PeoplePicker people={this.state.people} size={this.state.size} actions={this.state.onChange}/>
        </div>
      );
    }
  }
  
  export default Form;
  