import React from 'react'
import './toolbar.css';
function Toolbar({title, id}) {
  return (
    <section className="toolbar-component">
      {title} {id}
    </section>
  )
}

export default Toolbar;