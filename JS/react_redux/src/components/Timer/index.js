import React, { useState, useRef } from 'react';
import * as rxjs from 'rxjs';
import './style.css';

function Timer() {

  const step = 1000;
  const [seconds, setSeconds] = useState(0);
  const [$clockObservable] = useState(rxjs.interval(step));
  const [clockSubscription, setClockSubscription] = useState();

  function startTimer() {
    if (clockSubscription) {
      return;
    }
    setClockSubscription($clockObservable.subscribe(() => handleClock()));
  }

  function stopTimer() {
    clockSubscription && clockSubscription.unsubscribe();
    setClockSubscription(null);
  }

  function handleClock() {
    setSeconds(seconds => seconds + 1);
  }

  return (
    <div className="timerComponent">
      <p>{seconds}</p>
      <div className="buttonSection">
        <button onClick={startTimer}>Start</button>
        <button onClick={stopTimer}>Stop</button>
      </div>
    </div>
  )
}

export default Timer;