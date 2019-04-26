import Clock from './clock.js';
(function () {


  const clock = new Clock();
  const container = document.querySelector('.container');
  const clockElement = document.querySelector('.clock');
  const dayElement = clockElement.querySelector('.days');
  const hourElement = clockElement.querySelector('.hours');
  const minElement = clockElement.querySelector('.mins');
  const secondElement = clockElement.querySelector('.seconds');
  const startButton = document.getElementById('startButton');
  const datePicker = document.getElementById('datePicker');
  startButton.addEventListener('click', startDeadLine);
  container.addEventListener('click', changeBackground);
  
  let interval;
  function startDeadLine(event) {
    event.stopPropagation();
    const DATE = datePicker.value;
    clearInterval(interval);
    if(event.target.textContent === 'Start') {
      interval = startCount(DATE)
      event.target.textContent = 'Stop';
    } else {
      event.target.textContent = 'Start';
    }
  }

  function startCount(deadLine) {
    return setInterval(() => {
      clock.calculateTime(deadLine);
      dayElement.textContent = clock.days;
      hourElement.textContent = clock.hours;
      minElement.textContent = clock.mins;
      secondElement.textContent = clock.seconds;
      shouldAnimate(dayElement, hourElement, minElement, secondElement, clock);
    }, 1000);
  }


  function shouldAnimate(dayElement, hourElement, minElement, secondElement, clock) {
    animateElement(secondElement)
    if(clock.seconds === 59){
      animateElement(minElement);
    }

    if(clock.seconds === 59 && clock.mins === 59){
      animateElement(hourElement);
    }

    if(clock.seconds === 59 && clock.mins === 59 && clock.hours === 23) {
      animateElement(dayElement);
    }
  }

  function animateElement(element) {
    element.classList.add('animation');
      setTimeout(() => {
        element.classList.remove('animation');
      }, 500)
  }
  
  let index = 0;
  function changeBackground(event) {
    const backgrounds = [
      '#000',
      '#444',
      '#6C5B7B'
    ]
    container.style.background = backgrounds[index++];
    if(index === 3) {
      index = 0;
    }
  }

})();