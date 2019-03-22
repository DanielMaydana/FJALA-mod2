
export default class Elements{
    constructor(){
        this.principal = document.querySelector('#to-do-app');
        this.divContent = document.createElement('div'); 
        this.data = document.createElement('input');
        this.button = document.createElement('button');
    }

    initElements(item){
        this.button.setAttribute("id", "delete");
        this.data.setAttribute("id", "inputData");
        this.principal.appendChild(this.divContent);
        this.divContent.appendChild(this.data);
        this.divContent.appendChild(this.button);
        this.divContent.classList.add('task');
        this.button.textContent = "Delete";
        this.data.setAttribute('value', item.title);
    }
}