import React, { Component } from 'react';
import Form from '../../components/Form'
import ActionForm from '../../components/Form'

class TeamCreator extends Component {
    constructor(){
        super();
        this.state = {
            err_msg = "This is an error message",
            selectedPeople : [],
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
            
            actionButtons = [
                {
                    onClick: this.onButtonClicked,
                    textButton: 'Save Team',
                    iconButton: 'save',
                    typeButton: 'info',
                    isDisabled: false,
                    isLoading: false,
                }, {
                    onClick: this.onButtonClicked,
                    textButton: 'Save Team',
                    iconButton: 'save',
                    typeButton: 'warning',
                    isDisabled: false,
                    isLoading: false,
                }
            ]
        }
    }

    onPersonClicked = (idToFind) => {

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

    onButtonClicked = (text) => {
        console.log(text);
    }

    render() {

        return (
            <div className="App">
                <ActionForm accions = {accionsButton}>
                <Form members={this.state.members} people={this.state.people} onChangePill={this.onChangePill} handlerInput={this.handlerInput}></FormComponent>
                </ActionForm>
            </div>
        );
    } 

}