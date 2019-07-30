import React, { useState, useRef } from 'react';
import * as rxjs from 'rxjs';
import './style.css';

function CircularSlider() {

  const componentRef = React.createRef();

  return (
    <div className="circularSlider" ref={componentRef}>
      <div className="dial inner"></div>
      <div className="dial outer"></div>
      <div className='innerCircle'></div>
      <div className='outterCircle'></div>
    </div>
  )
}

export default CircularSlider;