import DataBase from './database.js';
import Elements from './createElements.js';
import ErrorHandler from './Errorhandler.js';

const inputElement = document.querySelector('#add-input');
var editTask = false;
var database = new DataBase();
var errorHandler = new ErrorHandler();

function elementCreate(item) {

    console.log(item.title);

    var element = new Elements();
    
    element.initElements(item);

    element.button.addEventListener('click', () => {
    
        database.removeTask(item.id).then(res =>{
    
            element.divContent.remove();
    
        }).catch(error =>{
    
            element.principal.appendChild(errorHandler.divError);
            errorHandler.initErrorHandler(error);
    
        });
    })

    element.data.addEventListener('blur', () => {
    
        item.title = element.data.value;
    
        database.updateTask(item).catch(error => {
    
            element.principal.appendChild(errorHandler.divError);
            errorHandler.initErrorHandler(error)
    
        })
    })
}


(function () {
    var element = new Elements();

    database.getList().then(result =>{
    
        result.map((res) =>{

            elementCreate(res);
        })
    
    }).catch(error => {
    
        element.principal.appendChild(errorHandler.divError);
        errorHandler.initErrorHandler(error)
    });

    inputElement.addEventListener('blur', () => {

        if(!editTask) {

            var valueInput = document.getElementById('add-input').value;

            const tasks = {

                title: valueInput,
                isDone: false
            }

            document.getElementById('add-input').value = '';

            database.addTask(tasks).then(res =>{
         
                elementCreate(tasks);

            }).catch(error =>{

                element.principal.appendChild(errorHandler.divError);
                errorHandler.initErrorHandler(error)

            });
        }
    });
})();
