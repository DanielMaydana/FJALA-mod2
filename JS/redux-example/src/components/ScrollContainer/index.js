import React, { useState, useEffect } from 'react';
import ActionButton from '../ActionButton';
import './scrollcontainer-style.css';

function ScrollContainer({onScroll, children}) {
  
  const [posX] = useState({x:0, y:0});


  // readScroll = (event) => {
  //   const scrolldiv = document.querySelector('.scrollcontainer-component');
  // }
//   let last_known_scroll_position = 0;
//   const scrollContainerRef = React.createRef();

//   useEffect( () => {

//     scrollContainerRef.current.addEventListener('scroll', function(e) {
      
//       last_known_scroll_position = e.scrollY;
//       onScroll(e);
//       // console.log(last_known_scroll_position);
  
//   });
// });

  return (
    <section className="scrollcontainer-component" ref={scrollContainerRef}>
      {children}
    </section>
  );
}

export default ScrollContainer;