import InputButton from './inputButton.js';

function fakeRequest(data) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      console.log('data is saved', data);
      resolve();
    }, 15000);
  });
}

export default class InputComponent {
  constructor(element) {
    this.element = element;
    this.input = element.querySelector('input');
    this.oldValue = '',
    this.saveBtnElement = null;
    this.cancelBtnElement = null;
    this.onInitComponent();
  }

  handleSave = () => {
    if(this.oldValue === this.input.value) {
      return;
    }
    this.input.classList.add('animated-input');
    this.toogleDisable(true);
    fakeRequest(this.oldValue)
    .then(response => {
      this.toogleDisable(false);
      this.input.classList.remove('animated-input');
    })
    .catch(error => {
      this.input.classList.remove('animated-input');
    })

  } 

  handleCancel = () => {
    this.input.value = this.oldValue;
    this.input.blur();
  }

  handleFocus = () => {
    this.oldValue = this.input.value;
    this.addButtons(this.handleSave, this.handleCancel);
  }

  handleBlur = () => {
    this.handleSave();
    const buttons = this.element.querySelectorAll('button');
    buttons.forEach(button => {
      button.classList.add('hide');
      setTimeout(() => {
        this.element.removeChild(button);
      }, 500);
    });
  }

  onInitComponent() {
    this.input.addEventListener('focus', this.handleFocus);
    this.input.addEventListener('blur', this.handleBlur);
    this.input.addEventListener('keypress', (event) => {
      if(event.keyCode === 13) {
        this.handleSave(event)
      }
    });
  }

  addButtons(onSave, onCancel) {
    const saveButton = new InputButton('Ok', onSave, 'save-btn');
    this.saveBtnElement = saveButton.generateButton();
    const cancelButton = new InputButton('No', onCancel, 'cancel-btn');
    this.cancelBtnElement = cancelButton.generateButton();
    this.saveBtnElement.classList.add('hide');
    this.cancelBtnElement.classList.add('hide');
    this.element.appendChild(this.saveBtnElement);
    this.element.appendChild(this.cancelBtnElement);
    setTimeout(() => {
      this.saveBtnElement.classList.remove('hide');
      this.cancelBtnElement.classList.remove('hide');
    })
  }

  toogleDisable(value) {
    if(value) {
      this.input.setAttribute('disabled', true);
      this.saveBtnElement.setAttribute('disabled', true);
      this.cancelBtnElement.setAttribute('disabled', true);
    } else {
      this.input.removeAttribute('disabled');
      this.saveBtnElement.removeAttribute('disabled');
      this.cancelBtnElement.removeAttribute('disabled');

    }
  }
}