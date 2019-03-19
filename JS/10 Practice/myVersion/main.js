(function(){

    var mainInput = document.querySelector('#add-input');
    
    mainInput.addEventListener('blur', () => {
        
        console.log(mainInput.value);
        var myEntry = new Entry(mainInput.value);

    });

})();

class Entry{
    constructor(tittle){
        
        this.object = document.querySelector('#to-do-app');
        this.divContent = document.createElement('div');
        this.divContent.classList.add('task');
        this.divContent.innerHTML = tittle;

        this.object.appendChild(this.divContent);
    }
}