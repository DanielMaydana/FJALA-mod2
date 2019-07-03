//import * as Incrementator from './IdCreator.js';

//Incrementator.GetIncrement()
//console.log(Incrementator.GetIncrement())

const input = document.querySelector('#add-input');
const body = document.getElementById('to-do-app');


input.addEventListener('blur',  (event) => {
    var div = document.createElement('div');
    var button = document.createElement("button");
    var textButton = document.createTextNode("Remove");
    var textDiv = document.createTextNode(input.value);

    div.appendChild(textDiv)
    button.appendChild(textButton);               
    div.appendChild(button);

    button.onclick = () => {
        body.parentNode.removeChild('id');  
    }

    div.classList.add('task');
    body.appendChild(div)
});

function removeData(){
    console.log("hello world");
    //body.parentNode.removeChild(id);
}