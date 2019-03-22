import Entry from './Entry.js';
import DataBase from './database.js';

var myDatabase = new DataBase();
const mainInput = document.getElementById('add-input');
const mainDiv = document.getElementById('to-do-app');

var i = 0;

function refreshMainDiv(){
    mainDiv.innerHTML = '';
    var dbContent = myDatabase.getList();

    dbContent.then(content=>{
        content.map(dbElement => {

            new Entry(dbElement);
        });
    }).catch();
}

(function(){

    refreshMainDiv();

    mainInput.addEventListener('blur', () => {

        var newTask = {
            title: mainInput.value,
            isDone: false
        };

        mainInput.value = '';
        
        myDatabase.addTask(newTask).then(dbTask => {
            
            i++;
            var newEntry = new Entry(dbTask);
            if(i == 2)
            {
                refreshMainDiv();
                i = 0;
            }

        });
        
    });
})();