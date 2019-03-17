(function(){

    const input = document.querySelector('#add-input');
    const whereToAdd = document.querySelector('#to-do-app');

    input.addEventListener('blur', event => {

        console.log(input.value);
        const newDiv = document.createElement('div');
        newDiv.classList.add('task');
        whereToAdd.appendChild(newDiv);
        newDiv.innerHTML = input.value;
    });


})();