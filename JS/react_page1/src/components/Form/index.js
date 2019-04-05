import React, { Component } from 'react';
import PeoplePicker from '../PeoplePicker';
import './Form.css';

class Form extends Component {
    
    constructor(props)
    {
        super(props);
        this.state = {
            size : 100,
            onChange : this.printPersonName,
            people : [
                {
                    name: "Antonio Sanchez",
                    id: Math.round(Math.random() * 10000),
                    avatar: "https://cdn2.iconfinder.com/data/icons/flatfaces-everyday-people-square/128/beard_male_man_face_avatar-512.png",
                    isActive: false
                }, {
                    name: "Gustavo Santaolalla",
                    id: Math.round(Math.random() * 10000),
                    email: "engageme.demo1@gmail.com",
                    isActive: false
                }, {
                    name: "Michael Been",
                    id: Math.round(Math.random() * 10000),
                    email: "cacodemon@gmail.com",
                    isActive: false
                }
            ],
            peopleSelection : []
        };
        
    }

    

    render() {
        return (
            <div className="form-component">
                {/* <Form onChange={this.clickedPersons} autoFocus={true} errorMessage={''} label={'This is an input'} placeholder={'Input text here'}/> */}
                <PeoplePicker people={this.state.people} size={this.state.size} actions={this.clickedPersons} activeMembers={this.state.peopleSelection}/>
            </div>
        );
    }
  }
  
  export default Form;
  