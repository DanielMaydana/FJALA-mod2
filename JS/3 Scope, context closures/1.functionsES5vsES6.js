/*
  so whats the difference between arrow functions ES6
  and ES5 functions;
*/

this.text = 'I am the global scope'; //global scope

const Reminder = {
  text: 'Do my homework', //reminder scope
  showA: function () {
    console.log(this.text);
  },
  showB: () => {
    console.log(this.text); //don't do this...
  }
}

Reminder.showA();
Reminder.showB();


const timmer = {
  time: 0,
  interval: 1000,
  start: function() {
    setInterval(function () { //Callback
      this.time++;
      console.log(this.time);
    }, this.interval);
  }
}

timmer.start();

//In a simple words every time do you need to use
//a callback() on high order function
//use arrow functions to mantain the context of this;