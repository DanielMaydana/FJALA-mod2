import React, { useState, useEffect } from 'react';
import ActionButton from '../ActionButton';
import './scrollcontainer-style.css';

function ScrollContainer({onScroll, children}) {
  
  function handleScroll (e) {

    onScroll(e.target.scrollTop);
  };

  const scrollRef = React.createRef();

  useEffect( function componentDidMount() {

    console.log('init');
		scrollRef.current.addEventListener('scroll', handleScroll);
		
		return function componentWillUnMount() {

      console.log('fail');
			// scrollRef.current.removeEventListener('scroll', handleScroll);
    }

  });

  return (
    <section className="scrollcontainer-component" ref={scrollRef}>
      {children}
    </section>
  );
};

ScrollContainer.defaultProps = {

  onScroll: () => {},
  children: null
}

export default ScrollContainer;