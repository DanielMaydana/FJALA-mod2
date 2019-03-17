export default class InputButton {
  constructor(label, onClick, className) {
    this.label = label;
    this.onClick = onClick;
    this.className = className;
  }

  generateButton() {
    const element = document.createElement('button');
    element.textContent = this.label;
    element.classList.add('btn');
    element.classList.add(this.className);
    element.addEventListener('mousedown', this.handleClick);
    return element;
  }

  handleClick = (event) => {
    console.log('handle click, ?????');
    event.stopPropagation();
    event.preventDefault();
    this.onClick()
  }

}