// import DataBase from "../sergio/database";

export default class Entry{
    constructor(dbTask){
        this.parentDiv = document.getElementById('to-do-app');
        this.div = document.createElement('div');
        this.input = document.createElement('input');
        this.button = document.createElement('button');

        this.div.setAttribute('class', 'task');
        this.div.setAttribute('id', dbTask.id);
        this.input.setAttribute('value', dbTask.title);
        this.button.textContent = 'Remove';
        this.div.appendChild(this.input);
        this.div.appendChild(this.button);
        this.parentDiv.appendChild(this.div);
    }
}