import DataBase from './database.js'; import Elements from './Elements.js'; import ErrorHandler from './Errorhandler.js';

var database = new DataBase();
var errorHandler = new ErrorHandler();
const mainInput = document.querySelector('#add-input');

function elementCreate(item) {

    var element = new Elements();
    element.initElements(item);

    element.button.addEventListener('click', () => {
        database.removeTask(item.id).then(res =>{

            console.clear();
            console.log(item.id);
            element.divContent.remove();

        }).catch(error =>{
        
            element.principal.appendChild(errorHandler.divError);
            errorHandler.initErrorHandler(error);
        });
    })

    element.data.addEventListener('blur', () => {

        item.title = element.data.value;
        
        database.updateTask(item).then(()=>{

            console.clear();
            console.log(item);
        }).catch(error => {
        
            element.principal.appendChild(errorHandler.divError);
            errorHandler.initErrorHandler(error);
        });
    });
}

function createFromDataBase(){
    
    database.getList().then(result =>{
        result.map((res) =>{

            elementCreate(res);
        })
    }).catch(error => {

        element.principal.appendChild(errorHandler.divError);
        errorHandler.initErrorHandler(error);
    });
}

(function () {

    var element = new Elements();

    createFromDataBase();

    mainInput.addEventListener('blur', () => {
        
        // var valueInput = document.getElementById('add-input').value;
        const tasks = {
            title: mainInput.value,
            isDone: false
        }
        document.getElementById('add-input').value = '';
        database.addTask(tasks).then(res =>{
            
            elementCreate(tasks);
            console.clear();
            console.log(tasks);

        }).catch(error =>{

            element.principal.appendChild(errorHandler.divError);
            errorHandler.initErrorHandler(error);
        });

    });
})();
