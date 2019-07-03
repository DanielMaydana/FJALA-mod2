import InputComponent from './inputComponent.js';

(function () {

  const form = document.querySelector('#people-form');
  const inputsElements = form.querySelectorAll('.input-component');

  inputsElements.forEach(element => {
    new InputComponent(element);
  });

})();