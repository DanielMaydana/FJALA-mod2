import React, { useState, useRef } from 'react';
import * as rxjs from 'rxjs';
import './style.css';

function CircularSlider() {

  const compRef = React.createRef();

  return (
    <div className="circularSlider" ref={compRef}>
      <div className="dial outer"></div>
      <div className="dial inner"></div>
      <div className='circle inner'></div>
      <div className='circle outer'></div>
    </div>
  )
}

export default CircularSlider;