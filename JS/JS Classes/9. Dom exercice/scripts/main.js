import StikyComponent from './stikyComponent.js';
import StikyScroll from './stikyScroll.js';

(function () {

  const stikyScrollElement = document.querySelector('.stiky-container');
  const stikyScroll = new StikyScroll(stikyScrollElement);
  const stikyComponentElements = document.querySelectorAll('.stiky-component');
  const stikyComponents = [];
  stikyComponentElements.forEach(element => {
    stikyComponents.push(new StikyComponent(element));
  });

  stikyComponents.forEach(component => {
    stikyScroll.addOnScrollCallback(component.handleOnScroll);
  });

  stikyScroll.initializeListener();

})();