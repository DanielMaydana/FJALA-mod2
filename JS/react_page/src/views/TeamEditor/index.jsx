import React, { Component } from 'react';
import Form from '../../components/MyForm'
import ActionForm from '../../components/ActionForm'
import { GetTeam } from '../../Services/Rest.jsx'


import leah from '../../images/leah1.jpg'
import rob from '../../images/rob1.jpg'
import pete from '../../images/peter1.jpg'
import jont from '../../images/jont1.jpg'
import daveg from '../../images/daveg.jpg'

class TeamEditor extends Component {

    constructor() {
        super();
        this.state = {
            err_msg: "This is an error message",
            selectedPeople: [],
            teamName: '',
            people: [
                {
                    name: 'Leah Shapiro',
                    id: 220048,
                    avatar: leah,
                    isActive: false
                }, {
                    name: 'Robert Been',
                    id: 114289,
                    avatar: rob,
                    email: 'rbeen@hotmail.com',
                    isActive: false
                }, {
                    name: 'Peter Hayes',
                    id: 324444,
                    avatar: pete,
                    isActive: false
                }
            ],
            actionButtons: [
                {
                    onClick: this.onButtonClicked,
                    textButton: 'Remove Selected',
                    iconButton: 'cancel',
                    typeButton: 'warning',
                    isDisabled: false,
                    isLoading: false,
                }
            ]
        }
    }

    onPersonClicked = (idToFind) => {

        let _copyPeople = [...this.state.people];
        let _copySelectedPeople = [...this.state.selectedPeople];
        let _foundId = _copySelectedPeople.find((element) => element === idToFind);

        if (_foundId) {
            let _auxIndex = _copySelectedPeople.indexOf(_foundId);
            _copySelectedPeople.splice(_auxIndex, 1);
        }
        else {
            _copySelectedPeople.push(idToFind);
            console.log(idToFind);
        }
        this.setState({
            ...this.state,
            selectedPeople: _copySelectedPeople
        });
    }

    onButtonClicked = (text) => {
        console.log(text);
    }

    async componentDidMount() {
        const request = await GetTeam('1');

        this.setState({
            // ...this.state,
            selectedPeople: request.hc_people
        });
    }


    inputHandler = (text) => {
        console.log('Input Handler ' + text);
    }

    render() {

        return (
            <div className="App">
                <ActionForm actions={this.state.actionButtons}>
                    <Form members={this.state.selectedPeople}
                        people={this.state.people}
                        onPillChange={this.onPersonClicked}
                        inputHandler={this.inputHandler} />
                </ActionForm>
            </div>
        );
    }
}

export default TeamEditor;