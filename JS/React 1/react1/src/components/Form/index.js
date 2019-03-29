import React, { Component } from 'react';
import PeoplePicker from '../PeoplePicker';
// import Form from '../Form';
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
                    name: "Gregory Frederickson",
                    id: Math.round(Math.random() * 10000),
                    avatar: "https://lh3.googleusercontent.com/-8Y5l_IGCkc8/AAAAAAAAAAI/AAAAAAAAAAc/hP8pp2loX3I/s96-c/photo.jpg",
                    isActive: false
                }, {
                    name: "Anthony Johnson",
                    id: Math.round(Math.random() * 10000),
                    avatar: "https://lh4.googleusercontent.com/-Mq3J6qJaPdA/AAAAAAAAAAI/AAAAAAAAAAc/XRSfECwWYEA/s96-c/photo.jpg",
                    email: "engageme.demo1@gmail.com",
                    isActive: false
                }, {
                    name: "Ernest Hemingway",
                    id: Math.round(Math.random() * 10000),
                    email: "cacodemon@gmail.com",
                    isActive: false
                }
            ],
            peopleSelection : []
        };
        
    }
    clickedPersons = (idToFind) => {

        let _copyPeople = [...this.state.people];
        let _copyPeopleSelection = [...this.state.peopleSelection];
        let _foundId = _copyPeopleSelection.find((element) => element === idToFind);
        
        if(_foundId)
        {
            let _auxIndex = _copyPeopleSelection.indexOf(_foundId);
            _copyPeopleSelection.splice(_auxIndex, 1);
            _copyPeople.map(element => console.log(element.id + ' spread'));
        }
        else
        {
            _copyPeopleSelection.push(idToFind);
        }
        this.setState({
            ...this.state,
            peopleSelection : _copyPeopleSelection
        });
        console.log(_copyPeopleSelection);
    }
    render() {
        return (
            <div className="form-component">
                <Form onChange={this.clickedPersons} autoFocus={true} errorMessage={''} label={'This is an input'} placeholder={'Input text here'}/>
                <PeoplePicker people={this.state.people} size={this.state.size} actions={this.clickedPersons}/>
            </div>
        );
    }
  }
  
  export default Form;
  