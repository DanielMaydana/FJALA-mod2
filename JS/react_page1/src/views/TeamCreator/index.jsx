import React, { Component } from 'react';
import Form from '../../components/MyForm'
import ActionForm from '../../components/ActionForm'

import leah from '../../images/leah1.jpg'
import rob from '../../images/rob1.jpg'
import pete from '../../images/peter1.jpg'
import jont from '../../images/jont1.jpg'
import daveg from '../../images/daveg.jpg'

class TeamCreator extends Component {

    constructor(){
        super();
        this.state = {
            err_msg : "This is an error message",
            selectedPeople : [],
            people : [
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
                    name: 'David Gilmour',
                    id: 985433,
                    avatar: daveg,
                    isActive: false
                }, {
                    name: 'Peter Hayes',
                    id: 324444,
                    avatar: pete,
                    isActive: false
                }, {
                    name: 'Anthony Bourdain',
                    id: 325454,
                    email: 'abourdain@cnn.com',
                    isActive: false
                }, {
                    name: 'Jon Theodore',
                    id: 676744,
                    avatar: jont,
                    email: 'jtheodore@qotsa.com',
                    isActive: false
                }, {
                    name: 'Yoko Kanno',
                    id: 523488,
                    email: 'catsinmars@cbbp.com',
                    isActive: false
                }
            ],
            actionButtons : [
                {
                    onClick: this.onButtonClicked,
                    textButton: 'Save Team',
                    iconButton: 'save',
                    typeButton: 'warning',
                    isDisabled: false,
                    isLoading: false,
                }, {
                    onClick: this.onButtonClicked,
                    textButton: 'Settings',
                    iconButton: 'settings',
                    typeButton: 'info',
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
        
        if(_foundId)
        {
            let _auxIndex = _copySelectedPeople.indexOf(_foundId);
            _copySelectedPeople.splice(_auxIndex, 1);
            _copyPeople.map(element => 
                console.log(element.id + ' rose'
            ));
        }
        else
        {
            _copySelectedPeople.push(idToFind);
        }
        this.setState({
            ...this.state,
            selectedPeople : _copySelectedPeople
        });
        // console.log(_copySelectedPeople);
    }

    onButtonClicked = (text) => {
        console.log(text);
    }

    inputHandler = (text) => {
        console.log('Input Handler ' + text);
    }

    render() {

        return (
            <div className="App">
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