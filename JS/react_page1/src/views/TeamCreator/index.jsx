import React, { Component } from 'react';
import Form from '../../components/MyForm'
import ActionForm from '../../components/ActionForm'

class TeamCreator extends Component {
    constructor(){
        super();
        this.state = {
            err_msg : "This is an error message",
            selectedPeople : [],
            people : [
                {
                    name: 'Antonio Sanchez',
                    id: 220048,
                    avatar: 'https://cdn2.iconfinder.com/data/icons/flatfaces-everyday-people-square/128/beard_male_man_face_avatar-512.png',
                    isActive: false
                }, {
                    name: 'Gustavo Santaolalla',
                    id: 114289,
                    email: 'lastofusmusic@gmail.com',
                    isActive: false
                }, {
                    name: 'Michael Been',
                    id: 324444,
                    email: 'cacodemon@gmail.com',
                    isActive: false
                }
            ],
            
            actionButtons : [
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
        let _copyPeopleSelection = [...this.state.selectedPeople];
        let _foundId = _copyPeopleSelection.find((element) => element === idToFind);
        
        if(_foundId)
        {
            let _auxIndex = _copyPeopleSelection.indexOf(_foundId);
            _copyPeopleSelection.splice(_auxIndex, 1);
            _copyPeople.map(element => 
                console.log(element.id + ' rose'
            ));
        }
        else
        {
            _copyPeopleSelection.push(idToFind);
        }
        this.setState({
            ...this.state,
            selectedPeople : _copyPeopleSelection
        });
        console.log(_copyPeopleSelection);
    }

    onButtonClicked = (text) => {
        console.log(text);
    }

    inputHandler = (text) => {
        console.log('Input Handler ' + text);
    }

    render() {

        return (
            <div className="App">Hate the taste
                <ActionForm actions ={this.state.actionButtons}>
                    <Form members={this.state.selectedPeople}
                            people={this.state.people}
                            onPillChange={this.onPersonClicked}
                            inputHandler={this.inputHandler}/>
                </ActionForm>
            </div>
        );
    }
}

export default TeamCreator;