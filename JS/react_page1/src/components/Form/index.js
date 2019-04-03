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
    clickedPersons = (idToFind) => {

        let _copyPeople = [...this.state.people];
        let _copyPeopleSelection = [...this.state.peopleSelection];
        let _foundId = _copyPeopleSelection.find((element) => element === idToFind);
        
        if(_foundId)
        {
            let _auxIndex = _copyPeopleSelection.indexOf(_foundId);
            _copyPeopleSelection.splice(_auxIndex, 1);
            _copyPeople.map(element => console.log(element.id + ' rose'));
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
                {/* <Form onChange={this.clickedPersons} autoFocus={true} errorMessage={''} label={'This is an input'} placeholder={'Input text here'}/> */}
                <PeoplePicker people={this.state.people} size={this.state.size} actions={this.clickedPersons} activeMembers={this.state.peopleSelection}/>
            </div>
        );
    }
  }
  
  export default Form;
  