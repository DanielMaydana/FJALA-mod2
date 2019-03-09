import Clock from './Clock.js';

const Clock = new Clock();

(function(){ // to avoid scope issues
    
    const myClock = new Clock;
    console.log(myClock);

})();