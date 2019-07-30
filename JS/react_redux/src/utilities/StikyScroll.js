export default class StikyScroll {
  constructor(element) {
    this.element = element;
    this.callbacks = [];
  }

  addOnScrollCallback(callback) {
    this.callbacks.push(callback);
  }

  initializeListener() {
    this.element.addEventListener('scroll', this.handleScroll);
    console.log(this.element, 'initializeListener');
  }

  handleScroll = event => {
    this.callbacks.forEach(callback => {
      callback(event);
    });
  }
};